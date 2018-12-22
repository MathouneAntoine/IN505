#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

void MouseKeyboard(SDL_Event &event)
{

            switch(event.type)
                {
                    case SDL_QUIT:
                    exit(0);
                    break;

                    case SDL_KEYDOWN:
                    cout <<"touche enfoncee"<<endl;
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP:
                        cout <<"Up"<<endl;

                        break;
                        case SDLK_DOWN:
                        cout <<"Down"<<endl;

                        break;
                        case SDLK_RIGHT:
                        cout <<"Right"<<endl;

                        break;
                        case SDLK_LEFT:
                        cout <<"Left"<<endl;
                        break;
                    }

                    case SDL_MOUSEBUTTONDOWN:

                    switch(event.button.button)
                    {
                         case SDL_BUTTON_RIGHT:
                         cout <<"Clic Right"<<endl;
                         cout<< "m_x = " << event.motion.x << endl;
                         cout<< "m_y = " << event.motion.y<<endl;
                         break;

                          case SDL_BUTTON_LEFT:
                         cout <<"Clic Left"<<endl;
                         cout<< "m_x = " << event.motion.x << endl;
                         cout<< "m_y = " << event.motion.y<<endl;
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
        cout <<"Sortie"<<endl;
        res = -1;
    }
    if (event.type == SDL_KEYDOWN) 
     switch(event.key.keysym.sym)
                    {
                        case SDLK_1:
                        cout <<"1"<<endl;
                        res=1;
                        break;
                        


                        case SDLK_2:
                        cout <<"2"<<endl;
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
                    cout <<"touche enfoncee"<<endl;
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_A:
                        cout <<"A"<<endl;
                        c='a';

                        break;
                        case SDLK_R:
                        cout <<"R"<<endl;
                        c='r';

                        break;
                        case SDLK_S:
                        cout <<"S"<<endl;
                        c='s';

                        break;
                        case SDLK_Q:
                        cout <<"Q"<<endl;
                        c='q';

                        break;
                    }
                break;
                }
    return c;
}