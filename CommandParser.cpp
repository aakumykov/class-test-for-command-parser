#include <Arduino.h>
#include <MemoryFree.h>

class CommandParser
{
  public:
    CommandParser(int max_input_len, char* command_delimiter, char* data_delimiter) {
      this->the_data = new int[max_input_len];
      this->command_delimiter = command_delimiter;
      this->data_delimiter = data_delimiter;
    }

    void parse(char* str, bool debug=false) {
      Serial.println(F(""));
      Serial.print(F("CommandParser.parse("));
      Serial.print(str);
      Serial.println(F(")"));

      this->clear();

      char* raw_command = strtok(str, this->command_delimiter);
      //Serial.print(F("raw_command: ")); Serial.println(raw_command);
      this->the_command = atoi(raw_command);
//      this->the_command = (unsigned long)(raw_command);
      
      char* raw_data_piece = strtok(NULL, this->data_delimiter);
      int data_piece = atoi(raw_data_piece);
      
      while (NULL != raw_data_piece) {
        this->the_data[this->the_counter++] = data_piece;
        //this->the_counter += 1;
        
        raw_data_piece = strtok(NULL, this->data_delimiter);
        data_piece = atoi(raw_data_piece);
      }

      if (debug) {
        this->command();
        //this->data();
        this->length();
        Serial.print(F("free memory: ")); Serial.println(freeMemory());
      }
    }

    byte command(){
      //Serial.println(F("CommandParser.getCommand()"));
      Serial.print(F("command: "));
      Serial.println(this->the_command);
      return this->the_command;
    }

    int* data() {
//      Serial.println(F("CommandParser.getData()"));

//      int* d = new int[this->the_counter];
//      for (int i=0; i < this->the_counter; i++) {
//        d[i] = this->the_data[i];
//      }
//      return d;

      Serial.print(F("data: "));
      for (int i=0; i < this->the_counter; i++) 
      {
        //Serial.print(i); Serial.print(F(":"));
        Serial.print(this->the_data[i]); Serial.print(F("-"));
      }
      Serial.println(F(""));

      return this->the_data;
    }

    int length() {
      //Serial.println(F("CommandParser.getDataCount()"));
      Serial.print(F("data count: "));
      Serial.println(this->the_counter);
      return this->the_counter;
    }

  private:
    char* command_delimiter;
    char* data_delimiter;
    
    unsigned long the_command;
    int* the_data;
    int the_counter = 0;

    void clear() {
      //Serial.println(F("CommandParser.clear()"));
      this->the_counter = 0;
    }
};

