
make: main.o Field.o Rock.o Tree.o Objects.o ./mesformes/Point.o ./mesformes/Forme.o ./mesformes/Rectangle.o
	g++ main.o Field.o Rock.o Tree.o Objects.o ./mesformes/Point.o ./mesformes/Forme.o ./mesformes/Rectangle.o -o Field

main.o: main.cc  Field.h Rock.h
	g++ -c -Wall main.cc 

Field.o: Field.cc  Field.h
	g++ -c -Wall Field.cc 

Objects.o: Objects.cc Objects.h Field.h ./mesformes/Forme.h
	g++ -c -Wall Objects.cc

Rock.o: Rock.cc  Rock.h Objects.h ./mesformes/Forme.h ./mesformes/Rectangle.h
	g++ -c -Wall Rock.cc 
Tree.o: Tree.cc  Tree.h Objects.h ./mesformes/Forme.h ./mesformes/Rectangle.h
	g++ -c -Wall Tree.cc 

clean:
	-rm *.o
	-rm Field