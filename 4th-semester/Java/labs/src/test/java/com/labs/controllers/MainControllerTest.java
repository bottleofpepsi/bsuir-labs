package com.labs.controllers;
import com.labs.entities.*;
import com.labs.memory.MemoryCache;
import com.labs.services.CallCountService;
import com.labs.services.FindMaxService;
import com.labs.validator.Validator;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import java.util.ArrayList;
import java.util.List;

import static org.mockito.Mockito.*;
import static org.mockito.MockitoAnnotations.*;

@ExtendWith(MockitoExtension.class)
public class MainControllerTest {

    @Mock
    private FindMaxService serviceFind = mock(FindMaxService.class);
    @Mock
    private CallCountService serviceCount = mock(CallCountService.class);
    @Mock
    private Validator validator = mock(Validator.class);
    @Mock
    private MemoryCache memory = mock(MemoryCache.class);
    @InjectMocks
    private MainController controller = new MainController(serviceFind, validator, memory, serviceCount);

    @BeforeEach
    public void setUp(){
        initMocks(this);
    }

    @Test
    public void testGoodResult(){
        String first = "15.9";
        String second = "-11.03";
        String third = "9";
        String key = first + second + third;
        
        Values resultOfFind = new Values((float)15.9, (float)-11.03, (float)9);
        
        Values resultOfFindExc = new Values();

        when(validator.validateParameter(first, second, third)).thenReturn(new ValidationError());
        when(serviceFind.findMax(Float.parseFloat(first), Float.parseFloat(second), Float.parseFloat(third))).thenReturn(resultOfFind);

        doNothing().when(memory).add(key,resultOfFind);
        doNothing().when(serviceCount).addAsyncCall();
        doNothing().when(serviceCount).addSyncCall();

        ResponseEntity<Result> response = controller.get(first, second, third);
        Result result = (Result) response.getBody();
        assertNotNull(response);
        assertNotEquals(resultOfFindExc, result.getResult());

        verify(memory, times(1)).add(key,resultOfFind);
        verify(serviceCount, times(1)).addAsyncCall();
        verify(serviceCount, times(1)).addSyncCall();
    }

    @Test
    public void testDuplicate() {
        String first = "15.9";
        String second = "-11.03";
        String third = "9";
        String key = first + second + third;

        Values resultOfFind = new Values((float) 15.9, (float) -11.03, (float) 9);
        Values resultOfFindExc = new Values();

        when(validator.validateParameter(first, second, third)).thenReturn(new ValidationError());
        when(memory.containsResponse(key)).thenReturn(true);

        when(memory.getResultByKey(key)).thenReturn(resultOfFind);
        doNothing().when(serviceCount).addAsyncCall();
        doNothing().when(serviceCount).addSyncCall();

        ResponseEntity<Result> response = controller.get(first, second, third);
        Result result = (Result) response.getBody();
        assertNotNull(response);
        assertNotEquals(resultOfFindExc, result.getResult());

        verify(serviceCount, times(1)).addAsyncCall();
        verify(serviceCount, times(1)).addSyncCall();
    }

    @Test
    public void testBadRequest(){
        String first = "frgnfei";
        String second = "-11.03";
        String third = "9";
        
        Values resultOfFind = new Values();
        ValidationError errorMessage = new ValidationError();

        errorMessage.addErrormessage("Первый параметр не является числом");
        when(validator.validateParameter(first, second, third)).thenReturn(errorMessage);

        doNothing().when(serviceCount).addAsyncCall();
        doNothing().when(serviceCount).addSyncCall();

        ResponseEntity<Result> response = controller.get(first, second, third);
        Result result = (Result) response.getBody();
        assertNotNull(result);
        assertEquals(result.getErrors(), errorMessage);

        verify(serviceCount, times(1)).addAsyncCall();
        verify(serviceCount, times(1)).addSyncCall();
    }

    @Test
    public void testException(){
        String first = "1000";
        String second = "-11.03";
        String third = "9";
        
        Values resultOfFind = new Values();

        when(validator.validateParameter(first, second, third)).thenReturn(new ValidationError());
        when(serviceFind.findMax(Float.parseFloat(first), Float.parseFloat(second), Float.parseFloat(third))).thenThrow(RuntimeException.class);

        doNothing().when(serviceCount).addAsyncCall();
        doNothing().when(serviceCount).addSyncCall();

        ResponseEntity<Result> response = controller.get(first, second, third);
        Result result = (Result) response.getBody();
        assertNotNull(result);

        verify(serviceCount, times(1)).addAsyncCall();
        verify(serviceCount, times(1)).addSyncCall();
    }

    @Test
    public void testBulk(){
        List<BulkParams> params = new ArrayList<>();
        params.add(new BulkParams("7", "3.44", "9.11"));

        List<Values> valueList = new ArrayList<>();
        valueList.add(new Values(7, (float) 3.44, (float) 9.11));

        List<String> emptyStrings = new ArrayList<String>();

        when(validator.validateParameter("7", "3.44", "9.11")).thenReturn(new ValidationError());
        doNothing().when(memory).addList(valueList);

        ResponseEntity<BulkResponse> response = controller.bulk(params);
        BulkResponse result = (BulkResponse) response.getBody();
        assertNotNull(response);
        assertEquals(result.getResults(), valueList);

        verify(memory, times(1)).addList(valueList);
    }

    @Test
    void inMemoryStorageTest(){
        ResponseEntity<Object> results = controller.getAllResults();
        ResponseEntity<Object> count = controller.getResultsCount();

        assertEquals(results.getStatusCode(), HttpStatus.OK);
        assertEquals(count.getStatusCode(), HttpStatus.OK);
    }

    @Test
    void callsCounterTest(){
        ResponseEntity<Object> result = controller.getCallsCount();

        assertEquals(result.getStatusCode(), HttpStatus.OK);
    }
}