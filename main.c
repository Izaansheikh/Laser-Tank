#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/* Main class only deals with appropriate call to functions required for lasertank to operater successfully. */
	
int main (int argc, char* argv[])
{
	/* variable declaration */
	LinkedList list;
	char **map, choice, pDir, eDir;
	int mapRow, mapCol, *pRow, *pCol, eRow, eCol, valid, result;
	valid = FALSE;
	if (argc < 2)
	{
		printf("Please enter file name as well.\n");
	}
	else
	{
		/* Allocating memory to 2 pointers used for changing player position. */
		pRow = (int*)malloc(sizeof(int));
		pCol = (int*)malloc(sizeof(int));
		/* Reading the inputs required for program from a file. */
		map = readFile(argv[1], &mapRow, &mapCol, pRow, pCol, &pDir, &eRow, &eCol, &eDir, &valid);
		/* The program only runs if all the file inputs are valid and file name is input. */
		if (valid)
		{
			createLinkedList(&list);
			system("clear");
			player(map, *pRow, *pCol, pDir);
			enemy(map, eRow, eCol, eDir);
			mapPrint(map, mapRow, mapCol);
			do
			{
				/* User is asked to move the player around and result is printed out according to player actions. */
				printf("w to go up/face up\ns to go/face down\na to go/face left\nd to go/face right\nf to shoot laser\naction: ");
				scanf(" %c", &choice);
				if ((choice == 'w') || (choice == 'a') || (choice == 's') || (choice == 'd'))
				{
					playerMove(map, pRow, pCol, choice, &list);
					system("clear");
					result = loseCheck(map, eRow, eCol);
					if (result == LOSE)
					{
						mapPrint(map, mapRow, mapCol);
						sleep(1);
					}
					else 
					{
						eraseLaser(map, mapRow, mapCol);
						mapPrint(map, mapRow, mapCol);
					}
				}
				else if (choice == 'f')
				{
					result = playerShoot(map, *pRow, *pCol, eRow, eCol);
					system("clear");
					mapPrint(map, mapRow, mapCol);
					sleep(1);
					if ((result != WIN) && (result != LOSE))
					{
						eraseLaser(map, mapRow, mapCol);
						system("clear");
						mapPrint(map, mapRow, mapCol);
					}
					insertLast(&list, pRow, pCol, "Laser");
				}
				else 
				{
					system("clear");
					mapPrint(map, mapRow, mapCol);
					printf("***Please enter a valid choice.***\n");
				}
			} while ((result != WIN) && (result != LOSE) &&(result != WIN2));
			/* Prints out the final result to the screen. */
			if (result == WIN)
			{
				printf("You win!\n");
				insertLast(&list, pRow, pCol, "Win");
			}
			else if (result == LOSE)
			{
				printf("You lose!\n");
				insertLast(&list, pRow, pCol, "Lose");
			}
			else if (result == WIN2)
			{
				printf("You win!\nYou will be missed, Captain.\nYou are our Hero.\n");
				insertLast(&list, pRow, pCol, "Both died.");
			}
			/* writeFile function is only called if LOG is defined while compiling. */
			#ifdef LOG
			writeFile(&list);
			#endif
			/* Pointers, 2-D array and LinkedList is freed so no memory leakage is detected. */
			free(pRow);
			pRow = NULL;
			free(pCol);
			pCol = NULL;
			freeMap(map, mapRow);
			freeLinkedList(&list);
		}
		else 
		{
			/* If values are invalid, it prints this message along with whats wrong. */
			printf("Please enter the value(s) in range.\n");
		}
	}
	return 0;
}