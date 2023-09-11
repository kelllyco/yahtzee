compile:
	g++ src/Dice.cpp -c -Wall
	g++ src/housekeeping.cpp -c -Wall
	g++ src/diceCup.cpp -c -Wall
	g++ src/Game.cpp -c -Wall -std=c++11
	g++ src/scoreCard.cpp -c -Wall -std=c++11
	g++ src/score.cpp -c -Wall -std=c++11
	g++ src/driver.cpp Dice.o housekeeping.o diceCup.o Game.o Score.o scoreCard.o -Wall -std=c++11

run:
	./a.out

clean:
	rm *.o

cun:
	make compile
	make run