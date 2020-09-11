CC=g++ 
CPPFLAGS=-g -Wall -std=c++14

gratacels: main.o Solucionador.o Solucio.o Candidats.o Visibilitats.o
	$(CC) -o gratacels main.o Solucionador.o Solucio.o Candidats.o Visibilitats.o

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp
	
Solucionador.o: Solucionador.h Solucionador.cpp
	$(CC) $(CPPFLAGS) -c Solucionador.cpp
	
Solucio.o: Solucio.h Solucio.cpp
	$(CC) $(CPPFLAGS) -c Solucio.cpp
	
Candidats.o: Candidats.h Candidats.cpp
	$(CC) $(CPPFLAGS) -c Candidats.cpp
	
Visibilitats.o: Visibilitats.h Visibilitats.cpp
	$(CC) $(CPPFLAGS) -c Visibilitats.cpp

clean:
	rm *.o gratacels
