#include <iostream>
#include <time.h>
#include "Tree.h"
#include "Objects.h"
#include "mes_formes.h"


using namespace std;

Tree::Tree()
{
	int i= rand()%2;
	if(i==0)
	{
		Point p1(15,20); 
		Point p2(10,10); 
		Point p3(20,10);
		this->f= new Triangle(p1,p2,p3);
		this->type='T';
	}
	if(i==1)
	{
		this->f = new Cercle(Point(10,10),10);
		this->type='C';
	}
	
	this->height=10;	
	this->diameter=20;
	this->altitude=50;
	this->life=(altitude/4)+(height+diameter);
}

Tree::Tree(Tree& t)
{
	if (t.type=='T') {this->f= new Triangle(t.getCenter(),t.diameter,t.height);}
	if (t.type=='C')	{this->f = new Cercle(t.getCenter(),t.diameter);}
	if (t.type!='C' && t.type!='T') {cout << "erreur construction arbre : type non reconnu";}
	this->type=t.type;
	this->life=t.life;
	this->height=t.height;	
	this->diameter=t.diameter;
	this->altitude=t.altitude;
}

Tree::Tree(Field* field, int height, int diameter, int altitude, int FromCenterX, int FromCenterY)
{
	this->center.setX(FromCenterX + field->getCenter().getX());
	this->center.setY(FromCenterY + field->getCenter().getY());

	int i= rand()%2;
	if(i==0)
	{
		this->f= new Triangle(this->center,diameter,height);
		this->type='T';
	}
	if(i==1)
	{
		this->f = new Cercle(this->center,diameter);
		this->type='C';
	}

	this->height=height;
	this->diameter=diameter;
	this->altitude=altitude;
	this->life=(altitude/4)+(height+diameter);	
}

Tree::Tree(char t, Point center, int height, int diameter, int altitude, int life)
{
	this->center.setX(center.getX());
	this->center.setY(center.getY());
	this->type=type;

	if (t=='T') {this->f= new Triangle(this->center,diameter,height);}
	if (t=='C')	{this->f = new Cercle(this->center,diameter);}
	if (t!='C' && t!='T') {cout << "erreur construction arbre : type non reconnu";}

	this->height=height;	
	this->diameter=diameter;
	this->altitude=altitude;
	this->life=life;	

}

Tree::Tree(Point center)
{
	this->center.setX(center.getX());
	this->center.setY(center.getY());

	this->diameter=rand()%100+60;
	this->height=rand()%100+60;
	this->altitude=rand()%150+80;

	int i= rand()%2;
	if(i==0)
	{
		this->f= new Triangle(this->center,this->diameter,this->height);
		this->type='T';
	}
	if(i==1)
	{
		this->f = new Cercle(this->center,this->diameter);
		this->type='C';
	}
}

void Tree::print()
{
	std::cout <<  "TREE" << std::endl;
}

Tree::~Tree()
{
 delete this->f;
}