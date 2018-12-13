#include <iostream>
#include <time.h>
#include "Rock.h"
#include "Objects.h"
#include "mes_formes.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;


Rock::Rock()
{
	Point p1(20,60);
	Point p2(20,10);
	Point p3(50,10);
	Point p4(50,60);

	int i= rand()%2;
	i=1;
	if(i==0)
	{
		this->f= new Rectangle(p1,p2,p3,p4);
		this->center.setX((p1.getX()-p2.getX()));
		this->center.setY((p1.getY()-p3.getY()));
	}

	if(i==1)
	{
		p2.setX(10);
		p2.setY(15);
		p3.setY(15);
		this->f= new Losange(p1,p3,p2,p4);
	}

	this->height=20;
	this->diameter=10;
	this->altitude=30;
	this->life=(altitude/2)+diameter+height;
}

Rock::Rock(Field* field, int height, int diameter, int altitude, int FromCenterX, int FromCenterY)
{
	this->center.setX(FromCenterX + field->getCenter().getX());
	this->center.setY(FromCenterY + field->getCenter().getY());

	int i= rand()%2;
    i=0;

	if(i==0) this->f= new Rectangle(this->center,diameter,height);
	if(i==1) this->f= new Losange(center,diameter,height);

	this->height=height;
	this->diameter=diameter;
	this->life=(altitude/2)+diameter+height;

}

Rock::Rock(int height, int diameter, int altitude, Point center)
{
	this->center.setX(center.getX());
	this->center.setY(center.getY());

	int i= rand()%2;
    i=0;
	if(i==0) this->f= new Rectangle(this->center,diameter,height);
	if(i==1) this->f= new Losange(center,diameter,height);

	this->height=height;
	this->diameter=diameter;
	this->altitude=altitude;
	this->life=(altitude/2)+diameter+height;
}

Forme* Rock::getForme()
{
	return this->f;
}

void Rock::print_Rock()
{
	cout <<  "ROCK" << endl;
	this->f->afficher();
}

void Rock::print()
{
    if(Rectangle *rect= dynamic_cast <Rectangle*> (this->getForme()))
    {
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
       glTexCoord2d(0,1);
        glVertex2i(rect->getP1().getX(),rect->getP1().getY());
       glTexCoord2d(0,0);
        glVertex2i(rect->getP2().getX(),rect->getP2().getY());
     glTexCoord2d(1,0);
        glVertex2i(rect->getP3().getX(),rect->getP3().getY());
     glTexCoord2d(1,1);
        glVertex2i(rect->getP4().getX(),rect->getP4().getY());

    glEnd();
//glFlush();


    }
    else if(Losange *losa= dynamic_cast <Losange*> (this->getForme()))
    {
    cout <<"ici"<<endl;
    glBegin(GL_QUADS);
            glColor3ub(255,0,0);
        //glTexCoord2d(0,1);
        glVertex2i(losa->getP1().getX(),losa->getP1().getY());
      //  glTexCoord2d(0,0);
        glVertex2i(losa->getP2().getX(),losa->getP2().getY());
      //  glTexCoord2d(1,0);
        glVertex2i(losa->getP3().getX(),losa->getP3().getY());
      //  glTexCoord2d(1,1);
        glVertex2i(losa->getP4().getX(),losa->getP4().getY());
    glEnd();

    }
    //glFlush();
}

Rock::~Rock()
{}

