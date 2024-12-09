OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

all: program.exe

program.exe: program.o Cjt_estaciones.o Estacion.o Cjt_Bicis.o Bici.o
	g++ $(OPCIONS) -o program.exe program.o Cjt_estaciones.o Estacion.o Cjt_Bicis.o Bici.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Cjt_estaciones.o: Cjt_estaciones.cc Cjt_estaciones.hh Estacion.hh
	g++ $(OPCIONS) -c Cjt_estaciones.cc

Estacion.o: Estacion.cc Estacion.hh Bici.hh
	g++ $(OPCIONS) -c Estacion.cc

Cjt_Bicis.o: Cjt_Bicis.cc Cjt_Bicis.hh Bici.hh
	g++ $(OPCIONS) -c Cjt_Bicis.cc

Bici.o: Bici.cc Bici.hh
	g++ $(OPCIONS) -c Bici.cc

clean:
	rm -f *.o
	rm -f *.exe

clean_win:
	del *.o
	del *.exe

tar:
	tar -cvf practica.tar Makefile program.cc Cjt_Bicis.cc Cjt_Bicis.hh Cjt_estaciones.cc Cjt_estaciones.hh Estacion.cc Estacion.hh Bici.cc Bici.hh DOC.zip Justificacio.pdf