#include <iostream>	
#include <time.h>
#include "Rock.h"
#include "Objects.h"
#include "mes_formes.h"

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

Rock::Rock(Point center)
{
	this->center.setX(center.getX());
	this->center.setY(center.getY());

	this->diameter=rand()%100+60;
	this->height=rand()%100+60;
	this->altitude=rand()%150+80;

	int i= rand()%2;
	if(i==0)
	{
		this->f= new Rectangle(this->center,this->diameter,this->height);
	}
	if(i==1)
		this->f = new Losange(this->center,this->diameter,this->height);
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

Rock::~Rock()
{
	delete this->f;
}