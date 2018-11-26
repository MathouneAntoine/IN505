#include <SDL2/SDL.h>
#include "iostream"
SDL_Window* Init_Screen()
{
       // Notre fenêtre

    SDL_Window* window(0);


    // Initialisation de la SDL

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
    }


    // Création de la fenêtre

    window = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);


}
