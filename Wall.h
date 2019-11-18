/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Wall.h
 * Header file for Wall class.
 * 
 */

#ifndef WALL_ANT_H_LOL
#define WALL_ANT_H_LOL

#include "Ant.h"

class Wall : public Ant
{
	public:
		Wall();
		~Wall();
		void attack(GameBoard& gb, int squareThisWallIsIn);
	private:
};

#endif
