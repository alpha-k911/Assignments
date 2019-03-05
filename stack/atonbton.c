
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_tag{
    char data;
    struct Node_tag *next;

}Node;

typedef enum status{SUCESS,FAIL} Status;
typedef struct Stack_tag{
    Node *top;
}Stack;

void initialize(Stack * sptr){
    sptr->top=NULL;
}

Node * MakeNode(char data){
    Node *nptr=(Node *)malloc(sizeof(Node));
    if(nptr!=NULL){
        nptr->data=data;
        nptr->next=NULL;
    }
    return nptr;
}

Status  push(Stack *sptr,char data){
    //it will be insert at start and delete at start;
    Node *nptr=MakeNode(data);
    Status sc=SUCESS;
    if(nptr==NULL){
        sc=FAIL;

    }else{
        nptr->next=sptr->top;
        sptr->top=nptr;
    }
    return sc;

}

Status pop(Stack *sptr){
    Status sc=SUCESS;
    Node *ptr=sptr->top;;
    if(ptr==NULL){
        sc=FAIL;
    }else{
        sptr->top=(ptr)->next;
        free(ptr);
    }

    return sc;
}


int main() {

    Stack stck;
    initialize(&stck);
    Status sc;
    char a[100],c;
    printf("enter the string \n");
    scanf("%s",a);
    int length=strlen(a);
    int i;
    if(length%2==1){
        printf("it can not be of the form a to n and b to n\n");
    }
    else if(length!=0){
        sc=push(&stck,a[0]);
        i=1;
        while(a[i]!='\0' && a[i]==a[i-1]){
            sc=push(&stck,a[i]);
            i++;
        }

        i++;
        sc=pop(&stck);
        while(a[i]!='\0' && a[i]==a[i-1] && sc==SUCESS){
            sc=pop(&stck);
            i++;
        }
        sc=pop(&stck);

        if(a[i]=='\0' && sc==FAIL ){
            printf("the string is of the form a to n b to n \n");
        }else{
            printf("the  string is not of the form a to n b to n \n ");
        }

    }




    return 0;
}

