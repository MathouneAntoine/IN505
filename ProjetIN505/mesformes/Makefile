Point: Point.o Segment.o Forme.o Triangle.o Rectangle.o Cercle.o main.o
	g++ Point.o Segment.o Forme.o Triangle.o Rectangle.o Cercle.o main.o -o Point

main.o: Rectangle.h
	g++ -c main.cc

Point.o: Point.h
	g++ -c Point.cc
Segment.o: Segment.h Point.h 
	g++ -c Segment.cc -Wall
Forme.o: Forme.h Point.h
	g++ -c Forme.cc -Wall
Triangle.o:  Forme.h Triangle.h Point.h 
	g++ -c Triangle.cc
Rectangle.o: Forme.h Rectangle.h Point.h
	g++ -c Rectangle.cc
Cercle.o: Cercle.h Point.h
	g++ -c Cercle.cc

clean:
	-rm *.o
	-rm Point
