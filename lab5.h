/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Lab5.
 *
 */

#ifndef LAB5_H_LOL
#define LAB5_H_LOL

#include "GameBoard.h"

std::string helpPromptString = 
"This is a game where you place ants onto a track in order to defend the\n"
"colony from the nasty mean old bee guys. If any bee makes it past the top \n"
"cell, you lose! You win by killing all the bees before the end of your turn.\n"
"\n"
"If you know exactly what you want to do in your next moves, you may queue\n"
"ants and their placements. For example, if you want to place a Harvester\n"
"at square 0, a Ninja at square 9, and a LongThrower at square 1, you can \n"
"enter: h0n9l1    This will place all those ants automatically for you.\n\n"
"Stephen Stengel <stephen.stengel@cwu.edu> 40819903\n"
"\n";

void helpPrompt(int argc, char** argv);
void welcome();


#endif
