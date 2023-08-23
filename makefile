compile:
	g++ Dice.cpp -c -Wall
	g++ housekeeping.cpp -c -Wall
	g++ diceCup.cpp -c -Wall
	g++ Game.cpp -c -Wall -std=c++11
	g++ scoreCard.cpp -c -Wall -std=c++11
	g++ score.cpp -c -Wall -std=c++11
	g++ calculator.cpp -c -Wall -std=c++11
	g++ driver.cpp Dice.o housekeeping.o diceCup.o Game.o Score.o scoreCard.o calculator.o -Wall -std=c++11

run:
	./a.out

clean:
	rm *.o

cun:
	make compile
	make run