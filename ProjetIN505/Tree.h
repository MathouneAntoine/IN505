#ifndef TREE_H
#define TREE_H

#include "Field.h"
#include "Objects.h"
#include "./mesformes/Forme.h"

class Tree :  public Objects
{
	public:

		Tree();
		Tree(Tree& t);
		Tree(Field* f, int life, int high, int diameter, int FromCenterX, int FromCenterY);
		Forme* getForme();
		void print();
		~Tree();

	private:

};

#endif
