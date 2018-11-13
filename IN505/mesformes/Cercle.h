#ifndef Cercle_h
#define Cercle_h
#include "Point.h"


class Cercle:public Point
{
	private:
		Point p;
		int diametre;
	public:
		Cercle(Point p1, int diam);
		Cercle(Cercle &cer);
		void deplacer(double dx, double dy);
		void afficher();
		~Cercle();
};
#endif



