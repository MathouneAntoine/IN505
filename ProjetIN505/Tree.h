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
	Tree(Field* field, int high, int diameter, int altitude, int FromCenterX, int FromCenterY);
	Tree(Forme* f, int high, int diameter, int altitude);
	Tree(Point center);
	Forme* getForme();
	void print();
	~Tree();

	private:
};

#endif