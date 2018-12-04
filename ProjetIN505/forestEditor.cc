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

Forest forestEditor::add_Element(Forest f, Objects* r, Point center)
{
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
    if (ok==1)
        {
            delete r;
            cout << "Veuillez cliquer autre part." << endl;
        }
    return f;       
}

Forest forestEditor::add_Rock(Forest f, Point center)
{
    Objects* r=new Rock(center);
    this->add_Element(f,r,center);
    return f;
}

Forest forestEditor::add_Tree(Forest f, Point center)
{
    Objects* t=new Tree(center);
    this->add_Element(f,t,center);
    return f;
}

Forest forestEditor::add_Player(Forest f, Point center)
{
   /* Character *c=new Player();
   */
}

Forest forestEditor::add_Ai(Forest f, Point center)
{
   /* Character *c=new Player();
   */
}

void forestEditor::write_Forest(Forest f)
{
   // string path = "./Saves  ";
   // int nbFichiersSD = Directory.GetFiles(path, "*.*", SearchOption.TopDirectory).Length - 1;

    ofstream file("Saves/test.txt",  ios::out | ios::trunc);
 
    if(file)  
    {       
       for(int unsigned i=0;i<f.List_Obj.size();i++)
        {
            if (dynamic_cast<Rock*>(f.List_Obj[i])) this->write_Rock(dynamic_cast<Rock*>(f.List_Obj[i]), file );
            if (dynamic_cast<Tree*>(f.List_Obj[i])) this->write_Tree(dynamic_cast<Tree*>(f.List_Obj[i]), file);
        }
        write_Character1(f.getP1(), file);
        write_Character1(f.getP2(), file);

        file.close();
    }
    else 
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

void forestEditor::write_Rock(Rock* r, ofstream &file)
{
    file << "R" << r->getCenter().getX() << " " << r->getCenter().getY();
    file << " " << r->getHeight() << " " <<r->getDiameter() << " " << r->getAltitude();
    file << " " << r->getLife() <<endl;
} //FAUT RAJOUTER LA FORME

void forestEditor::write_Tree(Tree* t, ofstream &file)
{
    file << "T" << r->getCenter().getX() << " " << r->getCenter().getY();
    file << " " << r->getHeight() << " " <<r->getDiameter() << " " << r->getAltitude();
    file << " " << r->getLife() <<endl;
}
void forestEditor::write_Character1(Character* c, ofstream &file){}
void forestEditor::write_Character2(Character* c, ofstream &file){}
Forest forestEditor::read_File(Forest f){return f;}
Forest forestEditor::read_Rock(Forest f){return f;}
Forest forestEditor::read_Tree(Forest f){return f;}
Forest forestEditor::read_Character1(Forest f){return f;}
Forest forestEditor::read_Character2(Forest f){return f;}
forestEditor::~forestEditor(){}
