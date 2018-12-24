#ifndef Cercle_h
#define Cercle_h

#include "Point.h"
#include "Forme.h"

class Cercle: public Forme
{
	private:
		int diametre;
	public:
		Cercle();
		Cercle(Point p1, int diam);
		Cercle(Cercle &cer);
		void deplacer(int dx, int dy);
		void afficher();
		int getDiametre();
		~Cercle();
};
#endif



