#include <Arduino.h>
#include "./JSONmake.h"

DynamicJsonDocument *Global_attribute::JSONdoc = new DynamicJsonDocument(1024);

JSONmake::JSONmake(/* args */)
{
}

JSONmake::~JSONmake()
{
}
void JSONmake::setBuffersize(size_t size_buffer)
{
    attr.JSONdoc = new DynamicJsonDocument(size_buffer);
}

void JSONmake::clear(JsonDocument &ref_docs)
{
    Serial.println(F("# [Clear Json buffer]"));
    ref_docs.clear();
    Serial.println(F("-------------------------------"));
}

size_t JSONmake::getBuffersize()
{
    return attr.JSONdoc->memoryPool().capacity();
}

void JSONmake::add(String key, String value, JsonDocument &ref_docs)
{
    int len = value.length();
    char *c_value = new char[len + 1];
    std::copy(value.begin(), value.end(), c_value);
    c_value[len] = '\0';
    ref_docs[key] = c_value;
    delete[] c_value;
}

void JSONmake::add(String key, const char *value, JsonDocument &ref_docs)
{
    ref_docs[key] = value;
}

void JSONmake::add(String key, int value, JsonDocument &ref_docs)
{
    ref_docs[key] = value;
}

void JSONmake::add(String key, float value, JsonDocument &ref_docs)
{
    ref_docs[key] = value;
}

void JSONmake::add(String key, boolean value, JsonDocument &ref_docs)
{
    ref_docs[key] = value;
}

void JSONmake::remove(String key, JsonDocument &ref_docs)
{
    Serial.println("Remove [Key]: " + key);
    ref_docs.remove(key);
}

boolean JSONmake::findKey(String key, JsonDocument &ref_docs)
{
    return ref_docs.containsKey(key);
}

size_t JSONmake::getUsedBuffer()
{
    return attr.JSONdoc->memoryPool().capacity();
}

size_t JSONmake::getCountKeyJSON()
{
    return attr.JSONdoc->size();
}

String JSONmake::buildJSON(boolean _clear, JsonDocument &ref_docs)
{
    String bufferJsonStr;
    // Serial.println("# [Build JSON Key is]: "+ String(ref_docs.size()) +" key");
    size_t mmr_usage = ref_docs.memoryUsage();
    size_t max_size = ref_docs.memoryPool().capacity();
    size_t safety_size = max_size * (0.97);
    // Serial.println("Safety size: "+String(safety_size));
    if (mmr_usage >= safety_size)
    {
        bufferJsonStr = "null";
        Serial.println("# [Overload memory toJSONString] *Maximum Safety Memory size to use is: " + String(safety_size));
    }
    else
    {
        serializeJson(ref_docs, bufferJsonStr);
        Serial.println("# [to JSON String Key is]: " + String(ref_docs.size()) + " key");
    }

    Serial.println("# MemoryUsage: " + String(mmr_usage) + "/" + String(safety_size) + " from(" + String(ref_docs.memoryPool().capacity()) + ")");
    if(_clear)
        clear(*attr.JSONdoc);
    return bufferJsonStr;
}