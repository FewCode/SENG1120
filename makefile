CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Card.cpp Node.h LinkedList.h DeckOfCards.cpp HandOfCards.cpp Blackjack.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=DeckOfCards

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
