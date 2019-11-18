/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Wall.cpp
 * 
 * Wall ant. Inherits from Ant
 *
 */

#include "Wall.h"

Wall::Wall()
{
	setType("Wall");
	setHealthRemaining(WALL_STARTING_HEALTH);
}

Wall::~Wall()
{
	
}

//Walls have no attack lol.
void Wall::attack(GameBoard& gb, int squareThisWallIsIn)
{
	
}
