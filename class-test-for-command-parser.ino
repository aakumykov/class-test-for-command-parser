#include "ParserClass.cpp"

ParserClass parser(512, ":", ",");

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("=class-test-for-command-parser=");

  parser.parse("11:2,3,4,5");
  
  Serial.print("command: "); Serial.println(parser.command());

  int count = parser.length();
  Serial.print("data count: "); Serial.println(count);
  
  int* data = parser.data();
  Serial.print("data: ");
  for (int i=0; i < count; i++) {
    Serial.print(i); Serial.print(":"); Serial.print(data[i]); Serial.print(", ");
  } Serial.println("");

  int* data2 = parser.data();
  Serial.print("data: ");
  for (int i=0; i < parser.length(); i++) {
    Serial.print(i); Serial.print(":"); Serial.print(data2[i]); Serial.print(", ");
  } Serial.println("");
  
  parser.parse("22:3,4,5,6,7,8,9");
  Serial.print("command: "); Serial.println(parser.command());
  int* data3 = parser.data();
  Serial.print("data: ");
  for (int i=0; i < parser.length(); i++) {
    Serial.print(i); Serial.print(":"); Serial.print(data3[i]); Serial.print(", ");
  } Serial.println("");
}

void loop() {
  
}
