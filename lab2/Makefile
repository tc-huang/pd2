CC = g++

main.out: main.o calculate.o
	$(CC) -o main.out main.o calculate.o -g
	./main.out
	cat file.out
main.o: main.cpp calculate.h
	$(CC) -c main.cpp -g
calculate.o: calculate.cpp calculate.h
	$(CC) -c calculate.cpp -g

.PHONY:
	clean

clean:
	rm  file.out *.o *.out