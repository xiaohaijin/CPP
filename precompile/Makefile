EXE = myexe
precompile = myhead.h.gch

EXE:mysource.o
	g++ mysource.o -o $(EXE)

precompile:myhead.h
	g++ -c myhead.h

mysource.o:mysource.cpp
	g++ -c mysource.cpp -o mysource.o
