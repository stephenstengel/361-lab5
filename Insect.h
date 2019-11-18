/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Insect.h
 * Header file for the insect class.
 * 
 */

#ifndef INSECT_H_LOL
#define INSECT_H_LOL

#include <iostream>
#include <string.h>

class GameBoard;


#define DEFAULT_BASE_HEALTH 1

class Insect
{
	public:
		Insect();
		virtual ~Insect();
		
		virtual void attack(GameBoard& gb, int squareThisInsectIsIn) = 0;
		
		void setHealthRemaining(int newHealth);
		int getHealthRemaining();
		void subtractFromHealth(int damage);
		
		void setType(std::string type);
		std::string getType();
		
		std::string toString();
	
	protected:
		int healthRemaining;
		std::string insectType;  //gives the type of the insect. Only used for toString. not logic.
		
	private:
		
};


#endif
