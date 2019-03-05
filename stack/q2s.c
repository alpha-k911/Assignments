#include <stdio.h>

typedef struct node_tag{
	int data;
	struct node_tag *next;
}node_type;

typedef struct stact_tag{
	node_type *top;
}stack_type;

typedef struct queue{
	stack_type *stck1;
	stack_type *stck2;
}queue_type;

typedef enum {F,S} status;
stack_type* initialiseS(stack_type *sptr){
	sptr->top=NULL;
}
queue_type* initialiseQ(queue_type *qptr){
	initialiseS((qptr -> &stck1));
	initialiseS((qptr -> &stck2));
}
node_type* makenode(int d)
{

	node_type *nptr;
	nptr = (node_type*)malloc(sizeof(node_type));
	nptr->data=d;
	return nptr;
}
stack_type* initialise(stack_type* sptr){
	sptr->top=NULL;
}

status pushS(stack_type* sptr,int d)
{
	status sc=S;
	node_type *nptr;
	nptr=makenode(d);
	nptr->next=sptr->top;
	sptr->top=nptr;
	return  S;
}
status popS(stack_type *sptr, int *d)
{
	node_type *ptr;
	status sc=S;
	if(sptr->top!=NULL)
	{
		ptr=sptr->top;
		*d = ptr -> data;
		sptr->top=(sptr->top)->next;
		free(ptr);
	}
	else{
		sc=F;
	}
	return sc;
}

status isSE(stack_type* sptr)
{
	status sc=S;
	if(sptr->top!=NULL)
	{
		sc=F;
	}
	return sc;
}
status pushQ(queue_type* qptr,int d){
	status sc=S;
	node_type *nptr;
	nptr=makenode(d);
	nptr -> next = qptr -> stck1 -> top;
	( qptr -> stck1 ) -> top = nptr;
	return sc;
}
status popQ(queue_type* qptr, int* d){
	status sc = F;
	node_type *ptr;
	if (!isSE((qptr -> &stck2))) {
		/* code */
		// *d = ((qptr -> stck2) -> top) -> data;
		// ptr = ((qptr -> stck2) -> top);
		// ((qptr -> stck2) -> top) = ((qptr -> stck2) -> top) -> next;
		popS((qptr -> (&stck2)),d);
	}
	else if(!isSE((qptr -> &stck1))){
		while ((qptr -> stck1) -> top != NULL) {
			/* code */
			popS((qptr -> stck1),d);
			pushS(qptr -> stck2,*d);
		}
		sc = popS((qptr -> &stck2),d);
	}
	return sc;
}
int main(int argc, char const *argv[]) {
	queue_type q;
	status sc;
	int d;
	initialiseQ(&q);
	pushQ(&q,2);
	pushQ(&q,5);
	pushQ(&q,7);
	pushQ(&q,8);
	pushQ(&q,9);
	sc = popQ(&q,&d);
	printf("%d\n", d);

	return 0;
}
