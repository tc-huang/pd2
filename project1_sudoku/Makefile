CC = g++
.DEFAULT_GOAL:=all

all: generate transform solve
	./generate
	./transform
	./solve

generate: generate.o sudoku.o
	$(CC) -o generate generate.o sudoku.o


generate.o: generate.cpp
	$(CC) -c generate.cpp

transform: transform.o sudoku.o
	$(CC) -o transform transform.o sudoku.o


transform.o: transform.cpp
	$(CC) -c transform.cpp

solve: solve.o sudoku.o
	$(CC) -o solve solve.o sudoku.o


solve.o: solve.cpp
	$(CC) -c solve.cpp

sudoku.o: sudoku.h sudoku.cpp
	$(CC) -c sudoku.cpp

.PHONY:
	clean

clean:
	rm *.o *.out