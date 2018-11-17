using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Forme.h"

void Forme::deplacer(int dx, int dy)
{
	centre.setX(centre.getX()+dx);
	centre.setY(centre.getY()+dy);

}
void Forme::setCentre(Point p)
{
	centre.setX(p.getX());
	centre.setY(p.getY());
}

void Forme::setColor(int col)
{
	this->color=col;
}
void Forme::afficher(){}


Forme::~Forme(){ cout << "destruciton Forme " << endl; }
