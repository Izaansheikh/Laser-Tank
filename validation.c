#include <stdio.h>
#include "validation.h"

/* This class help in validating all the command line arguments according to the range. */

/***************************************************************
 *SUBMODULE: validation
 *IMPORT: mRow (Integer), mCol (Integer), pRow (Integer), pCol (Integer), pDir (Character), eRow (Integer), eCol (Integer), eDir (Character)
 *EXPORT: finalValid (Integer)
 *ASSERTION: validates the file inputs.
 ***************************************************************/  
int validation(int mapRow, int mapCol, int pRow, int pCol, char pDir, int eRow, int eCol, int eDir)
{
    int v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, finalValid;
	finalValid = FALSE;
	
    /* Checking if Map dimension are in range */
    v1 = intCheck(5, 20, mapRow);
    if (!v1)
    {
        printf("Map Row is out of range.\n");
    }
	v2 = intCheck(5, 20, mapCol);
    if (!v2)
    {
        printf("Map Column is out of range.\n");
    }

	/* Checking if Player starting postion is in range and faces a valid direction */
    v3 = intCheck(1, mapRow - 2, pRow);
    if (!v3)
    {
        printf("Player Row is out of range.\n");
    }
	v4 = intCheck(1, mapCol - 2, pCol);
    if (!v4)
    {
        printf("Player Column is out of range.\n");
    }
    v5 = charCheck(pDir);
    if (!v5)
    {
        printf("Player Direction is invalid.\n");
    }

	/* Checking if Enemy starting postion is in range and faces a valid direction */
	v6 = intCheck(1, mapRow - 2, eRow);
    if (!v6)
    {
        printf("Enemy Row is out of range.\n");
    }
	v7 = intCheck(1, mapCol - 2, eCol);
    if (!v7)
    {
        printf("Enemy Column is out of range.\n");
    }
    v8 = charCheck(eDir);
    if (!v8)
    {
        printf("Enemy Direction is invalid.\n");
    }
	
	/*Checking if Player and Enemy starting position overlap.*/
	v9 = TRUE;
	if ((pRow == eRow) && (pCol == eCol))
	{
		printf("Player and Enemy starting postion are same.\n");
		v9 = FALSE;
	}
	
	/* Checking if Player is in direction of Enemy at start */
	v10 = instantLoseCheck(pRow, pCol, eRow, eCol, eDir);
	if (!v10)
	{
		printf("Player is in direction of Enemy at start. No Instant Lose allowed.\n");
	}
	
	/* Making sure if everthing is valid. */
    if (v1 && v2 && v3 && v4 && v5 && v6 && v7 && v8 && v9 && v10)
    {
        finalValid = TRUE;
    }
    return finalValid;
}

/***************************************************************
 *SUBMODULE: charCheck
 *IMPORT: eDir (Character)
 *EXPORT: valid (Integer)
 *ASSERTION: checks if the character is valid or not.
 ***************************************************************/  
int charCheck(char value)
{
    int valid = FALSE; 
    if ((value == 'u') || (value == 'l') || (value == 'd') || (value == 'r'))
    {
        valid = TRUE;
    }
    return valid;
}

/***************************************************************
 *SUBMODULE: instantLoseCheck
 *IMPORT: pRow (Integer), pCol (Integer), eRow (Integer), eCol (Integer), eDir (Character)
 *EXPORT: valid (Integer)
 *ASSERTION: checks if player is not in direction of enemy in start.
 ***************************************************************/
int instantLoseCheck(int pRow, int pCol, int eRow, int eCol, int eDir)
{
	int valid = TRUE;
	if (eDir == 'u')
	{
		if ((pRow < eRow) && (pCol == eCol))
		{
			valid = FALSE;
		}
	}
	else if (eDir == 'l')
	{
		if ((pCol < eCol) && (pRow == eRow))
		{
			valid = FALSE;
		}
	}
	else if (eDir == 'd')
	{
		if ((pRow > eRow) && (pCol == eCol))
		{
			valid = FALSE;
		}
	}
	else if (eDir == 'r')
	{
		if ((pCol > eCol) && (pRow == eRow))
		{
			valid = FALSE;
		}
	}
	return valid;
}

/***************************************************************
 *SUBMODULE: barrelCheck
 *IMPORT: mapRow (Integer), mapCol (Integer), pRow (Integer), pCol (Integer), eRow (Integer), eCol (Integer), bRow (Integer), bCol (Integer), valid (Integer)
 *EXPORT: finalValid (Integer)
 *ASSERTION: validates the barrels postion.
 ***************************************************************/  
int barrelCheck(int mapRow, int mapCol, int pRow, int pCol, int eRow, int eCol, int bRow, int bCol, int valid)
{
	int v1, v2, v3, v4, finalValid;
	finalValid = FALSE;
	/* Checking if Barrels are inside the map at start */
	v1 = intCheck(1, mapRow - 2, bRow);
	if (!v1)
    {
        printf("Barrel Row is out of range.\n");
    }
	v2 = intCheck(1, mapCol - 2, bCol);
    if (!v2)
    {
        printf("Barrel Column is out of range.\n");
    }
		
	/*Checking if Player and Enemy starting position overlap.*/
	v3 = TRUE;
	if ((bRow == pRow) && (bCol == pCol))
	{
		printf("Player and Barrel postions are same at start.\n");
		v3 = FALSE;
	}
	
	/*Checking if Player and Enemy starting position overlap.*/
	v4 = TRUE;
	if ((bRow == eRow) && (bCol == eCol))
	{
		printf("Enemy and Barrel postions are same at start.\n");
		v4 = FALSE;
	}
	
	/* Making sure if everthing is valid. */
    if (v1 && v2 && v3 && v4 && valid)
    {
        finalValid = TRUE;
    }
	return finalValid;
}