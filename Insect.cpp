/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Insect.cpp
 * 
 * Contains insect class stuff. Gets inherited from.
 *
 */

#include "Insect.h"

//~ #include "GameBoard.h" //needed to give access to the board


Insect::Insect()
{
	setHealthRemaining(DEFAULT_BASE_HEALTH);
}

Insect::~Insect()
{
	//~ printf("Calling INSECT destructor! Splat!\n");
	//~ printf("\a");
}


void Insect::setHealthRemaining(int newHealth)
{
	healthRemaining = newHealth;
}

int Insect::getHealthRemaining()
{
	return healthRemaining;
}

void Insect::subtractFromHealth(int damage)
{
	healthRemaining -= damage;
}

void Insect::setType(std::string newType)
{
	insectType = newType;
}

std::string Insect::getType()
{
	return insectType;
}

std::string Insect::toString()
{
	std::string rString = "";
	
	//~ rString += " Type: ";
	rString += getType();
	rString += " hp: ";
	rString += std::to_string( getHealthRemaining() );
	rString += " | ";
	
	return rString;
	
}








