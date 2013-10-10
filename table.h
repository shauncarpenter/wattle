
//Simple hash table implementation, based on the ideas from the Lua
//  table implementation.
//In other words, it uses a "seperate chaining" method of key insertion;
//  there are a seperate "array" and "table" parts

Table* make_table(int size);
void insert_key(Table* table, Value* key);
Node* retrieve_key(Table* table, Value* key);

