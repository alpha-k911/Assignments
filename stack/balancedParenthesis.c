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

Status pop(Stack *sptr,char *cptr){
    Status sc=SUCESS;
    Node *ptr=sptr->top;;
    if(ptr==NULL){
        sc=FAIL;
    }else{
        *cptr=(sptr->top)->data;
        sptr->top=(ptr)->next;
        free(ptr);
    }

    return sc;
}


int main() {
    int i,j,flag=1;
    Stack stck;
    initialize(&stck);
    char str[100],c;
    Status sc;
    printf("Enter the string \n");
    scanf("%s",str);
    for(i=0;str[i]!='\0' && flag==1;i++){
        switch (str[i]){
            case '{':
            case '[':
            case '(':
              sc=push(&stck,str[i]);
              break;
            case ')':
                sc=pop(&stck,&c);
                if(sc==FAIL){
                    //i.e stack is empty and hence it is not a balanced parenthesis
                   flag=0;
                }else{
                    if(c!='('){
                        flag=0;
                    }
                }

                break;
            case ']':
                sc=pop(&stck,&c);
                if(sc==FAIL){
                    //i.e stack is empty and hence it is not a balanced parenthesis
                    flag=0;
                }else{
                    if(c!='['){
                        flag=0;
                    }
                }
                break;
            case '}':
                sc=pop(&stck,&c);
                if(sc==FAIL){
                    //i.e stack is empty and hence it is not a balanced parenthesis
                    flag=0;
                }else{
                    if(c!='{'){
                        flag=0;
                    }
                }
                break;
            default:

                break;
        }



    }



    if(flag==1 && stck.top==NULL){
        printf("It is a balanced parenthesis \n");
    }else{
        printf("No it is not a balanced parentheses \n");
    }

    return 0;
}