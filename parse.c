#include <stdlib.h>
#include <stddef.h>

#include "parse.h"

Expression* parse_app(char* buf, long long int* index);
Expression* parse_number(char* buf, long long int* index);
Expression* parse_special(char* buf, long long int* index);

const int number_size = 100;

//Parse a source file, giving the "parse tree" in the form of a Parse_Data
//  Structure.
Parse_Data* parse(char* buf, long long int size){
  Parse_Data* data = malloc(sizeof(Parse_Data));
  data->exp = NULL;
  
  //Main parsing loop.
  for(long long int i = 0; i < size; i++){
    char next = buf[i];
    if(next == '('){
      //An application.
      add_expression(data, parse_app(buf, &i, size));
    }else if(next == '-' || next == '+' || isdigit(next)){
      //A number.
      add_expression(data, parse_number(buf, &i, size));
    }else if(isalpha(next))
      //Either a symbol or some sort of table access.
      add_expression(data, parse_special(buf, &i, size));
  }
  return data;
}		  

Expression* parse_number(char* buf, long long int* index, long long int size){
  char* point;
  double result = strtod(&buf[index], &point);
  
  if(double == 0.0){
    fprintf(stderr, "Invalid number");
  }
  *index = point-buf;
  
  //MAKE THE EXPRESSION
}

Expression* parse_special(char* buf, long long int* index, 
			  long long int size){
  
  
      
