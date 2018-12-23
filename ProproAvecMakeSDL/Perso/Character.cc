#include "Character.h"
#include "../mes_formes.h"

#include <iostream>
using namespace std;
Character::Character()
{
    Point p(50,50);
	int o = rand()%4;
	if(o == 0) {this->orientation = 0;}
	if(o == 1) {this->orientation = 90;}
	if(o == 2) {this->orientation = 180;}
	if(o == 3) {this->orientation = 270;}

	this->pv = 100;
	this->weaponDamage = 50;
	this->weaponRange= 5;
    this->cerc = new Cercle();
}

Character::Character(const Point p)
{
//	this->p = new Point(p);
	this->orientation = 0;
	this->pv = 100;
	this->weaponDamage = 50;
	this->weaponRange= 5;
}

void Character::PrintInfo()
{
	cout << "Orientation = " << this->orientation << "°" << endl;
	cout << "PV = " << this->pv << endl;
	cout << "weaponDamage = " << this->weaponDamage << endl;
	cout << "weaponRange = " << this->weaponRange << endl;
}
void Character::attack()
{

}

Cercle* Character::getForme()
{
    return this->cerc;
}

Character::~Character()
{


}
