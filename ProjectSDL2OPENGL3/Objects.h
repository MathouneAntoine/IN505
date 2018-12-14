#ifndef OBJECTS_H
#define OBJECTS_H

#include "./mesformes/Point.h"
#include "Field.h"
#include <iostream>

class Objects
{
	public:
		Objects();
		int getLife();
		int getHeight();
		int getDiameter();
		int getAltitude();
		Point getCenter();
		Forme* getForme();
		char getType();
		void printInfo();
		virtual void print();
		virtual ~Objects();

	protected:
		Forme * f;
		int life;
		int height;
		int diameter;
		int altitude;
		char type;

		Point center;
};

#endif
