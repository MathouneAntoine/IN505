#include <iostream>
#include "Rock.h"
#include "Objects.h"
#include "./mesformes/Forme.h"
#include "./mesformes/Rectangle.h"
#include "./mesformes/Point.h"

#include <SDL2/SDL.h>

using namespace std;

Rock::Rock()
{
	Point p1, p2,p3, p4;
	p1= Point(20,20);
	p2= Point(30,20);
	p3= Point(20,10);
	p4= Point(30,10);

	this->f= new Rectangle(p1,p2,p3,p4);
    this->p = p1;
	this->life=20;
	this->high=20;
	this->diameter=10;
	this->depth=10;
}

Rock::Rock(Field* f,int life, int high, int FromCenterX, int FromCenterY,  int diameter , int depth)
{
	Point p1, p2,p3, p4;
	p1= Point(FromCenterX + f->getCenter().getX(), FromCenterY + f->getCenter().getY());
	p2= Point(FromCenterX + f->getCenter().getX() + diameter, FromCenterY + f->getCenter().getY());
	p3= Point(FromCenterX + f->getCenter().getX(), FromCenterY + f->getCenter().getY()-depth );
	p4= Point(FromCenterX + f->getCenter().getX() + diameter, FromCenterY+ f->getCenter().getY() -depth );

	this->f= new Rectangle(p1,p2,p3,p4);
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

int Rock::sdl_print(SDL_Window* window)
{
    if (!window)
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    else
    {
    SDL_Surface *rectangle = NULL; //alloue une surface

    rectangle = SDL_CreateRGBSurface(0, this->diameter, this->depth, 32, 0, 0, 0, 0); //alloue notre nouvelle surface en mémoire




//    SDL_FillRect(rectangle, NULL, SDL_MapRGB(window->format, 0x50, 0x50, 0x0));
    SDL_Rect position;
    position.x = this->p.getX();
    position.y = this->p.getY();
//    SDL_BlitSurface(rectangle, NULL, window,&position); //colle sur l'écran le rectangle
    return 0;
    }

}
Rock::~Rock()
{}
