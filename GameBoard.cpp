/*
 * Stephen Stengel <stephen.stengel@cwu.edu> 40819903
 *
 * Lab5 cs361. GameBoard class.
 *
 */

//bug: entering more than one digit will feed all digits into input.

#include "GameBoard.h"

std::string turnOptions =	"h: Harvester Ant	" 
							+ std::to_string(HARVESTER_FOOD_COST) + " food\n"
							"t: Thrower Ant		" 
							+ std::to_string(THROWER_FOOD_COST) + " food\n"
							"f: Fire Ant		" 
							+ std::to_string(FIRE_FOOD_COST) + " food\n"
							"l: LongThrower Ant	" 
							+ std::to_string(LONG_THROWER_FOOD_COST) + " food\n"
							"r: ShortThrower Ant	" 
							+ std::to_string(SHORT_THROWER_FOOD_COST) +" food\n"
							"w: Wall Ant		" 
							+ std::to_string(WALL_FOOD_COST) + " food\n"
							"n: Ninja Ant		" 
							+ std::to_string(NINJA_FOOD_COST) + " food\n"
							"b: Bodyguard Ant	" 
							+ std::to_string(BODYGUARD_FOOD_COST) + " food\n"
							"s: Skip turn.\n"
							"q: quit the game.\n";

//generate the game board.
GameBoard::GameBoard()
{
	setUpGame();
}

GameBoard::~GameBoard()
{
	for (size_t i = 0; i < gameSquares.size(); i++)
	{
		delete gameSquares[i];
	}
}

//return 1 if win, 0 if lose, -1 if quit.
int GameBoard::runGame(GameBoard& gb)
{
	while (true)
	{
		beesActions(gb);
		gameSquares.back()->putBeeHere();
		displayBoard();
		
		char tmp = placeAntOnBoard(gb);
		if ( tmp == 'q' )
		{
			return -1;
		}
		
		makeAntsAttack(gb);
		displayBoard();
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		
		if ( !areThereAnyBeesLeft() )
		{
			printf("THERE ARE NO BEES LEFT!\nANTS WIN!!!\n\n");
			
			return 1; //Ants win!
		}
		else if ( !gameSquares[0]->isThereAnAntHere() && gameSquares[0]->isThereABeeHere() )
		{
			return 0; //Bees win. :(
		}
	}//end of turn-making while loop
	
	return 0;
}


bool GameBoard::areThereAnyBeesLeft()
{
	for ( size_t i = 0; i < gameSquares.size(); i++)
	{
		if ( gameSquares[i]->isThereABeeHere() )
		{
			return true;
		}
	}
	
	return false;
}


void GameBoard::makeAntsAttack(GameBoard& gb)
{
	for (size_t i = 0; i < gameSquares.size(); i++)
	{
			gameSquares[i]->squareAntsAttack(gb, i);
	}
}


void GameBoard::makeBeesAttack(GameBoard& gb)
{
	for (size_t i = 0; i < gameSquares.size(); i++)
	{
		gameSquares[i]->squareBeesAttack(gb, i);
	}
}


void GameBoard::beesActions(GameBoard& gb)
{
	//for each Square
	for (size_t i = 0; i < gameSquares.size(); i++)
	{
		gameSquares[i]->advanceOrAttackBees(gb, i);
	}
}

char GameBoard::placeAntOnBoard(GameBoard& gb)
{
	bool finishedPlacing = false;
	//while loop for placing an ant or skipping a turn or quitting.
	while (!finishedPlacing)
	{
		char antToPlace = askForAntToPlace();
		if ( antToPlace == 'q' )
		{
			return 'q';
		}
		else if ( antToPlace == 's' )
		{
			return 's';
		}
		if ( !canIPlaceAnAntSomewhere() )
		{
			printf("You can't place any ants anywhere this turn! Skipping!\n");
			return 's';
		}
		
		int indexToPlaceAt = askForIndexToPlaceAnt(antToPlace);
		
		if ( indexToPlaceAt == -2 )
		{
			return 'q';
		}
		else if (indexToPlaceAt == -1)
		{
			return 's';
		}
		
		finallyPlaceTheAnt(gb, antToPlace, indexToPlaceAt);
		
		return 'a'; //a for ant placed
	}
	
	printf("Error in placeAntOnBoard()\n");
	return 'q'; //for error!
}


//-2 quit
//-1 skip
//0-9 index
int GameBoard::askForIndexToPlaceAnt(char antToPlace)
{
	printf("Where would you like to place it? (0-9, q to quit, s to skip): ");
	while (true)
	{
		char placeAntIndex;
		std::cin >> placeAntIndex;
		
		if ( !isGoodIndexInput(placeAntIndex) )
		{
			printf("Could not use that input.\n");
			printf("Please enter a number between 0 and 9,"
					" or s to skip, or q to quit.\n");
			
			continue;
		}
		
		if (placeAntIndex == 'q')
		{
			return -2;
		}
		else if (placeAntIndex == 's')
		{
			return -1;
		}

		int integerIndex = placeAntIndex - '0';
		if (!checkIfICanPlaceThisAntHere(antToPlace, integerIndex) )
		{
			continue; //Repeat loop if cannot
		}
		
		return integerIndex;
	}
	
	//~ return -9;
}


