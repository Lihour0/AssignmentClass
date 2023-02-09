CC = g++
CCFLAGS = -std=c++2a -O
SRC = $(wildcard *.cc)
HH = $(wildcard *.h)
OBJ = $(SRC:%.cc=%.o)

a.out: $(OBJ)
	$(CC) $(CCFLAGS) $^

%.o: %.cc $(HH)
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o core a.out