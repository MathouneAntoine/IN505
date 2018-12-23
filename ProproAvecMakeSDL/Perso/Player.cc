#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include "Player.h"
#include "../mes_formes.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;
Player::Player()
{

}

void Player::movePlayer(SDL_Event event , int x, int y)
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
                            Translate(0);
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
                            Translate(180);
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
                            Translate(90);
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
                            Translate(270);
                        }
                        break;
                    }

                    case SDL_MOUSEBUTTONDOWN:

                    switch(event.button.button)
                    {
                         case SDL_BUTTON_RIGHT:
                         cout <<"Clic Right"<<endl;
                         cout<< "m_x = " << event.motion.x << endl;
                         cout<< "m_y = " << event.motion.y<<endl;
                         break;

                          case SDL_BUTTON_LEFT:
                         cout <<"Clic Left"<<endl;
                         cout<< "m_x = " << event.motion.x << endl;
                         cout<< "m_y = " << event.motion.y<<endl;
                         break;

                         default:
                         break;
                    }

                   /* case SDL_MOUSEMOTION:
                        cout<< "m_x = " << event.motion.x << endl;
                        cout<< "m_y = " << event.motion.y<<endl;
                        break;*/

        }
}

void Player::print_Player()
{
  cout << "Player" << endl;
    GLfloat x =cerc->getP().getX() ;
    GLfloat y =cerc->getP().getY();
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

void Player::Translate(int direction)
{
    switch(direction)
    {
        case 0:
        cerc->deplacer( 0,  3);

        break;
        case 90:
        cerc->deplacer( 3,  0);
        break;

        case 180:
        cerc->deplacer( 0,  -3);
        break;

        case 270:
        cerc->deplacer( -3,  0);
        break;
    }

}

Player::~Player()
{

}
