#include <Arduino.h>
#include "./utils/ArduinoJson-v6.18.3.h"
#include "./utils/Global_attribute.h"
class JSONmake
{
private:
    /* data */
public:
    JSONmake(/* args */);
    ~JSONmake();
    void setBuffersize(size_t size_buffer);
    size_t getBuffersize();
    size_t getUsedBuffer();
    size_t getCountKeyJSON();
    void clear(JsonDocument &ref_docs = *attr.JSONdoc);
    void add(String key, String value, JsonDocument &ref_docs = *attr.JSONdoc);
    void add(String key, const char* value, JsonDocument &ref_docs = *attr.JSONdoc);
    void add(String key, int value, JsonDocument &ref_docs = *attr.JSONdoc);
    void add(String key, float value, JsonDocument &ref_docs = *attr.JSONdoc);
    void add(String key, boolean value, JsonDocument &ref_docs = *attr.JSONdoc);
    void remove(String key, JsonDocument &ref_docs = *attr.JSONdoc);
    boolean findKey(String key, JsonDocument &ref_docs = *attr.JSONdoc);
    String buildJSON(boolean clear = false, JsonDocument &ref_docs = *attr.JSONdoc);
};