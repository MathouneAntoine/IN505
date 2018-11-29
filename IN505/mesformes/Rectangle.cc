using namespace std;
#include <iostream>
#include "Point.h"
#include "Rectangle.h"
#include "Forme.h"

Rectangle::Rectangle()
{
	this->p1.setX(0);
	this->p1.setY(10);
	this->p2.setX(0);
	this->p2.setY(0);
	this->p3.setX(10);
	this->p3.setY(0);
	this->p4.setX(10);
	this->p4.setY(10);
	this->center.setX((p1.getX()+p4.getX())/2);
	this->center.setY((p1.getY()+p2.getY())/2);
}

Rectangle::Rectangle(Point center, int diameter, int depth)
{
	this->center=Point(center);
	this->p1.setX(center.getX()-(diameter/2));
	this->p1.setY(center.getY()+(depth/2));

	this->p2.setX(center.getX()-(diameter/2));
	this->p2.setY(center.getY()-(depth/2));

	this->p3.setX(center.getX()+(diameter/2));
	this->p3.setY(center.getY()-(depth/2));

	this->p4.setX(center.getX()+(diameter/2));
	this->p4.setY(center.getY()+(depth/2));
}


Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4): p1(p1), p2(p2), p3(p3), p4(p4)
{
	center.setX((p4.getX()-p1.getX())/2);
	center.setX((p1.getY()-p2.getY())/2);
}

Rectangle::Rectangle(Rectangle& r)
{
	this->p1 = r.p1;
	this->p2 = r.p2;
	this->p3 = r.p3;
	this->p4 = r.p4;
	this->center = r.center;
}
void Rectangle::deplacer(int dx, int dy)
{
	p1.setX(p1.getX()+dx);
	p2.setX(p2.getX()+dx);
	p3.setX(p3.getX()+dx);
	p4.setX(p4.getX()+dx);
	center.setX(center.getX()+dx);

	p1.setY(p1.getY()+dy);
	p2.setY(p2.getY()+dy);
	p3.setY(p3.getY()+dy);
	p4.setY(p4.getY()+dy);
	center.setY(center.getY()+dy);
}

void Rectangle::afficher()
{
	cout <<"RECTANGLE :" <<endl;
	cout <<"p1.x = " << p1.getX() << " p1.y = " << p1.getY()<<endl;
	cout <<"p2.x = " << p2.getX() << " p2.y = " << p2.getY() << endl;
	cout <<"p3.x = " << p3.getX() << " p3.y = " << p3.getY() <<endl;
	cout <<"p4.x = " << p4.getX() << " p4.y = " << p4.getY() << endl;
}

Point Rectangle::getP1()
{
	return this->p1;
}
Point Rectangle::getP2()
{
	return this->p2;
}

Point Rectangle::getP3()
{
	return this->p3;
}
Point Rectangle::getP4()
{
	return this->p4;
}
Point Rectangle::getCenter()
{
	return this->center;
}

Rectangle::~Rectangle()
{ cout << "destruction Rectangle "<< endl; }

