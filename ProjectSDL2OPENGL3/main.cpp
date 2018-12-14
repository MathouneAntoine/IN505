#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <SDL2/SDL.h>
#include <iostream>
#include "Rock.h"
#include "Tree.h"
#include "Button.h"
#include "Screen.h"
#include "./mesformes/Point.h"
#include "MouseKeyboard.h"

int main(int argc, char **argv)
{
     // Notre fenêtre

    SDL_Window* fenetre = Screen_Init(argc, argv);
    SDL_GLContext contexteOpenGL(0);

    SDL_Event evenements;
    bool terminer(false);




    // Création du contexte OpenGL





    // Vertices et coordonnées
    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(fenetre, -1, 0);
    if(!renderer)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_RenderPresent(renderer); //Dessiner entre 2 render


 Field* f= new Field(250,250);

    Rock* R= new Rock(f,30, 100, 3, 60, 60);
    R->print_Rock();
    R->print();
    // Boucle principale
      SDL_RenderPresent(renderer);

    SDL_Event event;
    int x,y;

    bool end;
    end = false;
    while(!end)
    {
        SDL_WaitEvent(&event);
        SDL_GetMouseState(&x, &y);

        if(event.window.event == SDL_WINDOWEVENT_CLOSE)
        {
            end = true;
        }
        MouseKeyboard(event);

    }


        // Nettoyage de l'écran
        //glClear(GL_COLOR_BUFFER_BIT);

        // Actualisation de la fenêtre
        //SDL_GL_SwapWindow(fenetre);



    // On quitte la SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return 0;
}
