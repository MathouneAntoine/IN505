#ifndef CHARACTER_H
#define CHARACTER_H

#include "../mes_formes.h"

class Character
{

	public:
		Character();
		Character(const Point p);
		Character(const Point p, int orientation, int pv, int weaponDamage, int weaponRange);
        Cercle*  getForme();
        virtual void print();
		void PrintInfo();
		bool colisionObjet(int curseur_x,int curseur_y);
		bool colision(int x, int y);
		~Character();
	protected:
		Point p;
	    Cercle * cerc;
	    int orientation;
		int pv;
		int weaponRange;
		int weaponDamage;

};


#endif
