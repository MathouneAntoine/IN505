#include <vector>
#include <iostream>
#include <math.h>

#include "Character.h"
#include "../mes_formes.h"
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "../Objects.h"
using namespace std;
Character::Character()
{
    Point p(50,50);
	int o = rand()%4;
	if(o == 0) {this->orientation = 0;}
	if(o == 1) {this->orientation = 90;}
	if(o == 2) {this->orientation = 180;}
	if(o == 3) {this->orientation = 270;}

	this->pv = 100;
	this->weaponDamage = 50;
	this->weaponRange= 5;
    this->cerc = new Cercle();
}

Character::Character(Point p)
{
 	this->p.setX(p.getX());
 	this->p.setY(p.getY());
	this->orientation = 0;
	this->pv = 100;
	this->weaponDamage = 50;
	this->weaponRange= 5;
	this->cerc = new Cercle(this->p,20);
}

void Character::print(Field f)
{
	cout << "Character" << endl;
    GLfloat x =cerc->getCenter().getX()+f.getWidth() ;
    GLfloat y =cerc->getCenter().getY()+f.getHeight();
    GLfloat radius = cerc->getDiametre()/2;
    int i;
    int triangleAmount = 1000;
    float PI =3.14;
    GLfloat twicePi = 2.0f * PI;
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);

    glBegin(GL_LINES);
        glColor3f(1,1, 0);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void Character::PrintInfo()
{
	cout << "Position.x = " << this->p.getX()<< "Position.y = " << this->p.getY() << endl;
	cout << "Orientation = " << this->orientation << "°" << endl;
	cout << "PV = " << this->pv << endl;
	cout << "weaponDamage = " << this->weaponDamage << endl;
	cout << "weaponRange = " << this->weaponRange << endl;
}


Cercle* Character::getForme()
{
    return this->cerc;
}
float sign (Point P1, Point P2, Point P3)
{
    return (P1.getX() - P3.getX()) * (P2.getY() - P3.getY()) - (P2.getX() - P3.getX()) * (P1.getY() - P3.getY());
}

bool inTriangle (Point pt, Point P1, Point P2, Point P3)
{
    float d1, d2, d3;
    bool negative, positive;

    d1 = sign(pt, P1, P2);
    d2 = sign(pt, P2, P3);
    d3 = sign(pt, P3, P1);

    negative = (d1 < 0) || (d2 < 0) || (d3 < 0);
    positive = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(negative && positive);
}	
bool Character::collisionObjet(int curseur_x,int curseur_y, vector<Objects*> objet ) {     
    
    for(int unsigned i=0; i < objet.size();i++)
        {
            Objects* obj;
            obj=objet[i];
            //objet[0]->printInfo();
            if(Rectangle *rect= dynamic_cast <Rectangle*> (obj->getForme()))
            {
            	 cout <<"COLISION = " << endl;
            	 obj->printInfo();

                 if (curseur_x >= rect->getP1().getX() 
                && curseur_x <  rect->getP4().getX()
                && curseur_y >= rect->getP2().getY()  
                && curseur_y < rect->getP1().getY())
                   return true;
            }	

            else if(Cercle *cerc= dynamic_cast <Cercle*> (obj->getForme()))
            {    

             	int dist = sqrt( pow((cerc->getCenter().getX() - curseur_x),2) + (pow((cerc->getCenter().getY() - curseur_y),2)));
   				 return dist <= cerc->getDiametre()/2;
                  // return false;
            }

            else if(Losange *losa= dynamic_cast <Losange*> (obj->getForme()))
            {
                  Point pt ( curseur_x, curseur_y);

            	return (inTriangle (pt, losa->getP1(),losa->getP2(),losa->getP3()) ||  inTriangle (pt,losa->getP3(),losa->getP4(),losa->getP1()));
            }
            else if(Triangle *tria= dynamic_cast <Triangle*> (obj->getForme()))
            {
            	Point pt ( curseur_x, curseur_y);

            	return inTriangle(pt, tria->getP1(),tria->getP2(),tria->getP3());
            }
    }
    cout << "True" <<  endl;
    return true;
}

bool Character::collision(int x, int y, vector<Objects*> obj)
{
    if(x < 800 && x > 0 && y < 600 && y > 0 && !collisionObjet( x,y,obj) )
        return true;
    else
        return false;
}

Character::~Character()
{


}
