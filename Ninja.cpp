/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Ninja.cpp
 * 
 * Ninja ant. Inherits from Ant
 *
 */

#include "Ninja.h"
#include "GameBoard.h"
//~ class GameBoard;

Ninja::Ninja()
{
	setType("Ninja");
	setHealthRemaining(NINJA_STARTING_HEALTH);
}

Ninja::~Ninja()
{
	
}

//currently, I think I'll take the simple route and just have it attack things
//in the square every turn. Can change to attack each bee only once later.
//Maybee by calling this when new bees are added to the square.
//yeah, can just leave empty and have a different attack function
void Ninja::attack(GameBoard& gb, int thisIndex)
{
	//damage everything in this square
	if ( gb.gameSquares[thisIndex]->isThereABeeHere() )
	{
		gb.gameSquares[thisIndex]->damageEachBee(NINJA_DAMAGE);
	}
}
