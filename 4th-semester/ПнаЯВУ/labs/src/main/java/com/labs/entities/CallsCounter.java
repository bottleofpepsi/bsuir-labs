package com.labs.entities;

public class CallsCounter {
    private static int syncCount;
    private static int asyncCount;

    public CallsCounter() {}

    public static void setSyncCallsCount(int newCount){
        syncCount = newCount;
    }
    public static int getSyncCallsCount() {
        return syncCount;
    }

    public static void setAsyncCallsCount(int newCount){
        asyncCount = newCount;
    }
    public static int getAsyncCallsCount() { return asyncCount; }
}