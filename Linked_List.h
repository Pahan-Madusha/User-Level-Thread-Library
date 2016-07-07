
/*doubly linked list data structure*/

typedef struct list
{
  TCB box;
  struct list* next;
  struct list* prev;
}thread_list_node;

typedef thread_list_node* thread_list;

/*create a new list*/
thread_list createList();

/**/
int insert_to_list(TCB new_tcb, thread_list list);

/**/
//int remove_from_list(int id, thread_list list);

/**/


/************************/
thread_list createList()
{
  thread_list list = malloc(sizeof(thread_list_node));
  list -> box = NULL;
  list -> next = NULL;
  list -> prev = NULL;

  return list;
}

/************************************************/
int insert_to_list(TCB new_tcb, thread_list list)
{
  if(list -> next == NULL && list -> prev == NULL && list -> box == NULL)
  {
    list -> box = new_tcb;
    return 1;
  }
  
  thread_list tl = malloc(sizeof(thread_list_node));
 
  if(tl == NULL)
    return 0;

  tl -> box = new_tcb;
  tl -> prev = list;
  tl -> next = NULL;

  return 1;
}




