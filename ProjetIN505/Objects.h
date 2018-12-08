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
		int getHeight();
		int getDiameter();
		int getAltitude();
		Point getCenter();
		Forme* getForme();
		char getType();
		void printInfo();
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