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
		Character& getP1Ref();
		Character& getP2Ref();
		Objects* getObj(int i);
		void addList(Objects* o);
		void eraseList(int i);
		void setP1(Character* c);
		void setP2(Character* c);
		friend void setList(vector<Objects*> v);
		vector<Objects*>& getListPtr();

		Field getField();

		void print(SDL_Renderer *renderer, int i);
		std::vector<Objects*> getList();
		void init_forest();

		bool visible();
	

		~Forest();

        private:
        	
		Field f;
		std::vector<Objects*> List_Obj;
		Character* p1;
		Character* p2;
};

#endif
