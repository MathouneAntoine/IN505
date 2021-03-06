#include <iostream>
#include <time.h>
#include "Tree.h"
#include "Objects.h"
#include "mes_formes.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
using namespace std;

Tree::Tree()
{
    int i = rand() % 2;
    if (i == 0) {
	Point p1(10, 10);
	Point p2(40, 10);
	Point p3(25, 60);
	this->f = new Triangle(p1, p2, p3);
	this->type = 'T';
    }
    if (i == 1) {
	this->f = new Cercle(Point(10, 10), 10);
	this->type = 'C';
    }

    this->height = 50;
    this->diameter = 30;
    this->altitude = 50;
    this->life = (altitude / 4) + ((height + diameter) / 4);
}

Tree::Tree(Tree & t)
{
    if (t.type == 'T') {
	this->f = new Triangle(t.getCenter(), t.diameter, t.height);
    }
    if (t.type == 'C') {
	this->f = new Cercle(t.getCenter(), t.diameter);
    }
    if (t.type != 'C' && t.type != 'T') {
	cout << "erreur construction arbre : type non reconnu";
    }
    this->type = t.type;
    this->life = t.life;
    this->height = t.height;
    this->diameter = t.diameter;
    this->altitude = t.altitude;
}

Tree::Tree(Field * field, int height, int diameter, int altitude,
	   int FromCenterX, int FromCenterY)
{
    this->center.setX(FromCenterX + field->getCenter().getX());
    this->center.setY(FromCenterY + field->getCenter().getY());

    int i = rand() % 2;
    if (i == 0) {
	this->f = new Triangle(this->center, diameter, height);
	this->type = 'T';
    }
    if (i == 1) {
	this->f = new Cercle(this->center, diameter);
	this->type = 'C';
    }

    this->height = height;
    this->diameter = diameter;
    this->altitude = altitude;
    this->life = (altitude / 4) + ((height + diameter) / 4);
}

Tree::Tree(char t, Point center, int height, int diameter, int altitude,
	   int life)
{
    this->center.setX(center.getX());
    this->center.setY(center.getY());
    this->type = type;

    if (t == 'T') {
	this->f = new Triangle(this->center, diameter, height);
    }
    if (t == 'C') {
	this->f = new Cercle(this->center, diameter);
    }
    if (t != 'C' && t != 'T') {
	cout << "erreur construction arbre : type non reconnu";
    }

    this->height = height;
    this->diameter = diameter;
    this->altitude = altitude;
    this->life = life;

}

Tree::Tree(Point center)
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
    this->life = (altitude / 4) + ((height + diameter) / 4);

    int i = rand() % 2;
    if (i == 0) {
	this->f = new Triangle(this->center, this->diameter, this->height);
	this->type = 'T';
    }
    if (i == 1) {
	this->f = new Cercle(this->center, this->diameter);
	this->type = 'C';
    }
}

void
 Tree::print_Tree()
{
    std::cout << "TREE" << std::endl;
    this->f->afficher();
}

void Tree::print(Field f)
{
    if (Triangle * tria = dynamic_cast < Triangle * >(this->getForme())) {
	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
	glVertex2i(tria->getP1().getX() + (f.getWidth() / 2),
		   tria->getP1().getY() + (f.getHeight() / 2));
	glVertex2i(tria->getP2().getX() + (f.getWidth() / 2),
		   tria->getP2().getY() + (f.getHeight() / 2));
	glVertex2i(tria->getP3().getX() + (f.getWidth() / 2),
		   tria->getP3().getY() + (f.getHeight() / 2));
	glEnd();

    } else if (Cercle * cerc = dynamic_cast < Cercle * >(this->getForme())) {
	GLfloat x = cerc->getCenter().getX() + (f.getWidth() / 2);
	GLfloat y = cerc->getCenter().getY() + (f.getHeight() / 2);
	GLfloat radius = this->diameter / 2;
	int i;
	int triangleAmount = 1000;
	float PI = 3.14;
	GLfloat twicePi = 2.0f * PI;
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(5.0);

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	for (i = 0; i <= triangleAmount; i++) {
	    glVertex2f(x, y);
	    glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
		       y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();

    }
}

Tree::~Tree()
{
    delete this->f;
}
