#include <iostream>
#include "Objects.h"
#include "./mesformes/Forme.h"

using namespace std;

Objects::Objects()
{}

int Objects::getLife()
{
	return this->life;
}

int Objects::getHigh()
{
	return this->high;
}

int Objects::getDiameter()
{
	return this->diameter;
}

void Objects::printInfo()
{
	cout<<"Point de vie : "<< this->life << "  Hauteur : " << this->high << "  Diametre : " << this->diameter <<endl;
}

Objects::~Objects()
{}
