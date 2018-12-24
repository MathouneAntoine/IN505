#ifndef FORESTACTION_H
#define FORESTACTION_H
#include "./mes_formes.h"
#include "Forest.h"

class ForestAction : public Forest
{
	public:
	bool colisionObjet(int curseur_x,int curseur_y);
	bool colision(int x, int y);
	private:
	Forme* forme;


};
#endif	