

make: main.o Field.o Point.o
	g++ main.o Field.o Point.o -o Field

main.o: main.cc  Field.h
	g++ -c -Wall main.cc 
Field.o: Field.cc  Field.h
	g++ -c -Wall Field.cc 
Point.o: Point.cc  Point.h  main.cc 
	g++ -c -Wall Point.cc 

clean:
	-rm *.o
	-rm Field
