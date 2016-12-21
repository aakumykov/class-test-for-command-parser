#include <Arduino.h>

class ParserClass
{
  public:
    ParserClass() {
      this->data = new int[10];
    }

    void parse(char* str) {
      //Serial.print("ParserClass.parse("); Serial.print(str); Serial.println(")");

      // "стираю" старые данные
      this->data_counter = 0;

      char* raw_cmd = strtok(str, ":");
      this->cmd = atoi(raw_cmd);
      
      char* raw_data_piece = strtok(NULL, ",");
      int data_piece = atoi(raw_data_piece);
      
      while (NULL != raw_data_piece) {
        this->data[this->data_counter] = data_piece;
        this->data_counter += 1;
        
        raw_data_piece = strtok(NULL, ",");
        data_piece = atoi(raw_data_piece);
      }
    }

    int getCommand(){
      //Serial.println("ParserClass.getCommand()");
      return this->cmd;
    }

    int* getData() {
      Serial.println("ParserClass.getData()");
//      for (int i=0; i < this->data_counter; i++) {
//        Serial.print(i);
//        Serial.print(": ");
//        Serial.println(this->data[i]);
//      }
      int* d = new int[this->data_counter];
      for (int i=0; i < this->data_counter; i++) {
        d[i] = this->data[i];
      }
      return d;
    }

    int getLength() {
      Serial.println("ParserClass.getLength()");
      return this->data_counter;
    }

  private:
    int cmd;
    int* data = new int[512];
    int data_counter = 0;
};

