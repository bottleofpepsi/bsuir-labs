package com.labs.services;

import com.labs.entities.CallsCounter;
import org.springframework.stereotype.Service;

@Service
public class CallCountService {

    public synchronized void addSyncCall(){
        CallsCounter.setSyncCallsCount(CallsCounter.getSyncCallsCount() + 1);
    }

    public void addAsyncCall(){
        CallsCounter.setAsyncCallsCount(CallsCounter.getAsyncCallsCount() + 1);
    }
}
