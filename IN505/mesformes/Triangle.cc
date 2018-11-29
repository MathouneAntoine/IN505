using namespace std;
#include <iostream>
#include "Point.h"
#include "Triangle.h"
//Si il existe une fct virtuelle pure -> classes abstraite (pas d'instences)
//protected class hérite on accès aux attributs privés de la classe

Triangle::Triangle(Point p1, Point p2, Point p3): p1(p1),p2(p2),p3(p3)
{}

Triangle::Triangle(Triangle& pc)
{
	this->p1 = pc.p1;
	this->p2 = pc.p2;
	this->p3 = pc.p3;
}
void Triangle::deplacer(int dx, int dy)
{
	p1.deplacer(dx, dy);
	p2.deplacer(dx, dy);
	p3.deplacer(dx, dy);
}

void Triangle::afficher()
{
	cout << "TRIANGLE => p1.x = " << p1.getX() << " p1.y = " << p1.getY()<< endl;
	cout << "p2.x = " << p2.getX() << " p2.y = " << p2.getY() <<endl;
	cout <<"p3.x() = " << p3.getX() << " p3.y = " << p3.getY() << endl;
}


Point Triangle::getP1()
{
	return this->p1;
}
Point Triangle::getP2()
{
	return this->p2;
}

Point Triangle::getP3()
{
	return this->p3;
}

Point Triangle::getCenter()
{
	return this->center;
}

Triangle::~Triangle(){ cout << "destruction Triangle " << endl; }

