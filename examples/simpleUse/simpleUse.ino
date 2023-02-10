#include <Arduino.h>
#include <JSONmake.h>

JSONmake jsonMake;
void setup() {
  Serial.begin(115200);
  // jsonMake.setBuffersize(2048); // set new JSON buffersize
  // jsonMake.getBuffersize(); // get size JSON buffersize
  jsonMake.add("hello", "world");
  jsonMake.add("math", 1234);
  jsonMake.add("fload", 1.12464f);
  jsonMake.add("bool", true);
  jsonMake.add("deletes", 1.12464f);
  jsonMake.remove("deletes");
  Serial.println("getUsed: "+String(jsonMake.getUsedBuffer()));
  Serial.println("getBuffersize: "+String(jsonMake.getBuffersize()));
  Serial.println("bool is: "+String(jsonMake.findKey("bool")));
  Serial.println("man is: "+String(jsonMake.findKey("man")));
  Serial.println("getBuffersize: "+String(jsonMake.getBuffersize()));
  Serial.println("JSON: "+(jsonMake.buildJSON()));
}

void loop() {
  // put your main code here, to run repeatedly:
}