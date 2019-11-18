/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * ShortThrower.h
 * Header file for ShortThrower class.
 * 
 */

#ifndef SHORT_THROWER_ANT_H_LOL
#define SHORT_THROWER_ANT_H_LOL

#include "Ant.h"

class ShortThrower : public Ant
{
	public:
		ShortThrower();
		~ShortThrower();
		void attack(GameBoard& gb, int squareThisShortThrowerIsIn);
	private:
};

#endif
