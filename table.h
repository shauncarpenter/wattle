//Simple hash table implementation, based on the ideas from the Lua
//  table implementation.
//In other words, it uses a "seperate chaining" method of key insertion;
//  there are a seperate "array" and "table" parts

#include "values.h"

Table* make_table(int hash_size, int array_size);
Node* add_new_key(Table* table, Value* key);
Node* get_key(Table* table, Value* key);

