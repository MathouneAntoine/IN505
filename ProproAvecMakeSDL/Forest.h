#ifndef FOREST_H
#define FOREST_H

#include <SDL2/SDL.h>

#include <vector>
#include "mes_perso.h"
#include "mes_formes.h"
#include "Field.h"
#include "Objects.h"

class Forest
{
	public:

		Forest();
		Forest(Field f);
		Character* getP1();
		Character* getP2();
		Objects* getObj(int i);
		void addList(Objects* o);
		void setP1(Character* c);
		void setP2(Character* c);
		Field getField();
		void print(SDL_Renderer *renderer);
		std::vector<Objects*> getList();
		void init_forest();
		bool colisionObjet(int curseur_x,int curseur_y);
		bool colision(int x, int y);

		~Forest();

        private:
        	
		Field f;
		std::vector<Objects*> List_Obj;
		Character* p1;
		Character* p2;
};

#endif
