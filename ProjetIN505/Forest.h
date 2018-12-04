#ifndef FOREST_H
#define FOREST_H

#include <vector>
#include "mes_perso.h"
#include "mes_formes.h"
#include "Field.h"
#include "Objects.h"

class Forest
{
	public:

		Forest();
		Character* getP1();
		Character* getP2();
		void init_forest();
		~Forest();

	
		Field f;
		std::vector<Objects*> List_Obj;
		Character* p1;
		Character* p2;
	
};

#endif