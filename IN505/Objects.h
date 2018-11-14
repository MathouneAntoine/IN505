#ifndef OBJECTS_H
#define OBJECTS_H

#include "Forme.h"

class Objects : public Field
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
		Forme f;
		int life;
		int high;	
		int diameter;
	
};

#endif