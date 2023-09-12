compile:
	g++ src/Dice.cpp -c -Wall -o bin/Dice.o
	g++ src/housekeeping.cpp -c -Wall -o bin/housekeeping.o
	g++ src/diceCup.cpp -c -Wall -o bin/diceCup.o
	g++ src/score.cpp -c -Wall -std=c++11 -o bin/score.o
	g++ src/scoreCard.cpp -c -Wall -std=c++11 -o bin/scoreCard.o
	g++ src/Game.cpp -c -Wall -std=c++11 -o bin/Game.o
	g++ src/driver.cpp bin/Dice.o bin/housekeeping.o bin/diceCup.o bin/Game.o bin/Score.o bin/scoreCard.o -Wall -std=c++11 -o bin/a.out

run:
	./bin/a.out

clean:
	rm *.o

cun:
	make compile
	make run