//Simple hash table implementation, based on the ideas from the Lua
//  table implementation.
//In other words, it uses a "seperate chaining" method of key insertion;
//  there are a seperate "array" and "table" parts

#include "values.h"

Table* make_table(int size);
void add_new_key(Table* table, Value* key, Value* value);
Node* get_key(Table* table, Value* key);

