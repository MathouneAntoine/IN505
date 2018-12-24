#include "Character.h"
#include "../mes_formes.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "../Forest.h"

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

Character::~Character()
{


}
