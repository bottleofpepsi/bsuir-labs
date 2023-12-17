package com.labs.entities;

public class Result {
	
	private Values result;
	private ValidationError errors;
	
	public Result() {
		this.result = new Values();
		this.errors = new ValidationError();
	}
	
	public Result(Values result, ValidationError errors) {
		this.result = result;
		this.errors = errors;
	}
	
	public void setErrors(ValidationError errors) {
		this.errors = errors;
	}

	public ValidationError getErrors() {
		return errors;
	}
	
	public void setResult(Values result) {
		this.result = result;
	}
	
	public Values getResult() {
		return result;
	}
	
}