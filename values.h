struct Value;
struct Table;
struct Node;
struct String;
struct Function;
struct Number;

typedef struct Value{
  char type_tag;
  union {
    struct Table table;
    struct String string;
    struct Number number;
    struct Function func;
    int boolean;
  } value;
}Value;

typedef struct Table{
  struct Node* hash;
  struct Value* array;
  int array_size;
}Table;

typedef struct Node{
  struct Value* key;
  struct Value* val;
  struct Node* next;
}Node;

typedef struct String{
  char* data;
  int length;
}String;

typedef struct Number{
  double data;
}Number;

typedef struct Function{
  //No idea for this yet.
}Function;

const int nil_tag = 0;
const int table_tag = 1;
const int string_tag = 2;
const int number_tag = 3;
const int function_tag = 4;
const int boolean_tag = 5;
  
