/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Thrower.h
 * Header file for Thrower class.
 * 
 */

#ifndef THROWER_ANT_H_LOL
#define THROWER_ANT_H_LOL

#include "Ant.h"

class Thrower : public Ant
{
	public:
		Thrower();
		~Thrower();
	
	
		void attack(GameBoard& gb, int squareThisThrowerIsIn);
		
	private:
		
};

#endif
