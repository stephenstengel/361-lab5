#Stephen Stengel <stephen.stengel@cwu.edu> 40819903

#Create executable
lab5: lab5.o Insect.o Bee.o Ant.o \
		Harvester.o Thrower.o Fire.o LongThrower.o ShortThrower.o Wall.o \
		Ninja.o Bodyguard.o GameBoard.o Square.o
	g++ -std=c++14 -Wall -o lab5 lab5.o Insect.o Bee.o Ant.o \
			Harvester.o Thrower.o Fire.o LongThrower.o ShortThrower.o Wall.o \
			Ninja.o Bodyguard.o GameBoard.o Square.o


#Create object files
lab5.o: lab5.cpp lab5.h GameBoard.h
	g++ -std=c++14 -Wall -c lab5.cpp

Insect.o: Insect.cpp Insect.h GameBoard.h
	g++ -std=c++14 -Wall -c Insect.cpp
	
Bee.o: Bee.cpp Bee.h Insect.h GameBoard.h
	g++ -std=c++14 -Wall -c Bee.cpp

Ant.o: Ant.cpp Ant.h Insect.h
	g++ -std=c++14 -Wall -c Ant.cpp

Harvester.o: Harvester.cpp Harvester.h GameBoard.h Ant.h
	g++ -std=c++14 -Wall -c Harvester.cpp
	
Thrower.o: Thrower.cpp Thrower.h Ant.h GameBoard.h
	g++ -std=c++14 -Wall -c Thrower.cpp

Fire.o: Fire.cpp Fire.h Ant.h GameBoard.h
	g++ -std=c++14 -Wall -c Fire.cpp

LongThrower.o: LongThrower.cpp LongThrower.h Ant.h GameBoard.h
	g++ -std=c++14 -Wall -c LongThrower.cpp

ShortThrower.o: ShortThrower.cpp ShortThrower.h Ant.h GameBoard.h
	g++ -std=c++14 -Wall -c ShortThrower.cpp

#Wall does not need GameBoard
Wall.o: Wall.cpp Wall.h Ant.h
	g++ -std=c++14 -Wall -c Wall.cpp

Ninja.o: Ninja.cpp Ninja.h Ant.h GameBoard.h
	g++ -std=c++14 -Wall -c Ninja.cpp

#bodyguard does not need gameboard
Bodyguard.o: Bodyguard.cpp Bodyguard.h Ant.h
	g++ -std=c++14 -Wall -c Bodyguard.cpp

GameBoard.o: GameBoard.cpp GameBoard.h Insect.h Bee.h Ant.h Square.h \
		Harvester.h Thrower.h Fire.h LongThrower.h ShortThrower.h Wall.h \
		Ninja.h Bodyguard.h
	g++ -std=c++14 -Wall -c GameBoard.cpp

Square.o: Square.cpp Square.h Insect.h Ant.h Bee.h GameBoard.h
	g++ -std=c++14 -Wall -c Square.cpp


.PHONY: clean
clean:
	rm -f lab5 *.o lab5-stephen-stengel.zip

.PHONY: backup
backup:
	ssh-backup-pi | lolcat

.PHONY: zip
zip:
	7z a lab5-stephen-stengel.zip lab5 *.cpp *.h Makefile
