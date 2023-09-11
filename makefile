compile:
	g++ src/Dice.cpp -c -Wall
	g++ src/housekeeping.cpp -c -Wall
	g++ src/diceCup.cpp -c -Wall
	g++ src/Game.cpp -c -Wall -std=c++11
	g++ src/scoreCard.cpp -c -Wall -std=c++11
	g++ src/score.cpp -c -Wall -std=c++11
	g++ src/driver.cpp src/Dice.o src/housekeeping.o src/diceCup.o src/Game.o src/Score.o src/scoreCard.o -Wall -std=c++11

run:
	./a.out

clean:
	rm *.o

cun:
	make compile
	make run