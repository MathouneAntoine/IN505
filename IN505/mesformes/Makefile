EXEC=formes
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

all: $(EXEC)

formes: 

Point.o: Point.h
Segment.o: Segment.h Point.h 
Forme.o: Forme.h Point.h
Triangle.o:  Forme.h Triangle.h Point.h 
Rectangle.o: Forme.h Rectangle.h Point.h
Cercle.o: Cercle.h Point.h
Losange.o: Losange.h Point.h 

%.o: %.c
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
