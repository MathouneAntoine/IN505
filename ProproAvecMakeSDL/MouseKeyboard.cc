#include <SDL2/SDL.h>
#include <iostream>
#include "MouseKeyboard.h"
#include "mes_formes.h"

void MouseKeyboard(SDL_Event &event)
{

            switch(event.type)
                {
                    case SDL_QUIT:
                    exit(0);
                    break;

                    case SDL_KEYDOWN:
                    std::cout <<"touche enfoncee"<<std::endl;
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP:
                        std::cout <<"Up"<<std::endl;

                        break;
                        case SDLK_DOWN:
                        std::cout <<"Down"<<std::endl;

                        break;
                        case SDLK_RIGHT:
                        std::cout <<"Right"<<std::endl;

                        break;
                        case SDLK_LEFT:
                        std::cout <<"Left"<<std::endl;
                        break;
                    }

                    case SDL_MOUSEBUTTONDOWN:

                    switch(event.button.button)
                    {
                         case SDL_BUTTON_RIGHT:
                         std::cout <<"Clic Right"<<std::endl;
                         std::cout<< "m_x = " << event.motion.x <<std::endl;
                         std::cout<< "m_y = " << event.motion.y<<std::endl;
                         break;

                          case SDL_BUTTON_LEFT:
                         std::cout <<"Clic Left"<<std::endl;
                         std::cout<< "m_x = " << event.motion.x <<std::endl;
                         std::cout<< "m_y = " << event.motion.y<<std::endl;
                         break;

                         default:
                         break;
                    }

                   /* case SDL_MOUSEMOTION:
                        cout<< "m_x = " << event.motion.x << endl;
                        cout<< "m_y = " << event.motion.y<<endl;
                        break;*/

                break;
                }
  //  }
}

int Menu1or2 (SDL_Event &event)
{
    int res=0;
  
   if (event.type== SDL_QUIT)
    {    
        std::cout <<"Sortie"<<std::endl;
        res = -1;
    }
    if (event.type == SDL_KEYDOWN) 
     switch(event.key.keysym.sym)
                    {
                        case SDLK_1:
                        std::cout <<"1"<<std::endl;
                        res=1;
                        break;
                        


                        case SDLK_2:
                        std::cout <<"2"<<std::endl;
                        res=2;
                        break;
                    }
    return res;
}

char editor_Key(SDL_Event &event)
{
    char c='b';
            switch(event.type)
                {
                    case SDL_QUIT:
                    exit(0);
                    break;

                    case SDL_KEYDOWN:
                    std::cout <<"touche enfoncee"<<std::endl;
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_a:
                        std::cout <<"A"<<std::endl;
                        c='a';

                        break;
                        case SDLK_r:
                        std::cout <<"R"<<std::endl;
                        c='r';

                        break;
                        case SDLK_s:
                        std::cout <<"S"<<std::endl;
                        c='s';

                        break;
                        case SDLK_q:
                        std::cout <<"Q"<<std::endl;
                        c='q';

                        break;
                    }
                break;
                }
    return c;
}

void clic(SDL_Event &event, Point* clic)
{
        switch(event.type)
                {
                    case SDL_QUIT:
                    exit(0);
                    break;

                    case SDL_MOUSEBUTTONDOWN:

                     switch(event.button.button)
                    {
                         case SDL_BUTTON_LEFT:
                         std::cout <<"Clic Left"<<std::endl;
                         std::cout<< "m_x = " << event.motion.x <<std::endl;
                         std::cout<< "m_y = " << event.motion.y<<std::endl;
                          clic->setX(event.motion.x);
                         clic->setY(event.motion.y);
                         break;

                         default:
                         break;
                    }
                }
}