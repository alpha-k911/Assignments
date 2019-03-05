#include <stdio.h>
int foo(int n){
  int res;
  if (n == 1) {
    /* code */
    res = 2;;
  }else{
    res = n + foo(n-1);
  }
  return res;
}
int main(int argc, char const *argv[]) {
  /* code */
  int i,sum,t,n,a;
   scanf("%d", &t);
   for (int i = 0; i < t; i++) {
     /* code */
     scanf("%d",&a);
     sum = foo(a);
     printf("%d\n", sum);
   }
  return 0;
}
