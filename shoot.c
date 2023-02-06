#include "shoot.h"

/* This class help in shooting player laser and to check the winning or losing condition. */

/********************************************************************
 *SUBMODULE: playerShoot
 *IMPORT: **map (2-D Array), pRow (Integer), pCol (Integer)
 *EXPORT: result (Integer)
 *ASSERTION: shoots the laser and returns whether the player won or not.
 ********************************************************************/  
int playerShoot(char **map, int pRow, int pCol, int eRow, int eCol)
{
    int result = 0;
	char pos;
	int initialRow = pRow; 
	int initialCol = pCol;
	pos = map[pRow][pCol];
    if (pos == '^')
    {
		while ((map[pRow - 1][pCol] == ' ') || (map[pRow - 1][pCol] == 'X'))
		{
			while (map[pRow - 1][pCol] == 'X')
			{
				pRow = pRow - 1;
			}
			if (map[pRow - 1][pCol] == ' ')
			{
				pRow = pRow - 1;
				map[pRow][pCol] = '|';
			}
		}
		if (map[pRow - 1][pCol] == 'B')
		{
			result = barrelExplode(map, pRow - 1, pCol, initialRow, initialCol, eRow, eCol);
		}
		else if ((map[pRow - 1][pCol] != '*') && (map[pRow - 1][pCol] != 'X'))
		{
			map[pRow - 1][pCol] = 'X';
			result = WIN;
		}
    }
    else if (pos == '<')
    {
		while ((map[pRow][pCol - 1] == ' ') || (map[pRow][pCol - 1] == 'X'))
		{
			while (map[pRow][pCol - 1] == 'X')
			{
				pCol = pCol - 1;
			}
			if (map[pRow][pCol - 1] == ' ')
			{
				pCol = pCol - 1;
				map[pRow][pCol] = '-';
			}
		}
		if (map[pRow][pCol - 1] == 'B')
		{
			result = barrelExplode(map, pRow, pCol - 1, initialRow, initialCol, eRow, eCol);
		}
		else if ((map[pRow][pCol - 1] != '*') && (map[pRow][pCol - 1] != 'X'))
		{
			map[pRow][pCol - 1] = 'X';
			result = WIN;
		}
    }
    else if (pos == 'v')
    {
		while ((map[pRow + 1][pCol] == ' ') || (map[pRow + 1][pCol] == 'X'))
		{
			while (map[pRow + 1][pCol] == 'X')
			{
				pRow = pRow + 1;
			}
			if (map[pRow + 1][pCol] == ' ')
			{
				pRow = pRow + 1;
				map[pRow][pCol] = '|';
			}
		}
		if (map[pRow + 1][pCol] == 'B')
		{
			result = barrelExplode(map, pRow + 1, pCol, initialRow, initialCol, eRow, eCol);
		}
		else if ((map[pRow + 1][pCol] != '*') && (map[pRow + 1][pCol] != 'X'))
		{
			map[pRow + 1][pCol] = 'X';
			result = WIN;
		}
    }
    else if (pos == '>')
    {
		while ((map[pRow][pCol + 1] == ' ') || (map[pRow][pCol + 1] == 'X'))
		{
			while (map[pRow][pCol + 1] == 'X')
			{
				pCol = pCol + 1;
			}
			if (map[pRow][pCol + 1] == ' ')
			{
				pCol = pCol + 1;
				map[pRow][pCol] = '-';
			}
		}
		if (map[pRow][pCol + 1] == 'B')
		{
			result = barrelExplode(map, pRow, pCol + 1, initialRow, initialCol, eRow, eCol);
		}
		else if ((map[pRow][pCol + 1] != '*') && (map[pRow][pCol + 1] != 'X'))
		{
			map[pRow][pCol + 1] = 'X';
			result = WIN;
		}
    }
    return result;
}

/***************************************************************
 *SUBMODULE: eraseLaser
 *IMPORT: **map (2-D Array), mRow (Integer), mCol (Integer)
 *EXPORT: none
 *ASSERTION: erases the laser from the map.
 ***************************************************************/  
void eraseLaser(char **map, int mRow, int mCol)
{
    int i, j;
    for (i = 0; i < mRow; i++) 
	{
		for (j = 0; j < mCol; j++) 
		{
			if ((map[i][j] == '-') || (map[i][j] == '|'))
			{
				map[i][j] = ' ';
			}
        }
	}
}

/***************************************************************
 *SUBMODULE: barrelExplode
 *IMPORT: **map (2-D Array), bRow (Integer), bCol (Integer), pRow (Integer), pCol (Integer), eRow (Integer), eCol (Integer)
 *EXPORT: none
 *ASSERTION: Explodes the barrel and checks if theres any casualties.
 ***************************************************************/  
int barrelExplode(char **map, int bRow, int bCol, int pRow, int pCol, int eRow, int eCol)
{
	int i, j;
	int result = 0;
	/* Exploding the barrel and marking the position. */
	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			if (map[bRow + i][bCol + j] != '*')
			{
				map[bRow + i][bCol + j] = 'X';
			}
		}
	}
	/* Checks if both (player and enemy) exploded. */
	if ((map[pRow][pCol] == 'X') && (map[eRow][eCol] == 'X'))
	{
		result = WIN2;
	}
	/* Checks if player exploded. */
	else if (map[pRow][pCol] == 'X')
	{
		result = LOSE;
	}
	/* Checks if enemy exploded. */
	else if (map[eRow][eCol] == 'X')
	{
		result = WIN;
	}
	return result;
}