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
        bool movePlayer(SDL_Event event , int x, int y, vector<Objects*> obj);
        void print(Field f);
        void Translate(int direction,  vector<Objects*> obj);
        //void Attack(int direction, int range, int power,  vector<Objects*> obj);

		~Player();
	private:



};

#endif
