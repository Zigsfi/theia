CXX = g++
CFLAGS = -O3 -g -std=c++11 -pthread -Wall -Wpedantic -Werror
LFLAGS = -lpthread

all: pnm_image.o

clean:
	rm -f *.o

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<
