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
    char* _command_delimiter;
    char* _data_delimiter;
    
    unsigned long _command;
    int* _data;
    int _counter = 0;

    void clear();
};


#endif
