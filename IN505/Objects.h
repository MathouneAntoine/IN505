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
		void printInfo();
		virtual void print()=0;
		~Objects();

	protected:
		Forme * f;
		int life;
		int height;
		int altitude;
		int diameter;
		Point center;



};

#endif
