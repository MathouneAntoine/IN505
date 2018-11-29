export CXX=g++
export CXXFLAGS=-Wall 
export LDFLAGS=
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
	

game: $(OBJ) $(OBJ_Formes)
	$(CXX) -o $@ $^ $(LDFLAGS)

Field.o: 
Objects.o: Field.h 
Rock.o: Objects.h 
Tree.o: Objects.h 
main.o: Field.h Rock.h 

%.o: %.c mes_formes.h
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper $(EXEC) game

clean:
	@(cd $(MESFORMES_DIR) && $(MAKE) $@)
	@(cd $(PERSO_DIR) && $(MAKE) $@)
	rm -rf *.o

mrproper: clean
	@(cd $(MESFORMES_DIR) && $(MAKE) $@)
	@(cd $(PERSO_DIR) && $(MAKE) $@)
	rm -rf $(EXEC)