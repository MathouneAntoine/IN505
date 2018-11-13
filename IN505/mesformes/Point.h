#ifndef Point_h
#define Point_h
class Point
{
	protected:
		double x;
		double y;
		
	public:
		

		Point();
		Point(double x, double y);
		Point(const Point& p);
		void deplacer(double dx, double dy);

		~Point();
		double getx();
		double gety();
		void setx(double x);
		void sety(double y);

		void afficher();
		void cloner(const Point& p);

};
#endif



