/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * 
 * Lab5 cs361. The ants lab. The antening. Beehive Boogaloo.
 * 
 */

//Make a class named square which will hold the insects inside each square.
//It will contain a vector for the ants and another for the bees.

//There will be a vector of these squares. Will be easier to clean up than an array.



#include <iostream>
#include <string.h>
#include <vector>
#include <unistd.h>

#include "lab5.h"


int main(int argc, char **argv)
{
	helpPrompt(argc, argv);
	welcome();
	
	char continueChar = 'y';
	while ( continueChar == 'y' )
	{
		GameBoard* myGameBoard = new GameBoard();
		
		int result = myGameBoard->runGame(*myGameBoard);
		
		if ( result == -1 )
		{
			printf("Goodbye!\n\n");
		}
		else if( result )
		{
			printf("YOU WIN!  ");
		}
		else
		{
			printf("GAME OVER!  ");
		}
		
		myGameBoard->~GameBoard(); //was not being called automatically
		
		
		//munch extra characters if they are queued up.
		char char_ayy = '0';
		while((char_ayy = getchar()) != '\n' && char_ayy != EOF)
		{
			//NOTHING HEHE
		}
		
		printf("Play again? (y/n):");
		std::cin >> continueChar;
	}
	printf("\n");
	
	return 0;
}


//Prints a help message.
void helpPrompt(int argc, char** argv)
{
	if ( argc > 1 && (     !strcmp(argv[1], "help")
						|| !strcmp(argv[1], "-help")
						|| !strcmp(argv[1], "--help")
						|| !strcmp(argv[1], "-h") )  )
	{
		std::cout << helpPromptString;
		
		exit(0);
	}
}

void welcome()
{
	printf("Welcome to the Plants vs Zombies ripoff game!\n");
	
	for (int i = 0; i < 3; i++)
	{
		printf(".\n");
		sleep(1);
	}
}
