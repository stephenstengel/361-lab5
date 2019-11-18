/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 * 
 * Lab5 cs361. The Square class header.
 * 
 */

#ifndef SQUARE_H_LOL
#define SQUARE_H_LOL

#include <vector>

#include "Insect.h"
#include "Ant.h"
#include "Bee.h"
#include "GameBoard.h"

class Square
{
	public:
		Square();
		~Square();
		
		bool isThereAnAntHere();
		bool isThereABeeHere();
		bool isThereABodyguardHere();
		bool isFirstAntANinja();
		
		void putBeeHere();
		void putBeeHere(int health);
		void putAntHere(Ant* antToPlace);
		
		void advanceBee(GameBoard& gb, int squareIndex);
		void advanceOrAttackBees(GameBoard& gb, int squareIndex);
		
		void removeBeeFromFront();
		void removeAntFromFront();
		
		void removeBeeFromIndex(int indexToDelete);
		void removeAntFromIndex(int indexToDelete);
		
		std::string toString();
		
		int getSizeOfAntsInSquare();
		int getSizeOfBeesInSquare();
		
		void squareAntsAttack(GameBoard& gb, int squareIndex);
		void squareBeesAttack(GameBoard& gb, int squareIndex);
		
		void damageFirstBee(int damage);
		void damageFirstAnt(int damage);
		
		void damageEachBee(int damage);
		void destroyEachBee();
		
		bool isFrontBeeDead();
		bool isFrontAntDead();
		
		bool isBeeAtIndexDead(size_t beeIndex);
		
	private:
		//vector for ants
		std::vector<Ant*> antsInSquare;
		
		//vector for bees
		std::vector<Bee*> beesInSquare;
};

#endif
