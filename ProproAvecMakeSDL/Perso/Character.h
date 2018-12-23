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
		void PrintInfo();
		void attack();
		~Character();
	protected:
		Point p;
		int orientation;
	    Cercle * cerc;

		//Formes * f;
		int pv;
		int weaponRange;
		int weaponDamage;

};


#endif
