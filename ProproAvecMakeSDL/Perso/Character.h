#ifndef CHARACTER_H
#define CHARACTER_H


class Character 
{

	public:
		Character();
		//Character(Point p);
		void PrintInfo();
		void attack();

	private:
		int d;
		//Formes * f;
		int life;
		int weaponDamage;

};


#endif