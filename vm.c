#include<stdio.h>
typedef struct node_tag{
	int data;
	struct node_tag *next;
}node_type;
node_type* iaS(node_type **lpptr,int d)
{
	node_type *lptr,*ptr,*nptr;
	ptr=*lpptr;
	nptr=(node_type*)malloc(sizeof(node_type));
	nptr->data=d;
	nptr->next=ptr;
	lptr=nptr;
	return lptr;
}
create(int d)
{
	node_type *nptr,*lptr;
        int i,*data,a=15;
        data=&a;
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
traverse(node_type **lpptr)
{
	node_type *lptr,*ptr,*nptr;
        ptr=*lpptr;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}


void main()
{
int i=0,d;
printf("enter number of nodes");
scanf("%d",&d);
create(d);
traverse(&lptr);
while(i<d/2)
{
	nptr=nptr->next;
	i++;
}
printf("middle linked list is %d",nptr->next);
}
	
