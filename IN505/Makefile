
make: main.o Field.o ./mesformes/Point.o
	g++ main.o Field.o ./mesformes/Point.o -o Field

main.o: main.cc  Field.h
	g++ -c -Wall main.cc 
Field.o: Field.cc  Field.h
	g++ -c -Wall Field.cc 
	
./mesformes/Point.o: ./mesformes/Point.cc  ./mesformes/Point.h  main.cc 
	g++ -c -Wall ./mesformes/Point.cc 

clean:
	-rm *.o
	-rm Field
