/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Ant.cpp
 * 
 * Contains Ant class stuff. Inherrits from Insect.
 *
 */

#include "Ant.h"

Ant::Ant()
{
	setType("BASIC ANT!");
}

Ant::~Ant()
{
	//~ printf("Calling BASE ANT destructor! SQUISH!\n");
}

void Insect::attack(GameBoard& gb, int squareThisAntIsIn)
{
	//~ printf("BASIC ANT ATTACK! LOL\n");
}
