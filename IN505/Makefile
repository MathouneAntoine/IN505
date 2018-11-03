

make: main.o Terrain.o
	gcc main.o Terrain.o -o Terrain

main.o: Terrain.h
	g++ -c -Wall main.cc 
Terrain.o:Terrain.h
	g++ -c -Wall Terrain.cc 

clean:
	rm *.o
	rm Terrain
