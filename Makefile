main: main.o network.o profile.o
	g++ -o main main.o network.o profile.o

tests: tests.o network.o profile.o
	g++ -o tests tests.o network.o profile.o


main.o: main.cpp network.h profile.h

network.o: network.cpp network.h

profile.o: profile.cpp profile.h

tests.o: tests.cpp doctest.h network.h profile.h

clean:
	rm -f main.o network.o profile.o tests.o