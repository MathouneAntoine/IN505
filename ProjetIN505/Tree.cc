#include <iostream>
#include <time.h>
#include "Tree.h"
#include "Objects.h"
#include "mes_formes.h"


using namespace std;

Tree::Tree()
{
	int i= rand()%2;
	if(i==0)
	{
		Point p1(15,20); 
		Point p2(10,10); 
		Point p3(20,10);
		this->f= new Triangle(p1,p2,p3);
	}
	if(i==1)
		this->f = new Cercle(Point(10,10),10);
	
	this->high=10;	
	this->diameter=20;
	this->altitude=50;
	this->life=(altitude/4)+(high+diameter);
}

Tree::Tree(Tree& t)
{

	this->f=new Cercle(Point(10,10),10);
	this->life=t.life;
	this->high=t.high;	
	this->diameter=t.diameter;
	this->altitude=t.altitude;
}

Tree::Tree(Field* field, int high, int diameter, int altitude, int FromCenterX, int FromCenterY)
{
	this->center.setX(FromCenterX + field->getCenter().getX());
	this->center.setY(FromCenterY + field->getCenter().getY());

	int i= rand()%2;
	if(i==0)
	{
		this->f= new Triangle(this->center,diameter,high);
	}
	if(i==1)
		this->f = new Cercle(this->center,diameter);


	this->high=high;
	this->diameter=diameter;
	this->altitude=altitude;
	this->life=(altitude/4)+(high+diameter);	
}

Tree::Tree(Forme* f, int high, int diameter, int altitude)
{
	this->f= f;
	this->high=high;	
	this->diameter=diameter;
	this->altitude=altitude;
	this->life=(altitude/4)+(high+diameter);	

}

Tree::Tree(Point center)
{
	this->center.setX(center.getX());
	this->center.setY(center.getY());

	int diam=rand()%100+60;
	int high=rand()%100+60;
	int altitude=rand()%150+80;

}

Forme* Tree::getForme()
{
	return this->f;
}


void Tree::print()
{
	std::cout <<  "TREE" << std::endl;
}

Tree::~Tree()
{
 delete this->f;
}