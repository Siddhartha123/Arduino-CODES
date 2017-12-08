#ifndef variableChange_h
#define variableChange_h
#include "Arduino.h"
#include<EEPROM.h>

class variable{
public:
  uint8_t NUMBER_VARIABLES;
  void variable(char * variable_name, int *variable);
  void variable(char * variable_name, float *variable);
private:
int j;
String var;
uint8_t variables_index;
int * int_variables[NUMBER_VARIABLES];
char * int_variables_names[NUMBER_VARIABLES];
uint8_t float_variables_index;
float * float_variables[NUMBER_VARIABLES];
char * float_variables_names[NUMBER_VARIABLES];
String s;
String s1="                     ";

};
#endif
