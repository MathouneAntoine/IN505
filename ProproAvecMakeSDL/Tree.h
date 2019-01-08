#ifndef TREE_H
#define TREE_H

#include "Field.h"
#include "Objects.h"
#include "mes_formes.h"

class Tree :  public Objects
{
	public:
	Tree();
	Tree(Tree& t);
	Tree(Field* field, int height, int diameter, int altitude, int FromCenterX, int FromCenterY);
	Tree(char t, Point center, int height, int diameter, int altitude, int life);
	Tree(Point center);
	void print(Field f);
    void print_Tree();
    ~Tree();


	private:
};

#endif
