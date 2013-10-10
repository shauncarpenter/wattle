#include <stdlib.h>
#include <stdbool.h>

#include "table.h"

const int default_size = 2;

Table* make_table(int hash_size, int array_size){
  Table* table = malloc(sizeof(Table));
  
  //If the size given is invalid, then use the default size.
  if(hash_size < 0){
    hash_size = default_size;
  }
  if(array_size < 0){
    array_size = default_size;
  }

  //We want the hash part to be NULL if that part doesn't exist.
  if(hash_size !=0){
    table->hash = malloc(sizeof(Node)*hash_size);
  }else{
    table->hash = NULL;
  }
  
  //Same for the array part.
  if(array_size !=0){
    table->array = malloc(sizeof(Value)*array_size);
  }else{
    table->array = NULL;
  }
  table->array_size = array_size;

  //All done.
  return table;
}

//Use this to add a new key to a table;
Node* add_new_key(Table* table, Value* key);
Node* get_key(Table* table, Value* key);

//Hashing functions
int hash_string(String* string);
int hash_number(Number* number);
int hash_function(Function* function);
int hash_table(Table* table);
int hash_bool(int bool);
