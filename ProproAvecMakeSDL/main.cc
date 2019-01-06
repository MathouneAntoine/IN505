#include <GL/gl.h>
#include <GL/glu.h>
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

SDL_Renderer * printEnd(Forest *forest, SDL_Window* screen)
{
 SDL_Surface * text;
  SDL_Rect rect;
  TTF_Font * police = NULL;
  SDL_Color c = {38, 26, 13};

  police = TTF_OpenFont("./font.ttf", 50);
    if(!police) printf("TTF_OpenFont: %s\n", TTF_GetError());

  if (forest->getP1()->getLife()>0)text=TTF_RenderText_Blended(police, "* Joueur 1 Gagne *", c); 
  else if(forest->getP2()->getLife()>0) text=TTF_RenderText_Blended(police, "* Joueur 2 Gagne *", c); 

  rect.w = text->w;
  rect.h = text->h;

  	SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(screen, -1, 0);
    if(!renderer)
    {
        std::cout << "SDL Error @boucle_menu: " << SDL_GetError() << std::endl;
    }
    SDL_RenderPresent(renderer);

    if(text)
    {
      rect.x=400- rect.w/2 ; rect.y=150;

        SDL_Texture* b0 = SDL_CreateTextureFromSurface(renderer, text); 
        SDL_RenderCopy(renderer, b0, NULL, &rect);
        SDL_RenderPresent(renderer);
        
    }

TTF_CloseFont(police);
return renderer;
}


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
		std::cout << "SDL Error @main : " << SDL_GetError() << std::endl;
		return -1;
	}

	SDL_Event event;


	bool end;
	bool message=true;
	end = false;
	bool tour = false;
	bool tour2 = false;

	if (m.getGame_Type()!=-1)   
	{

	forest->print(renderer,0);
	Player* p=NULL;
	Ai* a=NULL;
	Player* p2=NULL;
	Ai* a2=NULL;
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

		if(event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			end = true;
			message=false;
		}

		if(tour==false && tour2==false)
		{
			//cout << "tour1" << endl;
			if(typepartie  == 1)
			{
				SDL_WaitEvent( &event);
				tour = p->movePlayer(event, forest->getListPtr(),forest->getP2Ref());
				if(p->getLife()<=0){ end = true;}

			}
			if(typepartie  == 2)
			{
				tour = a->live_Ai(forest->getListPtr(),forest->getP2Ref());
				if(a->getLife()<=0){ end = true;}

			}
			if(typepartie  == 3)
			{
				SDL_WaitEvent( &event);
				tour = p->movePlayer(event, forest->getListPtr(),forest->getP2Ref());
				p->PrintInfo();
				if(p->getLife()<=0){ end = true;}

			}
			if(typepartie  != 1)forest->print(renderer,1);
			else forest->print(renderer,0);
		}
		

		while(tour2==false && tour == true)
		{
			//cout << "tour2" << endl;

			if(typepartie  == 1)
			{
				tour2 = a->live_Ai(forest->getListPtr(),forest->getP1Ref());
				if(a->getLife()<=0){ end = true;}
			}
			if(typepartie  == 2)
			{
				tour2 = a2->live_Ai(forest->getListPtr(),forest->getP1Ref());
				if(a2->getLife()<=0){ end = true;}
			}
			if(typepartie  == 3)
			{
				SDL_WaitEvent( &event);
				tour2 = p2->movePlayer(event, forest->getListPtr(),forest->getP1Ref());
				p2->PrintInfo();
				if(p2->getLife()<=0){ end = true;}

			}
			
			forest->print(renderer,0);
		}

		tour = false;
		tour2 = false;
	}
}

  SDL_DestroyRenderer(renderer);

  end=false;

  SDL_Renderer *rende;

if (message==true && m.getGame_Type()!=-1) 
{
	rende=printEnd(forest, fenetre);
	while(!end)
	{
		if(event.window.event == SDL_WINDOWEVENT_CLOSE)
		{
			end = true;
		}
		SDL_WaitEvent( &event);
	}
}

SDL_DestroyRenderer(rende);

	delete(forest);

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