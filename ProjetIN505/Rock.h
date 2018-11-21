#ifndef ROCK_H
#define ROCK_H

#include <QRect>
#include <QPaintEvent>
#include "Field.h"
#include "Objects.h"
#include "./mesformes/Forme.h"
#include "./mesformes/Point.h"

class Rock :  public Objects
{
	public:

		Rock();
		Rock(Field* f,int life, int high, int diameter,  int FromCenterX, int FromCenterY, int depth);
		Rock(Forme* f,int life, int high, int diameter, int depth);
		Forme* getForme();
		void print();
        QRect* printQTRock();
        void QPaintEvent(const QRect &paintRect);
		~Rock();

	private:
		int depth;
        Point p1;
        Point p2;
        Point p3;
        Point p4;
};

#endif
