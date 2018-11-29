#ifndef FORME_h
#define FORME_h

#include "Point.h"


class Forme
{
	protected:
		Point center;
		
	public:
		Forme();
		virtual void afficher()=0;
		~Forme();
};
#endif



