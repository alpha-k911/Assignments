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
node_type* iaE(node_type **lpptr,int d)
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
		ptr=nptr;
	}
        return *lpptr;
}

node_type* deS(node_type **lpptr,int* data)
{
        node_type *lptr,*pre,*ptr,*nptr;
	ptr=*lpptr;
	if(ptr!=NULL)
	{
		nptr=ptr->next;
		free(ptr);
		*lpptr=nptr;
	}
	return *lpptr;
}


node_type* deE(node_type **lpptr,int* data)
{
        node_type *lptr,*pre,*ptr,*nptr;
	ptr=*lpptr;
	pre=*lpptr;
	if(ptr!=NULL)
	{
		if(ptr->next!=NULL)
		{
			while(ptr->next!=NULL)
			{
				pre=ptr;
				ptr=ptr->next;
			}
			*data=ptr->data;
			free(pre->next);
			pre->next=NULL;
		}
		else
		{
			*data=ptr->data;
			free(*lpptr);
			*lpptr=NULL;
		}
	}
	return *lpptr;
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
void middle(node_type* lptr){
  node_type *mid,*tail;
  mid = tail = lptr;
  int flag = 0;
  while (flag == 0 && lptr != NULL) {
    /* code */
    if ( tail != NULL && tail -> next != NULL) {
      /* code */
        tail = tail -> next;
        tail = tail -> next;
        mid = mid -> next;
    }
    else{
      flag = 1;
      printf("%d\n", mid -> data);
    }
  }
}
void dupli(node_type** lpptr){
  node_type *ptr,*pre,*dup;
  pre = *lpptr;
  if (*lpptr != NULL) {
    /* code */
      ptr = pre -> next;
      while (ptr != NULL) {
        /* code */
        if (ptr -> data != pre -> data) {
          /* code */
          pre = pre -> next;
          ptr = ptr -> next;
        }
        else{
          dup = ptr;
          ptr = ptr -> next;
          pre -> next = ptr;
          free(dup);
        }
    }
  }
}

main()
{
	node_type *nptr,*lptr;
	int i,*data,p=1,a,b=0,o;
	data=&b;e
	while(p!=0)
	{
		printf("0.create\n1.ias\n2.iaE\n3.deS\n4.deE\n5.traverse\n6.middle element\n7. Remove duplicates\n");
		printf("enter the no. for a func: ");
		scanf("%d",&o);
		switch(o)
		{
			case 0:printf("Enter no. of Nodes:");
				scanf("%d",&a);
				lptr=create(a);
				break;
			case 1:printf("Enter the value to be inserted at start:");
                                scanf("%d",&a);
                                lptr=iaS(&lptr,a);
                                break;
			case 2:printf("Enter the value to be inserted at end:");
                                scanf("%d",&a);
                                lptr=iaE(&lptr,a);
                                break;
			case 3:lptr=deS(&lptr,data);
				printf("deleted value is: %d",*data);
                                break;
			case 4:lptr=deE(&lptr,data);
				printf("deleted value is: %d",*data);
                                break;
			case 5: print_list(lptr);
				break;
			case 6: printf("the middle element is: \n");
				middle(lptr);
				break;
				case 7: dupli(&lptr);
				break;
			default:printf("enter a nice value :P");
				break;
		}
	}
}
