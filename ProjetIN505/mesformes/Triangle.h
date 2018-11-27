#ifndef Triangle_h
#define Triangle_h

#include "Point.h"
#include "Forme.h"


class Triangle:public Forme
{
	private:
		Point p1;
		Point p2;
		Point p3;	
		
	public:
		Triangle();
		Triangle(Point p1, Point p2, Point p3);
		Triangle(Triangle& pc);
		void deplacer(int dx, int dy);
		void afficher();
		void cloner(const Point& p);
		~Triangle();
};
#endif



