#ifndef Ai_H
#define Ai_H
#include "Character.h"
#include "../mes_formes.h"
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;
class Ai :public  Character
{
	public:
		Ai();
		void live_Ai();
		void print();

		void Translate(int direction);

		~Ai();
	private:

};

#endif
