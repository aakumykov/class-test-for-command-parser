#include "ParserClass.cpp"

ParserClass parser;

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("=class-test-for-command-parser=");

  parser.fillData();
  parser.getData();
}

void loop() {
  
}
