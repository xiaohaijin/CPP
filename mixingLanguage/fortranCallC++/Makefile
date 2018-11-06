fortranCallC++:testF.o testC.o
	gfortran -o fortranCallC++ testF.o testC.o -lstdc++

testF.o:testF.f90
	gfortran -c testF.f90

testC.o:testC.c
	gcc -c testC.c

.PHONY:clean
clean:
	$(RM) -r fortranCallC++ testF.o testC.o
