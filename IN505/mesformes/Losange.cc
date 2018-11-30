using namespace std;
#include <iostream>
#include "Point.h"
#include "Losange.h"
#include "Forme.h"

Losange::Losange()
{
	this->p1.setX(10);
	this->p1.setY(20);
	this->p2.setX(20);
	this->p2.setY(10);
	this->p3.setX(10);
	this->p3.setY(0);
	this->p4.setX(0);
	this->p4.setY(10);
	this->center.setX((p2.getX()+p4.getX())/2);
	this->center.setY((p1.getY()+p3.getY())/2);
}

Losange::Losange(Point center, int diameter, int depth)
{
	this->center=Point(center);
	this->p1.setX(center.getX());
	this->p1.setY(center.getY()+(depth/2));

	this->p2.setX(center.getX()+(diameter/2));
	this->p2.setY(center.getY());

	this->p3.setX(center.getX());
	this->p3.setY(center.getY()-(depth/2));

	this->p4.setX(center.getX()-(diameter/2));
	this->p4.setY(center.getY());
}


Losange::Losange(Point p1, Point p2, Point p3, Point p4): p1(p1), p2(p2), p3(p3), p4(p4)
{

	this->center.setX((p2.getX()+p4.getX())/2);
	this->center.setY((p1.getY()+p3.getY())/2);
}

Losange::Losange(Losange& r)
{
	this->p1 = r.p1;
	this->p2 = r.p2;
	this->p3 = r.p3;
	this->p4 = r.p4;
	this->center = r.center;
}
void Losange::deplacer(int dx, int dy)
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

void Losange::afficher()
{
	cout <<"Losange :" <<endl;
	cout <<"p1.x = " << p1.getX() << " p1.y = " << p1.getY()<<endl;
	cout <<"p2.x = " << p2.getX() << " p2.y = " << p2.getY() << endl;
	cout <<"p3.x = " << p3.getX() << " p3.y = " << p3.getY() <<endl;
	cout <<"p4.x = " << p4.getX() << " p4.y = " << p4.getY() << endl;
}

Point Losange::getP1()
{
	return this->p1;
}

Point Losange::getP2()
{
<<<<<<< HEAD
	return this->p2;
=======
	return this->p3;
>>>>>>> ee00255256108fac5d405208d5fdc777a9bee254
}

Point Losange::getP3()
{
	return this->p3;
}

Point Losange::getP4()
{
	return this->p4;
}

Point Losange::getCenter()
{
	return this->center;
}

Losange::~Losange()
{ cout << "destruction Losange "<< endl; }

