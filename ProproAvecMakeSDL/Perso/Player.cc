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

bool Player::movePlayer(SDL_Event event , int x, int y,vector<Objects*> obj)
{
 switch(event.type)
                {
                    case SDL_QUIT:
                    break;  
                    case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {


                        case SDLK_UP:
                        cout <<"Up"<<endl;
                        if(this->orientation!=0)
                        {
                            this->orientation = 0;
                        }
                        else
                        {
                            Translate(0,obj);
                        }
                        return true;
                        break;

                        case SDLK_DOWN:
                        cout <<"Down"<<endl;
                        if(this->orientation != 180)
                        {
                            this->orientation = 180;
                        }
                        else
                        {
                            Translate(180,obj);
                        }
                        return true;
                        break;

                        case SDLK_RIGHT:
                        cout <<"Right"<<endl;
                        if(this->orientation != 90)
                        {
                             this->orientation = 90;
                        }
                        else
                        {
                            Translate(90,obj);
                        }
                        return true;
                        break;

                        case SDLK_LEFT:
                        cout <<"Left"<<endl;
                        if(this->orientation !=270)
                        {
                            this->orientation = 270;
                        }
                        else
                        {
                            Translate(270,obj);
                        }
                        return true;
                        break;

                        default:
                        return false;
                        break;
                    }
        }
}

void Player::print()
{
    cout << "Player" << endl;
    GLfloat x =cerc->getCenter().getX() ;
    GLfloat y =cerc->getCenter().getY();
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

void Player::Translate(int direction, vector<Objects*> obj)
{

    switch(direction)
    {
        case 0:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 , (cerc->getCenter().getY()-cerc->getDiametre()/2 -3) ,obj ) && collision( cerc->getCenter().getX()-cerc->getDiametre()/2 , (cerc->getCenter().getY()-cerc->getDiametre()/2 -3) ,obj ))
        {
        	cerc->deplacer( 0,  -3);
        }
        break;

        case 90:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 +3 , (cerc->getCenter().getY()+cerc->getDiametre()/2) ,obj) && collision( cerc->getCenter().getX()+cerc->getDiametre()/2 +3 , (cerc->getCenter().getY()-cerc->getDiametre()/2) ,obj))
        {
        	cerc->deplacer( 3,  0);
        }
        break;

        case 180:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 , (cerc->getCenter().getY()+cerc->getDiametre()/2 +3) ,obj) && collision(cerc->getCenter().getX()-cerc->getDiametre()/2 , (cerc->getCenter().getY()+cerc->getDiametre()/2 +3) ,obj))
        {
        	cerc->deplacer( 0,  3);
        }
        break;

        case 270:
        if(collision( cerc->getCenter().getX()-cerc->getDiametre()/2 -3 , (cerc->getCenter().getY())+cerc->getDiametre()/2 ,obj) && collision( cerc->getCenter().getX()-cerc->getDiametre()/2 -3 , (cerc->getCenter().getY())-cerc->getDiametre()/2 ,obj))
		{
    	    cerc->deplacer( -3,  0);
    	}
        break;
    }

}

/*void Player::Attack(int direction, int range, int power,  vector<Objects*> obj)
{
    switch(direction)
    {
        case 0:
        if(collision( cerc->getCenter().getX(), (cerc->getCenter().getY()+cerc->getDiametre()/2 +range) ,obj )) 
        {
            cerc->deplacer( 0,  -3);
        }
        break;

        case 90:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 +range , (cerc->getCenter().getY()) ,obj))
        {
            cerc->deplacer( 3,  0);
        }
        break;

        case 180:
        if(collision( cerc->getCenter().getX(), (cerc->getCenter().getY()-cerc->getDiametre()/2 -range) ,obj))
        {
            cerc->deplacer( 0,  3);
        }
        break;

        case 270:
        if(collision( cerc->getCenter().getX()-cerc->getDiametre()/2 -range , (cerc->getCenter().getY()),obj))
        {
            cerc->deplacer( -3,  0);
        }
        break;
    }

}*/

Player::~Player()
{

}
