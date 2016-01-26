CFLAGS = --std=c++11 -I./include

SRC=$(wildcard src/Model/*.cpp src/Controller/*.cpp src/View/*.cpp src/*.cpp)


mastermind: $(SRC)
	g++ -o $@ $^ $(CFLAGS)

all: mastermind

clean:
	rm mastermind
