using namespace std;
#include <iostream>
#include <time.h>
#include "Point.h"
#include "Triangle.h"

/*
  0)   .P1.		1) P2\	   2)  P2 ------P3  3)     /P2
	  ......		| P1          .....          P1 |
	P2------P3 	   P3/	           p1 			   \P3

*/

Triangle::Triangle(Point p1, Point p2, Point p3): p1(p1),p2(p2),p3(p3)
{}

Triangle::Triangle(Point center,int diameter, int high)
{
	int i= rand()%4;
	if (i==0)
	{
		this->orientation = 0;
		this->p1.setX(center.getX());
		this->p1.setY(center.getY()+high/2);
		this->p2.setX(center.getX()-(diameter/2));
		this->p2.setY(center.getY()-high/2);
		this->p3.setX(center.getX()+(diameter/2));
		this->p3.setY(center.getY()-(high/2));
	}
	if (i==1)
	{
		this->orientation = 1;
		this->p1.setX(center.getX()+(diameter/2));
		this->p1.setY(center.getY());
		this->p2.setX(center.getX()-(diameter/2));
		this->p2.setY(center.getY()+high/2);
		this->p3.setX(center.getX()-(diameter/2));
		this->p3.setY(center.getY()-(high/2));
	}
	if (i==2)
	{
		this->orientation = 2;
		this->p1.setX(center.getX());
		this->p1.setY(center.getY()-high/2);
		this->p2.setX(center.getX()-(diameter/2));
		this->p2.setY(center.getY()+high/2);
		this->p3.setX(center.getX()+(diameter/2));
		this->p3.setY(center.getY()+(high/2));
	}
	if (i==3)
	{
		this->orientation = 3;
		this->p1.setX(center.getX()-(diameter/2));
		this->p1.setY(center.getY());
		this->p2.setX(center.getX()+(diameter/2));
		this->p2.setY(center.getY()+high/2);
		this->p3.setX(center.getX()+(diameter/2));
		this->p3.setY(center.getY()-(high/2));
	}
}

Triangle::Triangle(Triangle& pc)
{
	this->p1 = pc.p1;
	this->p2 = pc.p2;
	this->p3 = pc.p3;
}

void Triangle::afficher()
{
	cout << "TRIANGLE => p1.x = " << p1.getX() << " p1.y = " << p1.getY()<< endl;
	cout << "p2.x = " << p2.getX() << " p2.y = " << p2.getY() <<endl;
	cout <<"p3.x() = " << p3.getX() << " p3.y = " << p3.getY() << endl;
}

Point Triangle::getP1(){return this->p1;}

Point Triangle::getP2(){return this->p2;}

Point Triangle::getP3(){return this->p3;}
int Triangle::getOrientation()
{
	return this->orientation;
}

Triangle::~Triangle(){ cout << "destruction Triangle " << endl; }

