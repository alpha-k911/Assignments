#include<stdio.h>
typedef struct try_tag{
  int d;
}try;
foo(try* a){
  printf("%d\n", a -> d);
}
int main() {
  /* code */
  try a;
  a.d = 2;
  foo(&a);
  return 0;
}
