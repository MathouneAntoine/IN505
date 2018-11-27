#include <iostream>	
#include <time.h>
#include "Rock.h"
#include "Objects.h"
#include "mes_formes.h"

using namespace std;

Rock::Rock()
{
	Point p1(20,20);
	Point p2(30,20);
	Point p3(20,10);
	Point p4(30,10);

	int i= rand();
	if(i==0)
		this->f= new Rectangle(p1,p2,p3,p4);
	if(i==1)
	{
		p2.setX(10);
		p2.setY(15);
		p3.setY(15);
		this->f= new Losange(p1,p3,p2,p4);
	}

	this->life=20;
	this->high=20;	
	this->diameter=10;
	this->depth=10;
}

Rock::Rock(Field* field,int life, int high, int diameter, int depth, int FromCenterX, int FromCenterY)
{
	Point center(FromCenterX + field->getCenter().getX(), FromCenterY + field->getCenter().getY());

	//int i= rand(0,2);
	//if(i==0)
		this->f= new Rectangle(center,diameter,depth);
	/*if(i==1)
		this->f= new Triangle(p1,p2,p3);*/
	this->life=life;
	this->high=high;	
	this->diameter=diameter;
	this->depth=depth;
}

Rock::Rock(Forme* f,int life, int high, int diameter, int depth)
{
	this->f= f;
	this->life=life;
	this->high=high;	
	this->diameter=diameter;
	this->depth=depth;
}

Forme* Rock::getForme()
{
	return this->f;
}

void Rock::print()
{
	cout <<  "ROCK" << endl;
	this->f->afficher();
}
Rock::~Rock()
{}