#include "Menu.h"
#include "./mesformes/Point.h"
#include "./mesformes/Rectangle.h"
#include <iostream>
#include "Objects.h"
#include "mes_formes.h"
#include "Forest.h"
#include "forestEditor.h"
#include "MouseKeyboard.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

int end_menu=0;


Menu::Menu()
{
    fond = SDL_LoadBMP("./fond.bmp");
    int i;
    for(i=0;i<4;i++)
    {
        text[i] = NULL;
    }
    game_type=-1;
    map=-1;

}

bool Menu::init_principal()
{
  num_Menu=0;

  TTF_Font * police = NULL;
  SDL_Color c = {38, 26, 13};

  police = TTF_OpenFont("./font.ttf", 50);
    if(!police) printf("TTF_OpenFont: %s\n", TTF_GetError());

  text[0]=TTF_RenderText_Blended(police, "* Jouer *", c); 
  text[1]=TTF_RenderText_Blended(police, "* Editer *", c); 
  text[2]=TTF_RenderText_Blended(police, "* Quitter *", c); 

  rect[0].w = text[0]->w;
  rect[0].h = text[0]->h;

  rect[1].w = text[1]->w;
  rect[1].h = text[1]->h;
    
  rect[2].w = text[2]->w;
  rect[2].h = text[2]->h;

TTF_CloseFont(police);
   return true;
}

bool Menu::init_choix_joueur()
{
  num_Menu=1;

  TTF_Font * police = NULL;
  SDL_Color c = {38, 26, 13};

  police = TTF_OpenFont("./font.ttf", 45);
    if(!police) printf("TTF_OpenFont: %s\n", TTF_GetError());

  text[0]=TTF_RenderText_Blended(police, "* Joueur vs IA *", c); 
  text[1]=TTF_RenderText_Blended(police, "* IA vs IA *", c); 
  text[2]=TTF_RenderText_Blended(police, "* Joueur vs Joueur *", c); 

  rect[0].w = text[0]->w;
  rect[0].h = text[0]->h;

  rect[1].w = text[1]->w;
  rect[1].h = text[1]->h;
    
  rect[2].w = text[2]->w;
  rect[2].h = text[2]->h;

TTF_CloseFont(police);
  return true;
}

bool Menu::init_choix_map()
{
  num_Menu=2;

  TTF_Font * police = NULL;
  SDL_Color c = {38, 26, 13};

  police = TTF_OpenFont("./font.ttf", 45);
    if(!police) printf("TTF_OpenFont: %s\n", TTF_GetError());

  text[0]=TTF_RenderText_Blended(police, "* Difficile *", c); 
  text[1]=TTF_RenderText_Blended(police, "* Moyen *", c); 
  text[2]=TTF_RenderText_Blended(police, "* Facile *", c); 
  
  rect[0].w = text[0]->w;
  rect[0].h = text[0]->h;

  rect[1].w = text[1]->w;
  rect[1].h = text[1]->h;
    
  rect[2].w = text[2]->w;
  rect[2].h = text[2]->h;
  TTF_CloseFont(police);

   return true;
}
        
int Menu::clic(SDL_Event &event,SDL_Surface* pSurf, SDL_Window* screen)
{

   if (event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT)
   {
     int x= event.motion.x;
     int y= event.motion.y;
      Forest f;
      forestEditor edit;

    if((rect[0].x<x)&&(rect[0].x+rect[0].w>x)&&(rect[0].y<y)&&(rect[0].y+rect[0].h>y))
    {

        switch (num_Menu)
        {
            case(0):
               init_choix_joueur(); //lance partie
               print(pSurf, screen);
            break;
            case(1):
              game_type=1;
              init_choix_map(); 
              print(pSurf, screen);
            break;
            case(2):
              map=1;
                //map difficile
            break;
            default:
            exit(0);
        }
    }

    if((rect[1].x<x)&&(rect[1].x+rect[1].w>x)&&(rect[1].y<y)&&(rect[1].y+rect[1].h>y))
    {

        switch (num_Menu)
        {
            case(0):
            {
             for(int i=0;i<3;i++)
            
       {
         SDL_FreeSurface(text[i]) , text[i] = NULL;
       }
              cout<<"edit"<<endl;//edition
              edit.create_forest(f, screen, pSurf);
              end_menu=1;
            }
            break;
            case(1):
            game_type=2;
            init_choix_map(); 
            print(pSurf, screen);
            break;
            case(2):
              map=2;
            break;
            default:
            exit(0);

        }
    }

    if((rect[2].x<x)&&(rect[2].x+rect[2].w>x)&&(rect[2].y<y)&&(rect[2].y+rect[2].h>y))
    {

        switch (num_Menu)
        {
            case(0):
                cout<<"quitter"<<endl;//quitter
            break;
            case(1):
              game_type=3;
              init_choix_map(); 
              print(pSurf, screen);
            break;
            case(2):
            map=3;
            break;
            default:
            exit(0);

        }
    }
  }
}

void Menu::print(SDL_Surface* pSurf, SDL_Window* screen)
{
    if(fond && text[0] && text[1] && text[2])
    {
      rect[0].x=400- rect[0].w/2 ; rect[0].y=150;
      rect[1].x=400- rect[1].w/2 ; rect[1].y=250;
      rect[2].x=400- rect[2].w/2 ; rect[2].y=350;

      
        SDL_BlitSurface(fond,NULL,pSurf,NULL);
        SDL_BlitSurface(text[0],NULL,pSurf,&rect[0]);
        SDL_BlitSurface(text[1],NULL,pSurf,&rect[1]);
        SDL_BlitSurface(text[2],NULL,pSurf,&rect[2]);
        SDL_UpdateWindowSurface(screen);
    }
}

void Menu::Boucle_Menu(SDL_Window* screen)
{

    SDL_Event event;
    SDL_Surface* pSurf = SDL_GetWindowSurface(screen);

    TTF_Init();

    init_principal();
    print(pSurf, screen);
    

    while (!end_menu)
    {
     SDL_WaitEvent(&event);  
     MouseKeyboard(event);
     clic(event, pSurf, screen);
    } 

}

Menu::~Menu()
{
    for(int i=0;i<3;i++)
       {
         SDL_FreeSurface(text[i]) , text[i] = NULL;
       }
       
}