void GameBoard::finallyPlaceTheAnt(GameBoard& gb, char antToPlace, int indexToPlaceAt)
{
	//replace each case with helper function?
	switch (antToPlace)
	{
		case 'h':
			createAndPlaceHarvester(indexToPlaceAt);
			break;
		case 't':
			createAndPlaceThrower(indexToPlaceAt);
			break;
		case 'f':
			createAndPlaceFire(gb, indexToPlaceAt);
			break;
		case 'l':
			createAndPlaceLongThrower(indexToPlaceAt);
			break;
		case 'r': //AH POOP  CHANGE LATER
			createAndPlaceShortThrower(indexToPlaceAt);
			break;
		case 'w':
			createAndPlaceWall(indexToPlaceAt);
			break;
		case 'n':
			createAndPlaceNinja(indexToPlaceAt);
			break;
		case 'b':
			createAndPlaceBodyguard(indexToPlaceAt);
			break;
	}
}

void GameBoard::createAndPlaceHarvester(int indexToPlaceAt)
{
	Harvester* tempAnt = new Harvester();
	gameSquares.at(indexToPlaceAt)->putAntHere(tempAnt);
	subtractFromFood(HARVESTER_FOOD_COST);
}

void GameBoard::createAndPlaceThrower(int indexToPlaceAt)
{
	Thrower* tempAnt = new Thrower();
	gameSquares.at(indexToPlaceAt)->putAntHere(tempAnt);
	subtractFromFood(THROWER_FOOD_COST);
}

void GameBoard::createAndPlaceFire(GameBoard& gb, int indexToPlaceAt)///////////////////////////////////////////
{
	Fire* tempAnt = new Fire(gb, indexToPlaceAt);
	gameSquares.at(indexToPlaceAt)->putAntHere(tempAnt);
	subtractFromFood(FIRE_FOOD_COST);
}

void GameBoard::createAndPlaceLongThrower(int indexToPlaceAt)
{
	LongThrower* tempAnt = new LongThrower();
	gameSquares.at(indexToPlaceAt)->putAntHere(tempAnt);
	subtractFromFood(LONG_THROWER_FOOD_COST);
}

void GameBoard::createAndPlaceShortThrower(int indexToPlaceAt)
{
	ShortThrower* tempAnt = new ShortThrower();
	gameSquares.at(indexToPlaceAt)->putAntHere(tempAnt);
	subtractFromFood(SHORT_THROWER_FOOD_COST);
}

void GameBoard::createAndPlaceWall(int indexToPlaceAt)
{
	Wall* tempAnt = new Wall();
	gameSquares.at(indexToPlaceAt)->putAntHere(tempAnt);
	subtractFromFood(WALL_FOOD_COST);
}

void GameBoard::createAndPlaceNinja(int indexToPlaceAt)
{
	Ninja* tempAnt = new Ninja();
	gameSquares.at(indexToPlaceAt)->putAntHere(tempAnt);
	subtractFromFood(NINJA_FOOD_COST);
}

void GameBoard::createAndPlaceBodyguard(int indexToPlaceAt)
{
	Bodyguard* tempAnt = new Bodyguard();
	gameSquares.at(indexToPlaceAt)->putAntHere(tempAnt);
	subtractFromFood(BODYGUARD_FOOD_COST);
}


bool GameBoard::checkIfICanPlaceThisAntHere(char antToPlace, int integerIndex)
{
	if (antToPlace == 'b')
	{
		if ( gameSquares.at(integerIndex)->isThereABodyguardHere() )
		{
			printf("Can't place another Bodyguard here!\n");
			
			return false;
		}
	}
	else
	{
		if (gameSquares.at(integerIndex)->isThereAnAntHere() )
		{
			//if size >1 false
			if ( gameSquares.at(integerIndex)->getSizeOfAntsInSquare() > 1 )
			{
				printf("Can't place an ant there!\n");
				printf("Pick a different spot!: ");
				
				return false;
			}
			//if size = 1 and is bodyguard, true
			else if ( gameSquares.at(integerIndex)->getSizeOfAntsInSquare() == 1
					&& gameSquares.at(integerIndex)->isThereABodyguardHere() )
			{
				return true;
			}
			
			//if size = 1 and is not bodyguard false
			else if ( gameSquares.at(integerIndex)->getSizeOfAntsInSquare() == 1
					&& !gameSquares.at(integerIndex)->isThereABodyguardHere() )
			{
				printf("Can't place an ant there!\n");
				printf("Pick a different spot!: ");
				
				return false;
			}
		}
		
		return true; //unneeded
	}
	
	return true;
}


