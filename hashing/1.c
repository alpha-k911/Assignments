#include<stdio.h>
HASH(char d[],char m,char e){
  int M,E;
  M=m+1;
  M=M%6;
  E=e+1;
  E=E%6;
  // printf("%d\n", M);
  d[M]++;
  d[M]=d[E]+d[M];
}
int main(int argc, char const *argv[]) {
  int a,b,c,M,n;
  char d[7]={0},m,e;
  printf("Enter no. of entries: ");
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    /* code */
    scanf(" %c",&e);
    scanf(" %c",&m);
    // printf("%d %d\n", e,m);
    if (e!=m) {
      HASH(d,m,e);
      /* code */
      // HASH(d,m,e);
    }
  }
  for (int i = 0; i < 6; i++) {
    /* code */
    printf("%c = %d\n",i+65,d[i]);
  }
  return 0;
}
