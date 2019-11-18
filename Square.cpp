/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * 
 * Lab5 cs361. The Square class.
 * 
 */
 
 #include "Square.h"

Square::Square()
{
	
}

Square::~Square()
{
	//ants
	for (size_t i = 0; i < antsInSquare.size(); i++)
	{
		delete antsInSquare[i];
	}
	//bees
	for (size_t i = 0; i < beesInSquare.size(); i++)
	{
		delete beesInSquare[i];
	}
	
}

void Square::squareAntsAttack(GameBoard& gb, int squareIndex)
{
	//make each ant attack.
	for (size_t i = 0; i < antsInSquare.size(); i++)
	{
		antsInSquare[i]->attack(gb, squareIndex);
		
		gb.displayBoard();
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		sleep(1);
	}
}


void Square::squareBeesAttack(GameBoard& gb, int squareIndex)
{
	for (size_t i = 0; i < beesInSquare.size(); i++)
	{
		beesInSquare[i]->attack(gb, squareIndex);
	}
}


//Creates a new bee in this square. At the back of the vector.
void Square::putBeeHere()
{
	Bee* tempBee = new Bee();
	
	beesInSquare.push_back( tempBee );
}

//creates a bee with a specified health total.
void Square::putBeeHere(int health)
{
	Bee* tempBee = new Bee(health);
	
	beesInSquare.push_back( tempBee );
}


void Square::advanceBee(GameBoard& gb, int squareIndex)
{
	
}

//must make sure that is one bee kills the blocking ant, the rest can move.
void Square::advanceOrAttackBees(GameBoard& gb, int squareIndex)
{
	//for each bee
		//if can move move and break
		//else attack
	for (size_t i = 0; i < beesInSquare.size(); i++)
	{
		if ( beesInSquare[i]->canThisBeeMove(gb, squareIndex) )
		{
			gb.gameSquares[squareIndex - 1]->putBeeHere(beesInSquare[i]->getHealthRemaining() );
			removeBeeFromIndex(i);
			i--; //decrement i so we check all of them.
		}
		else if ( isThereAnAntHere() ) //can attack?
		{
			beesInSquare[i]->attack(gb, squareIndex);
		}
		gb.displayBoard();
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		sleep(1);
	}
}

//Damages the first bee in the bee vector. Removes it if it dies.
void Square::damageFirstBee(int damage)
{
	if ( isThereABeeHere() )
	{
		beesInSquare[0]->subtractFromHealth(damage);
		
		//if the first bee ran out of health, remove it
		if ( isFrontBeeDead() )
		{
			printf("\a");
			removeBeeFromFront();
		}
	}
	//else do nothing lol, safty first!
}

void Square::damageEachBee(int damage)
{
	if ( isThereABeeHere() )
	{
		for (size_t i = 0; i < beesInSquare.size(); i++)
		{
			beesInSquare[i]->subtractFromHealth(damage);
		}
		for (size_t i = 0; i < beesInSquare.size(); i++)
		{
			if ( isBeeAtIndexDead(i) )
			{
				printf("\a");
				removeBeeFromIndex(i);
				i--;//important. moves back the index because we just deleted a 
					//thingy and need to check the thing that was moved into its
					//place.
			}
		}
	}
}

void Square::destroyEachBee()
{
	if ( isThereABeeHere() )
	{
		for (size_t i = 0; i < beesInSquare.size(); i++)
		{
			delete beesInSquare[i];
			printf("\a");
		}
		for (size_t i = 0; i < beesInSquare.size(); i++)
		{
			beesInSquare.clear();
		}
	}
}


void Square::damageFirstAnt(int damage)
{
	if (isThereAnAntHere() )
	{
		antsInSquare[0]->subtractFromHealth(damage);
		
		if ( isFrontAntDead() )
		{
			printf("\a");
			removeAntFromFront();
		}
	}
}


bool Square::isFrontBeeDead()
{
	if ( beesInSquare[0]->getHealthRemaining() <= 0 )
	{
		return true;
	}
	
	return false;
}

bool Square::isBeeAtIndexDead(size_t beeIndex)
{
	if ( beesInSquare[beeIndex]->getHealthRemaining() <= 0 )
	{
		return true;
	}
	return false;
}

bool Square::isFrontAntDead()
{
	if ( antsInSquare[0]->getHealthRemaining() <= 0 )
	{
		return true;
	}
	
	return false;
}


//removes a bee at a specific index?
//Maybe just from the front. That will bee easy and make sense if they are lined up.
//Removes the bee from the front of the vector.
void Square::removeBeeFromFront()
{
	delete beesInSquare[0];
	beesInSquare.erase( beesInSquare.begin() );
}


void Square::removeAntFromFront()
{
	delete antsInSquare[0];
	antsInSquare.erase(antsInSquare.begin() );
}


//Removes a bee at a specific index
void Square::removeBeeFromIndex(int indexToDelete)
{
	delete beesInSquare[indexToDelete];
	beesInSquare.erase( beesInSquare.begin() + indexToDelete );
}


//places an ant pointer into the vector of ants.
//Pushes to beginning if bodyguard, end if other.
void Square::putAntHere( Ant* antToPlace )
{
	
	if ( antToPlace->getType() == "Bodyguard" )
	{
		antsInSquare.insert( antsInSquare.begin(), antToPlace );
	}
	else
	{
		antsInSquare.push_back( antToPlace );
	}
	
}


//function to remove an ant at a specific index
void Square::removeAntFromIndex(int indexToDelete)
{
	delete antsInSquare[indexToDelete];
	antsInSquare.erase( antsInSquare.begin() + indexToDelete );
}


//Returns true if there are any Ants in this Square.
bool Square::isThereAnAntHere()
{
	if ( antsInSquare.size() > 0 )
	{
		return true;
	}
	
	return false;
}


//Returns true if there are any Bees in this Square.
bool Square::isThereABeeHere()
{
	if ( beesInSquare.size() > 0 )
	{
		return true;
	}
	
	return false;
}

bool Square::isThereABodyguardHere()
{
	if ( !isThereAnAntHere() )
	{
		return false;
	}
	
	for (size_t i = 0; i < antsInSquare.size(); i++)
	{
		if ( antsInSquare.at(i)->getType() == "Bodyguard" )
		{
			return true;
		}
	}
	
	return false;
}


bool Square::isFirstAntANinja()
{
	if ( !isThereAnAntHere() )
	{
		return false;
	}
	else if (antsInSquare[0]->getType() == "Ninja")
	{
		return true;
	}
	
	return false;
}

int Square::getSizeOfAntsInSquare()
{
	return antsInSquare.size();
}

int Square::getSizeOfBeesInSquare()
{
	return beesInSquare.size();
}

std::string Square::toString()
{
	std::string rString = "";
	
	for (size_t i = 0; i < antsInSquare.size(); i++)
	{
		rString += antsInSquare.at(i)->toString();
	}
	for (size_t i = 0; i < beesInSquare.size(); i++)
	{
		rString += beesInSquare.at(i)->toString();
	}
	return rString;
}
