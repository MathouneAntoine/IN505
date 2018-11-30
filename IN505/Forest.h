#ifndef FOREST_H
#define FOREST_H

#include <vector>
#include "Perso/Character.h"
#include "Field.h"
#include "Objects.h"
using namespace std;

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
