#include "Field.h"
#include "mes_formes.h"
#include <iostream>

using namespace std;

Field::Field()
{
    this->center.setX(400);
    this->center.setY(300);
    this->width = 800;
    this->height = 600;
}

Field::Field(int width, int height)
{
    this->center.setX(width / 2);
    this->center.setY(height / 2);
    this->width = width;
    this->height = height;
}

Point Field::getCenter()
{
    return this->center;
}

int Field::getHeight()
{
    return this->height;
}

int Field::getWidth()
{
    return this->width;
}

void Field::print()
{
    cout << endl << "Field : " << endl;
    cout << "Largeur : " << this->width << endl;
    cout << "Hauteur : " << this->height << endl;
    cout << "Centre : x: " << this->center.getX() << " y: " << this->
	center.getY() << endl;
}



Field::~Field()
{
}
