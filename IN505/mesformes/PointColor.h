#ifndef PointColor_h
#define PointColor_h
#include "Point.h"

class PointColor:public Point
{
	private:
		int color;
		
	public:
		PointColor();
		PointColor(const double x, const double y, int col);
		PointColor(PointColor& p);
		PointColor(PointColor& pc, int col);
		~PointColor();
		int getcolor();
		void afficher();
		
		void cloner(const Point& p);
};
#endif



