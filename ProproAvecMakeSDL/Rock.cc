#include <iostream>
#include <time.h>
#include "Rock.h"
#include "Objects.h"
#include "mes_formes.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>

using namespace std;

Rock::Rock()
{
    Point p1(20, 60);
    Point p2(20, 10);
    Point p3(60, 10);
    Point p4(60, 60);

    int i = rand() % 2;
    if (i == 0) {
	this->f = new Rectangle(p1, p2, p3, p4);
	this->center.setX((p1.getX() - p3.getX()) / 2);
	this->center.setY((p1.getY() - p2.getY()) / 2);
	this->type = 'R';
    }

    if (i == 1) {
	p1.setX(70);
	p1.setY(75);
	p2.setX(90);
	p2.setY(50);
	p3.setX(70);
	p3.setY(25);
	p4.setX(50);
	p4.setY(50);

	this->center.setX(p1.getX());
	this->center.setY(p2.getY());
	this->f = new Losange(p1, p2, p3, p4);
	this->type = 'L';
    }

    this->height = 50;
    this->diameter = 40;
    this->altitude = 30;
    this->life = (altitude / 4) + (diameter / 4) + (height / 4);
}

Rock::Rock(Point center)
{
    this->center.setX(center.getX());
    this->center.setY(center.getY());

    this->diameter = rand() % 100 + 60;
    if (this->diameter % 2 != 0)
	this->diameter++;
    this->height = rand() % 100 + 60;
    if (this->height % 2 != 0)
	this->height++;
    this->altitude = rand() % 150 + 80;
    if (this->altitude % 2 != 0)
	this->altitude++;
    this->life = (altitude / 4) + (diameter / 4) + (height / 4);

    int i = rand() % 2;
    if (i == 0) {
	this->f =
	    new Rectangle(this->center, this->diameter, this->height);
	this->type = 'R';
    }
    if (i == 1) {
	this->f = new Losange(this->center, this->diameter, this->height);
	this->type = 'L';
    }
}

Rock::Rock(Field * field, int height, int diameter, int altitude,
	   int FromCenterX, int FromCenterY)
{
    this->center.setX(FromCenterX + field->getCenter().getX());
    this->center.setY(FromCenterY + field->getCenter().getY());

    int i = rand() % 2;

    if (i == 0) {
	this->f = new Rectangle(center, diameter, height);
	this->type = 'R';
    }
    if (i == 1) {
	this->f = new Losange(center, diameter, height);
	this->type = 'L';
    }

    this->height = height;
    this->diameter = diameter;
    this->life = (altitude / 4) + (diameter / 4) + (height / 4);
}

Rock::Rock(char t, Point center, int height, int diameter, int altitude,
	   int life)
{
    this->center.setX(center.getX());
    this->center.setY(center.getY());

    if (t == 'R')
	this->f = new Rectangle(center, diameter, height);
    if (t == 'L')
	this->f = new Losange(center, diameter, height);

    this->height = height;
    this->diameter = diameter;
    this->altitude = altitude;
    this->life = life;
    this->type = t;
}

void
 Rock::print_Rock()
{
    cout << "ROCK" << endl;
    this->f->afficher();
}

void Rock::print(Field f)
{
    if (Rectangle * rect = dynamic_cast < Rectangle * >(this->getForme())) {
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2i(rect->getP1().getX() + (f.getWidth() / 2),
		   rect->getP1().getY() + (f.getHeight() / 2));
	glVertex2i(rect->getP2().getX() + (f.getWidth() / 2),
		   rect->getP2().getY() + (f.getHeight() / 2));
	glVertex2i(rect->getP3().getX() + (f.getWidth() / 2),
		   rect->getP3().getY() + (f.getHeight() / 2));
	glVertex2i(rect->getP4().getX() + (f.getWidth() / 2),
		   rect->getP4().getY() + (f.getHeight() / 2));
	glEnd();
    } else if (Losange * losa =
	       dynamic_cast < Losange * >(this->getForme())) {
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2i(losa->getP1().getX() + (f.getWidth() / 2),
		   losa->getP1().getY() + (f.getHeight() / 2));
	glVertex2i(losa->getP2().getX() + (f.getWidth() / 2),
		   losa->getP2().getY() + (f.getHeight() / 2));
	glVertex2i(losa->getP3().getX() + (f.getWidth() / 2),
		   losa->getP3().getY() + (f.getHeight() / 2));
	glVertex2i(losa->getP4().getX() + (f.getWidth() / 2),
		   losa->getP4().getY() + (f.getHeight() / 2));
	glEnd();

    }
    glFlush();
}

Rock::~Rock()
{
}
