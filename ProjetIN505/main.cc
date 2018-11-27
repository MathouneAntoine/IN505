#include "Field.h"
#include "Rock.h"
#include "Tree.h"
#include "mes_formes.h"

int main(int argc, char const *argv[])
{
	Field* f= new Field(500,400);

	//vector<Object *> tab(0); 
	Objects* o;
	int i = 0;
	if(i==1)
	{

		Rock* R= new Rock(f,10, 20, 30, 40, 50, 60);
		Rectangle *rect= dynamic_cast <Rectangle*> (R->getForme());
		rect->getP1();
		//tab.push_back(R);

		//tab.push_back(T);
	}

	if (i==2)
	{

	}
	
	if (i==3)
	{

	}	


	return 0;
}