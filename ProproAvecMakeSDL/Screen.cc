#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "Field.h"

SDL_Window *Screen_Init(int argc, char *argv[], Field f)
{

    SDL_Window *fenetre(0);

    // Initialisation de la SDL

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	std::cout << "Erreur lors de l'initialisation de la SDL : " <<
	    SDL_GetError() << std::endl;
	SDL_Quit();

	exit(0);
    }
    // Version d'OpenGL

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Double Buffer

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


    // Création de la fenêtre

    fenetre =
	SDL_CreateWindow("FOREST GAME", SDL_WINDOWPOS_CENTERED,
			 SDL_WINDOWPOS_CENTERED, f.getWidth(),
			 f.getHeight(),
			 SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (fenetre == 0) {
	std::cout << "Erreur lors de la creation de la fenetre : " <<
	    SDL_GetError() << std::endl;
	SDL_Quit();

	exit(0);
    }

    return fenetre;


}
