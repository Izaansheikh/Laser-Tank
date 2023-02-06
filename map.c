#include <stdio.h>
#include <stdlib.h>
#include "map.h"

/* This class creates the inital map, prints it and frees it. */

/***************************************************************
 *SUBMODULE: createMap
 *IMPORT: **map (2-D Character Array), mRow (Integer), mCol (Integer)
 *EXPORT: none
 *ASSERTION: create the initial map and along with its borders.
 ***************************************************************/  
void createMap(char **map, int mRow, int mCol)
{
	int i, j;
	for (i = 0; i < mRow; i++) 
	{
		for (j = 0; j < mCol; j++) 
		{
			if ((i == 0) || (j == 0) || (i == mRow - 1) || (j == mCol - 1))
			{
				map[i][j] = '*';
			}
			else 
			{
				map[i][j] = ' ';
			}
        }
	}
}

/***************************************************************
 *SUBMODULE: mapPrint
 *IMPORT: **map (2-D Character Array), mRow (Integer), mCol (Integer)
 *EXPORT: none
 *ASSERTION: prints the map.
 ***************************************************************/  
void mapPrint(char **map, int mRow, int mCol)
{
	int i, j;
	for (i = 0; i < mRow; i++) 
	{
		for (j = 0; j < mCol; j++) 
		{
			printf("%c ", map[i][j]);
		}
        printf("\n");
	}
}

/***************************************************************
 *SUBMODULE: freeMap
 *IMPORT: **map (2-D Character Array), mRow (Integer)
 *EXPORT: none
 *ASSERTION: frees the memory allocated to map.
 ***************************************************************/  
void freeMap(char** map, int mRow)
{
	int i;
	for (i = 0; i < mRow; i++) 
	{
		free(map[i]);
	}
	free(map); 
}