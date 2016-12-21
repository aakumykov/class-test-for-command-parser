#include "ParserClass.cpp"

ParserClass parser;

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("=class-test-for-command-parser=");

  parser.parse("1:2,3,4,5");
  
  //parser.fillData();
  //parser.getData();
}

void loop() {
  
}
