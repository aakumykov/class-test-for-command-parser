#include <Arduino.h>

class ParserClass
{
  public:
    ParserClass() {
      this->data = new int[10];
    }

    void parse(char* str) {
      Serial.print("ParserClass.parse(");
      Serial.print(str);
      Serial.println(")");

      char* cmd = strtok(str, ":");
      Serial.print("cmd: ");
      Serial.println(cmd);
      
      char* data_piece = strtok(NULL, ",");
      while (NULL != data_piece) {
          Serial.print("data_piece: ");
          Serial.println(data_piece);
        data_piece = strtok(NULL, ",");
      }
      
      //Serial.println();
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
      //int* data = new int[10];
      int* data;
};

