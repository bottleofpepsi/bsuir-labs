package com.labs.services;

import com.labs.entities.CallsCounter;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CallCountServiceTest {
    CallCountService service;

    @BeforeEach
    void setUp() {
        service = new CallCountService();
    }

    @Test
    public void testCounter() {
        int syncCalls = CallsCounter.getSyncCallsCount();
        int asyncCalls = CallsCounter.getAsyncCallsCount();
        service.addSyncCall();
        service.addAsyncCall();

        assertEquals(asyncCalls + 1, CallsCounter.getAsyncCallsCount());
        assertEquals(syncCalls + 1, CallsCounter.getSyncCallsCount());
    }
}