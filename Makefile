OBJS = test.o
CC = clang++
CFLAGS = -Wall -c -std=c++17
LFLAGS = -Wall -std=c++17
OUTFILE = a.out

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUTFILE)

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

clean:
	\rm *.o $(OUTFILE)