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
		Forest(Forest &f);
		Character* getP1();
		Character* getP2();
		void print(SDL_Renderer *renderer);
		std::vector<Objects*> getList();
		void init_forest();
		~Forest();

        // private:
		Field f;
		std::vector<Objects*> List_Obj;
		Character* p1;
		Character* p2;
};

#endif
