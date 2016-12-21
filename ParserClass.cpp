#include <Arduino.h>

class ParserClass
{
  public:
    ParserClass(int maxDataLen, char* command_delimiter, char* data_delimiter) {
      this->the_data = new int[maxDataLen];
      this->command_delimiter = command_delimiter;
      this->data_delimiter = data_delimiter;
    }

    void parse(char* str) {
      Serial.println("");
      Serial.print("ParserClass.parse("); Serial.print(str); Serial.println(")");

      this->clear();

      char* raw_command = strtok(str, this->command_delimiter);
      this->the_command = atoi(raw_command);
      
      char* raw_data_piece = strtok(NULL, this->data_delimiter);
      int data_piece = atoi(raw_data_piece);
      
      while (NULL != raw_data_piece) {
        this->the_data[this->the_counter++] = data_piece;
        //this->the_counter += 1;
        
        raw_data_piece = strtok(NULL, this->data_delimiter);
        data_piece = atoi(raw_data_piece);
      }
    }

    int command(){
      //Serial.println("ParserClass.getCommand()");
      return this->the_command;
    }

    int* data() {
      //Serial.println("ParserClass.getData()");
//      int* d = new int[this->the_counter];
//      for (int i=0; i < this->the_counter; i++) {
//        d[i] = this->the_data[i];
//      }
//      return d;
      return this->the_data;
    }

    int length() {
      //Serial.println("ParserClass.getDataCount()");
      return this->the_counter;
    }

    void clear() {
      this->the_counter = 0;
    }

  private:
    char* command_delimiter;
    char* data_delimiter;
    
    int the_command;
    int* the_data;
    int the_counter = 0;
};

