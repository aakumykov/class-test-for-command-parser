#include "ParserClass.cpp"

ParserClass parser(512, ":", ",");

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("=class-test-for-command-parser=");

  parser.parse("11:2,3,4,5");
  
  Serial.print("command: "); Serial.println(parser.getCommand());

  int count = parser.getDataCount();
  Serial.print("data count: "); Serial.println(count);
  
  int* data = parser.getData();
  Serial.print("data: ");
  for (int i=0; i < count; i++) {
    Serial.print(i); Serial.print(":"); Serial.print(data[i]); Serial.print(", ");
  } Serial.println("");

  int* data2 = parser.getData();
  Serial.print("data: ");
  for (int i=0; i < count; i++) {
    Serial.print(i); Serial.print(":"); Serial.print(data2[i]); Serial.print(", ");
  } Serial.println("");
  
  parser.parse("22:3,4,5,6");
  Serial.print("command: ");
  Serial.println(parser.getCommand());
  int* data3 = parser.getData();
  Serial.print("data: ");
  for (int i=0; i < count; i++) {
    Serial.print(i); Serial.print(":"); Serial.print(data3[i]); Serial.print(", ");
  } Serial.println("");

//  parser.parse("33:4,5,6,7");
//  Serial.print("command: ");
//  Serial.println(parser.getCommand());
//  parser.getData();
}

void loop() {
  
}
