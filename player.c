#include "player.h"

/* This class help in assigning inital position of player and helps in moving it as well. */

/********************************************************************
 *SUBMODULE: player
 *IMPORT: **map (2-D Array), pRow (Integer), pCol (Integer), pDir (Character)
 *EXPORT: none
 *ASSERTION: sets the initial player position and direction.
 ********************************************************************/  
void player(char **map, int pRow, int pCol, char pDir)
{
	if (pDir == 'r')
	{
		map[pRow][pCol] = '>';
	}
	else if (pDir == 'l')
	{
		map[pRow][pCol] = '<';
	}
	else if (pDir == 'u')
	{
		map[pRow][pCol] = '^';
	}
	else if (pDir == 'd')
	{
		map[pRow][pCol] = 'v';
	}
}

/********************************************************************
 *SUBMODULE: playerMove
 *IMPORT: **map (2-D Array), pRow (Integer), pCol (Integer), pDir (Character)
 *EXPORT: none
 *ASSERTION: helps player to move and change direction according to user input.
 ********************************************************************/
void playerMove(char **map, int *pRow, int *pCol, char choice, LinkedList* list)
{
	char pos = map[*pRow][*pCol];
	char next;
	map[*pRow][*pCol] = ' ';
	if (choice == 'w')
	{
		next = map[*pRow - 1][*pCol];
		if ((pos == '^') && (next == ' '))
		{
			*pRow = *pRow - 1;
		}
		map[*pRow][*pCol] = '^';
		insertLast(list, pRow, pCol, "Up");
	}
	else if (choice == 'a')
	{
		next = map[*pRow][*pCol - 1];
		if ((pos == '<') && (next == ' '))
		{
			*pCol = *pCol - 1;
		}
		map[*pRow][*pCol] = '<';
		insertLast(list, pRow, pCol, "Left");
	}
	else if (choice == 's')
	{
		next = map[*pRow + 1][*pCol];
		if ((pos == 'v') && (next  == ' '))
		{
			*pRow = *pRow + 1;
		}
		map[*pRow][*pCol] = 'v';
		insertLast(list, pRow, pCol, "Down");
	}
	else if (choice == 'd')
	{	
		next = map[*pRow][*pCol + 1];
		if ((pos == '>') && (next == ' '))
		{
			*pCol = *pCol + 1;
		}
		map[*pRow][*pCol] = '>';
		insertLast(list, pRow, pCol, "Right");
	}
}