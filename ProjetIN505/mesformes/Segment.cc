#include "Segment.h"
#include "Point.h"
#include "Forme.h"
#include <iostream>

using namespace std;

Segment::Segment() : p(0,0),q(0,0) 
{}

Segment::Segment(Point& p1, Point& p2): p(p1), q(p2)
{}

Segment::Segment(int x1, int y1, int x2, int y2): p(x1,y1), q(x2,y2)
{}

Point& Segment::getP()
{
	return this->p;
}

Point& Segment::getQ()
{
	return this->q;
}

void Segment::afficher()
{
	cout<< endl<<" SEGMENT (Defini par 2 points) : "<< endl;
	cout<< "POINT 1 	"<< "x: " << this->p.getX() << "  y: "<< this->p.getY()  << endl;
	cout<< "POINT 2	 	"<< "x: " << this->q.getX() << "  y: "<< this->q.getY()  << endl;
}

void Segment::deplacer(int x, int y)
{
	//avance en X
	this->p.setX(this->p.getX() + x);
	this->q.setX(this->q.getX() + x);

	//avance en y
	this->p.setY(this->p.getY() + y);
	this->q.setY(this->q.getY() + y);
}

Segment::~Segment()
{}