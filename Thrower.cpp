/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Thrower.cpp
 * 
 * Thrower ant. Inherits from Ant
 *
 */

#include "Thrower.h"
#include "GameBoard.h"

Thrower::Thrower()
{
	setType("Thrower");
	setHealthRemaining(THROWER_STARTING_HEALTH);
}

Thrower::~Thrower()
{
	
}

//Damages bee in this square.
void Thrower::attack(GameBoard& gb, int squareThisThrowerIsIn)
{
	if ( gb.gameSquares[squareThisThrowerIsIn]->isThereABeeHere() )
	{
		gb.gameSquares[squareThisThrowerIsIn]->damageFirstBee(THROWER_DAMAGE);
	}
}
