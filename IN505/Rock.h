#ifndef ROCK_H
#define ROCK_H

#include "Field.h"
#include "Objects.h"
#include "mes_formes.h"

class Rock :  public Objects
{
	public:

		Rock();
		Rock(Field* field, int high, int diameter, int altitude, int FromCenterX, int FromCenterY);
		Rock(int high, int diameter, int altitude, Point center); //Le point centre doit etre deja definie par rapport au centre de la carte
		Rock(Point center);
		Forme* getForme();
		void print();
        void print_Rock();
        void print_Triangle();
		~Rock();


	private:
		int depth;

};

#endif
