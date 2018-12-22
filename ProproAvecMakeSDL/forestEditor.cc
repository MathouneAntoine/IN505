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
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

forestEditor::forestEditor()
{}

void forestEditor::create_forest(Forest f, SDL_Window* screen,SDL_Surface* pSurf  )
{
    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(screen, -1, 0);
    if(!renderer)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
    }

    SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

  SDL_Surface * text=NULL;
  TTF_Font * police = NULL;
  SDL_Color c = {38, 26, 13};

  police = TTF_OpenFont("./font.ttf", 15);
    if(!police) printf("TTF_OpenFont: %s\n", TTF_GetError());

  text=TTF_RenderText_Blended(police, "Appuyer sur A pour placer un arbre, R pour un Rocher, P un personnage", c);
  SDL_Rect Message_rect; //create a rect
Message_rect.x = 0;  //controls the rect's x coordinate 
Message_rect.y = 0; // controls the rect's y coordinte
Message_rect.w = text->w; // controls the width of the rect
Message_rect.h = text->h; // controls the height of the rect

SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, text); 

SDL_RenderCopy(renderer, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

SDL_RenderPresent(renderer);

 while (editor_Key(SDL_Event &event)=='s' || editor_Key(SDL_Event &event)=='q' )
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
    file << "R" << " " << r->getCenter().getX() << " " << r->getCenter().getY();
    file << " " << r->getHeight() << " " <<r->getDiameter() << " " << r->getAltitude();
    file << " " << r->getLife()<< " " << r->getType() <<endl;
} 

void forestEditor::write_Tree(Tree* t, ofstream &file)
{
    file << "T"  << " " << t->getCenter().getX() << " " << t->getCenter().getY();
    file << " " << t->getHeight() << " " <<t->getDiameter() << " " << t->getAltitude();
    file << " " << t->getLife() << " " << t->getType() <<endl;
}
void forestEditor::write_Character1(Character* c, ofstream &file)
{

}
void forestEditor::write_Character2(Character* c, ofstream &file){}

Forest forestEditor::read_File(Forest f, int i)
{
    ifstream file("./Saves/test.txt", ios::in);  
    char c,t;
    Point center;
    int height, diameter, altitude, life, x, y;

        if(file) 
        {       
            while(!file.eof())
            {
                file >> c; 

                if (file.tellg() != -1)
                switch (c)
                {
                    case 'R':
                    {
                        file >> x >> y >> height >> diameter >> altitude >> life >> t;
                        cout << x <<y << height << diameter<< altitude << life<< t << endl;
                        center.setX(x);
                        center.setY(y);
                        Rock* r= new Rock(t, center, height, diameter, altitude, life);
                        f.List_Obj.push_back(r);
                    }
                    break;

                    case 'T':
                    {
                        file >> x >> y >> height >> diameter >> altitude >> life >> t;
                        cout << x <<y << height << diameter<< altitude << life<< t << endl;
                        center.setX(x);
                        center.setY(y);
                        Tree* r= new Tree(t, center, height, diameter, altitude, life);
                        f.List_Obj.push_back(r);
                    }
                    break;

                    case 'C':

                    break;

                    default: cout << "Erreur lecture" ;

                }
            }

            file.close(); 
        }
        else  
                cerr << "Impossible d'ouvrir le fichier !" << endl;

    return f;
}

Forest forestEditor::read_Rock(Forest f, ifstream &file){return f;}
Forest forestEditor::read_Tree(Forest f, ifstream &file){return f;}
Forest forestEditor::read_Character1(Forest f, ifstream &file){return f;}
Forest forestEditor::read_Character2(Forest f, ifstream &file){return f;}
forestEditor::~forestEditor(){}