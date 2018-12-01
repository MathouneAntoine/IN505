#include<vector>
#include<iostream>
#include<fstream>
//  #include <filesystem>
#include "Forest.h"
#include "forestEditor.h"
#include "Rock.h"
#include "Tree.h"
#include "mes_perso.h"
#include "Objects.h"

using namespace std;

forestEditor::forestEditor()
{}

void forestEditor::create_forest(Forest f)
{
     
}

Forest forestEditor::add_Element(Forest f)
{
        
}

Forest forestEditor::add_Rock(Forest f, Point center)
{
    Objects* r=new Rock(center);
    Objects* r_list;
    bool ok=0;

    for(int j=0; j<5; j++)
    {
        ok=0;
        for(int unsigned i=0;i<f.List_Obj.size()&& ok !=1 ;i++)
        {
            r_list=f.List_Obj[i];
            int rx=r_list->getCenter().getX();
            int ry=r_list->getCenter().getY();
            int rd=r_list->getDiameter()/2;
            int rh=r_list->getHeight()/2;

            if (((r->getCenter().getX()+(r->getDiameter()/2) > (rx-(rd)) && r->getCenter().getX()+(r->getDiameter()/2) < (rx+(rd)) 
                        && (r->getCenter().getY()-(r->getHeight()/2)) < (ry+(rh)) && (r->getCenter().getY()-(r->getHeight() /2)) > (ry-(rh)))
                )||(                
                    (r->getCenter().getX()-(r->getDiameter()/2) < (rx+(rd)) && r->getCenter().getX()-(r->getDiameter()/2) > (rx-(rd))
                        && (r->getCenter().getY()-(r->getHeight()/2)) < (ry+(rh))) && (r->getCenter().getY()-(r->getHeight()/2)) > (ry-(rh))
                )||(
                    (r->getCenter().getX()+(r->getDiameter()/2) > (rx-(rd)) && r->getCenter().getX()+(r->getDiameter()/2) < (rx+(rd))
                        && (r->getCenter().getY()+(r->getHeight()/2)) > (ry-(rh))) && (r->getCenter().getY()+(r->getHeight()/2)) < (ry+(rh))
                )||(
                    (r->getCenter().getX()-(r->getDiameter()/2) < (rx+(rd)) && r->getCenter().getX()-(r->getDiameter()/2) > (rx-(rd)) 
                        && (r->getCenter().getY()+(r->getHeight()/2)) > (ry-(rh))) && (r->getCenter().getY()+(r->getHeight()/2)) < (ry+(rh))))
                ok=1;
            delete r_list;
        }

        if (ok==1)
        {
            delete r;
            Objects* r=new Rock(center);
        }
        else
        {
            f.List_Obj.push_back(r);  
            //this->write_Rock(dynamic_cast<Rock*>(r));
            return f;
        }
    }

       return f;
}

Forest forestEditor::add_Tree(Forest f, Point center)
{

}

Forest forestEditor::add_Character1(Forest f, Point center)
{

}

Forest forestEditor::add_Character2(Forest f, Point center)
{

}

void forestEditor::write_Forest(Forest f)
{
   // string path = "./Saves  ";
   // int nbFichiersSD = Directory.GetFiles(path, "*.*", SearchOption.TopDirectory).Length - 1;

    ifstream fichier("Saves/test.txt", ios::in);
 
    if(fichier)  
    {       
        
        fichier.close();
    }
    else 
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

void forestEditor::write_Rock(Rock* r){}
void forestEditor::write_Tree(Tree* t){}
void forestEditor::write_Character1(Character* c){}
void forestEditor::write_Character2(Character* c){}
Forest forestEditor::read_File(Forest f){}
Forest forestEditor::read_Rock(Forest f){}
Forest forestEditor::read_Tree(Forest f){}
Forest forestEditor::read_Character1(Forest f){}
Forest forestEditor::read_Character2(Forest f){}
forestEditor::~forestEditor(){}
