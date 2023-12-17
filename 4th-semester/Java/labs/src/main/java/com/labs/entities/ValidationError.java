package com.labs.entities;
import java.util.ArrayList;
import java.util.List;

public class ValidationError {
	
    private final List<String> errorMessages;
    private String status;

    public ValidationError() {
        this.errorMessages = new ArrayList<String>();
        this.status = "";
    }

    public List<String> getErrormessage(){
        return errorMessages;
    }
    public void addErrormessage(String errormessage){
        this.errorMessages.add(errormessage);
    }
    public String getStatus() {
         return status;
    }
    public void setStatus(String status){
        this.status = status;
    }
}