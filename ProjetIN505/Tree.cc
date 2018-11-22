#include <iostream>
#include "Tree.h"
#include "Objects.h"
#include "./mesformes/Forme.h"
#include "./mesformes/Cercle.h"

using namespace std;

Tree::Tree()
{
	this->f= new Cercle();
	this->life=20;
	this->high=20;
	this->diameter=20;
}

Tree::Tree(Tree& t)
{
	this->f=new Cercle();
	this->life=t.life;
	this->high=t.high;
	this->diameter=t.diameter;
}

Tree::Tree(Field* f, int life, int high, int diameter, int FromCenterX, int FromCenterY)
{

	this->center= Point(FromCenterX + f->getCenter().getX(), FromCenterY + f->getCenter().getY());

	this->f= new Cercle(center,diameter);
	this->life=life;
	this->high=high;
	this->diameter=diameter;
}

Forme* Tree::getForme()
{
	return this->f;
}


void Tree::print()
{
	cout <<  "TREE" << endl;
}

Tree::~Tree()
{}
