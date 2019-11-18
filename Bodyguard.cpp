/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Bodyguard.cpp
 * 
 * Bodyguard ant. Inherits from Ant
 *
 */

#include "Bodyguard.h"

Bodyguard::Bodyguard()
{
	setType("Bodyguard");
	setHealthRemaining(BODYGUARD_STARTING_HEALTH);
}

Bodyguard::~Bodyguard()
{
	
}

//Bodyguard does not attack.
void Bodyguard::attack(GameBoard& gb, int squareThisBodyguardIsIn)
{
	
}
