#ifndef Rectangle_h
#define Rectangle_h
#include "Point.h"


class Rectangle: public Point
{
	private:
		Point p1;
		Point p2;
		Point p3;		
		Point p4;

	public:
		Rectangle(Point p1, Point p2, Point p3, Point p4);
		Rectangle(Rectangle& r);
		void deplacer(int dx, int dy);

		~Rectangle();
		void afficher();
		
};
#endif



