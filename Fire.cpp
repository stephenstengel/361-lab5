/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Fire.cpp
 * 
 * Fire ant. Inherits from Ant
 *
 */

#include "Fire.h"
#include "GameBoard.h"

Fire::Fire()
{
	setType("Fire");
	setHealthRemaining(FIRE_STARTING_HEALTH);
}


Fire::Fire(GameBoard& inputGameBoard, int indexToPlaceAt)
{
	setType("Fire");
	setHealthRemaining(FIRE_STARTING_HEALTH);
	gb = &inputGameBoard;
	indexOfFireAnt = indexToPlaceAt;
}

Fire::~Fire()
{
	selfdestruct(*gb, indexOfFireAnt);
}

//Fire ants do not attack normally.
void Fire::attack(GameBoard& gb, int squareThisFireIsIn)
{
	
}

void Fire::selfdestruct(GameBoard& gb, int fireIndex)
{
	//~ printf("BOOM!\n");
	if ( gb.gameSquares[fireIndex]->isThereABeeHere() )
	{
		gb.gameSquares[fireIndex]->destroyEachBee();
	}
}

