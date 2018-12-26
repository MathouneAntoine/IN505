#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Forest.h"
#include "forestEditor.h"
#include "Rock.h"
#include "Tree.h"
#include "mes_perso.h"
#include "Objects.h"
#include "MouseKeyboard.h"

using namespace std;

forestEditor::forestEditor()
{}

void forestEditor::create_forest(Forest *f, SDL_Window* screen,SDL_Surface* pSurf  )
{
     message(screen);

    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(screen, -1, 0);
    if(!renderer)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
    }

    SDL_RenderPresent(renderer);
    SDL_Event event;
    char res='b';
    Point center;
    int count =1;
    f->print(renderer);
     while (res !='s' && res!='q' )
     {
         f->print(renderer);
        while(res=='b')
        {
            SDL_WaitEvent(&event);  
            res=editor_Key(event);
        }
        while(center.getX()==0 && center.getY()==0 && res !='s' && res!='q' )
        {
           SDL_WaitEvent(&event);
           clic(event,&center);
        }

        if (res=='a')
        {  
            if (add_Tree(f,center)==true)
            {
                int t=f->getList().size();               
               dynamic_cast<Tree*>(f->getObj(t-1))->print(f->getField());
            }
            res='b';
        }
        if (res=='r')
        {
            if (add_Rock(f,center)==true)
            {
                int t=f->getList().size();       
                cerr<< "T = " << t << endl; 
               dynamic_cast<Rock*>(f->getObj(t-1))->print();
              
            }
            res='b';
        }
        if (res=='p' && count <3)
        {
            if (add_Player(f,center,count)==true)
            {
                if (count ==1) f->getP1()->print();
                if (count ==2) f->getP2()->print(); 
                 count++;
            }
            res='b';
        }

        if (res=='p' && count >=3)res='b';
        if (res=='s' && (f->getP1()==NULL || f->getP2()==NULL))res='b';

        center.setX(0);
        center.setY(0);             
     }
     SDL_DestroyRenderer(renderer);

     if (res=='s'&& f->getP1()!=NULL && f->getP2()!=NULL)
     {
        write_Forest(f);
     }

     cout<< "FIN EDITION";
}

void forestEditor::message(SDL_Window* screen)
{
    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(screen, -1, 0);
    if(!renderer)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
    }
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255,255, 255);

  SDL_Surface * text=NULL;
  TTF_Font * police = NULL;
  SDL_Color c = {38, 26, 13};

  police = TTF_OpenFont("./font.ttf", 15);
    if(!police) printf("TTF_OpenFont: %s\n", TTF_GetError());

  text=TTF_RenderText_Blended(police, "Appuyer sur A pour placer un arbre, R pour un Rocher, P un personnage", c);
  SDL_Rect Message_rect;
    Message_rect.x = 0; 
    Message_rect.y = 0;
    Message_rect.w = text->w; 
    Message_rect.h = text->h; 

    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, text); 
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect); 
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;

    while(event.key.keysym.sym != SDLK_RETURN)
    {
        cout<< "OKK";
     SDL_WaitEvent(&event);
    }

    SDL_DestroyRenderer(renderer);

}

