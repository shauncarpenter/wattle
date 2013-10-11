#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

const char* keywords[] = {"require", "let", "var", "if", "sol", "nil"};

typedef struct Source{
  char* data;
  long long int size;
  FILE* fp;
}Source;

typedef struct Parse_Data{
}Parse_Data

Source* read_file(char* path); 
void close_file(Source* s);
Parse_Data* parse(char* buf, long long int size);

int main(int argc, char** argv){
  int files = argc-1;
  char** sources = argv+1;

  if(files < 1){
    fprintf(stderr, "No source files given; place them after \"solc\"");
  }else{
    //Read the source files
    Source* s = read_file(sources[i]);
    char* buf = b.data;
    int size = b.size;
    Parse_Data* parse_data = parse(buf, size);
    close_file(s);
  }

}

Source* read_file(char* path){
  Source* source = malloc(sizeof(Source));
  struct stat st;
  if(stat(path, &st) == 0){
    source->size = st.st_size;
  }else{
    fprintf(stderr, "File %s doesn't exist\n", path);
  }
  
  source->fp = fopen(path, "r");
  source->data = malloc(sizeof(char)*source->size + 1);
  if(fread(source->data, source->size, 1, source->fp) != size){
    printf("Didn't read the same amount of bytes as the file apparently has");
  }

  source->data[source->size] = '\0';
  return source;
}

void close_file(Source* s){
  free(s->data);
  fclose(s->fp);
}

Parse_Data* parse(char* buf, long long int size){
  int i=0;
  Parse_Data* data = malloc(sizeof(Parse_Data));


