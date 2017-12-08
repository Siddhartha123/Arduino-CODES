void variable(char * variable_name, int *variable){

  int_variables[variables_index] = variable;
  int_variables_names[variables_index] = variable_name;
  int_variables_index++;

}

void variable(char * variable_name, float *variable){

  float_variables[float_variables_index] = variable;
  float_variables_names[float_variables_index] = variable_name;
  float_variables_index++;
}

uint8_t find_variable(char *variable_name){
  for(j=0;j<int_variables_index;j++)
  {
    if(variable_name==int_variables_names[j])
    return j;
  }
  for(j=0;j<float_variables_index;j++)
  {
    if(variable_name==float_variables_names[j])
    return j;
  }



  return 255;
}
