#ifndef DEF_SEGMENT
#define DEF_SEGMENT

#include "Forme.h"
#include "Point.h"

class Segment : public Forme
{
	public :

	Segment();
	Segment(Point& a, Point& b);
	Segment(int a, int b, int c, int d);
	Point& getP();
	Point& getQ();
	void afficher();
	void deplacer(int x, int y);
	~Segment();

	protected :

		Point p;
		Point q;
};

#endif
