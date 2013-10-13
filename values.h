struct Value;
struct Table;
struct Node;
struct String;
struct Function;
struct Number;

typedef struct Table{
  struct Node* hash;
  struct Value* array;
  int array_size, hash_size;
  struct Node* last_free;
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
  int data;
}Number;

typedef struct Function{
  //No idea for this yet.
}Function;

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


//const int nil_tag = 0;
extern const int table_tag;
extern const int string_tag;
extern const int number_tag;
extern const int function_tag;
extern const int boolean_tag;
  
