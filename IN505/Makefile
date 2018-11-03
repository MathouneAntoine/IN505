

make: main.o Terrain.o Point.o
	gcc main.o Terrain.o Point.o -o Terrain

main.o: main.cc  Terrain.h
	g++ -c -Wall main.cc 
Terrain.o: Terrain.cc  Terrain.h
	g++ -c -Wall Terrain.cc 
Point.o: Point.cc  Point.h  main.cc 
	g++ -c -Wall Point.cc 

clean:
	rm *.o
	rm Terrain
