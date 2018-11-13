using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Rectangle.h"

//Si il existe une fct virtuelle pure -> classes abstraite (pas d'instences)
//protected class hérite on accès aux attributs privés de la classe
Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4): p1(p1.getx(),p1.gety()), p2(p2.getx(),p2.gety()), p3(p3.getx(),p3.gety()), p4(p4.getx(),p4.gety()){}

Rectangle::Rectangle(Rectangle& r)
{
	this->p1 = r.p1;
	this->p2 = r.p2;
	this->p3 = r.p3;
	this->p4 = r.p4;
}
void Rectangle::deplacer(double dx, double dy){ p1.deplacer(dx, dy); p2.deplacer(dx, dy); p3.deplacer(dx, dy); p4.deplacer(dx, dy);}

Rectangle::~Rectangle(){ cout << "destruction Rectangle "<< endl; }



void Rectangle::afficher()
{
	cout << "RECTANGLES => p1.x() = " << p1.getx() << " p1.y = " << p1.gety() <<"p2.x = " << p2.getx() << " p2.y = " << p2.gety() <<"p3.x = " << p3.getx() << " p3.y = " << p4.gety() << p4.getx() << " p4.y = " << p4.gety() << endl;
}


