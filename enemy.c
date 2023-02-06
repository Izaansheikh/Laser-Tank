#include "enemy.h"

/* This class help in assigning inital position of enemy and helps in checking the losing condition. */

/********************************************************************
 *SUBMODULE: enemy
 *IMPORT: **map (2-D Array), eRow (Integer), eCol (Integer), eDir (Character)
 *EXPORT: none
 *ASSERTION: sets the initial enemy position and direction.
 ********************************************************************/  
void enemy(char **map, int eRow, int eCol, char eDir)
{
	if (eDir == 'r')
	{
		map[eRow][eCol] = '>';
	}
	else if (eDir == 'l')
	{
		map[eRow][eCol] = '<';
	}
	else if (eDir == 'u')
	{
		map[eRow][eCol] = '^';
	}
	else if (eDir == 'd')
	{
		map[eRow][eCol] = 'v';
	}
}

/********************************************************************
 *SUBMODULE: loseCheck
 *IMPORT: **map (2-D Array), eRow (Integer), eCol (Integer)
 *EXPORT: result (Integer)
 *ASSERTION: determines if a player has lost the game or not.
 ********************************************************************/  
int loseCheck(char **map, int eRow, int eCol)
{
	int result = 0;
	char pos;
	pos = map[eRow][eCol];
    if (pos == '^')
    {
		while ((map[eRow - 1][eCol] == ' ') || (map[eRow - 1][eCol] == 'B') || (map[eRow - 1][eCol] == 'X'))
		{
			if (map[eRow - 1][eCol] == ' ')
			{
				eRow = eRow - 1;
				map[eRow][eCol] = '|';
			}	
			while ((map[eRow - 1][eCol] == 'B') || (map[eRow - 1][eCol] == 'X'))
			{
				eRow = eRow - 1;
			}
		}
		if (map[eRow - 1][eCol] != '*')
		{
			map[eRow - 1][eCol] = 'X';
			result = LOSE;
		}
    }
	else if(pos == '<')
	{
		while ((map[eRow][eCol - 1] == ' ') || (map[eRow][eCol - 1] == 'B') || (map[eRow][eCol - 1] == 'X'))
		{
			if (map[eRow][eCol - 1] == ' ')
			{
				eCol = eCol - 1;
				map[eRow][eCol] = '-';
			}
			while ((map[eRow][eCol - 1] == 'B') || (map[eRow][eCol - 1] == 'X'))
			{
				eCol = eCol - 1;
			}
		}
		if (map[eRow][eCol - 1] != '*')
		{
			map[eRow][eCol - 1] = 'X';
			result = LOSE;
		}
	}
	else if (pos == 'v')
	{
		while ((map[eRow + 1][eCol] == ' ') || (map[eRow + 1][eCol] == 'B') || (map[eRow + 1][eCol] == 'X'))
		{
			if (map[eRow + 1][eCol] == ' ')
			{
				eRow = eRow + 1;
				map[eRow][eCol] = '|';
			}
			while ((map[eRow + 1][eCol] == 'B') || (map[eRow + 1][eCol] == 'X'))
			{
				eRow = eRow + 1;
			}
		}
		if (map[eRow + 1][eCol] != '*')
		{
			map[eRow + 1][eCol] = 'X';
			result = LOSE;
		}
    }
	else if (pos == '>')
	{
		while ((map[eRow][eCol + 1] == ' ') || (map[eRow][eCol + 1] == 'B') || (map[eRow][eCol + 1] == 'X'))
		{
			if (map[eRow][eCol + 1] == ' ')
			{
				eCol = eCol + 1;
				map[eRow][eCol] = '-';
			}
			while ((map[eRow][eCol + 1] == 'B') || (map[eRow][eCol + 1] == 'X'))
			{
				eCol = eCol + 1;
			}
		}
		if (map[eRow][eCol + 1] != '*')
		{
			map[eRow][eCol + 1] = 'X';
			result = LOSE;
		}		
	}
	return result;
}