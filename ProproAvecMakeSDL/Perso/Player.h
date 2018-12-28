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
		Player(Point p);
        bool movePlayer(SDL_Event event,  vector<Objects*> &obj,Character &p);
        void print(Field f);
		void Translate(int direction, vector<Objects*> &obj,Character &p);

	    ~Player();
	private:



};

#endif
