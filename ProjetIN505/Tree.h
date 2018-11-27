#ifndef TREE_H
#define TREE_H

#include "Field.h"
#include "Objects.h"
#include "./mesformes/Forme.h"

class Tree :  public Objects
{
	public:

		Tree();
		Tree(Tree t);
		Tree(int life, int high, int diameter);
		Tree(Forme f,int life, int high, int diameter);
		Forme getForme();
		void print();
		~Tree();

	private:
};

#endif