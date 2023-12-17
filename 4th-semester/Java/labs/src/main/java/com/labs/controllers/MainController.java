package com.labs.controllers;

import com.labs.entities.*;
import com.labs.memory.MemoryCache;
import com.labs.services.CallCountService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.labs.services.FindMaxService;
import com.labs.validator.Validator;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("api")
public class MainController {
	@Autowired
	private final FindMaxService serviceFind;
	@Autowired
	private final CallCountService serviceCount;
	private final Validator validator;
	private static final Logger logger = LoggerFactory.getLogger(MainController.class);
	private final MemoryCache memory;

	@Autowired
	public MainController(FindMaxService serviceFind, Validator validator, MemoryCache memory, CallCountService serviceCount) {
		this.serviceFind = serviceFind;
		this.validator = validator;
		this.memory = memory;
		this.serviceCount = serviceCount;
	}

	@GetMapping(value = "/findmax", produces = MediaType.APPLICATION_JSON_VALUE)
	@ResponseStatus(HttpStatus.OK)
	public ResponseEntity<Result> get(@RequestParam(name = "first", required = false) String first,
									  @RequestParam(name = "second", required = false) String second,
									  @RequestParam(name = "third", required = false) String third) {

		Result result = new Result();
		Values serviceResult;

		logger.info("Сервис CallCountService");
		serviceCount.addAsyncCall();
		serviceCount.addSyncCall();

		logger.info("Валидация");
		result.setErrors(validator.validateParameter(first, second, third));

		if (!result.getErrors().getErrormessage().isEmpty()) {
			result.getErrors().setStatus("BAD_REQUEST");
			return new ResponseEntity<>(result, HttpStatus.BAD_REQUEST);
		}

		try {
			logger.info("Работа с MemoryCache");
			String key = first + second + third;

			if (memory.containsResponse(key)) {
				result.setResult(memory.getResultByKey(key));
			} else {
				logger.info("Сервис FindMaxService");
				serviceResult = serviceFind.findMax(Float.parseFloat(first),
						Float.parseFloat(second),
						Float.parseFloat(third));

				memory.add(key,serviceResult);
				result.setResult(serviceResult);
			}
			result.getErrors().setStatus("OK");
		} catch (RuntimeException exception){
			result.getErrors().setStatus("INTERNAL_SERVER_ERROR");
			result.getErrors().addErrormessage(exception.getMessage());
			return new ResponseEntity<>(result, HttpStatus.INTERNAL_SERVER_ERROR);
		}

		return new ResponseEntity<>(result, HttpStatus.OK);
	}



	@GetMapping("/all")
	@ResponseStatus(HttpStatus.OK)
	public ResponseEntity<Object> getAllResults(){
		return new ResponseEntity<>(memory.getCache(), HttpStatus.OK);
	}

	@GetMapping("/all/size")
	@ResponseStatus(HttpStatus.OK)
	public ResponseEntity<Object> getResultsCount() {
		return new ResponseEntity<>(memory.getSize(), HttpStatus.OK);
	}

	@GetMapping("/calls")
	@ResponseStatus(HttpStatus.OK)
	public ResponseEntity<Object> getCallsCount() {
		List<Object> list = new ArrayList<>();
		list.add(CallsCounter.getSyncCallsCount());
		list.add(CallsCounter.getAsyncCallsCount());
		return new ResponseEntity<>(list, HttpStatus.OK);
	}

	@PostMapping("/findmax")
	@ResponseStatus(HttpStatus.CREATED)
	public ResponseEntity<BulkResponse> bulk(@RequestBody List<BulkParams> params) {
		params.forEach(bulkParams -> {
			ValidationError validation = validator.validateParameter(bulkParams.getFirstValue(),
																	 bulkParams.getSecondValue(),
																	 bulkParams.getThirdValue());
			if (!validation.getErrormessage().isEmpty())
				params.remove(bulkParams);
		});

		List<Values> resultList = serviceFind.bulkFindMax(params);
		memory.addList(resultList);

		float min = serviceFind.findMinValue(resultList),
				average = serviceFind.findAverageValue(resultList),
				max = serviceFind.findMaxValue(resultList);

		BulkResponse response = new BulkResponse(resultList, min, average, max);
		logger.info("Минимальное maxValue = " + min);
		logger.info("Среднее maxValue = " + average);
		logger.info("Максимальное maxValue = " + max);

		return new ResponseEntity<>(response, HttpStatus.CREATED);
	}
}


