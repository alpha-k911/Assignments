#include<stdio.h>
#include<string.h>
typedef struct node_tag{
	char data;
	struct node_tag *next;
}node_type;
typedef struct stack_tag{
	node_type *top;
}stack_type;
typedef enum {F,S} status;
node_type* makenode(char d)
{

	node_type *nptr;
	nptr=(node_type*)malloc(sizeof(node_type));
	nptr->data=d;
	return nptr;
}
stack_type* initialise(stack_type *sptr){
	sptr->top=NULL;
}

status push(stack_type *sptr,char d)
{
	status sc=S;
	node_type *nptr;
	nptr=makenode(d);
	nptr->next=sptr->top;
	sptr->top=nptr;
	return  S;
}

status pop(stack_type *sptr,char *d)
{
	stack_type *ptr;
	status sc=S;
	if(sptr->top!=NULL)
	{
		*d=(sptr->top)->data;
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
	char str[50],p;
	status sc;
	int i,*data,o,a,l,d,flag=1;

	initialise(&stck);
	printf("enter the string to check: ");
	scanf("%s",str);
	l=strlen(str);
	if(l%2==0&&flag==1)
	{
		for(i=0;i<l/2&&flag==1;i++)
		{
			push(&stck,str[i]);
		}
		for(i=l/2;i<l&&flag==1;i++)
		{
			sc=pop(&stck,&p);
			if(sc==1)
			{
				if(p!=str[i]) flag=0;
			}
			else flag=0;
		}
		sc=isSE(&stck);
		if(flag==1&&sc==1) printf("Yeahh!! It's a palindrome\n");
		else printf("nope!!\n");
	}
	else
	{
		for(i=0;i<l/2&&flag==1;i++)
		{
			push(&stck,str[i]);
		}

		for(i=((l/2)+1);i<l&&flag==1;i++)
		{
			sc=pop(&stck,&p);
			if(sc==1)
			{
				if(p!=str[i]) flag=0;
			}
			else flag=0;
		}
		sc=isSE(&stck);
		if(flag==1&&sc==1) printf("Yeahh!! It's a palindrome\n");
		else printf("nope!!\n");
	}


}
