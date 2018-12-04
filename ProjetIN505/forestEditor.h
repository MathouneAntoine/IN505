#ifndef FORESTEDITOR_H
#define FORESTEDITOR_H

#include "Forest.h"
#include "Rock.h"
#include "Tree.h"
#include "mes_perso.h"
#include "Objects.h"

class forestEditor
{
	public:
		forestEditor();

		void create_forest(Forest f);

		Forest add_Element(Forest f, Objects* r, Point center);
		Forest add_Rock(Forest f, Point center);
		Forest add_Tree(Forest f, Point center);
		Forest add_Player(Forest f, Point center);
		Forest add_Ai(Forest f, Point center);

		void write_Forest(Forest f);
		void write_Rock(Rock * r, std::ofstream &file);
		void write_Tree(Tree* t, std::ofstream &file);
		void write_Character1(Character* c, std::ofstream &file);
		void write_Character2(Character* c, std::ofstream &file);

		Forest read_File(Forest f);
		Forest read_Rock(Forest f);
		Forest read_Tree(Forest f);
		Forest read_Character1(Forest f);
		Forest read_Character2(Forest f);

		~forestEditor();

	private:

};
#endif