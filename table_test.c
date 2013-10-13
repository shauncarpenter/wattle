#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "table.h"
#include "hash.h"

const int number_iterations = 1000000;
const int number_values = 1000000;

int main(){
  Table* table = make_table(10, 10);
  Value* keys = (Value*)malloc(sizeof(Value)*number_values);
  Value* values = (Value*)malloc(sizeof(Value)*number_values);

  for(int i=0; i<number_values; i++){
    keys[i].value.number.data = i;
    values[i].value.number.data = i*100;
  }
  for(int i=0; i<number_values; i++){
    Node* node = add_new_key(table, &keys[i]);
    node->val = &values[i];
  }

  for(int i=0; i<number_values; i++){
    Node* node = get_key(table, &keys[i]);
    if(node->val->value.number.data != values[i].value.number.data){
      printf("ERROR, WRONG KEY RETRIEVED!");
    }
    //printf("key: %d, value: %d.\n", 
    //   node->key->value.number.data, node->val->value.number.data);
  }
  return 1;
}
