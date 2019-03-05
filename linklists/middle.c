void middle(node_type* lptr){
  node_type *mid,*tail;
  mid = tail = lptr;
  int flag = 0;
  while (flag = 0 && lptr != NULL) {
    /* code */
    if ( tail != NULL || tail -> next != NULL) {
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
