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
	this->p.setX(50);
	this->p.setY(50);
	this->diametre = 15; 
}

Cercle::Cercle(Point p, int diam): p(p)
{
	this->diametre = diam; 
}

Cercle::Cercle(Cercle& c)
{
	this->p = c.p;
	this->diametre = c.diametre;
}
void Cercle::deplacer(int dx, int dy)
{ 
	p.deplacer(dx, dy);
}

void Cercle::afficher()
{
	cout << "Cercle => p.x = " << p.getX() << " p.y = " << p.getY() << endl;
}

Cercle::~Cercle(){ cout << "destruction Cercle " << endl; }

