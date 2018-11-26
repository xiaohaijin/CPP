EXE=kronrod

$(EXE):kronrod_prb.o kronrod.o
	g++ -o $(EXE) kronrod_prb.o kronrod.o -lgfortran

kronrod_prb.o:kronrod_prb.cpp
	g++ -c kronrod_prb.cpp

kronrod.o:kronrod.f
	gfortran -c kronrod.f

.PHONY:clean
clean:
	$(RM) -r $(EXE) kronrod_prb.o kronrod.o
