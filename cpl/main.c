#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nxt=0;
typedef struct memory_tag{
    int array[100];
}mem;
typedef struct allocList_tag{
    int start;
    int end;
    struct allocList_tag* next;
}allocList;
typedef struct freeList_tag{
    int start;
    int end;
    struct freeList_tag* next;
}freeList;
typedef struct varList_tag{
    char var_name[50];
    struct allocList_tag *node;
    struct varList_tag *next;
}varList;
allocList *aptr;
freeList *fptr;
varList *vptr;
allocList* init_alloc1(int s, int e){
    allocList *nptr;
    nptr = (allocList*)malloc(sizeof(allocList));
    nptr -> start = s;
    nptr -> end = e;
    nptr -> next = NULL;
    return nptr;
}
allocList* init_alloc(){
    aptr = NULL;
}
freeList* init_free(){
    fptr = (freeList*)malloc(sizeof(freeList));
    fptr -> start = 0;
    fptr -> end = 99;
    fptr -> next = NULL;
    return fptr;
}
freeList* init_free1(int s, int e){
    freeList *ptr;
    ptr = (freeList*)malloc(sizeof(freeList));
    ptr -> start = s;
    ptr -> end = e;
    ptr -> next = NULL;
    return ptr;
}
varList* init_var(){
    vptr = NULL;
    // vptr = (varList*)malloc(sizeof(varList));
    // vptr -> var_name[0] = '\0';
    // vptr -> start = 0;
    // vptr -> end = 0;
}
void traverseA(allocList *nptr){
    if (nptr) {
        /* code */
        while (nptr) {
            printf("Allocated: %d - %d \n", nptr -> start, nptr -> end);
            nptr = nptr -> next;
        }
    }else{
        printf("Empty!!\n");
    }
}
void traverseF(freeList *nptr){
    if (nptr) {
        /* code */
        while (nptr) {
            printf("Free: %d - %d \n", nptr -> start, nptr -> end);
            nptr = nptr -> next;
        }
    }else{
        printf("Empty!!\n");
    }
}
void traverseAV(varList *nptr){
    allocList *alptr;
    if (nptr) {
        /* code */
        while (nptr) {
            alptr = nptr -> node;
            printf("Allocated: %s = %d - %d \n", nptr -> var_name, alptr -> start, alptr -> end);
            nptr = nptr -> next;
        }
    }else{
        printf("Empty!!\n");
    }
}
void freeFree(freeList *ptr){
    freeList *pre,*tptr;
    pre = fptr;
    tptr = fptr;
    if (ptr == tptr) {
        /* code */
        fptr = fptr -> next;
        free(ptr);
    }
    else{
        while (ptr != tptr) {
            /* code */
            pre = tptr;
            tptr = tptr -> next;
        }
        pre -> next = tptr -> next;
        free(ptr);
    }
}
void _mallocf(int size, char a[]){
    int i,j,k,s,e,x,flag;
    allocList *a1ptr,*tptr,*pre;
    freeList *ptr;
    varList *tvptr;
    ptr = fptr;
    i = 0;
    j = size - 1;
    flag = 0;
    while (!flag && ptr) {
        x = ptr -> end - ptr -> start + 1;
        if (x >= size) {
            flag = 1;
            s = ptr -> start;
            e = ptr -> start + size -1;
            a1ptr = init_alloc1(s, e);
            tvptr = (varList*)malloc(sizeof(varList));
            strcpy(tvptr -> var_name, a);
            tvptr -> node = a1ptr;
            tvptr -> next = vptr;
            vptr = tvptr;
            nxt = e;
            if (x != size) {
                ptr -> start = e + 1;
            }
            else{
                freeFree(ptr);
            }
        }
        else{
            ptr = ptr -> next;
        }
    }
    if (flag == 0) {
        /* code */
        printf("Out of space!!!\n");
    }
    else{
        tptr = aptr;
        pre = aptr;
        if (aptr) {
            /* code */
            while (tptr != NULL && a1ptr -> start > tptr -> start) {
                pre = tptr;
                tptr = tptr -> next;
            }
            if (pre != tptr) {
                /* code */
                a1ptr -> next = tptr;
                pre -> next = a1ptr;
            }
            else{
                a1ptr -> next = tptr;
                aptr = a1ptr;
            }
        }
        else{
            aptr = a1ptr;
        }
        // traverseA(a1ptr);
        printf("Successfully Allocated\n");
    }
}
void _mallocn(int size, char a[]){
    int found=0,i,j,x,y,s,e,n,flag=0;
    allocList *a1ptr,*tptr,*pre;
    freeList *ptr;
    varList *tvptr;
    ptr = fptr;
    while ((nxt > ptr -> start)&&(ptr != NULL)) {
        ptr = ptr -> next;
    }
    if (ptr) {
        flag = 0;
        while (!flag && ptr) {
            x = ptr -> end - ptr -> start + 1;
            if (x >= size) {
                flag = 1;
                s = ptr -> start;
                e = ptr -> start + size -1;
                a1ptr = init_alloc1(s, e);
                tvptr = (varList*)malloc(sizeof(varList));
                strcpy(tvptr -> var_name, a);
                tvptr -> node = a1ptr;
                tvptr -> next = vptr;
                vptr = tvptr;
                n = e + 1;
                if (x != size) {
                    ptr -> start = e + 1;
                }
                else{
                    freeFree(ptr);
                }
            }
            else{
                ptr = ptr -> next;
            }
        }
        if (ptr == NULL && flag == 0) {
            ptr = fptr;
            while (!flag && ptr) {
                x = ptr -> end - ptr -> start + 1;
                if (x >= size) {
                    flag = 1;
                    s = ptr -> start;
                    e = ptr -> start + size -1;
                    a1ptr = init_alloc1(s, e);
                    n = e + 1;
                    if (x != size) {
                        ptr -> start = e + 1;
                    }
                    else{
                        freeFree(ptr);
                    }
                }
                else{
                    ptr = ptr -> next;
                }
            }
        }else if(flag == 1){
            tptr = aptr;
            pre = aptr;
            if (aptr) {
                /* code */
                while (tptr != NULL && a1ptr -> start > tptr -> start) {
                    pre = tptr;
                    tptr = tptr -> next;
                }
                if (pre != tptr) {
                    /* code */
                    a1ptr -> next = tptr;
                    pre -> next = a1ptr;
                }
                else{
                    a1ptr -> next = tptr;
                    aptr = a1ptr;
                }
            }
            else{
                aptr = a1ptr;
            }
            // traverseA(a1ptr);
            printf("Successfully Allocated\n");

        }
    }
}
void _free(char a[]){
    int flag = 0, i;
    varList *ptr,*pre;
    freeList *frptr,*prefptr,*dptr,*tfptr;
    allocList *praptr, *taptr, *anptr;
    ptr = vptr;
    pre = vptr;
    while (ptr && flag == 0) {
        i = strcmp(a, ptr -> var_name);
        if (i == 0) {
            /* code */
            flag = 1;
        }
        else{
            pre = ptr;
            ptr = ptr -> next;
        }
    }
    if (flag == 1) {
        //free node
        anptr = ptr -> node;
        if (anptr) {
            taptr = aptr;
            praptr = aptr;
            while (taptr != NULL && anptr -> start > taptr -> start) {
                /* code */
                praptr = taptr;
                taptr = taptr -> next;
            }
            if (praptr == taptr) {
                /* code */
                aptr = aptr -> next;
            }
            else{
                praptr -> next = anptr -> next;
            }

            prefptr = fptr;
            tfptr = fptr;
            while (tfptr != NULL && tfptr -> start < anptr -> start) {
                /* code */
                prefptr = tfptr;
                tfptr = tfptr -> next;
            }
            if (prefptr != tfptr) {
                    /* code */
                if (prefptr -> end + 1 == anptr -> start) {
                    /* code */
                    if (anptr -> end + 1 == tfptr -> start) {
                        /* code */
                        prefptr -> end = tfptr -> end;
                        prefptr -> next = tfptr -> next;
                        free(tfptr);
                    }else{
                        prefptr -> end = anptr -> end;
                    }
                }else{
                    if (anptr -> end + 1 == tfptr -> start) {
                        /* code */
                        tfptr -> start = anptr -> start;
                    }
                    else{
                        dptr = init_free1(anptr -> start, anptr -> end);
                        dptr -> next = prefptr -> next;
                        prefptr -> next = dptr;
                    }
                }
            }
            else{
                if (anptr -> end + 1 == prefptr -> start) {
                    /* code */
                    prefptr -> start = anptr -> start;
                }
                else{
                    dptr = init_free1(anptr -> start, anptr -> end);
                    dptr -> next = fptr;
                    fptr = dptr;
                }
            }
        }
        free(anptr);
        ptr -> node = NULL;
        if (pre == ptr) {
            vptr = vptr -> next;
            free(pre);
        }
        else{
            pre -> next = ptr -> next;
            free(ptr);
        }
    }
}
int main(int argc, char const *argv[]) {
    char a[10];
    init_free();
    init_var();
    init_alloc();
    strcpy(a,"x\0");
    _mallocf(10,a);
    strcpy(a,"y\0");
    _mallocn(20,a);
    // traverseA(aptr);
    // traverseF(fptr);
    // traverseAV(vptr);
    // strcpy(a,"x\0");
    // printf("\n");
    _free("x\0");
    // _free("y\0");
    _mallocf(10,"z\0");
    traverseA(aptr);
    traverseF(fptr);
    traverseAV(vptr);

    return 0;
}


































//nsak
