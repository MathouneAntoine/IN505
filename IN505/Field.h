#ifndef FIELD_H
#define FIELD_H

#include "Point.h"

class Field
{
	public:
	
	Field();
	Field( int heigth, int width);
	Point getCenter();
	int getHeight();
	int getWidth();
	void print();
	~Field();

	protected:

	Point center;
	int height; //y
	int width; //x
	
};

#endif