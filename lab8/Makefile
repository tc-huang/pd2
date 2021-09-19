CC = g++

lab8_3.out: lab8_3.o HugeInt.o
	$(CC) -o lab8_3.out lab8_3.o HugeInt.o
	./lab8_3.out
lab8_3.o: lab8_3.cpp HugeInt.h
	$(CC) -c lab8_3.cpp
HugeInt.o: HugeInt.cpp HugeInt.h
	$(CC) -c HugeInt.cpp

.PHONY:
	clean

clean:
	rm  *.o *.out