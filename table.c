#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "table.h"
#include "hash.h"

const int default_size = 0;
void allocate_table(Table* table, int hash_size, int array_size);
int hash_value(Table* t, Value* value);
void rehash_table(Table* table);
Node* get_next_free(Table* table);


Table* make_table(int hash_size, int array_size){
  Table* table = (Table*)malloc(sizeof(Table));
  allocate_table(table, hash_size, array_size);
  return table;
}

void allocate_table(Table* table, int hash_size, int array_size){
  
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
    table->last_free = table->hash+hash_size;
  }else{
    table->hash = NULL;
    table->last_free = NULL;
  }
  table->hash_size = hash_size;
  
  //Same for the array part.
  if(array_size !=0){
    table->array = malloc(sizeof(Value)*array_size);
  }else{
    table->array = NULL;
  }
  table->array_size = array_size;
}

    
//Use this to add a new key to a table;
Node* add_new_key(Table* table, Value* key){
  //First, hash the key
  int hash = hash_value(table, key);

  //Use that value to index the hash part of the table;
  Node* node = &table->hash[hash];

  //Is the hashed location taken?
  if(node->key == NULL){
    //No! return this location
    node->key = key;
    return node;
  }else{
    //Yes! Get the next free spot
    Node* next_free = get_next_free(table);
    
    if(next_free == NULL){
      //if there is no more free space, rehash the table.
      rehash_table(table);

      //Then insert the key in the newly hashed table.
      return add_new_key(table, key);
    }

    //check if the key in the spot is in it's main position.
    if(hash_value(table, node->key) == hash){
      //The original is in main position, it stays, the new one goes to the
      //  next free spot.
      next_free->next = node->next;
      node->next = next_free;
      next_free->key = key;
      return next_free;
    }else{
      //The original *isn't* in main position, the new one takes its spot.
      next_free->next = node->next;
      node->next = next_free;
      
      //Move the original to the free spot
      next_free->key = node->key;
      next_free->val = node->val;
      
      //Clear the original spot to make way for the new value.
      node->key = key;
      node->val = NULL;
      return node;
    }
  }
}

Node* get_key(Table* table, Value* key){
  //First, hash the key
  int hash = hash_value(table, key);

  //Use that value to index the hash part of the table.
  Node* node = &table->hash[hash];
  
  //loop the comparison until you find the key or reach the end of the chain.
  while(node->key != NULL){
    if(node->key == key){
      return node;
    }
    node = node->next;
  }
  //If you reach here, the key isn't in the table.
  return NULL;
}

//Hashing functions

int hash_value(Table* t, Value* value){

  /*  switch(value->type_tag){
  case string_tag:
    return hash_string(t, value);
    break;
  case number_tag:
    return hash_number(t, value);
    break;
  case table_tag:
    return hash_table(t, value);
    break;
  case function_tag:
    return hash_function(t, value);
    break;
  case boolean_tag:
    return hash_boolean(t, value);
    break;
  default:
    printf("The type tag is invalid; something has gone horribly wrong\n");
    exit(1);
    }*/

  //For now, simply hash every value by it's pointer.  This will be correct
  //  only if there is only one copy of every value.
  unsigned int hash = SuperFastHash((const char*)(&value), sizeof(value));

  return hash % t->hash_size;
}

Node* get_next_free(Table* table){
  //Keep going until you get to the start of the hash array or encounter a
  //  free spot.
  while(table->last_free > table->hash){
    table->last_free--;
    if(table->last_free->key == NULL){
      return table->last_free;
    }
  }
  return NULL;
}

//This is used when a table is full, and you need to resize it.
//  This involves allocating a new space, and then placing all the current
//  elements into that table again.
void rehash_table(Table* table){
  Table old_table = *table;
  allocate_table(table, old_table.hash_size*2, old_table.array_size*2);
  for(int i=0; i<old_table.hash_size; i++){
    Node old = old_table.hash[i];
    Node* node = add_new_key(table, old_table.hash[i].key);
    node->key = old.key;
    node->val = old.val;
  }
  /*  for(int i=0; i<old_table.array_size; i++){
    add_new_key(table, old_table.array[i]);
    }*/

  free(old_table.array);
  free(old_table.hash);
}
