/*
Author:Worawit Sayned
Create Date: 10 Feb 2023. 
*/
#ifndef GLOBAL_ATTRIBUTE_H
#define GLOBAL_ATTRIBUTE_H
#include <Arduino.h>
#include "./ArduinoJson-v6.18.3.h"
class Global_attribute
{
public:
    static DynamicJsonDocument *JSONdoc;
};
extern Global_attribute attr;
#endif