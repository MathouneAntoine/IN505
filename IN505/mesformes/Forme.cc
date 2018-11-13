using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Forme.h"

void Forme::deplacer(double dx, double dy)
{
	centre.setx(centre.getx()+dx);
	centre.sety(centre.gety()+dy);

}
void Forme::setCentre(Point p)
{
	centre.setx(p.getx());
	centre.sety(p.gety());
}

void Forme::setColor(int col)
{
	this->color=col;
}
void Forme::afficher(){}


Forme::~Forme(){ cout << "destruciton Forme " << endl; }
