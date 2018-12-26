#ifndef Losange_h
#define Losange_h
#include "Forme.h"
#include "Point.h"


/*
  	 .P1.
  	.    .				  			  ^
 P4.center .p2 		depth(de p3 à p1) |
    .    .				  
  	 .p3.			diameter(de p4 à p2) -->

*/


class Losange: public Forme
{
	private:
		Point p1;
		Point p2;
		Point p3;		
		Point p4;

	public:
		Losange();
		Losange(Point p1, int diameter, int depth);
		Losange(Point p1, Point p2, Point p3, Point p4);
		Losange(Losange& r);
		Point getP1();
		Point getP2();
		Point getP3();
		Point getP4();
		Point getP5();
		Point getP6();
		Point getCenter();
		void deplacer(int dx, int dy);

		~Losange();
		void afficher();
		
};
#endif



