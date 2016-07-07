
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
int insert_to_list(TCB new_tcb, Thread_List list);

/**/
int remove_from_list(int id, Thread_List list);


/************************/
Thread_List createThreadList(void)
{
  Thread_List list = NULL;
  return list;
}

/************************************************/
int insert_to_list(TCB new_tcb, Thread_List list)
{
  Thread_List current = list;

  if(list == NULL)
  {
    list -> box = new_tcb;
    return 1;
  }
  
  Thread_List tl = malloc(sizeof(thread_list_node));
 
  if(tl == NULL)
    return 0;

  while(current -> next != NULL)
  {
    current = current -> next;
  }

  tl -> box = new_tcb;
  tl -> prev = current;
  tl -> next = NULL;
  current -> next = tl;

  return 1;
}

/***************************************************/
int remove_from_list(int id, Thread_List list)
{
  Thread_List current = list;
  
  while(current -> box != NULL)
  {
    if( (current -> box) -> id == id)
    { 
      if( current -> prev == NULL)
      {
        current -> box = NULL; 
        return 1; 
      }  
      (current -> prev) -> next = current -> next;
      free(current);
      return 1;
    }
  }

  return 0;
}














