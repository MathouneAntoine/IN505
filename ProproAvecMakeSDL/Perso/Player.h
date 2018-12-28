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
        bool movePlayer(SDL_Event event,  vector<Objects*> &obj);
        void print(Field f);
        void Translate(int direction,  vector<Objects*> &obj);
        void Attack(int direction, int range,  vector<Objects*> &obj, int power);

		~Player();
	private:



};

#endif
