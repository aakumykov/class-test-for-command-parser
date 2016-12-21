#include <Arduino.h>

class ParserClass
{
  public:
    ParserClass(int maxDataLen, char* command_delimiter, char* data_delimiter) {
      this->data = new int[maxDataLen];
      this->command_delimiter = command_delimiter;
      this->data_delimiter = data_delimiter;
    }

    void parse(char* str) {
      Serial.print("ParserClass.parse("); Serial.print(str); Serial.println(")");

      this->clear();

      char* raw_command = strtok(str, this->command_delimiter);
      this->command = atoi(raw_command);
      
      char* raw_data_piece = strtok(NULL, this->data_delimiter);
      int data_piece = atoi(raw_data_piece);
      
      while (NULL != raw_data_piece) {
        this->data[this->counter] = data_piece;
        this->counter += 1;
        
        raw_data_piece = strtok(NULL, this->data_delimiter);
        data_piece = atoi(raw_data_piece);
      }
    }

    int getCommand(){
      //Serial.println("ParserClass.getCommand()");
      return this->command;
    }

    int* getData() {
      //Serial.println("ParserClass.getData()");
      int* d = new int[this->counter];
      for (int i=0; i < this->counter; i++) {
        d[i] = this->data[i];
      }
      return d;
    }

    int getDataCount() {
      //Serial.println("ParserClass.getDataCount()");
      return this->counter;
    }

    void clear() {
      this->counter = 0;
    }

  private:
    char* command_delimiter;
    char* data_delimiter;
    
    int command;
    int* data;
    int counter = 0;
};

