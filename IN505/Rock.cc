#include <iostream>
#include <time.h>
#include "Rock.h"
#include "Objects.h"
#include "mes_formes.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

using namespace std;


Rock::Rock()
{
	Point p1(20,60);
	Point p2(20,10);
	Point p3(50,10);
	Point p4(50,60);

	int i= rand()%2;
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

	if(i==0) this->f= new Rectangle(center,diameter,height);
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

	if(i==0) this->f= new Rectangle(center,diameter,height);
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

void Rock::print()
{
	cout <<  "ROCK" << endl;
	this->f->afficher();
}

void Rock::print_Rock()
{
/*
unsigned int texture;
glGenTextures(1, &texture);
glBindTexture(GL_TEXTURE_2D, texture);
// set the texture wrapping/filtering options (on the currently bound texture object)
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// load and generate the texture
int width, height, nrChannels;
unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
if (data)
{
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}
else
{
    std::cout << "Failed to load texture" << std::endl;
}
stbi_image_free(data);*/
/*int width, height, nrChannels;

width =830;
height = 710;

   glEnable(GL_TEXTURE_2D);
   GLuint texture;
   texture = loadTexture("MAVERICK", width, height);
    glBindTexture(GL_TEXTURE_2D, texture);

        glGenTextures(1, &texture);
       glBindTexture(GL_TEXTURE_2D, texture);
//        stbi_image_free(texture);


 // draw stuff here

        // render container


     glLoadIdentity;
   glTranslatef(-5, 0, -15);
   glBindTexture(GL_TEXTURE_2D, texture);
*/

    if(Rectangle *rect= dynamic_cast <Rectangle*> (this->getForme()))
    {
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
//        glBindTexture(GL_TEXTURE_2D, texture);
                glTexCoord2f(1, 0);

        glVertex2i(rect->getP1().getX(),rect->getP1().getY());
               glTexCoord2f(0, 0);

        glVertex2i(rect->getP2().getX(),rect->getP2().getY());
               glTexCoord2f(0, 1);

        glVertex2i(rect->getP3().getX(),rect->getP3().getY());
               glTexCoord2f(1, 1);

        glVertex2i(rect->getP4().getX(),rect->getP4().getY());
    glEnd();
    }
    else
    {
    Triangle *tria= dynamic_cast <Triangle*> (this->getForme());
    glBegin(GL_TRIANGLES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(tria->getP1().getX(),tria->getP1().getY());
        glVertex2i(tria->getP2().getX(),tria->getP2().getY());
        glVertex2i(tria->getP3().getX(),tria->getP3().getY());

    glEnd();

    }

    glDisable(GL_TEXTURE_2D);

}

void Rock::print_Triangle()
{
    Triangle *tria= dynamic_cast <Triangle*> (this->getForme());

    glBegin(GL_TRIANGLES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex2i(tria->getP1().getX(),tria->getP1().getY());
        glVertex2i(tria->getP2().getX(),tria->getP2().getY());
        glVertex2i(tria->getP3().getX(),tria->getP3().getY());

    glEnd();
}
Rock::~Rock()
{}

