#include "Point.h"

Point::Point()
	{
		this->x = 0;
		this->y = 0;
	}
Point::Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
Point::Point(const Point &p)
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
void Point::setX(int x)
	{
		this->x =x; 
	}	
void Point::setY(int y)
	{
		this->y = y; 
	}	


void Point::afficher()
	{
		//std::cout << this->x << this->y << std::endl;
	}
	
void Point::cloner(const Point X)
	{
			this->x = X.x;
			this->y = X.y;
	}

Point::~Point()
	{
		//std::cout << "appel au destructeur" << std::endl;
	}
	
