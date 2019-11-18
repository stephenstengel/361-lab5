/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Harvester.h
 * Header file for Harvester class.
 * 
 */

#ifndef HARVESTER_ANT_H_LOL
#define HARVESTER_ANT_H_LOL

#include "Ant.h"


class Harvester : public Ant
{
	public:
		Harvester();
		~Harvester();
		
		void attack(GameBoard& gb, int squareThisHarvesterIsIn);
	
	private:
		const int AMMOUNT_OF_FOOD_THAT_HARVESTER_MAKES = 1;
			
};


#endif
