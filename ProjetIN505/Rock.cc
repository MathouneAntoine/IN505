#include <iostream>
#include <QRect>
#include "Rock.h"
#include "Objects.h"
#include "./mesformes/Forme.h"
#include "./mesformes/Rectangle.h"

using namespace std;

Rock::Rock()
{
	Point p1, p2,p3, p4;
	p1= Point(20,20);
	p2= Point(30,20);
	p3= Point(20,10);
	p4= Point(30,10);

	this->f= new Rectangle(p1,p2,p3,p4);

	this->life=20;
	this->high=20;	
	this->diameter=10;
	this->depth=10;
}

Rock::Rock(Field* field,int life, int high, int diameter, int depth, int FromCenterX, int FromCenterY)
{
	Point center;
	center= Point(FromCenterX + field->getCenter().getX(), FromCenterY + field->getCenter().getY());

	this->f= new Rectangle(center,diameter,depth);
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

void Rock::printQt()
{
	QRect rect = new QRect(this->p1.getX(), this->p1.getY(), this->diameter, this->depth);
}

Rock::~Rock()
{}