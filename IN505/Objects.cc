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

void Objects::printInfo()
{
	cout<<"Point de vie : "<< this->life << "  Hauteur : " << this->height << "  Diametre : " << this->diameter <<endl;
}

Objects::~Objects()
{}
