#include <iostream>
#include "Objects.h"
#include "mes_formes.h"

using namespace std;

Objects::Objects()
{}

int Objects::getLife()
{
	return this->life;
}

void Objects::setLife(int life)
{
	this->life = life;
}
int Objects::getHeight()
{
	return this->height;
}

int Objects::getDiameter()
{
	return this->diameter;
}

int Objects::getAltitude()
{
	return this->altitude;
}

Point Objects::getCenter()
{
	return this->center;
}

char Objects::getType()
{
	return this->type;
}

Forme* Objects::getForme()
{
	return this->f;
}

void Objects::printInfo()
{
	cout<< endl <<" Height : "<< this->height << "  Diameter : "
		 << this->diameter << "  Altitude : " << this->altitude<< " Life : " << this->life <<endl;
	cout << "center X : " << center.getX() << " center Y : " << center.getY() << endl;
}

void Objects::print()
{
	cout<<"undefined"<<endl;
}

Objects::~Objects()
{
	delete this->f;
}
