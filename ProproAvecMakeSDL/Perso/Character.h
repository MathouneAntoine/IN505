#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include "../mes_formes.h"
#include "../Objects.h"

using namespace std;
class Character
{

	public:
		Character();
		Character(Point p);

		Character(const Point p, Field f);
		Character(const Point p, int orientation, int pv, int weaponDamage, int weaponRange);
        Cercle*  getForme();
        int getLife();
        int getOrientation();
        void setLife(int pv);

        virtual void print(Field f);
		void PrintInfo();
		bool collision(int x, int y,  vector<Objects*> &obj,int power,Character &p);
		bool collisionObjet(int curseur_x,int curseur_y,  vector<Objects*> &obj ,int power,Character &p);  
		void Attack(int direction, int range,  vector<Objects*> &obj, int power, Character &p);

		void takeDamage(vector<Objects*> &v ,Objects *o,int i, int power,Character &p);
		void takeDamageCharacter(Character &p, int power);

		
		 ~Character();
	protected:
		Point p;
	    Cercle *cerc;
	    int orientation;
		int pv;
		int weaponRange;
		int weaponDamage;

};


#endif
