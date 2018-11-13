#ifndef FORME_h
#define FORME_h
#include "Point.h"


class Forme
{
	protected:
		Point centre;
		int color;	
	public:
		virtual void deplacer(double dx, double dy);
		virtual void afficher();
		void setCentre(Point p);
		void setColor(int col);
		~Forme();
};
#endif



