#include "Field.h"
#include "Rock.h"
#include "Tree.h"


#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton hello("Hello world!");

    hello.show();
    return app.exec();
}

/*int main(int argc, char const *argv[])
{
	Field* f= new Field(500,400);

	//vector<Object *> tab(0); 
	Objects* o;
	int i = 0;
	if(i==1)
	{

		Rock* R= new Rock(f,10, 20, 30, 40, 50, 60);
		//tab.push_back(R);
		R= new Rock(f,10, 20, 30, 40, 50, 60);
		//tab.push_back(R);

		Tree* T= new Tree(f,10, 20, 30, 40, 50, 60);
		//tab.push_back(T);
	}

	if (i==2)
	{

	}
	
	if (i==3)
	{

	}	
	QWindow();


	return 0;
}*/