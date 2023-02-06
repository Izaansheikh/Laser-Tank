#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

/********************************************************************
 *SUBMODULE: createLinkedList
 *IMPORT: list (LinkedList*)
 *EXPORT: none
 *ASSERTION: creates a linkedlist.
 ********************************************************************/  
void createLinkedList(LinkedList* list)
{
	(*list).head = NULL;
	(*list).tail = NULL;
}

/********************************************************************
 *SUBMODULE: insertLast
 *IMPORT: list (LinkedList*), row (void*), col (void*), action (void*)
 *EXPORT: none
 *ASSERTION: Inserts the data at the end of linkedlist.
 ********************************************************************/  
void insertLast(LinkedList* list, void* row, void* col, void* action)
{
	int *pRow, *pCol; 
	char *pAction;
	/* typecasting the imports to store them properly */
	pRow = malloc(sizeof(double));
	pCol = malloc(sizeof(double));
	pAction = malloc(sizeof(double));
	memcpy(pRow, row, sizeof(double));
	memcpy(pCol, col, sizeof(double));
	memcpy(pAction, action, sizeof(double));
	/* storing inputs in the last node of linkedList */
	if ((*list).head == NULL)
	{
		(*list).head = malloc(sizeof(LinkedListNode));
		(*((*list).head)).row = pRow;
		(*((*list).head)).col = pCol;
		(*((*list).head)).action = pAction;
		(*list).tail = (*list).head;
	}
	else
	{
        (*((*list).tail)).next = malloc(sizeof(LinkedListNode));
        (*((*((*list).tail)).next)).row = pRow;
        (*((*((*list).tail)).next)).col = pCol;
        ((*((*((*list).tail)).next)).action) = pAction;
        (*list).tail = (*((*list).tail)).next;
    }
    (*((*list).tail)).next = NULL;
}

/********************************************************************
 *SUBMODULE: freeNode
 *IMPORT: node (LinkedListNode*)
 *EXPORT: none
 *ASSERTION: frees the node.
 ********************************************************************/  
void freeNode(LinkedListNode *node)
{
	if (node != NULL)
	{
		freeNode((*node).next);
		free((*node).row);
		free((*node).col);
		free((*node).action);
		free(node);
	}
}

/********************************************************************
 *SUBMODULE: freeLinkedList
 *IMPORT: list (LinkedList*)
 *EXPORT: none
 *ASSERTION: frees the linkedlist.
 ********************************************************************/  
void freeLinkedList(LinkedList* list)
{
	freeNode((*list).head);
}