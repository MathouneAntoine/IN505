#include <vector>
#include "Field.h"
#include "Rock.h"
#include "Tree.h"
#include "mes_formes.h"
#include "forestEditor.h"
#include "Forest.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Field* f= new Field(500,400);
	srand(time(NULL));

	vector<Objects> v;
	forestEditor edit;
	Forest forest;
	Rock * r=new Rock();
	r->printInfo();
	r->print();
	Rock * r2=new Rock();
	r2->printInfo();
	r2->print();
	forest.List_Obj.push_back(r2);
	forest.List_Obj.push_back(r);
	edit.write_Forest(forest);

	Forest forest2;	
	forest2=edit.read_File(forest2, 0);

	forest2.List_Obj[0]->printInfo();
	forest2.List_Obj[0]->print();
	forest2.List_Obj[1]->printInfo();
	forest2.List_Obj[1]->print();
	return 0;
}