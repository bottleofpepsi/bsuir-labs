package com.labs.entities;

import java.util.ArrayList;
import java.util.List;

public class BulkResponse {

    private List<Values> results;
    private float min;
    private float average;
    private float max;

    public BulkResponse(){
        this.results = new ArrayList<>();
        this.min = 0;
        this.average = 0;
        this.max = 0;
    }
    public BulkResponse(List<Values> results, float min, float average, float max) {
        this.results = results;
        this.min = min;
        this.average = average;
        this.max = max;
    }

    public List<Values> getResults() {
        return results;
    }
    public void setResults(List<Values> results) {
        this.results = results;
    }

    public float getMin() {
        return min;
    }
    public void setMin(float min) {
        this.min = min;
    }

    public float getAverage() {
        return average;
    }
    public void setAverage(float average) {
        this.average = average;
    }

    public float getMax() {
        return max;
    }
    public void setMax(float max) {
        this.max = max;
    }
}
