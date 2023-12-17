package com.labs.services;

import com.labs.entities.BulkParams;
import com.labs.entities.BulkResponse;
import com.labs.entities.Result;
import org.springframework.stereotype.Service;

import com.labs.entities.Values;

import java.util.ArrayList;
import java.util.List;

@Service
public class FindMaxService {
	
	public Values findMax(float first, float second, float third) {
		Values response = new Values(first, second, third);
		float max;

		max = Math.max(first, Math.max(second, third));

		if (max == 1000) throw new RuntimeException("Костыльная 500 ошибка для примера (max = 1000)");
		
		response.setMaxValue(max);
		
		return response;
	}

	public List<Values> bulkFindMax(List<BulkParams> params){
		List<Values> result = new ArrayList<>();
		params.forEach(bulkParams -> result.add(findMax(Float.parseFloat(bulkParams.getFirstValue()),
								   						Float.parseFloat(bulkParams.getSecondValue()),
								  				 		Float.parseFloat(bulkParams.getThirdValue()))));
		return result;
	}

	public float findMinValue(List<Values> values) {
		return (float) values.stream().mapToDouble(Values::getMaxValue).min().getAsDouble();
	}
	public float findAverageValue(List<Values> values) {
		return (float) values.stream().mapToDouble(Values::getMaxValue).average().getAsDouble();
	}
	public float findMaxValue(List<Values> values) {
		return (float) values.stream().mapToDouble(Values::getMaxValue).max().getAsDouble();
	}
}
