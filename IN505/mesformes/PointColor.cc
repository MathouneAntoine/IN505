using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "PointColor.h"
//Si il existe une fct virtuelle pure -> classes abstraite (pas d'instences)
//protected class hérite on accès aux attributs privés de la classe
PointColor::PointColor():color(0){};
PointColor::PointColor(const double x, const double y, int col):Point(x,y)
{
	color = col;
}

PointColor::PointColor(PointColor& pc)
{
	this->x = pc.getx();
	this->y = pc.gety();
	this->color = pc.getcolor();
}
PointColor::PointColor(PointColor& pc, int col)
{
	this->x = pc.getx();
	this->y = pc.gety();
	this->color = col;
}

PointColor::~PointColor(){ cout << "destruction PointColor " << x << " " << y << endl; }

int PointColor::getcolor()
{
	return this->color;
}

void PointColor::afficher()
{
	cout << "x = " << getx() << " y = " << gety() << "color =" << getcolor() << endl;
}


