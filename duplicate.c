void dupli(node_type** lpptr){
  node_type *ptr,*pre,*dup;
  pre = *lpptr;
  if (*lpptr != NULL) {
      ptr = pre -> next;
      while (ptr != NULL) {
        if (ptr -> data != pre -> data) {
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
