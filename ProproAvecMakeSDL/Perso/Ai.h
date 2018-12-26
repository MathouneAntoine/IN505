#ifndef Ai_H
#define Ai_H
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "../Forest.h"
#include "Character.h"
#include "../mes_formes.h"

using namespace std;


class Ai : public  Character
{
	public:
		Ai();
		void live_Ai(vector<Objects*> obj);
		void print();

		void Translate(int direction, vector<Objects*> obj);

		~Ai();
	private:

};

#endif
