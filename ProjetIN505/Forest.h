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
		void init_forest();
		~Forest();

	private:
		Field f;
		vector<Objects> List_Obj;
		Character p1;
		Character p2;
	
};

#endif