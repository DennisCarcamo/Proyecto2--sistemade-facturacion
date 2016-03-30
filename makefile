main: main.o aparato.o PlasmaTv.o  equipo.o  HornoMicroondas.o refrigeradora.o
	g++ main.o aparato.o PlasmaTv.o  equipo.o HornoMicroondas.o refrigeradora.o -o a 
	
main.o:	main.cpp aparato.h PlasmaTv.h  
	g++ -c main.cpp 

equipo.o:	equipo.cpp equipo.h aparato.h
	g++ -c equipo.cpp 

PlasmaTv.o:	PlasmaTv.cpp PlasmaTv.h aparato.h
	g++ -c PlasmaTv.cpp 

HornoMicroondas.o:	HornoMicroondas.cpp HornoMicroondas.h aparato.h
	g++ -c HornoMicroondas.cpp 

aparato.o:	aparato.cpp aparato.h
	g++ -c aparato.cpp 

refrigeradora.o:	refrigeradora.cpp refrigeradora.h
	g++ -c refrigeradora.cpp 
