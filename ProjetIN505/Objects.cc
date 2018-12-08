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
	cout<<"Point de vie : "<< this->life << "  Hauteur : " << this->height << "  Diametre : " << this->diameter <<endl;
}

Objects::~Objects()
{
	delete this->f;
}
