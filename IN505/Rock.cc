#include <iostream>
#include <time.h>
#include "Rock.h"
#include "Objects.h"
#include "mes_formes.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

Rock::Rock()
{
	Point p1(20,20);
	Point p2(30,20);
	Point p3(20,10);
	Point p4(30,10);
	int i= rand();
	if(i==0)
		this->f= new Rectangle(p1,p2,p3,p4);
	if(i==1)
	{
		p2.setX(10);
		p2.setY(15);
		p3.setY(15);
//		this->f= new Losange(p1,p3,p2,p4);
	}

	this->life=20;
	this->high=20;
	this->diameter=10;
	this->depth=10;
}

Rock::Rock(Field* field,int life, int high, int diameter, int depth, int FromCenterX, int FromCenterY)
{
	Point center(FromCenterX + field->getCenter().getX(), FromCenterY + field->getCenter().getY());

	//int i= rand(0,2);
	//if(i==0)
		this->f= new Rectangle(center,diameter,depth);
	/*if(i==1)
		this->f= new Triangle(p1,p2,p3);*/
	this->life=life;
	this->high=high;
	this->diameter=diameter;
	this->depth=depth;
}

Rock::Rock(Forme* f,int life, int high, int diameter, int depth)
{
	this->f= f;
	this->life=life;
	this->high=high;
	this->diameter=diameter;
	this->depth=depth;
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
void Rock::print_Rectangle()
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
    Rectangle *rect= dynamic_cast <Rectangle*> (this->getForme());
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
    glDisable(GL_TEXTURE_2D);

}

void Rock::print_Triangle()
{
        Triangle *tria= dynamic_cast <Triangle*> (this->getForme());

    glBegin(GL_TRIANGLES);
        glColor3f(0.5, 0.5, 0.5);
        //glVertex2i(tria->getP1().getX(),tria->getP1().getY());
        //glVertex2i(tria->getP2().getX(),tria->getP2().getY());
        //glVertex2i(tria->getP3().getX(),tria->getP3().getY());

    glEnd();
}
Rock::~Rock()
{}

