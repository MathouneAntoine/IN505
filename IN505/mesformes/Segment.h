#ifndef Segment_h
#define Segment_h

#include "Point.h"

class Segment
{
	private:
		Point p1;
		Point p2;
		
	public:
		Segment();
		Segment(Point const& p, const double x, const double y);
		~Segment(); //un destructeur ne se surcharge pas.
		double longueur();
		bool estHorizontal();
		bool estVertical();
		bool estSurDiagonal();
};
#endif
