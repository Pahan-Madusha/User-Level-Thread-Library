#ifndef _STACK_
#define _STACK_

#include <stdlib.h>
#include <limits.h>
#include "linked_list.h"

/*functions and data structure are implemented in the header file*/

/*Data structure for stack*/
typedef struct node
{
	node_ref list;
	int size;
	
}stack_node;

typedef stack_node* stack_ref;


//function prototypes

/*Allocate memory and create a stack
  NO arguments
  Returns a reference to the stack*/
stack_ref stackCreate();

/*Free the memory allocated for the stack
  Arguments - Pointer to the stack
  Return 1 on success*/
int stackDestroy(stack_ref st);

/*Insert an element to the stack
  Arguments - pointer to the stack, integer
  Return 1 on success*/
int stackPush(stack_ref st, void* el);

/*Remove the last inserted element from the stack
  Arguments - pointer to the stack
  Returns the element on success
  Returns INT_MIN if stack is empty*/
void* stackPop(stack_ref st);

/*Arguments - pointer to the stack
  Return the last inserted element of the stack
  Return INT_MIN if stack is empty*/
void* stackPeek(stack_ref st);

/*Arguments - Pointer to the stack
  Return 1 if stack is empty
  0 otherwise*/
int StackIsEmpty(stack_ref st);


/*Function implementations*/
/**********************************************************************************/
//create a new stack
stack_ref stackCreate()
{
	stack_ref ref = malloc(sizeof(stack_node));
	ref -> size = 0;
	return ref;
}

/**********************************************************************************/
//destroy an existing stack
int stackDestroy(stack_ref st)
{
	erase_list(&(st -> list));
	free(st);
	return 1;
}

/**********************************************************************************/
//add a new element
int stackPush(stack_ref st, void* el)
{
	add_node(&(st -> list),el);
	(st -> size)++;
	return 1;

}

/**********************************************************************************/
//remove the last element
void* stackPop(stack_ref st)
{
	if(StackIsEmpty(st))
	{
		return NULL;
	}	
	void* ans = stackPeek(st);
	remove_last_node(&(st -> list));
	(st -> size)--;

	return ans;
}

/**********************************************************************************/
//peek at the top element
void* stackPeek(stack_ref st)
{
	if(StackIsEmpty(st))
	{
		return NULL;
	}	
	return peak_last_node(&(st -> list));
}

/**********************************************************************************/
//if stack is empty
int StackIsEmpty(stack_ref st)
{
	if(st -> list == NULL)
		return 1;
	return 0;
}

#endif





