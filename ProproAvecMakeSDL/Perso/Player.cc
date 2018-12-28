#include <time.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>

#include "Player.h"
#include "../mes_formes.h"
#include "../Objects.h"
#include "Character.h"

using namespace std;
Player::Player()
{

}
Player::Player(Point p)
{
    this->p.setX(p.getX());
    this->p.setY(p.getY());
    this->orientation = 0;
    this->pv = 100;
    this->weaponDamage = 50;
    this->weaponRange= 6;
    this->cerc = new Cercle(this->p,20);
}
bool Player::movePlayer(SDL_Event event, vector<Objects*> &obj, Character &p)
{

    bool tour = false;
    switch(event.type)
                {
                    case SDL_QUIT:
                    break;  

                    case SDL_KEYDOWN: //KEYDOWN ??
                    tour= true;
                    switch(event.key.keysym.sym)
                    {
                        case 't':
                        cout <<"Tirer!"<<endl;
                        Attack(this->orientation, 10,  obj, 50,p);
                        break;

                        case SDLK_UP:
                        cout <<"Up"<<endl;
                        if(this->orientation!=0)
                        {
                            this->orientation = 0;
                        }
                        else
                        {
                            Translate(0,obj,p);
                        }
                        break;

                        
                        case SDLK_DOWN:
                        cout <<"Down"<<endl;
                        if(this->orientation != 180)
                        {
                            this->orientation = 180;
                        }
                        else
                        {
                            Translate(180,obj,p);
                        }
                        break;

                        case SDLK_RIGHT:
                        cout <<"Right"<<endl;
                        if(this->orientation != 90)
                        {
                             this->orientation = 90;
                        }
                        else
                        {
                            Translate(90,obj,p);
                        }
                        break;

                        case SDLK_LEFT:
                        cout <<"Left"<<endl;
                        if(this->orientation !=270)
                        {
                            this->orientation = 270;
                        }
                        else
                        {
                            Translate(270,obj,p);
                        }
                        break;
                    }
                 break;
        }
    return tour;

}

void Player::print(Field f)
{   
    if(this->orientation == 0)
    {
        glBegin(GL_LINES);
        glColor3f(0.88, 0.41 ,0);
        glVertex2f(cerc->getCenter().getX()+(f.getWidth()/2), cerc->getCenter().getY()+(f.getHeight()/2)-cerc->getDiametre()/2);
        glVertex2f(cerc->getCenter().getX()+(f.getWidth()/2), cerc->getCenter().getY()+(f.getHeight()/2)-cerc->getDiametre()/2-this->weaponRange);
        glEnd();
    }
    if(this->orientation == 90)
    {
        glBegin(GL_LINES);
        glColor3f(0.88, 0.41 ,0);
        glVertex2f(cerc->getCenter().getX()+(f.getWidth()/2)+cerc->getDiametre()/2, cerc->getCenter().getY()+(f.getHeight()/2));
        glVertex2f(cerc->getCenter().getX()+(f.getWidth()/2)+cerc->getDiametre()/2+this->weaponRange, cerc->getCenter().getY()+(f.getHeight()/2));
        glEnd();
    }
    if(this->orientation == 180)
    {
        glBegin(GL_LINES);
        glColor3f(0.88, 0.41 ,0);
        glVertex2f(cerc->getCenter().getX()+(f.getWidth()/2), cerc->getCenter().getY()+(f.getHeight()/2)+cerc->getDiametre()/2);
        glVertex2f(cerc->getCenter().getX()+(f.getWidth()/2), cerc->getCenter().getY()+(f.getHeight()/2)+cerc->getDiametre()/2+this->weaponRange);
        glEnd();
    }
    if(this->orientation == 270)
    {
        glBegin(GL_LINES);
        glColor3f(0.88, 0.41 ,0);
        glVertex2f(cerc->getCenter().getX()+(f.getWidth()/2)-cerc->getDiametre()/2, cerc->getCenter().getY()+(f.getHeight()/2));
        glVertex2f(cerc->getCenter().getX()+(f.getWidth()/2)-cerc->getDiametre()/2-this->weaponRange, cerc->getCenter().getY()+(f.getHeight()/2));
        glEnd();
    }

  

    GLfloat x =cerc->getCenter().getX()+(f.getWidth()/2) ;
    GLfloat y =cerc->getCenter().getY()+(f.getHeight()/2);
    GLfloat radius = cerc->getDiametre()/2;
    int i;
    int triangleAmount = 1000;
    float PI =3.14;
    GLfloat twicePi = 2.0f * PI;
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);

    glBegin(GL_LINES);
        glColor3f(0, 1, 0);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void Player::Translate(int direction, vector<Objects*> &obj,Character &p)
{
    switch(direction)
    {
        case 0:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 , (cerc->getCenter().getY()-cerc->getDiametre()/2 -3) ,obj,0,p ) && collision( cerc->getCenter().getX()-cerc->getDiametre()/2 , (cerc->getCenter().getY()-cerc->getDiametre()/2 -3) ,obj,0,p))
        {
        	cerc->deplacer( 0,  -3);
        }
        break;

        case 90:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 +3 , (cerc->getCenter().getY()+cerc->getDiametre()/2) ,obj,0,p) && collision( cerc->getCenter().getX()+cerc->getDiametre()/2 +3 , (cerc->getCenter().getY()-cerc->getDiametre()/2) ,obj,0,p))
        {
        	cerc->deplacer( 3,  0);
        }
        break;

        case 180:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 , (cerc->getCenter().getY()+cerc->getDiametre()/2 +3) ,obj,0,p) && collision(cerc->getCenter().getX()-cerc->getDiametre()/2 , (cerc->getCenter().getY()+cerc->getDiametre()/2 +3) ,obj,0,p))
        {
        	cerc->deplacer( 0,  3);
        }
        break;

        case 270:
        if(collision( cerc->getCenter().getX()-cerc->getDiametre()/2 -3 , (cerc->getCenter().getY())+cerc->getDiametre()/2 ,obj,0,p) && collision( cerc->getCenter().getX()-cerc->getDiametre()/2 -3 , (cerc->getCenter().getY())-cerc->getDiametre()/2 ,obj,0,p))
		{
    	    cerc->deplacer( -3,  0);
    	}
        break;
    }

}

void Player::Attack(int direction, int range,  vector<Objects*> &obj, int power,Character &p)
{
    for(int r = 0; r < range; range--)
    {
        for(int po = 0; po < power; power--)
        switch(direction)
        {
            case 0:
            collision( (cerc->getCenter().getX()+power), (cerc->getCenter().getY()+cerc->getDiametre()/2 +range) ,obj,power,p );
            break;

            case 90:
            collision( (cerc->getCenter().getX()+cerc->getDiametre()/2 +range) , (cerc->getCenter().getY()+power) ,obj,power,p);
            break;

            case 180:
            collision( (cerc->getCenter().getX()+power), (cerc->getCenter().getY()-cerc->getDiametre()/2 -range) ,obj,power,p);
            break;

            case 270:
            collision( (cerc->getCenter().getX()-cerc->getDiametre()/2 -range) , (cerc->getCenter().getY()+power),obj,power,p);
            break;
        }
    }
}

Player::~Player()
{

}
