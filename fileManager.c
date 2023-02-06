#include <stdio.h>
#include <stdlib.h>
#include "fileManager.h"

/* This class help in reading the input file and writing the linkedlist. */

/***************************************************************
 *SUBMODULE: readFile
 *IMPORT: fileName (Character), mapRow (Integer), mapCol (Integer), pRow (Integer), pCol (Integer), pDir (Character), eRow (Integer), eCol (Integer), eDir (Character)
 *EXPORT: map (2-D Character Array)
 *ASSERTION: reads the file and stores the values in appropriate variable.
 ***************************************************************/  
char** readFile(char *fileName, int *mapRow, int *mapCol, int *pRow, int *pCol, char *pDir, int *eRow, int *eCol, char *eDir, int *valid)
{
	FILE* f = fopen(fileName, "r");
	int bRow, bCol, i;
	char **map;
	if (f == NULL) 
	{
		perror("Error opening 'map.txt'");
	}
	else 
	{
		/* Assigning map dimension to variable. */
		fscanf(f, "%d , %d", mapRow, mapCol);
		/* Assigning player initial position and direction to a variable. */
		fscanf(f, "%d , %d , %c", pRow, pCol, pDir);
		/* Assigning enemy initial position and direction to a variable. */
		fscanf(f, "%d , %d , %c", eRow, eCol, eDir);
		/* Allocating memory for a 2-D array for map. */
		map = (char**)malloc(*mapRow * sizeof(char*));
		for (i = 0; i < *mapRow; i++)
		{
			map[i] = malloc(*mapRow * sizeof(char));
		}
		/* Map is created according to file inputs. */
		createMap(map, *mapRow, *mapCol);
		/* Checking if file inputs are valid. otherwise, it will just print error(s) with what is wrong. */
		*valid = validation(*mapRow, *mapCol, *pRow, *pCol, *pDir, *eRow, *eCol, *eDir);
		while(!feof(f))
		{
			fscanf(f, "%d , %d", &bRow, &bCol);
			/* Checking if the barrel location are valid. otherwise, it will just print error(s) with what is wrong. */
			*valid = barrelCheck(*mapRow, *mapCol, *pRow, *pCol, *eRow, *eCol, bRow, bCol, *valid);
			map[bRow][bCol] = 'B';
		}
		if (ferror(f)) 
		{
			perror("Error reading from 'map.txt'\n");
		}
		fclose(f);
	}
	return map;
}

/********************************************************************
 *SUBMODULE: writeFile
 *IMPORT: list (LinkedList*)
 *EXPORT: none
 *ASSERTION: writes the linkedlist to a file.
 ********************************************************************/  
void writeFile(LinkedList* list)
{
	FILE* f;
	LinkedListNode current = *(list->head);
	f = fopen("log.txt", "w");
	while(current.next != NULL)
	{
		fprintf(f, "%d, %d, %s\n", *(int*)current.row, *(int*)current.col, (char*)current.action);
		current = *(current.next);
	}
	fprintf(f, "%d, %d, %s", *(int*)current.row, *(int*)current.col, (char*)current.action);
	fclose(f);
}