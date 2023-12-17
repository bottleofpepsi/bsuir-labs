package com.labs.entities;

public class BulkParams {

    String firstValue;
    String secondValue;
    String thirdValue;

    public BulkParams() {
        this.firstValue = "";
        this.secondValue = "";
        this.thirdValue = "";
    }
    public BulkParams(String firstValue, String secondValue, String thirdValue) {
        this.firstValue = firstValue;
        this.secondValue = secondValue;
        this.thirdValue = thirdValue;
    }
    public String getFirstValue() {
        return firstValue;
    }
    public void setFirstValue(String firstValue) {
        this.firstValue = firstValue;
    }

    public String getSecondValue() {
        return secondValue;
    }
    public void setSecondValue(String secondValue) {
        this.secondValue = secondValue;
    }

    public String getThirdValue() {
        return thirdValue;
    }
    public void setThirdValue(String thirdValue) {
        this.thirdValue = thirdValue;
    }
}
