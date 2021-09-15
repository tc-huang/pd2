CC = g++

lab3_b.out: lab3_b.o Clock.o
	$(CC) -o lab3_b.out lab3_b.o Clock.o -g
	./lab3_b.out

Clock.o: Clock.cpp Clock.h
	$(CC) -c Clock.cpp

.PHONY:
	clean

clean:
	rm  *.o *.out