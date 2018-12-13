#include <SDL.h>
#include <iostream>
using namespace std;
void MouseKeyboard()
{

   // while(!end)
   // {
            // Gestion des évènements
        //SDL_WaitEvent(&event);
       // int x,y;
     //   SDL_GetMouseState(&x, &y);


            switch(event.type)
                {
                    case SDL_QUIT:
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
