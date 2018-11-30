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
		Triangle(Point center,int diameter, int high);
		Triangle(Triangle& pc);
		void afficher();
		void cloner(const Point& p);
<<<<<<< HEAD
		Point getP1();
        Point getP2();
        Point getP3();



=======
>>>>>>> ee00255256108fac5d405208d5fdc777a9bee254
		~Triangle();
};
#endif



