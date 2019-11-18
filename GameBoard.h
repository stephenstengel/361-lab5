/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * 
 * Lab5 cs361. GameBoard header.
 * 
 */

#ifndef GAME_BOARD_LOL
#define GAME_BOARD_LOL

#include <iostream>
#include <string.h>
#include <vector>
#include <unistd.h>

#include "Insect.h"
#include "Bee.h"
#include "Ant.h"
#include "Square.h"
#include "Harvester.h"
#include "Thrower.h"
#include "Fire.h"
#include "LongThrower.h"
#include "ShortThrower.h"
#include "Wall.h"
#include "Ninja.h"
#include "Bodyguard.h"

#define NUMBER_OF_SQUARES_IN_GAME 10
#define STARTING_FOOD_LEVEL 50

#define HARVESTER_FOOD_COST 2
#define THROWER_FOOD_COST 4
#define FIRE_FOOD_COST 4
#define LONG_THROWER_FOOD_COST 3
#define SHORT_THROWER_FOOD_COST 3
#define WALL_FOOD_COST 4
#define NINJA_FOOD_COST 6
#define BODYGUARD_FOOD_COST 4

class Square;

class GameBoard
{
	public:
		friend class Bee;
		friend class Harvester;
		friend class Thrower;
		friend class Fire;
		friend class LongThrower;
		friend class ShortThrower;
		friend class Wall;
		friend class Ninja;
		friend class Bodyguard;
		friend class Square;
		
		GameBoard();
		~GameBoard();
		
		int runGame(GameBoard& gb);
		
		int getCurrentFood();
		void setCurrentFood(int a);
		void subtractFromFood(int a);
		void addToFood(int a);
		
	
	private:
		std::vector<Square*> gameSquares;
		
		int currentFoodLevel;

		void setUpGame();
		void displayBoard();
		
		bool doesPlayerHaveEnoughFood(char antInQuestion);
		
		char placeAntOnBoard(GameBoard& gb);
		char askForAntToPlace();
		int askForIndexToPlaceAnt(char antToPlace);
		bool isGoodIndexInput(char placeAntIndex);
		
		bool checkIfICanPlaceThisAntHere(char antToPlace, int integerIndex);
		void finallyPlaceTheAnt(GameBoard& gb, char antToPlace, int indexToPlaceAt);
		
		bool canIPlaceAnAntSomewhere();
		
		void createAndPlaceHarvester(int indexToPlaceAt);
		void createAndPlaceThrower(int indexToPlaceAt);
		void createAndPlaceFire(GameBoard& gb, int indexToPlaceAt);
		void createAndPlaceLongThrower(int indexToPlaceAt);
		void createAndPlaceShortThrower(int indexToPlaceAt);
		void createAndPlaceWall(int indexToPlaceAt);
		void createAndPlaceNinja(int indexToPlaceAt);
		void createAndPlaceBodyguard(int indexToPlaceAt);
		
		void makeAntsAttack(GameBoard& gb);
		void makeBeesAttack(GameBoard& gb);
		
		void beesActions(GameBoard& gb);
		
		bool areThereAnyBeesLeft();
		
};


#endif
