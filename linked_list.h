#ifndef _LINKED_LIST_
#define _LINKED_LIST_

//linked list data structure
typedef struct list
{
	void* data;
	struct list* next;
}node;

typedef node* node_ref;

//Function prototypes

/*Create a new linked_list
  Returns a pointer to a list
*/
node_ref create_list();

/*Add a new node to the head of a list
  Arguments - Pointer to a pointer of linked_list, integer
  Returns 1 on success*/
int add_node(node_ref* nd, void* data);

/*Remove the last added integer to the list and free the memory
  Arguments - Pointer to a pointer of linked_list
  Return 1 on success
  Return 0 if empty*/
int remove_last_node(node_ref* nd);

/*Free memory and clean the list
  Arguments - Pointer to a pointer of linked_list
  Return 1 on success*/
int erase_list(node_ref* nd);

/*Return the element in last node without removing it
  Arguments - Pointer to a pointer of linked_list
  Return INT_MIN if empty
*/
void* peak_last_node(node_ref* nd);


//Implementations

/*************************************************************************************/
node_ref create_list()
{
	node_ref nd;
	return nd;
}


/*************************************************************************************/
int add_node(node_ref* nd, void* data)
{
	node_ref new_node = malloc(sizeof(node));
	
	new_node -> data = data;
	if(!(*nd))
	{	
		new_node -> next = NULL;
	}
	else
	{
		new_node -> next = *nd;
	}
	*nd = new_node;
	return 1;
}


/*************************************************************************************/
int remove_last_node(node_ref* nd)
{
	if(!(*nd))
		return 0;

	node_ref last = *nd;
	(*nd) = last -> next;
	free(last);
	return 1;	
}


/*************************************************************************************/
int erase_list(node_ref* nd)
{
	node_ref curr;
	while(1)
	{
		curr = (*nd) -> next;
		free(*nd);
		if(!curr)
			break;
		*nd = curr;
	} 
	return 1;
}


/*************************************************************************************/
void* peak_last_node(node_ref* nd)
{
	if(!(*nd))
		return NULL;

	return ((*nd) -> data);
		
}

#endif






