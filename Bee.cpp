/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Bee.cpp
 * 
 * Contains bee class stuff. Inherrits from Insect.
 *
 */

#include "Bee.h"
#include "GameBoard.h"

Bee::Bee()
{
	setHealthRemaining(BEE_HEALTH);
	setType("Bee");
}

Bee::Bee(int health)
{
	setHealthRemaining(health);
	setType("Bee");
}

Bee::~Bee()
{
	//~ printf("Calling bee destructor, BUZZBUZZ!\n");
}


//Inherited attack function specific to bees.
void Bee::attack(GameBoard& gb, int squareThisBeeIsIn)
{
	//check that there is an ant to attack.
	//	IF none, donothing
	if ( gb.gameSquares[squareThisBeeIsIn]->isThereAnAntHere() )
	{
		//if first ant not ninja
		if ( !gb.gameSquares[squareThisBeeIsIn]->isFirstAntANinja() )
		{
			gb.gameSquares[squareThisBeeIsIn]->damageFirstAnt(BEE_DAMAGE);
		}
	}
}


bool Bee::canThisBeeMove(GameBoard& gb, int squareIndex)
{
	if ( squareIndex <= 0 )
	{
		return false;
	}
	else if ( gb.gameSquares[squareIndex]->isThereAnAntHere() && !gb.gameSquares[squareIndex]->isFirstAntANinja() )
	{
		return false;
	}
	
	return true;
}
