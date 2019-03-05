#include <stdio.h>
int maxm(int t[],int l,int r){
  int max = 0,p=0;
  p=l;
  max=t[l];
  for (int i = l+1; i <= r; i++) {
    /* code */
    if (t[i]>max) {
      /* code */
      p=i;
      max = t[i];
    }
  }
  return p;
}
main(){
    int i,j,n,z,p,q,done,rem,l,r,max,mi,m,c=0,t[100000];
    scanf("%d",&z);
    for(i=0;i<z;i++){
        scanf("%d",&n);
        for (int j = 0; j < n; j++) {
          /* code */
          scanf("%d", &t[j]);
        }
        r=n-1;
        l=0;
        mi=maxm(t,0,n-1);
        m = t[mi];
        done=0;
        c=0;
        while (!done&&l<=r) {
          /* code */
            if (mi!=l&&mi!=r) {
              /* code */
              if (mi<=(l+r)/2) {
                /* code */
                r=mi-1;
                c++;
              }
              else{
                l=mi+1;
                c++;
              }
            }
            else{
              c++;
              done=1;
            }
            mi=maxm(t,l,r);
          }
          printf("%d\n", c);
    }
}
