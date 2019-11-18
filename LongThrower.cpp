/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * LongThrower.cpp
 * 
 * LongThrower ant. Inherits from Ant
 *
 */

#include "LongThrower.h"
#include "GameBoard.h"

LongThrower::LongThrower()
{
	setType("LongThrower");
	setHealthRemaining(LONG_THROWER_STARTING_HEALTH);
}

LongThrower::~LongThrower()
{
	
}

//Damage to nearest bee that is at least 4 squares away.
void LongThrower::attack(GameBoard& gb, int squareThisLongThrowerIsIn)
{
	for (size_t i = squareThisLongThrowerIsIn + 4; i < gb.gameSquares.size(); i++)
	{
		if ( gb.gameSquares[i]->isThereABeeHere() )
		{
			gb.gameSquares[i]->damageFirstBee(LONG_THROWER_DAMAGE);
			
			break;
		}
	}
}
