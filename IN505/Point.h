#ifndef POINT_H
#define POINT_H
class Point
{
	private :
	int x;
	int y;
	
	public:
	Point();
	Point(int x, int y);
	Point(const Point &p);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void afficher();
	void cloner(const Point x);
	~Point();
	
};
#endif



