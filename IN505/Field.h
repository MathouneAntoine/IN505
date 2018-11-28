#ifndef FIELD_H
#define FIELD_H

#include "mes_formes.h"

class Field
{
	public:
	
	Field();
	Field( int width, int height);
	Point getCenter();
	int getHeight();
	int getWidth();
	void print();
	~Field();

	private:

	Point center;
	int height; //y
	int width; //x
	
};

#endif