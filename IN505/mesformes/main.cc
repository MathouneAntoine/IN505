using namespace std ;
#include <iostream>
#include "Point.h"
#include "PointColor.h"
#include "Segment.h"
#include "Triangle.h"
#include "Rectangle.h"

int main()
{
	Point *p1 = new Point(); //Allocation dynamique
	Point p2(2.4, 3);
	Point p4(2.4, 3);
	Point p3(*p1);
	
	p1->afficher();
	p1->cloner(p2);
	p1->afficher();
	
	Point& p = *p1;
	Segment *s1 = new Segment();
	Segment s2; //on initialise sans parentheses pour un objet statique avec le constructueur vide
	//Segment s2 = Point(); marche aussi
	Segment *s3 = new Segment(p, 0.3, 5);
	Segment s4(p, 0.3, 5);
	
	cout << "longueur " << s1->longueur() << endl;
	cout << "longueur " << s2.longueur() << endl; 
	cout << "longueur " << s3->longueur() << endl;
	cout << "longueur " << s4.longueur() << endl;
	
	cout << s1->estHorizontal() << endl; //1
	cout << s3->estHorizontal() << endl; //0
	cout << s1->estVertical() << endl; //1
	cout << s1->estSurDiagonal() << endl; //1
	PointColor().afficher();
	Triangle(p2,p3,p4).afficher();
	Rectangle(p2,p3,p4,p4).afficher();
	delete p1; //liberation de la memoire allouee (car utilisation de new, objets dynamiques)
	//p2, p3 appel automatique du destructeur (objets statiques)
	delete s1;
	delete s3;

	Point p5(2.4, 3);
	    Point p6(1, 2);
	    Point p7(3, 6);
	    Point p8(8, 8);

	for(int i =0;i<5;i++)
	{
		Triangle(p6,p7,p8).afficher();
	    Rectangle(p6,p7,p8,p5).afficher();
	}
	//au total destruction de 3 points + 4segments + les 8 points des segments
	return 0;
}