bool forestEditor::add_Element(Forest* f, Objects* r, Point center)
{
    Objects* obj;
    bool ok=0;

    int r_x=r->getCenter().getX();
    int r_y=r->getCenter().getY();
    int r_d=r->getDiameter()/2;
    int r_h=r->getHeight()/2;

    for(int unsigned i=0; i < f->getList().size() && ok !=1 ;i++)
        {
            obj=f->getObj(i);
            int obj_x=obj->getCenter().getX();
            int obj_y=obj->getCenter().getY();
            int obj_d=obj->getDiameter()/2;
            int obj_h=obj->getHeight()/2;

            if (((r_x+r_d >= (obj_x-(obj_d)) && r_x+r_d <= (obj_x+(obj_d)) 
                        && (r_y-r_h) <= (obj_y+(obj_h)) && (r_y-r_h) >= (obj_y-(obj_h)))
                )||(                
                    (r_x-r_d <= (obj_x+(obj_d)) && r_x-r_d >= (obj_x-(obj_d))
                        && (r_y-r_h) <= (obj_y+(obj_h))) && (r_y-r_h) >= (obj_y-(obj_h))
                )||(
                    (r_x+r_d >= (obj_x-(obj_d)) && r_x+r_d <= (obj_x+(obj_d))
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x+(obj_d)) && r_x-r_d >= (obj_x-(obj_d)) 
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x-(obj_d)) && r_x+r_d >= (obj_x+(obj_d)) 
                        && (r_y-r_h) <= (obj_y+(obj_h))) && (r_y+r_h) >= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x-(obj_d)) && r_x+r_d >= (obj_x+(obj_d)) 
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_y+r_h >= (obj_y+(obj_h)) && r_y-r_h <= (obj_y-(obj_h)) 
                        && (r_x+r_d) >= (obj_x-(obj_x))) && (r_x+r_d) <= (obj_x+(obj_x))
                ))
                {  cout << "DANS LE IF " << endl;
                    ok=1;}
        }      

    if (ok==1)
        {
            cout << "Veuillez cliquer autre part." << endl;
            return false;
        }

     if (ok==0)
        {
            if (f->getP1() != NULL)
            {
                 cout << "P1 existe" <<endl;
                int obj_x=f->getP1()->getForme()->getCenter().getX();
                int obj_y=f->getP1()->getForme()->getCenter().getY();
                int obj_d=f->getP1()->getForme()->getDiametre()/2;
                int obj_h=obj_d;

               if (((r_x+r_d >= (obj_x-(obj_d)) && r_x+r_d <= (obj_x+(obj_d)) 
                        && (r_y-r_h) <= (obj_y+(obj_h)) && (r_y-r_h) >= (obj_y-(obj_h)))
                )||(                
                    (r_x-r_d <= (obj_x+(obj_d)) && r_x-r_d >= (obj_x-(obj_d))
                        && (r_y-r_h) <= (obj_y+(obj_h))) && (r_y-r_h) >= (obj_y-(obj_h))
                )||(
                    (r_x+r_d >= (obj_x-(obj_d)) && r_x+r_d <= (obj_x+(obj_d))
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x+(obj_d)) && r_x-r_d >= (obj_x-(obj_d)) 
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x-(obj_d)) && r_x+r_d >= (obj_x+(obj_d)) 
                        && (r_y-r_h) <= (obj_y+(obj_h))) && (r_y+r_h) >= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x-(obj_d)) && r_x+r_d >= (obj_x+(obj_d)) 
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_y+r_h >= (obj_y+(obj_h)) && r_y-r_h <= (obj_y-(obj_h)) 
                        && (r_x+r_d) >= (obj_x-(obj_x))) && (r_x+r_d) <= (obj_x+(obj_x))
                ))
                {ok=1;}
            }

            if (f->getP2() != NULL)
            {
                cout << "P2 existe" <<endl;

                int obj_x=f->getP2()->getForme()->getCenter().getX();
                int obj_y=f->getP2()->getForme()->getCenter().getY();
                int obj_d=f->getP2()->getForme()->getDiametre()/2;
                int obj_h=obj_d;

              if (((r_x+r_d >= (obj_x-(obj_d)) && r_x+r_d <= (obj_x+(obj_d)) 
                        && (r_y-r_h) <= (obj_y+(obj_h)) && (r_y-r_h) >= (obj_y-(obj_h)))
                )||(                
                    (r_x-r_d <= (obj_x+(obj_d)) && r_x-r_d >= (obj_x-(obj_d))
                        && (r_y-r_h) <= (obj_y+(obj_h))) && (r_y-r_h) >= (obj_y-(obj_h))
                )||(
                    (r_x+r_d >= (obj_x-(obj_d)) && r_x+r_d <= (obj_x+(obj_d))
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x+(obj_d)) && r_x-r_d >= (obj_x-(obj_d)) 
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x-(obj_d)) && r_x+r_d >= (obj_x+(obj_d)) 
                        && (r_y-r_h) <= (obj_y+(obj_h))) && (r_y+r_h) >= (obj_y+(obj_h))
                )||(
                    (r_x-r_d <= (obj_x-(obj_d)) && r_x+r_d >= (obj_x+(obj_d)) 
                        && (r_y+r_h) >= (obj_y-(obj_h))) && (r_y+r_h) <= (obj_y+(obj_h))
                )||(
                    (r_y+r_h >= (obj_y+(obj_h)) && r_y-r_h <= (obj_y-(obj_h)) 
                        && (r_x+r_d) >= (obj_x-(obj_x))) && (r_x+r_d) <= (obj_x+(obj_x))
                ))
                {ok=1;}
            }
        }

  
    if (ok ==0)
    {
        f->addList(r);
        
        return true;
    }


    return false;       
}

bool forestEditor::add_Rock(Forest* f, Point center)
{
    return this->add_Element(f,new Rock(center),center);
}

bool forestEditor::add_Tree(Forest* f, Point center)
{
    return this->add_Element(f,new Tree(center),center);
}

