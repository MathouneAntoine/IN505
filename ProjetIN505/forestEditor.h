#ifndef FORESTEDITOR_H
#define FORESTEDITOR_H

#include "Forest.h"

class forestEditor
{
	public:
		forestEditor();

		void create_forest();

		Forest add_Element();
		Forest add_Rock();
		Forest add_Tree();
		Forest add_Character1();
		Forest add_Character2();

		Forest write_Element();
		Forest write_Rock();
		Forest write_Tree();
		Forest write_Character1();
		Forest write_Character2();

		Forest read_File();
		Forest read_Rock();
		Forest read_Tree();
		Forest read_Character1();
		Forest read_Character2();

		~forestEditor();

	private:

};
#endif