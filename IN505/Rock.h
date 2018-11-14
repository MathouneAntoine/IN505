#ifndef ROCK_H
#define ROCK_H

#include "Field.h"
#include "Forme.h"

class Rock : public Objects
{
	public:

		Rock();
		Forme getForme();
		void print();
		~Rock();

	private:

		??Forme f;
		??color c;
} 

#endif ROCK_H