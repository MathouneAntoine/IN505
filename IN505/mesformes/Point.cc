using namespace std;
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

//double constant
Point::Point(const double x, const double y)
{
	//Pour un type X donne, this est de type X* (pointeur sur X) d'ou la fleche
	//this leve l'ambiguite avec le parametre de la methodes
	this->x = x;
	this->y = y;
}

//référence sur un point constant
Point::Point(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
}
void Point::deplacer(double dx, double dy){ x += dx; y += dy; }

Point::~Point(){ cout << "destruciton point " << x << " " << y << endl; }
double Point::getx(){ return x; }
double Point::gety(){ return y; }
void Point::setx(double x){this->x = x;}
void Point::sety(double y){this->y = y;}

void Point::afficher()
{
	cout << "x = " << x << " y = " << y << endl;
}

void Point::cloner(const Point& p)
{
	this->x = p.x;
	this->y = p.y;
}

//classe composée : au moins un membre est lui-meme un objet d'une classe