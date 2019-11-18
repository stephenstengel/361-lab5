/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * Ant.h
 * Header file for the Ant class.
 * 
 */

#ifndef ANT_H_LOL
#define ANT_H_LOL


#include "Insect.h"


#define HARVESTER_STARTING_HEALTH 1
#define THROWER_STARTING_HEALTH 1
#define FIRE_STARTING_HEALTH 1
#define LONG_THROWER_STARTING_HEALTH 1
#define SHORT_THROWER_STARTING_HEALTH 1
#define WALL_STARTING_HEALTH 4
#define NINJA_STARTING_HEALTH 1
#define BODYGUARD_STARTING_HEALTH 2

//harvester cannot attack
#define THROWER_DAMAGE 1
//fire has a special attack. Doesn't do normal damage.
#define LONG_THROWER_DAMAGE 1
#define SHORT_THROWER_DAMAGE 2
#define NINJA_DAMAGE 1

class Ant : public Insect
{
	public:
		Ant();
		~Ant();
		
	private:
		
};


#endif
