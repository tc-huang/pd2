tetris.out: tetris.o genMino.o Mino.o MinoI.o MinoS.o MinoJ.o MinoZ.o
	g++ -o tetris.out tetris.o genMino.o Mino.o MinoI.o MinoS.o MinoJ.o MinoZ.o

tetris.o: tetris.cpp genMino.h
	g++ -c tetris.cpp

genMino.o: genMino.cpp genMino.h
	g++ -c genMino.cpp

Mino.o: Mino.cpp Mino.h
	g++ -c Mino.cpp

MinoJ.o: MinoI.cpp MinoI.h
	g++ -c MinoI.cpp

MinoJ.o: MinoS.cpp MinoS.h
	g++ -c MinoS.cpp

MinoJ.o: MinoJ.cpp MinoJ.h
	g++ -c MinoJ.cpp

MinoZ.o: MinoZ.cpp MinoZ.h
	g++ -c MinoZ.cpp

.PHONY:
	clean

clean:
	rm *.o *.out