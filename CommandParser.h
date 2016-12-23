#include <Arduino.h>
#include <MemoryFree.h>

#ifndef CommandParser_h
#define CommandParser_h

 
class CommandParser
{
  public:
    CommandParser(int max_input_len, char* command_delimiter, char* data_delimiter);
    void parse(char* str, bool debug=false);
    byte command();
    int* data();
    int length();

    
  private:
    char* command_delimiter;
    char* data_delimiter;
    
    unsigned long the_command;
    int* the_data;
    int the_counter = 0;

    void clear();
};


#endif
