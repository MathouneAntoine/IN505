#include <iostream>
#include "Tree.h"
#include "Objects.h"
#include "mes_formes.h"


using namespace std;

Tree::Tree()
{
	this->f = new Cercle(Point(10,10),10);
	this->life=20;
	this->high=20;	
	this->diameter=20;
}

Tree::Tree(Tree& t)
{

	this->f=new Cercle(Point(10,10),10);
	this->life=t.life;
	this->high=t.high;	
	this->diameter=t.diameter;
}

Tree::Tree(Field* field, int life, int high, int diameter, int FromCenterX, int FromCenterY,  int depth)
{
	Point p(FromCenterX + field->getCenter().getX(), FromCenterY + field->getCenter().getY());

	this->f= new Cercle(Point(10,10),10);
	this->life=life;
	this->high=high;	
	this->diameter=diameter;
}

Tree::Tree(Forme* f,int life, int high, int diameter)
{
	this->f= f;
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