#include "Ai.h"
#include <SDL2/SDL.h>
#include <time.h>
#include <SDL2/SDL.h>

#include <iostream>
#include "../mes_formes.h"
#include <GL/gl.h>

Ai::Ai()
{
	
}

void Ai::live_Ai()
{

		int i= rand()%4;
		if(i==0) 
		{
			this->orientation = 0;
			Translate(0);
		}
		if(i==1)
		{
			this->orientation = 90;
			Translate(90);
		} 

		if(i==2) 
		{
			this->orientation = 180;
			Translate(180);
		}

		if(i==3) 
		{
			this->orientation = 270;
			Translate(270);
		}
}
void Ai::print()
{
    cout << "Ai" << endl;
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
        glColor3f(1, 0, 0);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void Ai::Translate(int direction)
{
    switch(direction)
    {
        case 0:
        if(colision( cerc->getCenter().getX() , (cerc->getCenter().getY()+cerc->getDiametre()/2 +3)) )
        {
        	cerc->deplacer( 0,  3);
        }
        break;

        case 90:
        if(colision( cerc->getCenter().getX()+cerc->getDiametre()/2 +3 , (cerc->getCenter().getY())) )
        {
        	cerc->deplacer( 3,  0);
        }
        break;

        case 180:
        if(colision( cerc->getCenter().getX() , (cerc->getCenter().getY()-cerc->getDiametre()/2 -3)) )
        {
        	cerc->deplacer( 0,  -3);
        }
        break;

        case 270:
        if(colision( cerc->getCenter().getX()-cerc->getDiametre()/2 -3 , (cerc->getCenter().getY())) )
		{
    	    cerc->deplacer( -3,  0);
    	}
        break;
    }

}

Ai::~Ai()
{


}
