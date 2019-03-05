#include<stdio.h>
#include <stdlib.h>
typedef struct node_tag {
  /* data */
  int data;
  struct node_tag *next;
}node_type;
typedef enum status_code {FAILURE,SUCCESS} status;
typedef enum boolean {FALSE,TRUE} bool;
node_type* create(){
  node_type *nptr;
  nptr = NULL;
  return nptr;
}
node_type* makenode(int d){
  node_type *nptr;
  nptr = (node_type*)malloc(sizeof(node_type));
  nptr->data = d;
  nptr->next = NULL;
  return nptr;
}
bool is_element_of(int x, node_type* sptr){
  bool b = FALSE;
  int flag = 0;
  while (sptr != NULL && flag == 0) {
    /* code */
    if (sptr -> data == x) {
      /* code */
      flag = 1;
      b = TRUE;
    }
    else{
      sptr = sptr -> next;
    }
  }
  return b;
}
void print_list(node_type* sptr)
{
  if(sptr == NULL){
    printf("Empty Link_list;\n");
  }
  else{
    printf("List : \n");
    while(sptr!=NULL)
    {
      printf("%d  ",sptr->data);
      sptr = sptr -> next;
    }
    printf("\n");
  }
}
status add(node_type** spptr,int x){
  node_type *nptr,*ptr;
  int flag=0;
  status sc=SUCCESS;
  bool b;
  ptr=*spptr;
  while (ptr != NULL && flag == 0) {
    /* code */
    flag = (int)is_element_of(x, ptr);
    ptr = ptr -> next;
  }
  if(flag==0){
    nptr = makenode(x);
    nptr->next = *spptr;
    *spptr = nptr;
  }
  else sc=FAILURE;
  return sc;
}
node_type* enumerate(node_type* sptr)
{
  node_type *lptr=NULL;
  while (sptr != NULL) {
    /* code */
    add(&lptr,sptr -> data);
    sptr = sptr -> next;
  }
  return lptr;
}
node_type* build(){
  int n,d,p;
  node_type *nptr,*lptr = NULL;
  printf("Enter no. of elements in Link_List:" );
  scanf("%d", &n);
  p = n;
  while(n != 0){
    printf("Enter the _%d_ element:\n", p - n);
    scanf("%d", &d);
    add(&lptr, d);
    n--;
  }
  return lptr;
}

status Remove(node_type** spptr,int x){
  node_type *nptr,*ptr,*pre;
  int flag=0;
  status sc=SUCCESS;
  ptr=pre=*spptr;
  if(ptr!=NULL&&flag == 0){
    if (ptr->next != NULL) {
      /* code */
      while (ptr != NULL && flag == 0) {
        /* code */
        if(ptr->data==x){
          if (ptr != pre) {
            /* code */
            pre -> next = ptr -> next;
            ptr -> next = NULL;
            free(ptr);
            flag = 1;
          }
          else{
            pre = pre -> next;
            *spptr = pre;
            flag = 1;
            free(ptr);
          }
        }
        else{
          pre = ptr;
          ptr = ptr->next;
        }
      }
    }
    else{
      if (ptr -> data == x) {
        /* code */
        free(ptr);
        *spptr=NULL;
        flag = 1;
      }
    }
  }
  if(flag == 0){
    sc = FAILURE;
  }
  return sc;
}
bool is_empty(node_type* sptr){
  bool b = FALSE;
  if (sptr == NULL) {
    /* code */
    b = TRUE;
  }
  return b;
}
int size(node_type* sptr){
  int l=0;
  while (sptr != NULL) {
    /* code */
    sptr = sptr -> next;
    l++;
  }
  return l;
}
node_type* inter(node_type* sptr, node_type* tptr){
  node_type *nptr, *temp, *lptr = NULL;
  temp = tptr;
  int a, b, flag = 0;
  a = size(sptr);
  b = size(tptr);
  if (a < b) {
    /* code */
    while (sptr != NULL) {
      /* code */
      flag = (int)is_element_of(sptr -> data, tptr);
      if (flag == 1) {
        /* code */
        add(&lptr, sptr -> data);
      }
      sptr = sptr -> next;
    }
  }
  else{
    while (tptr != NULL) {
      /* code */
      flag = (int)is_element_of(tptr -> data, sptr);
      if (flag == 1) {
        /* code */
        add(&lptr, tptr -> data);
      }
      tptr = tptr -> next;
    }
  }
  return lptr;
  /*
  while (sptr != NULL) {

    add(&lptr, sptr -> data);
    sptr = sptr -> next;
  }
  while (tptr != NULL) {

    add(&lptr, tptr -> data);
    tptr = tptr -> next;
  }
  return lptr;

  */
}
node_type* Union(node_type* sptr, node_type* tptr){
  int a,b;
  node_type *nptr, *temp, *lptr = NULL;
  temp = sptr;
  while (sptr != NULL) {
    /* code */
    add(&lptr, sptr -> data);
    sptr = sptr -> next;
  }
  sptr = temp;
  while (tptr != NULL) {
    /* code */
    b = is_element_of(tptr -> data, sptr);
    if(b == 0){
      add(&lptr, tptr -> data);
    }
    tptr = tptr -> next;
  }
  return lptr;
}
node_type* differ(node_type* sptr, node_type* tptr){
  node_type *nptr, *temp, *lptr = NULL;
  temp = tptr;
  int a, b, flag = 0;
  while (sptr != NULL) {
    /* code */
    flag = (int)is_element_of(sptr -> data, tptr);
    if (flag == 0) {
      /* code */
      add(&lptr, sptr -> data);
    }
    sptr = sptr -> next;
  }
  return lptr;
}
bool Subset(node_type* sptr, node_type* tptr){
  bool bl = FALSE;
  int a, b, flag = 1;
  a = size(sptr);
  b = size(tptr);
  if (a <= b) {
    /* code */
    while (sptr != NULL && flag == 1) {
      /* code */
      flag = (int)is_element_of(sptr -> data, tptr); //flag becomes 1 if element in S also presents in T and continues..
      sptr = sptr -> next;
    }
    if (flag == 1) {
      /* code */
      bl = TRUE;
    }
  }
  return bl;
}

