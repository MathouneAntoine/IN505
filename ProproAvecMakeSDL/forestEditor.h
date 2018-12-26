#ifndef FORESTEDITOR_H
#define FORESTEDITOR_H

#include <string>
#include "Forest.h"
#include "Rock.h"
#include "Tree.h"
#include "mes_perso.h"
#include "Objects.h"

class forestEditor
{
	public:
		forestEditor();

		void create_forest(Forest *f, SDL_Window* screen,SDL_Surface* pSurf);

		bool add_Element(Forest *f, Objects* r, Point center);
		bool add_Rock(Forest *f, Point center);
		bool add_Tree(Forest *f, Point center);
		bool add_Player(Forest *f, Point center, int i);

		void write_Forest(Forest* f);
		void write_Rock(Rock * r, std::ofstream &file);
		void write_Tree(Tree* t, std::ofstream &file);
		void write_Character(Character* c, std::ofstream &file,int i);

		Forest* read_File(Forest *f, std::string s);

		~forestEditor();

	private:

};
#endif