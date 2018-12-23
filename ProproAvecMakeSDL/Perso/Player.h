#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
class Player : public Character
{
	public:
		Player();
        void movePlayer(SDL_Event event , int x, int y);
        void print_Player();
        void Translate(int direction);


		~Player();
	private:



};










#endif
