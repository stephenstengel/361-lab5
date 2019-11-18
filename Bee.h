/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Bee.h
 * Header file for the Bee class.
 * 
 */

#ifndef BEE_H_LOL
#define BEE_H_LOL

#include "Insect.h"

#define BEE_HEALTH 3
#define BEE_DAMAGE 1

class Bee : public Insect
{
	public:
		Bee();
		Bee(int health);
		~Bee();
		virtual void attack(GameBoard& gb, int squareThisBeeIsIn);
		bool canThisBeeMove(GameBoard& gb, int squareIndex);
	private:
};

#endif
