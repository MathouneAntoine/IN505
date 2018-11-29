#ifndef OBJECTS_H
#define OBJECTS_H

#include "mes_formes.h"
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
		virtual ~Objects();
		
	protected:
		Forme * f;
		int life;
		int high;	
		int diameter;
		Point center;

		
	
};

#endif