
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

    Stack stck1,stck2;
    initialize(&stck1);
    initialize(&stck2);
    Status sc1,sc2;
    char a[100],c;
    printf("enter the string \n");
    scanf("%s",a);
    int length=strlen(a);
    int i;
    if(length>=3){
        sc1=push(&stck1,a[0]);
        i=1;
        while(a[i]!='\0' && a[i]==a[i-1]){
            sc1=push(&stck1,a[i]);
            i++;
        }
        if(a[i]!='\0'){
           sc1=push(&stck2,a[i]);
           i++;
        }
        while(a[i]!='\0' && a[i]==a[i-1]){
            sc2=push(&stck2,a[i]);
            i++;
        }

        sc1=pop(&stck1);
        sc2=pop(&stck2);
        i++;
        while(a[i]!='\0' && a[i]==a[i-1] && sc1==SUCESS && sc2==SUCESS){
            sc1=pop(&stck1);
            sc2=pop(&stck2);
            i++;
        }
        sc1=pop(&stck1);
        sc2=pop(&stck2);

        if(a[i]=='\0' && sc1==FAIL && sc2==FAIL ){
            printf("the string is of the form a to n b to n c to n\n");
        }else{
            printf("the string is NOT of the form a to n b to n \n ");
        }

    }




    return 0;
}







