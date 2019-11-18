/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Bodyguard.h
 * Header file for Bodyguard class.
 * 
 */

#ifndef BODYGUARD_ANT_H_LOL
#define BODYGUARD_ANT_H_LOL

#include "Ant.h"
//does not need gameboard

class Bodyguard : public Ant
{
	public:
		Bodyguard();
		~Bodyguard();
		void attack(GameBoard& gb, int squareThisBodyguardIsIn);
	private:
};

#endif
