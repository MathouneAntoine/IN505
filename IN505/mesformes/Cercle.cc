using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Cercle.h"
//Si il existe une fct virtuelle pure -> classes abstraite (pas d'instences)
//protected class hérite on accès aux attributs privés de la classe

Cercle::Cercle(Point p, int diam): p(p.getx(),p.gety())
{
	this->diametre = diam; 
}

Cercle::Cercle(Cercle& c)
{
	this->p = c.p;
	this->diametre = c.diametre;
}
void Cercle::deplacer(double dx, double dy){ p.deplacer(dx, dy); }
void Cercle::afficher()
{
	cout << "Cercle => p.x = " << p.getx() << " p.y = " << p.gety() << endl;
}

Cercle::~Cercle(){ cout << "destruction Cercle " << x << " " << y << endl; }

