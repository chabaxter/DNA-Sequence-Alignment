CC = g++
CFLAGS = -std=c++14 -c -g -Og -Wall -ggdb3 -Werror -pedantic
OBJ = main.o EDistance.o
DEPS = main.cpp EDistance.cpp EDistance.h
EXE = EDistance

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
