using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Triangle.h"
//Si il existe une fct virtuelle pure -> classes abstraite (pas d'instences)
//protected class hérite on accès aux attributs privés de la classe

Triangle::Triangle(Point p1, Point p2, Point p3): p1(p1.getx(),p1.gety()),p2(p2.getx(),p2.gety()),p3(p3.getx(),p3.gety()){}

Triangle::Triangle(Triangle& pc)
{
	this->p1 = pc.p1;
	this->p2 = pc.p2;
	this->p3 = pc.p3;
}
void Triangle::deplacer(double dx, double dy){ p1.deplacer(dx, dy); p2.deplacer(dx, dy); p3.deplacer(dx, dy); }
void Triangle::afficher()
{
	cout << "TRIANGLE => p1.x = " << p1.getx() << " p1.y = " << p1.gety() <<"p2.x = " << p2.getx() << " p2.y = " << p2.gety() <<"p3.x() = " << p3.getx() << " p3.y = " << p3.gety() << endl;
}

Triangle::~Triangle(){ cout << "destruction Triangle " << x << " " << y << endl; }

