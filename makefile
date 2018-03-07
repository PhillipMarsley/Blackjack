# makefile
# --------

OBJS = main.o cardDeck.o
CC = g++ -std=c++0x -std=gnu++0x
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Run : $(OBJS)
	$(CC) $(LFAGS) $(OBJS) -o Run

main.o : main.cpp cardDeck.hpp
	$(CC) $(CFLAGS) main.cpp

cardDeck.o : cardDeck.cpp cardDeck.hpp
	$(CC) $(CFLAGS) cardDeck.cpp	

clean:
	rm *.o Run
