#ifndef ROCK_H
#define ROCK_H

#include "Field.h"
#include "Objects.h"
#include "mes_formes.h"

class Rock :  public Objects
{
	public:

		Rock();
		Rock(Field* field, int height, int diameter, int altitude, int FromCenterX, int FromCenterY);
		Rock(Point center);
		Rock(char t, Point center, int height, int diameter, int altitude, int life);
		void print();
        void print_Rock();
		~Rock();


	private:
		int depth;

};

#endif
