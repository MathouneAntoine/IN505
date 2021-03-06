#include <vector>
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>

#include "../Forest.h"
#include "Character.h"
#include "../mes_formes.h"
#include "../Objects.h"
using namespace std;

Character::Character()
{
    Point p(50,50);
    int o = rand()%4;
    if(o == 0) {this->orientation = 0;}
    if(o == 1) {this->orientation = 90;}
    if(o == 2) {this->orientation = 180;}
    if(o == 3) {this->orientation = 270;}

    this->pv = 100;
    this->weaponDamage = 5;
    this->weaponRange= 6;
    this->cerc = new Cercle();
}
Character::Character(Point p)
{
  this->p.setX(p.getX());
  this->p.setY(p.getY());
  this->orientation = 0;
  this->pv = 100;
  this->weaponDamage = 5;
  this->weaponRange= 6;
  this->cerc = new Cercle(this->p,20);
}


void Character::print(Field f)
{
	cout << "Character" << endl;
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
    glColor3f(1,1, 0);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x, y);
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void Character::PrintInfo()
{
	cout << "Position.x = " << this->p.getX()<< "Position.y = " << this->p.getY() << endl;
	cout << "Orientation = " << this->orientation << "°" << endl;
	cout << "PV = " << this->pv << endl;
	cout << "weaponDamage = " << this->weaponDamage << endl;
	cout << "weaponRange = " << this->weaponRange << endl;
}


Cercle* Character::getForme()
{
    return this->cerc;
}
int Character::getLife()
{
	return this->pv;
}

int Character::getOrientation()
{
    return this->orientation;
}
void Character::setLife(int pv)
{
  this->pv=pv;
}

// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle 
float sign (Point P1, Point P2, Point P3) 
{
    return (P1.getX() - P3.getX()) * (P2.getY() - P3.getY()) - (P2.getX() - P3.getX()) * (P1.getY() - P3.getY());
}

bool inTriangle (Point pt, Point P1, Point P2, Point P3) //Return true si on est dans un triangle
{
    float d1, d2, d3;
    bool negative, positive;

    d1 = sign(pt, P1, P2);
    d2 = sign(pt, P2, P3);
    d3 = sign(pt, P3, P1);

    negative = (d1 < 0) || (d2 < 0) || (d3 < 0);
    positive = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(negative && positive);
}	

bool Character::collisionObjet(int curseur_x,int curseur_y, vector<Objects*> &objet,int power,Character &p)  // Power prend 0 lors des déplacements ou la valeur de l'attaque si il y a un tir.
{     

    if(Cercle *cerc= p.cerc)
    {
    	int dist = sqrt( pow((cerc->getCenter().getX() - curseur_x),2) + (pow((cerc->getCenter().getY() - curseur_y),2)));
        if(dist <= cerc->getDiametre()/2)
        {
            if(power>0) takeDamageCharacter(p,power);
           return true;
       }
   }

   for(int unsigned i=0; i < objet.size();i++)
   {
            Objects* obj;
            obj=objet[i];
           // obj->printInfo();
            if(Rectangle *rect= dynamic_cast <Rectangle*> (obj->getForme()))
            {
               if (curseur_x >= rect->getP1().getX()
                && curseur_x <  rect->getP4().getX()
                && curseur_y >= rect->getP2().getY()  
                && curseur_y < rect->getP1().getY())
               {
                    if(power>0) takeDamage(objet,obj,i,power,p);
                   return true;
               }
           }	

           else if(Cercle *cerc= dynamic_cast <Cercle*> (obj->getForme()))
           {    

              int dist = sqrt( pow((cerc->getCenter().getX() - curseur_x),2) + (pow((cerc->getCenter().getY() - curseur_y),2)));

              if(dist <= cerc->getDiametre()/2)
              {
                if(power>0) takeDamage(objet,obj,i,power,p);
               return true;
           }
        }

        else if(Losange *losa= dynamic_cast <Losange*> (obj->getForme()))
        {
            Point pt ( curseur_x, curseur_y);
            if(inTriangle (pt, losa->getP1(),losa->getP2(),losa->getP3()) ||  inTriangle (pt,losa->getP3(),losa->getP4(),losa->getP1()))
            {
                if(power>0) takeDamage(objet,obj,i,power,p);
               return true;
           }
        }
        else if(Triangle *tria= dynamic_cast <Triangle*> (obj->getForme()))
        {
           Point pt ( curseur_x, curseur_y);
           if(inTriangle(pt, tria->getP1(),tria->getP2(),tria->getP3()))
           {
               if(power>0) takeDamage(objet,obj,i,power,p);
               return true;
           }
        }
    }
return false;
}

bool Character::collision(int x, int y, vector<Objects*> &obj,int power,Character &p)
{
    if(x < 400 && x > -400 && y < 300 && y > -300 && !collisionObjet( x,y,obj,power,p) ) // Si on est dans la fenetre et qu'il n'y a pas d'objet genant
        return true;
    else
        return false;
}

void Character::Attack(int direction, int range,  vector<Objects*> &obj, int power,Character &p)
{
	int zone=power;
    for(int r = 0; r < range; range--) //Boucle pour la portée
    {
        for(int po = 0; po < zone; zone--) //Boucle pour la zone
            switch(direction)
        {
            case 0:
            collision( (cerc->getCenter().getX()+zone), (cerc->getCenter().getY()-cerc->getDiametre()/2 -range) ,obj,power,p);
            break;

            case 90:
            collision( (cerc->getCenter().getX()+cerc->getDiametre()/2 +range) , (cerc->getCenter().getY()+zone) ,obj,power,p);
            break;
            
            case 180:
            collision( (cerc->getCenter().getX()+zone), (cerc->getCenter().getY()+cerc->getDiametre()/2 +range) ,obj,power,p );
            break;            

            case 270:
            collision( (cerc->getCenter().getX()-cerc->getDiametre()/2 -range) , (cerc->getCenter().getY()+zone),obj,power,p);
            break;
        }
    }
}
void Character::takeDamage(vector<Objects*> &v ,Objects *o,int i, int power,Character &p)
{
	if(this->pv-power/2 > 0) // Si le joueur a assez de vie
	{
		this->pv = this->pv-power/10; // Il perd des pv en fonction de la force du tir
    o->printInfo();
		if ((o->getLife() - power) <= 0) // Si l'objet n'a plus de pv 
       {
          cout << "dead Object" << v.size()<<  endl;

          v.erase(v.begin()+i);
          cout << "dead after Object" << v.size()<<  endl;
      }
      else o->setLife(o->getLife() - power); //Diminue la vie de l'objet
  }

}
void Character::takeDamageCharacter(Character &p, int power)
{
	if(this->pv-power/2 > 0) // Si le joueur a assez de vie
	{
   cout  << endl << "INFO attaquant" <<endl; this->PrintInfo(); cout<< "FIN INFO attaquant" << endl << endl;
   cout << "INFO attaqué" <<endl; p.PrintInfo(); cout<< "FIN INFO attaqué" << endl << endl;

       if ((p.getLife() - power) <= 0) // si l'adversaire n'a plus de pv
       {
         p.setLife(p.getLife() - power); //Vie mise inférieur à 0, fini le main
         cout << "dead" << endl;
     }
     else p.setLife(p.getLife() - power); //Diminu la vie de l'adversaire
 }
}

Character::~Character()
{
	delete (cerc);
	cout << "Destructeur Character "<<  endl;
}
