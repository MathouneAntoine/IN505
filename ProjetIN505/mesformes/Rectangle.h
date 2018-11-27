#ifndef Rectangle_h
#define Rectangle_h
#include "Forme.h"
#include "Point.h"


/*
   P1-----P4
   |center|
   P2-----P3
*/


class Rectangle: public Forme
{
	private:
		Point p1;
		Point p2;
		Point p3;		
		Point p4;
		Point center;

	public:
		Rectangle();
		Rectangle(Point p1, int diameter, int depth);
		Rectangle(Point p1, Point p2, Point p3, Point p4);
		Rectangle(Rectangle& r);
		Point getP1();
		Point getP3();
		Point getCenter();
		void deplacer(int dx, int dy);

		~Rectangle();
		void afficher();
		
};
#endif


