/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * LongThrower.h
 * Header file for LongThrower class.
 * 
 */

#ifndef LONG_THROWER_ANT_H_LOL
#define LONG_THROWER_ANT_H_LOL

#include "Ant.h"

class LongThrower : public Ant
{
	public:
		LongThrower();
		~LongThrower();
		void attack(GameBoard& gb, int squareThisLongThrowerIsIn);
	private:
};

#endif
