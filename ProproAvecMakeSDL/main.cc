#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <time.h>

#include "Rock.h"
#include "Tree.h"
#include "Screen.h"
#include "./mesformes/Point.h"
#include "MouseKeyboard.h"
#include "Forest.h"
#include "Menu.h"
#include "./mes_perso.h"

#include "forestEditor.h"

int main(int argc, char **argv)
{
    srand(time(NULL));

     // Notre fenêtre
    Field f(800,600);
    SDL_Window* fenetre = Screen_Init(argc, argv, f);
    SDL_GLContext contexteOpenGL(0);

    Forest *forest=new Forest(f);

    Menu m;
    int joue=0;
    joue=m.Boucle_Menu(fenetre,forest);
    int typepartie =  m.getGame_Type();
     SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(fenetre, -1, 0);
    if(!renderer)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Event event;
    SDL_Event event2;

    bool end;
    end = false;
    bool tour = false;
    bool tour2 = false;

    forest->print(renderer);
    Player* p;
    Ai* a;
    Player* p2;
    Ai* a2;
    if(typepartie  == 1 )
    {
        p= dynamic_cast<Player*> (forest->getP1());
        a= dynamic_cast<Ai*> (forest->getP2());
    } 

    
    if(typepartie  == 2)                    
    {
        a= dynamic_cast<Ai*> (forest->getP1());
        a2= dynamic_cast<Ai*> (forest->getP2());

    }


    if(typepartie  == 3) 
    {
        p= dynamic_cast<Player*> (forest->getP1());
        p2= dynamic_cast<Player*> (forest->getP2());

    }                  
    while(!end)
    {
                SDL_WaitEvent( &event);
                SDL_WaitEvent( &event2);

        if(event.window.event == SDL_WINDOWEVENT_CLOSE)
        {
            end = true;
        }
        //SDL_Delay(1000);
        if(tour==false && tour2==false)
        {
            cout << "tour1" << endl;
            if(typepartie  == 1)
            {
                        //SDL_Delay(100);

                tour = p->movePlayer(event, forest->getListPtr());


            }
            if(typepartie  == 2)
            {

                tour = a->live_Ai(forest->getListPtr());

            }
            if(typepartie  == 3)
            {

                tour = p->movePlayer(event, forest->getListPtr());

            }
        }
        if(tour2==false && tour == true)
        {
            cout << "tour2" << endl;

            if(typepartie  == 1)
            {

                tour2 = a->live_Ai(forest->getListPtr());

            }
            if(typepartie  == 2)
            {

                tour2 = a2->live_Ai(forest->getListPtr());

            }
            if(typepartie  == 3)
            {
                tour2 = p2->movePlayer(event2, forest->getListPtr());

            }
        }
        
        
        forest->print(renderer);
        tour = false;
        tour2 = false;
    }

    SDL_DestroyWindow(fenetre);
    
    TTF_Quit();
    SDL_Quit();

    return 0;
}

/*
#include <vector>
#include "Field.h"
#include "Rock.h"
#include "Tree.h"
#include "mes_formes.h"
#include "forestEditor.h"
#include "Forest.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Field* f= new Field(500,400);
	srand(time(NULL));

	vector<Objects> v;
	forestEditor edit;
	Forest forest;
	Rock * r=new Rock();
	r->printInfo();
	r->print();
	Tree * r2=new Tree();
	r2->printInfo();
	r2->print();
	forest.List_Obj.push_back(r2);
	forest.List_Obj.push_back(r);
	edit.write_Forest(forest);

	Forest forest2;	
	forest2=edit.read_File(forest2, 0);

	forest2.List_Obj[0]->printInfo();
	forest2.List_Obj[0]->print();
	forest2.List_Obj[1]->printInfo();
	forest2.List_Obj[1]->print();
	return 0;
}
*/