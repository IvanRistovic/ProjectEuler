CC  	= g++
CCFLAGS	= -Wall -Wextra -O3
PROGRAM	= 0049.out
OBJ 	= 		 	\
	main.o   	 	\
	../timer.o		\
	../primes.o


%.o: %.c
	$(CC) -c -o $@ $< $(CCFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)


.PHONY: clean

clean:
	rm -f src/*.swp *.swp *~ src/*~ *.o
