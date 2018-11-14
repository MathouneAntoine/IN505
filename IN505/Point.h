#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point 
{
	public:
	Point();
	Point(int x, int y);
	Point(const Point &p);
	void clone(const Point &x);
	int getX();
	int getY();
	void setX(int const x);
	void setY(int const y);
	void print();
	~Point();

	private :
	int x;
	int y;
	
};

#endif