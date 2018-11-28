#include <iostream>
#include "Rectangle.h"

int main(int argc, char const *argv[])
{
	
	Point centre=Point(50,50);

	Rectangle* r = new Rectangle(centre, 10, 20);
	r->afficher();
	return 0;
}