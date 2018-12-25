#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <vector>

#include "Character.h"
#include "../Objects.h"


using namespace std;
class Player: public Character
{
	public:
		Player();
        void movePlayer(SDL_Event event , int x, int y, vector<Objects*> obj);
        void print();
        void Translate(int direction,  vector<Objects*> obj);

		~Player();
	private:



};

#endif
