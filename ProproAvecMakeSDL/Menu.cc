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

int Menu::getGame_Type() {return game_type ;}
int Menu::getMap(){return map;}

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
  text[1]=TTF_RenderText_Blended(police, "* Normal *", c); 
  text[2]=TTF_RenderText_Blended(police, "* Personnalisee *", c); 
  
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
     Forest *f=new Forest();
     forestEditor edit;

    if((rect[0].x<x)&&(rect[0].x+rect[0].w>x)&&(rect[0].y<y)&&(rect[0].y+rect[0].h>y))
    {

        switch (num_Menu)
        {
            case(0):
               init_choix_joueur(); //lance partie
              print(screen);
            break;
            case(1):
              game_type=1; // joueur vs Ia
              init_choix_map(); 
              print(screen);
            break;
            case(2):
              map=1;
               end_menu=1;
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
              cout<<"edit"<<endl;//edition
              edit.create_forest(f, screen, pSurf);
              init_principal();
              print(screen);
            }
            break;
            case(1):
            game_type=2; //ia vs ia
            init_choix_map(); 
            print(screen);
            break;
            case(2):
              map=2;
               end_menu=1;
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
                end_menu= -1;
            break;
            case(1):
              game_type=3; // joueur vs joueur
              init_choix_map(); 
             print(screen);
            break;
            case(2):
            map=3;
            end_menu=1;
            break;
            default:
            end_menu=1;
            game_type=-1;

        }
    }
  }
}

void Menu::print(SDL_Window* screen)

{
  SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(screen, -1, 0);
    if(!renderer)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
    }
    SDL_RenderPresent(renderer);

    if(fond && text[0] && text[1] && text[2])
    {
      rect[0].x=400- rect[0].w/2 ; rect[0].y=150;
      rect[1].x=400- rect[1].w/2 ; rect[1].y=250;
      rect[2].x=400- rect[2].w/2 ; rect[2].y=350;

        SDL_Texture* f = SDL_CreateTextureFromSurface(renderer, fond);
        SDL_Texture* b0 = SDL_CreateTextureFromSurface(renderer, text[0]);
        SDL_Texture* b1 = SDL_CreateTextureFromSurface(renderer, text[1]);
        SDL_Texture* b2 = SDL_CreateTextureFromSurface(renderer, text[2]); 

        SDL_RenderCopy(renderer, f, NULL, NULL);
        SDL_RenderCopy(renderer, b0, NULL, &rect[0]);
        SDL_RenderCopy(renderer, b1, NULL, &rect[1]);
        SDL_RenderCopy(renderer, b2, NULL, &rect[2]);

         SDL_RenderPresent(renderer);
         SDL_DestroyRenderer(renderer);
    }
}

int Menu::Boucle_Menu(SDL_Window* screen, Forest *f)
{

    SDL_Event event;
    SDL_Surface* pSurf = SDL_GetWindowSurface(screen);

    TTF_Init();

    init_principal();
    print( screen);    

    while (!end_menu)
    {
     SDL_WaitEvent(&event);  
     MouseKeyboard(event);
     clic(event, pSurf, screen);
    } 

   SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(screen, -1, 0);
    if(!renderer)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
    }

    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

    if(game_type !=-1)
    {
    forestEditor fe;
    fe.read_File(f, game_type, map);
    }
    SDL_DestroyRenderer(renderer);
}

Menu::~Menu()
{
    for(int i=0;i<3;i++)
       {
         SDL_FreeSurface(text[i]) , text[i] = NULL;
       }
       
}
