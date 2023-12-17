package com.labs.services;
import com.labs.entities.Values;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class FindMaxServiceTest {
    FindMaxService service;

    @BeforeEach
    void setUp() {
        service = new FindMaxService();
    }

    @Test
    public void testFind() {
        assertEquals(55, service.findMax(55, (float) -11.03, 9).getMaxValue());
    }

    @Test
    public void testException() {
        Throwable exception = assertThrows(RuntimeException.class,
                () -> service.findMax(55, (float) -11.03, 1000));
        assertNotNull(exception.getMessage());
    }

    @Test
    public void testEmptyResult()
    {
        Values resultOfDivide = service.findMax(55, (float) -11.03, 9);
        Values resultNull = service.findMax(0, 0, 0);
        assertNotEquals(resultNull, resultOfDivide);
    }

    @Test
    public void testAggregation()
    {
        List<Values> values = new ArrayList<>();
        float minValue, averageValue, maxValue;

        values.add(new Values(10,12,14));
        values.add(new Values(-8,-9,2));
        values.add(new Values(15,11,17));

        minValue = service.findMinValue(values);
        averageValue = service.findAverageValue(values);
        maxValue = service.findMaxValue(values);

        assertNotEquals(minValue, (float) values.stream().mapToDouble(Values::getMaxValue).min().getAsDouble());
        assertNotEquals(averageValue, (float) values.stream().mapToDouble(Values::getMaxValue).average().getAsDouble());
        assertNotEquals(maxValue, (float) values.stream().mapToDouble(Values::getMaxValue).max().getAsDouble());
    }
}