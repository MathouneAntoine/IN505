#ifndef FORME_h
#define FORME_h

#include "Point.h"


class Forme
{
	protected:
		Point center;
		
	public:
		Forme();
		Point getCenter();
		virtual void afficher()=0;
		virtual ~Forme();
};
#endif