bool forestEditor::add_Player(Forest* f, Point center, int i)
{
    Character *c=new Character(center);
    cout<< "Perso x" << c->getForme()->getCenter().getX() << " Y " << c->getForme()->getCenter().getY() << endl;
    Objects* obj;
    bool ok=0;

    for(int unsigned i=0; i < f->getList().size()&& ok !=1 ;i++)
        {
            obj=(f->getList())[i];
            int rx=obj->getCenter().getX();
            int ry=obj->getCenter().getY();
            int rd=obj->getDiameter()/2;
            int obj_h=obj->getHeight()/2;

            if (((c->getForme()->getCenter().getX()+(c->getForme()->getDiametre()/2) > (rx-(rd)) && c->getForme()->getCenter().getX()+(c->getForme()->getDiametre()/2) < (rx+(rd)) 
                        && (c->getForme()->getCenter().getY())+(c->getForme()->getDiametre()/2) < (ry+(obj_h)) && (c->getForme()->getCenter().getY()+(c->getForme()->getDiametre()/2)) > (ry-(obj_h)))
                )||(                
                    (c->getForme()->getCenter().getX()-(c->getForme()->getDiametre()/2) < (rx+(rd)) && c->getForme()->getCenter().getX()-(c->getForme()->getDiametre()/2) > (rx-(rd))
                        && (c->getForme()->getCenter().getY()-(c->getForme()->getDiametre()/2)) < (ry+(obj_h)) && c->getForme()->getCenter().getX()+(c->getForme()->getDiametre()/2)) > (ry-(obj_h))
                )||(
                    (c->getForme()->getCenter().getX()-(c->getForme()->getDiametre()/2) > (rx-(rd)) && c->getForme()->getCenter().getX()-(c->getForme()->getDiametre()/2) < (rx+(rd))
                        && (c->getForme()->getCenter().getY()-(c->getForme()->getDiametre()/2)) > (ry-(obj_h))) && (c->getForme()->getCenter().getY()+(c->getForme()->getDiametre()/2) < (ry+(obj_h))
                )||(
                    (c->getForme()->getCenter().getX()-(c->getForme()->getDiametre()/2)< (rx+(rd)) && c->getForme()->getCenter().getX()-(c->getForme()->getDiametre()/2) > (rx-(rd)) 
                        && (c->getForme()->getCenter().getY()+(c->getForme()->getDiametre()/2)) > (ry-(obj_h)) && (c->getForme()->getCenter().getY()-(c->getForme()->getDiametre()/2)) < (ry+(obj_h))))))
                ok=1;
        }

    if (ok==1)
        {
            cout << "Veuillez cliquer autre part." << endl;
            return false;
        }

     if (ok==0 && (i==1 || i==2))
        {
            if (i==1) { cout << "ADD 1" <<endl; f->setP1(c);}
            if (i==2) { cout << "ADD 2" <<endl; f->setP2(c);}
            return true;
        }
    return false;  

   
}

void forestEditor::write_Forest(Forest* f)
{
    ofstream file("Saves/personalisee.txt",  ios::out | ios::trunc);
 
    if(file)  
    {       
       for(int unsigned i=0;i<f->getList().size();i++)
        {
            if (dynamic_cast<Rock*>(f->getList()[i])) this->write_Rock(dynamic_cast<Rock*>(f->getList()[i]), file );
            if (dynamic_cast<Tree*>(f->getList()[i])) this->write_Tree(dynamic_cast<Tree*>(f->getList()[i]), file);
        }

        cout<< "P1== " << endl; 
        f->getP1()->PrintInfo();
        write_Character(f->getP1(), file,1);
        write_Character(f->getP2(), file,2);

        file.close();
    }
    else 
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

void forestEditor::write_Rock(Rock* r, ofstream &file)
{
    file << "R" << " " << r->getCenter().getX() << " " <<  r->getCenter().getY() ;
    file << " " << r->getHeight() << " " <<r->getDiameter() << " " << r->getAltitude();
    file << " " << r->getLife()<< " " << r->getType() <<endl;
} 

void forestEditor::write_Tree(Tree* t, ofstream &file)
{
    file << "T"  << " " << t->getCenter().getX() << " " << t->getCenter().getY();
    file << " " << t->getHeight() << " " <<t->getDiameter() << " " << t->getAltitude();
    file << " " << t->getLife() << " " << t->getType() <<endl;
}

void forestEditor::write_Character(Character* c, ofstream &file, int i)
{
   if(c!=NULL) cout<<"PAS NULL";
   if(c==NULL) cout<<"NULL";


   // file << "C" << i << " " << c->getForme()->getCenter().getX() << " " << c->getForme()->getCenter().getY() << endl;
}

Forest* forestEditor::read_File(Forest* f, string s)
{
    ifstream file(s, ios::in);  
    char c,t;
    Point center;
    int height, diameter, altitude, life, x, y;
    int i=0;

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
                        f->getList().push_back(r);
                    }
                    break;

                    case 'T':
                    {
                        file >> x >> y >> height >> diameter >> altitude >> life >> t;
                        cout << x <<y << height << diameter<< altitude << life<< t << endl;
                        center.setX(x);
                        center.setY(y);
                        Tree* r= new Tree(t, center, height, diameter, altitude, life);
                        f->getList().push_back(r);
                    }
                    break;

                    case 'C':
                    {
                        file >> i >> x >> y;
                        cout << x <<y <<endl;
                        center.setX(x);
                        center.setY(y);
                        Character* perso=new Character(center);
                        if (i==1) f->setP1(perso);
                        if (i==2) f->setP2(perso);
                        if (i!=1 && i!=2) cout<<"ERREUR LECTURE FICHIER PERSO";
                    }

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
forestEditor::~forestEditor(){}