int main(int argc, char const *argv[]) {
  /* code */
  status sc;
  bool b, sub;
  int l, p = 1, f, scn;
  node_type *s = NULL, *bld = NULL, *t = NULL, *u = NULL, *in = NULL, *di = NULL, *enu = NULL; // initialising with null for avoiding any errors....
  s = create();
  while (p != 0) {
    /* code */
    printf("###########################################\n");
    printf("1.Create()\n2.add(S,x)\n3.remove(s,x)\n4.is_element_of(x,S)\n5.is_empty(S)\n6.size(S)\n7.enumerate(S)\n8.build(x 1 ,x 2 ,...,x n ,)\n9.Build 'T'\n10.union(S,T)\n11.intersection(S,T)\n12.difference(S,T)\n13.subset(S,T)\n14.print_list(S)\n15.print_list(T)\n16.exit()\n");
    printf("Enter the no. for a func: ");
		scanf("%d",&f);
    switch (f) {
      case 1: s = create();
      printf("Created a empty Set Structure......\n");
              break;
      case 2:  printf("Enter the value to 'add' in S: \n");
      scanf("%d", &scn);
      sc = add(&s,scn);
      sc == 1 ? printf("SUCCESS\n") : printf("FAILURE - As the element is already present!!!\n");
      break;
      case 3: printf("Enter the value to 'remove' in S: \n");
      scanf("%d", &scn);
      sc = Remove(&s,scn);
      sc == 1 ? printf("SUCCESS\n") : printf("FAILURE - As the element is not present!!!\n");
      break;
      case 4: printf("Enter the value to 'check' whether it is element of S: \n");
      scanf("%d",scn);
      b = is_element_of(scn, s);
      b == 1 ? printf("TRUE\n") : printf("FALSE\n");
      break;
      case 5: printf("Checking whether S is empty...?  \n");
      b = is_empty(s);
      b == 1 ? printf("TRUE\n") : printf("FALSE\n");
      break;
      case 6: printf("Size of S is : ");
      l = size(s);
      printf("%d\n", l);
      break;
      case 7: printf("Enumerating S.....\n");
      enu = enumerate(s);
      printf("Printing the Enumerated Set Structure.......\n");
      print_list(enu);
      break;
      case 8: printf("Building new Set Structure......\n");
      bld = build();
      print_list(bld); // printing the same set Structure for knowing whether returned properly or not?
      break;
      case 9: t = build();
      break;
      case 10: u = Union(s, t);
      printf("Union of S and T : \n");
      print_list(u);
      break;
      case 11: in = inter(s, t);
      printf("Intersection of S and T : \n");
      print_list(in);
      break;
      case 12: di = differ(s, t);
      printf("Difference of S and T :\n");
      print_list(di);
      break;
      case 13: sub = Subset(s, t);
      sub == 1 ? printf("TRUE\n") : printf("FALSE\n");
      break;
      case 14: print_list(s);
      break;
      case 15: print_list(t);
      break;
      case 16:
      p = 0;
      printf("#############  ExItiNg.....  #############\n");
      break;
      default : printf("Enter a Nice Value.... \n");
      break;
    }
  }
  return 0;
}
