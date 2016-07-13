
/*doubly linked list data structure*/

typedef struct list
{
  TCB box;
  struct list* next;
  struct list* prev;
}thread_list_node;

typedef thread_list_node* Thread_List;

/*create a new list*/
Thread_List createThreadList(void);

/**/
Thread_List insert_to_list(TCB new_tcb, Thread_List list);

/**/
Thread_List remove_from_list(int id, Thread_List list);


/************************/
Thread_List createThreadList(void)
{
  Thread_List list = NULL;
  return list;
}

/************************************************/
Thread_List insert_to_list(TCB new_tcb, Thread_List list)
{
  if(list == NULL)
  {
    list = malloc(sizeof(thread_list_node));
    list -> box = new_tcb;
    list -> prev = NULL;
    list -> next = NULL;
    //printf("%p\n",list);
    return list;
  }

  /*not first thread*/
  Thread_List current = list;

  Thread_List tl = malloc(sizeof(thread_list_node));
 
  if(tl == NULL)
  {
    printf("Memory failed!\n");
    return NULL;
  }
    
  while(current -> next != NULL)
  {
    current = current -> next;
  }

  tl -> box = new_tcb;
  tl -> prev = current;
  tl -> next = NULL;
  current -> next = tl;

  return list;
}

/***************************************************/
Thread_List remove_from_list(int id, Thread_List list)
{
  Thread_List current = list;
  
  while(current -> box != NULL)
  {
    if( (current -> box) -> id == id)
    { 
      if( current -> prev == NULL)
      {
        current -> box = NULL; 
        return NULL; 
      }  
      (current -> prev) -> next = current -> next;
      free(current);
      return list;
    }
  }
  
  return NULL;
}

/****************************************/
void print_the_threads(Thread_List list)
{
  while(list != NULL)
  {
    printf("id = %d,  sp = %p\n",list -> box -> id, list -> box -> sp);
    list = list -> next;
  }
}














