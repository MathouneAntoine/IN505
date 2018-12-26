#include "Ai.h"
#include <SDL2/SDL.h>
#include <time.h>

#include <iostream>
#include "../mes_formes.h"
#include <GL/gl.h>

Ai::Ai()
{
	
}
Ai::Ai(Point p)
{
    this->p.setX(p.getX() );
    this->p.setY(p.getY() );
    this->orientation = 0;
    this->pv = 100;
    this->weaponDamage = 50;
    this->weaponRange= 5;
    this->cerc = new Cercle(this->p,20);
}

void Ai::live_Ai(vector<Objects*> obj)
{

		int i= rand()%4;
		if(i==0) 
		{
			this->orientation = 0;
			Translate(0,obj);
		}
		if(i==1)
		{
			this->orientation = 90;
			Translate(90,obj);
		} 

		if(i==2) 
		{
			this->orientation = 180;
			Translate(180,obj);
		}

		if(i==2) 
		{
			this->orientation = 270;
			Translate(270,obj);
		}
}
void Ai::print(Field f)
{
 
    cout << "Ai" << endl;
    GLfloat x =cerc->getCenter().getX()+f.getWidth() ;
    GLfloat y =cerc->getCenter().getY()+f.getHeight();
    GLfloat radius = cerc->getDiametre()/2;
    int i;
    int triangleAmount = 1000;
    float PI =2.14;
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

void Ai::Translate(int direction, vector<Objects*> obj)
{
    switch(direction)
    {
        case 0:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 , (cerc->getCenter().getY()-cerc->getDiametre()/2 -2) ,obj,0 ) && collision( cerc->getCenter().getX()-cerc->getDiametre()/2 , (cerc->getCenter().getY()-cerc->getDiametre()/2 -2) ,obj,0))
        {
            cerc->deplacer( 0,  -2);
        }
        break;

        case 90:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 +2 , (cerc->getCenter().getY()+cerc->getDiametre()/2) ,obj,0) && collision( cerc->getCenter().getX()+cerc->getDiametre()/2 +2 , (cerc->getCenter().getY()-cerc->getDiametre()/2) ,obj,0))
        {
            cerc->deplacer( 2,  0);
        }
        break;

        case 180:
        if(collision( cerc->getCenter().getX()+cerc->getDiametre()/2 , (cerc->getCenter().getY()+cerc->getDiametre()/2 +2) ,obj,0) && collision(cerc->getCenter().getX()-cerc->getDiametre()/2 , (cerc->getCenter().getY()+cerc->getDiametre()/2 +2) ,obj,0))
        {
            cerc->deplacer( 0,  2);
        }
        break;

        case 270:
        if(collision( cerc->getCenter().getX()-cerc->getDiametre()/2 -2 , (cerc->getCenter().getY())+cerc->getDiametre()/2 ,obj,0) && collision( cerc->getCenter().getX()-cerc->getDiametre()/2 -2 , (cerc->getCenter().getY())-cerc->getDiametre()/2 ,obj,0))
        {
            cerc->deplacer( -2,  0);
        }
        break;
    }

}

Ai::~Ai()
{


}
