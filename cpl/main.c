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
    printf("Free_List: \n");
    if (nptr) {
        /* code */
        while (nptr) {
            printf("%d - %d \n", nptr -> start, nptr -> end);
            nptr = nptr -> next;
        }
    }else{
        printf("Empty!!\n");
    }
}
void traverseAV(varList *nptr){
    allocList *alptr;
    printf("Alloc_List: \n");
    if (nptr) {
        /* code */
        while (nptr) {
            alptr = nptr -> node;
            printf("%s = %d - %d \n", nptr -> var_name, alptr -> start, alptr -> end);
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
    int i,j,e,k,s,x,flag, found = 0;
    allocList *a1ptr,*tptr,*pre;
    freeList *ptr;
    varList *tvptr,*vvptr;
    ptr = fptr;
    i = 0;
    j = size - 1;
    flag = 0;
    vvptr = vptr;
    while (vvptr && !found) {
        i = strcmp(a, vvptr -> var_name);
        if (i == 0) {
            /* code */
            found = 1;
        }
        else{
            vvptr = vvptr -> next;
        }
    }
    if (!found) {
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
            printf("Successfully Allocated: %s\n",a);
        }
    }
    else{
        printf("Can't Allocate %s as it already exits\n", a);
    }
}
void _mallocn(int size, char a[]){
    int found=0,i,j,x,y,s,e,n,flag=0;
    allocList *a1ptr,*tptr,*pre;
    freeList *ptr;
    ptr = fptr;
    varList *tvptr,*vvptr;
    vvptr = vptr;
    while (vvptr && !found) {
        i = strcmp(a, vvptr -> var_name);
        if (i == 0) {
            /* code */
            found = 1;
        }
        else{
            vvptr = vvptr -> next;
        }
    }
    if (!found) {
        while ((ptr != NULL)&&(nxt > ptr -> start)) {
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
                printf("Successfully Allocated: %s\n",a);

            }
        }
        else{
            printf("Out of space!!\n");
        }
    }
    else{
        printf("Can't Allocate %s as it already exits\n", a);
    }
}
void _mallocb(int size, char a[]){
    int i,j,e,k,s,x,flag,min,found=0;
    allocList *a1ptr,*tptr,*pre;
    freeList *ptr, *mptr;
    varList *tvptr,*vvptr;
    ptr = fptr;
    i = 0;
    j = size - 1;
    flag = 0;
    min = -1;
    vvptr = vptr;
    while (vvptr && !found) {
        i = strcmp(a, vvptr -> var_name);
        if (i == 0) {
            /* code */
            found = 1;
        }
        else{
            vvptr = vvptr -> next;
        }
    }
    if (!found) {
        if(ptr){
            min = 101;
        }
        while (ptr) {
            x = ptr -> end - ptr -> start + 1;
            if (x >= size) {
                /* code */
                if (x < min) {
                    /* code */
                    min = x;
                    mptr = ptr;
                }
            }
            ptr = ptr -> next;
        }
        if (min >= size) {
            flag = 1;
            s = mptr -> start;
            e = mptr -> start + size -1;
            a1ptr = init_alloc1(s, e);
            tvptr = (varList*)malloc(sizeof(varList));
            strcpy(tvptr -> var_name, a);
            tvptr -> node = a1ptr;
            tvptr -> next = vptr;
            vptr = tvptr;
            nxt = e;
            if (x != size) {
                mptr -> start = e + 1;
            }
            else{
                freeFree(mptr);
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
            printf("Successfully Allocated: %s\n",a);
        }
    }
    else{
        printf("Can't Allocate %s as it already exits\n", a);
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
                    if (tfptr){
                        if (anptr -> end + 1 == tfptr -> start) {
                            /* code */
                            prefptr -> end = tfptr -> end;
                            prefptr -> next = tfptr -> next;
                            free(tfptr);
                        }else{
                            prefptr -> end = anptr -> end;
                        }
                    } else{
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
                if (prefptr) {
                    /* code */
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
                else{
                    dptr = init_free1(anptr -> start, anptr -> end);
                    dptr -> next = NULL;
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
    int l=1,choice,d=0;
    char chr[10];
    char a[10];
    init_free();
    init_var();
    init_alloc();
    // strcpy(a,"x\0");
    // _mallocf(100,a);
    // strcpy(a,"x\0");
    // _mallocf(30,a);
    // traverseA(aptr);
    // traverseF(fptr);
    // traverseAV(vptr);
    // strcpy(a,"x\0");
    // printf("\n");
    // _free("x\0");
    // _free("y\0");
    // _mallocb(10,"z\0");
    // _mallocb(20,"p\0");
    // _mallocb(10,"l\0");
    // strcpy(a,"x\0");
    // _mallocf(30,a);
    // traverseA(aptr);
    traverseF(fptr);
    traverseAV(vptr);
    printf("===============HEAP MANAGEMENT==============\n");
    while (l) {
        printf("============================================\n");
        printf("1.Malloc => First Fit\n2.Malloc => Next Fit\n3.Malloc => Best Fit\n4.Free()\n5.Display Alloc_List & Free_List\n");
        printf("============================================\n");
        printf("6.ExIt\n");
        printf("============================================\n");
        printf("Enter your choice>>> ");
        scanf("%d",&choice );
        printf("============================================\n");
        switch (choice) {
            case 1 : printf("Enter the Variable name to allocate Memory: ");
                scanf("%s", &chr);
                printf("Enter the Size: ");
                scanf("%d", &d);
                if (d>=1 && d<=100) {
                    _mallocf(d,chr);
                }
                break;
            case 2 : printf("Enter the Variable name to allocate Memory: ");
                scanf("%s", &chr);
                printf("Enter the Size: ");
                scanf("%d", &d);
                if (d>=1 && d<=100) {
                    _mallocn(d,chr);
                }
                break;
            case 3 : printf("Enter the Variable name to allocate Memory: ");
                scanf("%s", &chr);
                printf("Enter the Size: ");
                scanf("%d", &d);
                if (d>=1 && d<=100) {
                    _mallocb(d,chr);
                }
                break;
            case 4 : printf("Enter the Variable to be freed: ");
                scanf("%s", &chr);
                _free(chr);
                break;
            case 5 : traverseF(fptr);
                traverseAV(vptr);
                break;
            case 6 : l = 0;
                break;
            default : printf("Enter a proper Choice....\n");
                break;
        }
    }


    return 0;
}
