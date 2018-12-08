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
		this->type='R';
	}
	
	if(i==1)
	{
		p2.setX(10);
		p2.setY(15);
		p3.setY(15);
		this->f= new Losange(p1,p3,p2,p4);
		this->type='L';
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
	if (this->diameter%2!=0) this->diameter++;
	this->height=rand()%100+60;
	if (this->height%2!=0) this->height++;
	this->altitude=rand()%150+80;
	if (this->altitude%2!=0) this->altitude++;
	this->life=(altitude/2)+diameter+height;

	int i= rand()%2;
	if(i==0)
	{
		this->f= new Rectangle(this->center,this->diameter,this->height);
		this->type='R';
	}
	if(i==1)
		{this->f = new Losange(this->center,this->diameter,this->height);
		this->type='L';}
}

Rock::Rock(Field* field, int height, int diameter, int altitude, int FromCenterX, int FromCenterY)	
{
	this->center.setX(FromCenterX + field->getCenter().getX());
	this->center.setY(FromCenterY + field->getCenter().getY());

	int i= rand()%2;

	if(i==0) {this->f= new Rectangle(center,diameter,height); this->type='R';}
	if(i==1) {this->f= new Losange(center,diameter,height); this->type='L';}

	this->height=height;	
	this->diameter=diameter;
	this->life=(altitude/2)+diameter+height;

}

Rock::Rock(char t, Point center, int height, int diameter, int altitude, int life)
{
	this->center.setX(center.getX());
	this->center.setY(center.getY());
	
	if(t=='R') this->f= new Rectangle(center,diameter,height);
	if(t=='L') this->f= new Losange(center,diameter,height);

	this->height=height;	
	this->diameter=diameter;
	this->altitude=altitude;
	this->life=life;
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