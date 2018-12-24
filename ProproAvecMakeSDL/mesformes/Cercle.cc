using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Cercle.h"
//Si il existe une fct virtuelle pure -> classes abstraite (pas d'instences)
//protected class hérite on accès aux attributs privés de la classe

Cercle::Cercle()
{
	this->center.setX(50);
	this->center.setY(50);
	this->diametre = 15;
}

Cercle::Cercle(Point p, int diam)
{
	this->center.setX(p.getX());
	this->center.setY(p.getY());
	this->diametre = diam;
}

Cercle::Cercle(Cercle& c)
{
	this->center = c.center;
	this->diametre = c.diametre;
}

int Cercle::getDiametre()
{
	return this->diametre;
}
void Cercle::deplacer(int dx, int dy)
{
	center.deplacer(dx, dy);
}
void Cercle::afficher()
{
    cout << "Cercle"<<endl;
	cout << " p.x = " << center.getX() << " p.y = " << center.getY() << endl;
}

Cercle::~Cercle(){ cout << "destruction Cercle " << endl; }

