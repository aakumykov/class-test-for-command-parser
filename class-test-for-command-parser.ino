#include "ParserClass.cpp"

ParserClass parser(128, ":", ",");

void setup() {
  Serial.begin(9600); while(!Serial);
  Serial.println("=class-test-for-command-parser=");

  //char str[] = "1:2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30";
  //char str[] = "1:2,3,4,5";
  char str[] = "22:3,4,5,6";

  //parser.parse(str); // так не работает!
  parser.parse("1:2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30");
  Serial.print("command: "); Serial.println(parser.command());
  int* data3 = parser.data();
  Serial.print("data: ");
  for (int i=0; i < parser.length(); i++) {
    Serial.print(i); Serial.print(":"); Serial.print(data3[i]); Serial.print(", ");
  } Serial.println("");
  delete data3;


  //parser.parse(str); // так не работает!
  parser.parse("22:2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30");
  Serial.print("command: "); Serial.println(parser.command());
  int* data4 = parser.data();
  Serial.print("data: ");
  for (int i=0; i < parser.length(); i++) {
    Serial.print(i); Serial.print(":"); Serial.print(data4[i]); Serial.print(", ");
  } Serial.println("");
  delete data4;
  
}

void loop() {
  
}
