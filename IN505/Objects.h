#ifndef OBJECTS_H
#define OBJECTS_H

#include "./mesformes/Forme.h"
#include "./mesformes/Point.h"
#include "Field.h"
#include <iostream>

class Objects
{
	public:
		Objects();
		int getLife();
		int getHigh();
		int getDiameter();
		void printInfo();
		virtual void print()=0;
		~Objects();

	protected:
		Forme * f;
		int life;
		int high;
		int diameter;
		Point center;

};

#endif
