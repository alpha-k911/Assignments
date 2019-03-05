#include<stdio.h>
typedef struct node_tag{
	int data;
	struct node_tag *next;
}node_type;
typedef struct stack_tag{
	node_type *top;
}stack_type;
typedef enum {F,S} status;
node_type* makenode(int d)
{

	node_type *nptr;
	nptr=(node_type*)malloc(sizeof(node_type));
	nptr->data=d;
	return nptr;
}
stack_type* initialise(stack_type *sptr){
	sptr->top=NULL;
}

status push(stack_type *sptr,int d)
{
	status sc=S;
	node_type *nptr;
	nptr=makenode(d);
	nptr->next=sptr->top;
	sptr->top=nptr;
	return  S;
}

status pop(stack_type *sptr)
{
	stack_type *ptr;
	status sc=S;
	if(sptr->top!=NULL)
	{
		ptr=sptr->top;
		sptr->top=(sptr->top)->next;
		free(ptr);
	}
	else{
		sc=F;
	}
	return sc;
}

status isSE(stack_type *sptr)
{
	status sc=S;
	if(sptr->top!=NULL)
	{
		sc=F;
	}
	return sc;
}

main()
{
	node_type *nptr,*lptr;
	stack_type stck;
	status sc;
	int i,*data,p=1,o,a,l,d;

	initialise(&stck);
	while(p!=0)
	{
		printf("0.push\n1.pop\n2.isStackEmpty?\n3.exit\n");
		printf("enter the no. for a func: ");
		scanf("%d",&o);
		switch(o)
		{
			case 0:printf("Enter the value to push:");
				scanf("%d",&a);
				sc=push(&stck,a);
				if(sc==0){printf("Failure\n");}
				else{printf("Success\n");}
				break;
			case 1: sc=pop(&stck);
				if(sc==0){printf("Failure\n");}
				else{printf("Success\n");}
                                break;
			case 2: sc=isSE(&stck);
				if(sc==0){printf("False\n");}
				else{printf("True\n");}
                                break;
			case 3: p=0;
				printf("Byee!!!\n");
				break;
			default:printf("enter a nice value :P");
				break;
		}
	}
}
