#include <Arduino.h>

class ParserClass
{
  public:
    ParserClass() {
    }

    void fillData() {
      Serial.println("ParserClass.fillData()");
      for (int i=0; i < this->len; i++) {
//        Serial.print(i);
//        Serial.print(": ");
//        Serial.println(i*2);
        this->data[i] = i*2;
      }
    }

    void getData() {
      Serial.println("ParserClass.getData()");
      for (int i=0; i < this->len; i++) {
        Serial.print(i);
        Serial.print(": ");
        Serial.println(this->data[i]);
      }
    }

  private:
      int len = 5;
      int* data = new int[10];
};

