BIN    = bin
CFLAGS = --std=c++14 -I./include
CC     = g++
DEPS   = $(wildcard include/*.h)
SRCS   = $(wildcard src/Model/*.cpp src/Controller/*.cpp src/View/*.cpp src/*.cpp)
OBJS   = $(patsubst %.cpp,%.o,$(SRCS))

%.o: %.cpp $(DEPS)
	$(CC) -O3 -c -o $@ $< $(CFLAGS)

mastermind: $(OBJS)
	mkdir -p ${BIN}
	$(CC) -o ${BIN}/$@ $^ $(CFLAGS)

all: mastermind

clean:
	rm -rfv $(BIN)
	find . -name '*.o' -exec rm -f {} \; -print

