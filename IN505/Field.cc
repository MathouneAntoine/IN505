#include "Field.h"
#include "./mesformes/Point.h"
#include<iostream>

using namespace std;

Field::Field()
{
	this->center.setX(400);
	this->center.setY(300);
	this->width=800;
	this->height=600;
}

Field::Field( int heigth, int width)
{
	this->center.setX(width/2);
	this->center.setY(heigth/2);
	this->width=width;
	this->height=height;
}

Point Field::getCenter()
{return this->center;}

int Field::getHeight()
{return this->height;}

int Field::getWidth()
{return this->width;}

void Field::print()
{
	cout << "Largeur : " << this->width << endl;
	cout << "Hauteur : " << this->height << endl;
	cout << "Centre : x: " << this->center.getX()<< " y: " << this->center.getY() << endl;
}


Field::~Field()
{}
