#ifndef ROCK_H
#define ROCK_H

#include "Field.h"
#include "Objects.h"
#include "mes_formes.h"

class Rock :  public Objects
{
	public:

		Rock();
		Rock(Field* f,int life, int high, int diameter, int depth, int FromCenterX, int FromCenterY);
		Rock(Forme* f,int life, int high, int diameter, int depth);
		Forme* getForme();
		void print();
        void print_Rectangle();
        void print_Triangle();
		~Rock();


	private:
		int depth;

};

#endif
