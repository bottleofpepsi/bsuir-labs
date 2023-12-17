package com.labs.memory;
import com.labs.entities.Values;
import org.springframework.stereotype.Component;

import java.util.*;

@Component
public class MemoryCache
{
    private Map<String, Values> cache;

    public MemoryCache() {
        this.cache = new HashMap<String, Values>();
    }
    public MemoryCache(Map<String, Values> cache) {
        this.cache = cache;
    }

    public List<Values> getCache() {
        return cache.values().stream().toList();
    }

    public void setCache(Map<String, Values> cache) {
        this.cache = cache;
    }

    public void add(String key, Values result) {
        cache.put(key, result);
    }

    public void addList(List<Values> valueList) {
        valueList.forEach(values -> {
            String key = Float.toString(values.getFirstValue()) + Float.toString(values.getSecondValue()) +
                                                                  Float.toString(values.getThirdValue());
            cache.put(key,values);
        });

    }

    public Values getResultByKey(String key){
        Values result = cache.get(key);
        return result;
    }

    public boolean containsResponse(String key){
        return cache.containsKey(key);
    }

    public int getSize(){
        return cache.size();
    }

    public boolean isEmpty(){
        return cache.isEmpty();
    }
}