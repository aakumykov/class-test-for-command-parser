#include "ParserClass.cpp"

ParserClass parser;

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("=class-test-for-command-parser=");

  parser.parse("11:2,3,4,5");
  Serial.print("command: ");
  Serial.println(parser.getCommand());
  int* data = parser.getData();
  

//  parser.parse("22:3,4,5,6");
//  Serial.print("command: ");
//  Serial.println(parser.getCommand());
//  parser.getData();
//
//  parser.parse("33:4,5,6,7");
//  Serial.print("command: ");
//  Serial.println(parser.getCommand());
//  parser.getData();
}

void loop() {
  
}
