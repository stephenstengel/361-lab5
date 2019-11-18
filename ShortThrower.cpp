/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * ShortThrower.cpp
 * 
 * ShortThrower ant. Inherits from Ant
 *
 */

#include "ShortThrower.h"
#include "GameBoard.h"

ShortThrower::ShortThrower()
{
	setType("ShortThrower");
	setHealthRemaining(SHORT_THROWER_STARTING_HEALTH);
}

ShortThrower::~ShortThrower()
{
	
}

//Damage to bee closest, but no more than 2 squares away.
void ShortThrower::attack(GameBoard& gb, int thisIndex)
{
	//NOTE: Converting from int to size_t is fine here, because thisIndex will always be positive or 0!
	for (size_t i = thisIndex; i < gb.gameSquares.size() && i <= (size_t)(thisIndex + 2); i++)
	{
		if ( gb.gameSquares[i]->isThereABeeHere() )
		{
			gb.gameSquares[i]->damageFirstBee(SHORT_THROWER_DAMAGE);
			
			break;
		}
	}
}
