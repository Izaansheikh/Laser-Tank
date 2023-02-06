#ifndef linkedList_h
#define linkedList_h

typedef struct LinkedListNode 
{
	void* row;
	void* col;
	void* action;
	struct LinkedListNode* next;
} LinkedListNode;

typedef struct 
{
	LinkedListNode* head;
	LinkedListNode* tail;
} LinkedList;

LinkedList linkedList;

void createLinkedList(LinkedList* list);

void insertLast(LinkedList* list, void* row, void* col, void* action);

void freeNode(LinkedListNode *node);

void freeLinkedList(LinkedList* list);

#endif