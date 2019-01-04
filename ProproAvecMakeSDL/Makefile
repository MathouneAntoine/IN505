export CXX=g++
export CXXFLAGS=`sdl2-config --cflags`  
export LDFLAGS=`sdl2-config --libs` -lGL -lGLU -lSDL2_ttf 
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

MESFORMES_DIR=./mesformes/
SRC_Formes= $(wildcard $(MESFORMES_DIR)*.cc)
OBJ_Formes= $(SRC_Formes:.cc=.o)

PERSO_DIR=./Perso/
SRC_Perso= $(wildcard $(PERSO_DIR)*.cc)
OBJ_Perso= $(SRC_Perso:.cc=.o)


all: $(EXEC) game

$(EXEC):
	@(cd $(MESFORMES_DIR) && $(MAKE))
	@(cd $(PERSO_DIR) && $(MAKE))
	

game: $(OBJ) $(OBJ_Formes) $(OBJ_Perso)
	$(CXX) -o $@ $^ $(LDFLAGS)
	
Field.o: 
Objects.o: Field.h 
Rock.o: Objects.h 
Tree.o: Objects.h
Forest.o:
forestEditor.o:Forest.h Rock.h Tree.h mes_perso.h
main.o: Field.h Rock.h Forest.h forestEditor.h


%.o: %.c mes_formes.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper $(EXEC) game

clean:
	rm -rf *.o
	@(cd $(MESFORMES_DIR) && $(MAKE) $@)
	@(cd $(PERSO_DIR) && $(MAKE) $@)
	rm -rf *.o
	
mrproper: clean
	@(cd $(MESFORMES_DIR) && $(MAKE) $@)
	@(cd $(PERSO_DIR) && $(MAKE) $@)
	rm -rf $(EXEC)

install:
	sudo apt-get install make
	sudo apt-get install g++
	sudo apt-get install libsdl2-dev 
	sudo apt-get install libsdl2-ttf-dev
	sudo apt-get install freeglut3-dev
	sudo apt-get install libglu1-mesa-dev
	sudo apt-get install mesa-common-dev
	sudo apt-get install libsdl2-2.0-0