bool GameBoard::isGoodIndexInput(char placeAntIndex)
{
	if ( placeAntIndex == 'q' || placeAntIndex == 's')
	{
		return true;
	}
	
	int temp = placeAntIndex - '0';
	
	if ( temp >= 0 && temp <= 9 )
	{
		return true;
	}
	
	return false;
}


//return q if quit
//return s if skip turn
//return a corresponding antChar if ant placed
char GameBoard::askForAntToPlace()
{
	char antChar;
	
	while (true)
	{
		//Ask what kind of ant they would like to place.
		std::cout << turnOptions << std::endl;
		printf("What kind of ant will you place?: ");
		
		//~ antChar = 's'; //testing destructors!
		std::cin >> antChar;
		antChar = tolower(antChar);
		
		if (antChar == 'q')
		{
			printf("Quitting this game.\n");
			
			return 'q'; //q for quit!
		}
		else if ( antChar == 's' )
		{
			printf("Skipping this turn.\n");
			
			return 's'; //s for skip
		}
		else if ( !doesPlayerHaveEnoughFood(antChar) )
		{
			printf("YOU DON'T HAVE ENOUGH FOOD FOR THAT!\n");
			
			continue; //Repeat this asking function.
		}
		else
		{
			return antChar;
		}
	}
}


void GameBoard::setUpGame()
{
	//make the squares vector NUMBER_OF_SQUARES_IN_GAME squares long.
	for (int i = 0; i < NUMBER_OF_SQUARES_IN_GAME; i++)
	{
		Square* tmpSquare = new Square();
		gameSquares.push_back( tmpSquare );
	}
	
	setCurrentFood(STARTING_FOOD_LEVEL);
}


//Bees will obviously be B
//Ants will be whatever their class is.
//later can rewrite to check how many lines needed to print board on one line.
//This prints vertically.
void GameBoard::displayBoard()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	for (size_t i = 0; i < NUMBER_OF_SQUARES_IN_GAME; i++)
	{
		std::cout << "--------\n| ";
		std::cout << i << " | ";
		
		if (gameSquares.at(i)->isThereAnAntHere() || gameSquares.at(i)->isThereABeeHere() )
		{
			std::cout << gameSquares.at(i)->toString() << " \n";
		}
		else
		{
			std::cout << " " << std::endl;
		}
	}
	std::cout << "--------\n";
	//~ sleep(1);
	printf("##############\n");
	//~ std::cout << "Food: " << currentFoodLevel << " " << std::endl;
	printf("#  Food: %2d  #\n", currentFoodLevel);
	printf("##############\n");
}

int GameBoard::getCurrentFood()
{
	return currentFoodLevel;
}

void GameBoard::setCurrentFood(int a)
{
	currentFoodLevel = a;
}

void GameBoard::subtractFromFood(int a)
{
	currentFoodLevel -= a;
}

void GameBoard::addToFood(int a)
{
	currentFoodLevel += a;
}

bool GameBoard::doesPlayerHaveEnoughFood(char antInQuestion)
{
	int foodNeeded = 99999;
	
	switch (antInQuestion)
	{
		case 'h':
			foodNeeded = HARVESTER_FOOD_COST;
			break;
		case 't':
			foodNeeded = THROWER_FOOD_COST;
			break;
		case 'f':
			foodNeeded = FIRE_FOOD_COST;
			break;
		case 'l':
			foodNeeded = LONG_THROWER_FOOD_COST;
			break;
		case 'r':
			foodNeeded = SHORT_THROWER_FOOD_COST;/////////////////////////////////////it's r now
			break;
		case 'w':
			foodNeeded = WALL_FOOD_COST;
			break;
		case 'n':
			foodNeeded = NINJA_FOOD_COST;
			break;
		case 'b':
			foodNeeded = BODYGUARD_FOOD_COST;
			break;
		default:
			break;
	}
	
	if (foodNeeded <= currentFoodLevel)
	{
		return true;
	}
	
	return false;
}


bool GameBoard::canIPlaceAnAntSomewhere()
{
	//check if have food for bodyguard
	//IF YES, check all spots for bodyguard
	if (currentFoodLevel >= BODYGUARD_FOOD_COST)
	{
		//check for bodyguards
		//for each square, if no have bodyguard, return true
		for (size_t i = 0; i < gameSquares.size() ; i++)
		{
			if ( !gameSquares.at(i)->isThereABodyguardHere() )
			{
				return true;
			}
		}
	}
	
	for (size_t i = 0; i < gameSquares.size(); i++)
	{
		if ( !gameSquares.at(i)->isThereAnAntHere() )
		{
			return true;
		}
	}
	
	return false;
}
