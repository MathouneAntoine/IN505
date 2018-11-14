#include "Point.h"

	Point::Point()
	{
		x = 50;
		y = 100;
	}

	Point::Point(int a, int b)
	{
		x = a;
		y = b;
	}

	Point::Point(const Point &p)
	{
		this->x=p.x;
		this->y=p.y;
	}

	void Point::clone(const Point &p)
	{
		this->x=p.x;
		this->y=p.y;
	}

	int Point::getX()
	{
		return this->x;
	}

	int Point::getY()
	{
		return this->y;
	}

	void Point::setX(int const x)
	{
		this->x=x;
	}

	void Point::setY(int const y)
	{
		this->y=y;
	}

	Point::~Point()
	{}