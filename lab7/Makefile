CC = g++

main.out: main.o HugeInt.o
	$(CC) -o main.out main.o HugeInt.o
	./main.out
main.o: main.cpp HugeInt.h
	$(CC) -c main.cpp
HugeInt.o: HugeInt.cpp HugeInt.h
	$(CC) -c HugeInt.cpp

.PHONY:
	clean

clean:
	rm  *.o *.out