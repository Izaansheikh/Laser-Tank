#include "validation.h"

#define FALSE	0
#define TRUE	!FALSE
#include "map.h"
#include "linkedList.h"

char** readFile(char *fileName, int *mapRow, int *mapCol, int *pRow, int *pCol, char *pDir, int *eRow, int *eCol, char *eDir, int *valid);

void writeFile(LinkedList* list);