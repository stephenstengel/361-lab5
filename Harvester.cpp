/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Harvester.cpp
 * 
 * Harvester ant. Inherits from Ant
 *
 */

#include "Harvester.h"
#include "GameBoard.h"

Harvester::Harvester()
{
	setType("Harvester");
	setHealthRemaining(HARVESTER_STARTING_HEALTH);
}

Harvester::~Harvester()
{
	
}

//"Attack" is to add food to colony.
void Harvester::attack(GameBoard& gb, int squareThisHarvesterIsIn)
{
	gb.currentFoodLevel += AMMOUNT_OF_FOOD_THAT_HARVESTER_MAKES;
}
