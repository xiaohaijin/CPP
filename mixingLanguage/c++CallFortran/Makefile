EXE=C++CallFortran

$(EXE):testC.o testF.o
	g++ -o $(EXE) testC.o testF.o -lgfortran

testC.o:testC.cpp
	g++ -c testC.cpp

testF.o:testF.f90
	gfortran -c testF.f90

.PHONY:clean
clean:
	$(RM) -r $(EXE) testC.o testF.o
