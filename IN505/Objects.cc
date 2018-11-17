#include <iostream>
#include "Objects.h"
#include "./Formes.h"
using namespace std;

Objects()
{}

int getLife()
{
	return this->life;
}

int getHigh()
{
	return this->high;
}

int getDiameter()
{
	return this->diameter;
}

void printInfo()
{
	cout<<"Point de vie : "<< this->life << "Hauteur : " << this->high << "Diametre : " << this->diameter <<endl;
}

~Objects()
{

}