typedef struct Expression{
  Value* value;
  struct Expression* next;
}Expression;

typedef struct Parse_Data{
  Expression exp;
}Parse_Data;

Parse_Data* parse(char* buf, long long int size);
  
