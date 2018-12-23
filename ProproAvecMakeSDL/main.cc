#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include "Rock.h"
#include "Tree.h"
#include "Screen.h"
#include "./mesformes/Point.h"
#include "MouseKeyboard.h"
#include "Forest.h"
#include "Menu.h"

#include "forestEditor.h"

int main(int argc, char **argv)
{
     // Notre fenêtre
    Field f(800,600);
    SDL_Window* fenetre = Screen_Init(argc, argv, f);
    SDL_GLContext contexteOpenGL(0);
    SDL_Event evenements;
    bool terminer(false);

    Menu m;
    int joue=0;
    joue=m.Boucle_Menu(fenetre);


    SDL_Event event;
    int x,y;

    bool end;
    end = false;

   /* if (!joue)
    {
        Forest forest;
        if (m.getGame_Type()==1){f= read_File(forest, "./Saves/hard.txt");}
        if (m.getGame_Type()==2){f= read_File(forest, "./Saves/normal.txt");}
        if (m.getGame_Type()==3){f= read_File(forest, "./Saves/perso.txt");}
    }*/
     /*   while(!end)
        {
            SDL_WaitEvent(&event);
            SDL_GetMouseState(&x, &y);

            if(event.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                end = true;
            }
        }*/
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