#include <vector>
#include <iostream>


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

void Character::print()
{
	cout << "Character" << endl;
    GLfloat x =cerc->getCenter().getX() ;
    GLfloat y =cerc->getCenter().getY();
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

bool Character::colisionObjet(int curseur_x,int curseur_y, vector<Objects*> objet ) {     
    cout <<"Début size list objet = " << objet.size()<<  endl;
    
    for(int unsigned i=0; i < objet.size();i++)
        {
            Objects* obj;
            obj=objet[i];
            objet[0]->printInfo();
            if(Rectangle *rect= dynamic_cast <Rectangle*> (obj->getForme()))
            {
                 if (curseur_x >= rect->getP1().getX() 
                && curseur_x <  rect->getP4().getX()
                && curseur_y >= rect->getP2().getY()  
                && curseur_y < rect->getP1().getY())
                   return false;
            }

            else if(Cercle *cerc= dynamic_cast <Cercle*> (obj->getForme()))
            {
                 if (curseur_x >= cerc->getCenter().getX()- cerc->getDiametre()/2
                && curseur_x <   cerc->getCenter().getX()+ cerc->getDiametre()/2
                && curseur_y >=  cerc->getCenter().getY()- cerc->getDiametre()/2
                && curseur_y < cerc->getCenter().getY()+ cerc->getDiametre()/2)
                   return false;
            }

            else if(Losange *losa= dynamic_cast <Losange*> (obj->getForme()))
            {
                  if (curseur_x >= rect->getP4().getX() 
                && curseur_x <  rect->getP2().getX()
                && curseur_y >= rect->getP3().getY()  
                && curseur_y < rect->getP1().getY())
                   return false;
            }
            else if(Triangle *tria= dynamic_cast <Triangle*> (obj->getForme()))
            {
                if(tria->getOrientation()==0)
                {
                     if (curseur_x >= rect->getP2().getX() 
                && curseur_x <  rect->getP3().getX()
                && curseur_y >= rect->getP1().getY()  
                && curseur_y < rect->getP2().getY())
                   return false;


                }
                if(tria->getOrientation()==1)
                {
                    if (curseur_x >= rect->getP2().getX() 
                && curseur_x <  rect->getP1().getX()
                && curseur_y >= rect->getP3().getY()  
                && curseur_y < rect->getP2().getY())
                   return false;
                    
                }
                if(tria->getOrientation()==2)
                {
                    if (curseur_x >= rect->getP2().getX() 
                && curseur_x <  rect->getP3().getX()
                && curseur_y >= rect->getP1().getY()  
                && curseur_y < rect->getP2().getY())
                   return false;
                    
                }
                if(tria->getOrientation()==3)
                {
                    if (curseur_x >= rect->getP1().getX() 
                && curseur_x <  rect->getP2().getX()
                && curseur_y >= rect->getP3().getY()  
                && curseur_y < rect->getP2().getY())
                   return false;
                }
            }
    }
    cout << "True" <<  endl;
    return true;
}

bool Character::colision(int x, int y, vector<Objects*> obj)
{
    cout << "colisionObjet:" << colisionObjet( x,y,obj) <<endl;
    if(x < 800 && x > 0 && y < 600 && y > 0 && colisionObjet( x,y,obj) )
        return true;
    else
        return false;
}

Character::~Character()
{


}
