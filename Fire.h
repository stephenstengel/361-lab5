/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Fire.h
 * Header file for Fire class.
 * 
 */

#ifndef FIRE_ANT_H_LOL
#define FIRE_ANT_H_LOL


#include "Ant.h"



class Fire : public Ant
{
	public:
		Fire();
		Fire(GameBoard& gb, int indexToPlaceAt);
		~Fire();
		void attack(GameBoard& gb, int squareThisFireIsIn);
		
		
	private:
		void selfdestruct(GameBoard& gb, int fireIndex);
		
		GameBoard* gb;
		int indexOfFireAnt;
};

#endif
