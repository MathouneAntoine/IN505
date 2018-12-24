EXEC=perso
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

all: $(EXEC)

perso: 



%.o: %.c ../ForestAction.h	
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
