#ifndef ROCK_H
#define ROCK_H

#include "Field.h"
#include "Objects.h"
#include "./mesformes/Forme.h"
#include "./mesformes/Point.h"
#include <SDL2/SDL.h>


class Rock :  public Objects
{
	public:

		Rock();
        Rock(Field* f,int life, int high, int FromCenterX, int FromCenterY,  int diameter , int depth);
		Rock(Forme* f,int life, int high, int diameter, int depth);
		Forme* getForme();
		void print();
        int sdl_print(SDL_Window* window);

		~Rock();

	private:
		int depth;
		Point p;
};

#endif
