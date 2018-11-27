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
	Tree(Field* field, int life, int high, int diameter, int FromCenterX, int FromCenterY,  int depth);
	Tree(Forme* f,int life, int high, int diameter);
	Forme* getForme();
	void print();
	~Tree();

	private:
};

#endif