
make: main.o Character.o Ai.o Player.o 
	g++ main.o Character.o Ai.o Player.o -o Player

main.o: main.cc  Character.h Ai.h Player.h
	g++ -c -Wall main.cc 

Character.o: Character.cc  Character.h 
	g++ -c -Wall Character.cc

Ai.o: Ai.cc Ai.h Character.h 
	g++ -c -Wall Ai.cc

Player.o: Player.cc Player.h Character.h 
	g++ -c -Wall Player.cc 

clean:
	-rm *.o
	-rm Player