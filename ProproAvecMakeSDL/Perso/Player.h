#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include "Character.h"
class Player: public Character
{
	public:
		Player();
        void movePlayer(SDL_Event event , int x, int y);
        void print();
        void Translate(int direction);


		~Player();
	private:



};

#endif
