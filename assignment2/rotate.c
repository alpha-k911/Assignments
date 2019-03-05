#include <stdio.h>
#include <stdlib.h>
typedef struct node_tag{
	int data;
	struct node_tag *next;
}node_type;
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
node_type* create(int d)
{
	node_type *nptr,*lptr;
        int i;
        lptr=NULL;
	for(i=0;i<d;i++)
        {
                nptr=(node_type*)malloc(sizeof(node_type));
                nptr->data=i;
                nptr->next=lptr;
                lptr=nptr;
        }
	return lptr;
}
node_type* iaS(node_type **lpptr,int d)
{
	node_type *lptr,*ptr,*nptr;
	ptr=*lpptr;
	nptr=(node_type*)malloc(sizeof(node_type));
	nptr->data=d;
	nptr->next=*lpptr;
	// ptr=nptr;
  *lpptr = nptr;
}
void iaE(node_type **lpptr,int d)
{
  node_type *lptr,*ptr,*nptr;
  ptr=*lpptr;
  nptr=(node_type*)malloc(sizeof(node_type));
  nptr->data=d;
  nptr->next=NULL;
	if(ptr!=NULL)
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=nptr;
	}
	else
	{
		*lpptr=nptr;
	}
}
rotate(node_type **lpptr, int k){
  node_type *start,*end,*ptr,*lptr;
  lptr = *lpptr;
  int i;
  start = ptr = end = lptr;
  for ( i = 0; i < k; i++) {
    /* code */
    start = start -> next;
  }
  while (end -> next != NULL) {
    /* code */
    end = end -> next;
  }
  while (ptr != start) {
    /* code */
    end -> next = ptr;
    ptr = ptr -> next;
    end = end -> next;
    end -> next = NULL;
  }
  *lpptr = start;
}
node_type* reverse(node_type *f, node_type *s, node_type *t ){
  node_type *ptr;
  if (t == NULL) {
    /* code */
    s -> next = f;
    ptr = s;
  }
  else{
    s -> next = f;
    ptr = reverse(s, t, t -> next);
  }
  return ptr;
}
node_type* add2N(node_type *a, node_type *b){
  node_type *res = NULL, *e1, *e2;
  int c = 0, sum = 0;
  while (a != NULL && b != NULL) {
    /* code */
    sum = a -> data + b -> data + c;
    c = sum/10;
    sum = sum % 10;
    iaS(&res, sum);
    a = a -> next;
    b = b -> next;
  }
  if(a != NULL){
    while (a != NULL) {
      /* code */
      sum = a -> data + c;
      c = sum/10;
      sum = sum % 10;
      iaS(&res, sum);
      a = a -> next;
    }
  }
  else  if(b != NULL){
    while (b != NULL) {
      /* code */
      sum = b -> data + c;
      c = sum/10;
      sum = sum % 10;
      iaS(&res, sum);
      b = b -> next;
    }
  }
  if (c != 0) {
    /* code */
    iaS(&res, c);
  }
  return res;
}
int main() {
  /* code */
  int k, a, i;
  node_type *lptr = NULL,*nptr, *aptr, *bptr, *r = NULL;
  // nptr=(node_type*)malloc(sizeof(node_type));
  // nptr -> data = 10;
  // nptr -> next = NULL;
  // lptr = nptr;
  iaE(&lptr, 20);
  iaE(&lptr, 30);
  iaE(&lptr, 40);
  iaE(&lptr, 50);
  iaE(&lptr, 60);
  print_list(lptr);
  // printf("enter value of k: \n");
  // scanf("%d", &k);
  // rotate(&lptr,k);
  // print_list(lptr);

  // lptr = reverse(NULL, lptr, lptr -> next);
  // print_list(lptr);
  aptr = bptr = NULL;
  printf("enter the no. of digits of a:");
  scanf("%d", &k);
  for ( i = 0; i < k; i++) {
    /* code */
    scanf("%d", &a);
    iaS(&aptr, a);
  }
  printf("enter the no. of digits of b:");
  scanf("%d", &k);
  for ( i = 0; i < k; i++) {
    /* code */
    scanf("%d", &a);
    iaS(&bptr, a);
  }
  print_list(aptr);
  print_list(bptr);
  // iaS(&r,0);
  r = add2N(aptr, bptr);
  print_list(r);
  return 0;
}
