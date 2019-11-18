/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Ninja.h
 * Header file for Ninja class.
 * 
 */

#ifndef NINJA_ANT_H_LOL
#define NINJA_ANT_H_LOL

#include "Ant.h"

class Ninja : public Ant
{
	public:
		Ninja();
		~Ninja();
		void attack(GameBoard& gb, int squareThisNinjaIsIn);
	private:
};

#endif
