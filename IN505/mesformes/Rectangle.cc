using namespace std;
#include <iostream>
#include "Point.h"
#include "Rectangle.h"

/* p1 en haut à gauche, p2 en haut à droite, p3 en bas à gauche, p4 en bas à droite  */


Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4): p1(p1), p2(p2), p3(p3), p4(p4){}

Rectangle::Rectangle(Rectangle& r)
{
	this->p1 = r.p1;
	this->p2 = r.p2;
	this->p3 = r.p3;
	this->p4 = r.p4;
}
void Rectangle::deplacer(int dx, int dy)
{ 
	p1.deplacer(dx, dy); 
	p2.deplacer(dx, dy);
	p3.deplacer(dx, dy); 
	p4.deplacer(dx, dy);
}

void Rectangle::afficher()
{
	cout <<"RECTANGLE :" <<endl;
	cout <<" p1.x() = " << p1.getX() << " p1.y = " << p1.getY()<<endl;
	cout <<"p2.x = " << p2.getX() << " p2.y = " << p2.getY() << endl;
	cout <<"p3.x = " << p3.getX() << " p3.y = " << p3.getY() <<endl;
	cout <<"p4.x = " << p4.getX() << " p4.y = " << p4.getY() << endl;
}

Rectangle::~Rectangle()
{ cout << "destruction Rectangle "<< endl; }

