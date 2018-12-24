#include <iostream>
#include "ForestAction.h"
#include "Objects.h"
using namespace std;
bool ForestAction::colisionObjet(int curseur_x,int curseur_y)
{
	cout << "Débutttttttttttt" << this->List_Obj.size()<<  endl;
	
	for(int unsigned i=0; i < this->List_Obj.size();i++)
        {
        	Objects* obj;
            obj=this->List_Obj[i];
    				cout << "FORMEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE?" << this->forme << endl;
    		this->List_Obj[0]->printInfo();
		    if(Rectangle *rect= dynamic_cast <Rectangle*> (obj->getForme()))
		    {
				 if (curseur_x >= rect->getP1().getX() 
			    && curseur_x <  rect->getP4().getX()
			    && curseur_y >= rect->getP2().getY()  
			    && curseur_y < rect->getP1().getY())
			       return false;
			}

			else if(Cercle *cerc= dynamic_cast <Cercle*> (obj->getForme()))
		    {
				 if (curseur_x >= cerc->getCenter().getX()- cerc->getDiametre()/2
			    && curseur_x <   cerc->getCenter().getX()+ cerc->getDiametre()/2
			    && curseur_y >=  cerc->getCenter().getY()- cerc->getDiametre()/2
			    && curseur_y < cerc->getCenter().getY()+ cerc->getDiametre()/2)
			       return false;
			}

			else if(Losange *losa= dynamic_cast <Losange*> (obj->getForme()))
			{
				  if (curseur_x >= rect->getP4().getX() 
			    && curseur_x <  rect->getP2().getX()
			    && curseur_y >= rect->getP3().getY()  
			    && curseur_y < rect->getP1().getY())
			       return false;
			}
			else if(Triangle *tria= dynamic_cast <Triangle*> (obj->getForme()))
			{
				if(tria->getOrientation()==0)
				{
					 if (curseur_x >= rect->getP2().getX() 
			    && curseur_x <  rect->getP3().getX()
			    && curseur_y >= rect->getP1().getY()  
			    && curseur_y < rect->getP2().getY())
			       return false;


				}
				if(tria->getOrientation()==1)
				{
		 			if (curseur_x >= rect->getP2().getX() 
			    && curseur_x <  rect->getP1().getX()
			    && curseur_y >= rect->getP3().getY()  
			    && curseur_y < rect->getP2().getY())
			       return false;
					
				}
				if(tria->getOrientation()==2)
				{
					if (curseur_x >= rect->getP2().getX() 
			    && curseur_x <  rect->getP3().getX()
			    && curseur_y >= rect->getP1().getY()  
			    && curseur_y < rect->getP2().getY())
			       return false;
					
				}
				if(tria->getOrientation()==3)
				{
					if (curseur_x >= rect->getP1().getX() 
			    && curseur_x <  rect->getP2().getX()
			    && curseur_y >= rect->getP3().getY()  
			    && curseur_y < rect->getP2().getY())
			       return false;
				}
			}
	}
	cout << "True" <<  endl;
	return true;
}

bool ForestAction::colision(int x, int y)
{
	cout << "colisionObjet:" << colisionObjet( x,y) <<endl;
	if(x < 800 && x > 0 && y < 600 && y > 0 && colisionObjet( x,y) )
		return true;
	else
		return false;
}