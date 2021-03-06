#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Forest.h"
#include "forestEditor.h"
#include "Rock.h"
#include "Tree.h"
#include "mes_perso.h"
#include "Objects.h"
#include "MouseKeyboard.h"

using namespace std;

void create_forest(Forest * f, SDL_Window * screen)
{
    message(screen);

    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(screen, -1, 0);
    if (!renderer) {
	std::cout << "SDL Error : " << SDL_GetError() << std::endl;
    }

    SDL_RenderPresent(renderer);
    SDL_Event event;
    char res = 'b';
    Point center;
    int count = 1;
    f->print(renderer, 2);
    while (res != 's' && res != 'q') {
	f->print(renderer, 2);
	while (res == 'b') {
	    SDL_WaitEvent(&event);
	    res = editor_Key(event);
	}
	while (center.getX() == 0 && center.getY() == 0 && res != 's'
	       && res != 'q') {
	    SDL_WaitEvent(&event);
	    clic(event, &center);
	}

	if (res == 'a') {
	    if (add_Tree(f, center) == true) {
		int t = f->getList().size();
		dynamic_cast <
		    Tree * >(f->getObj(t - 1))->print(f->getField());
	    }
	    res = 'b';
	}
	if (res == 'r') {
	    if (add_Rock(f, center) == true) {
		int t = f->getList().size();
		cerr << "T = " << t << endl;
		dynamic_cast <
		    Rock * >(f->getObj(t - 1))->print(f->getField());

	    }
	    res = 'b';
	}
	if (res == 'p' && count < 3) {
	    if (add_Player(f, center, count) == true) {
		if (count == 1)
		    f->getP1()->print(f->getField());
		if (count == 2)
		    f->getP2()->print(f->getField());
		count++;
	    }
	    res = 'b';
	}

	if (res == 'p' && count >= 3)
	    res = 'b';
	if (res == 's' && (f->getP1() == NULL || f->getP2() == NULL))
	    res = 'b';

	center.setX(0);
	center.setY(0);
    }
    SDL_DestroyRenderer(renderer);

    if (res == 's' && f->getP1() != NULL && f->getP2() != NULL) {
	write_Forest(f);
    }

    cout << "FIN EDITION";
}

void message(SDL_Window * screen)
{
    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(screen, -1, 0);
    if (!renderer) {
	std::cout << "SDL Error : " << SDL_GetError() << std::endl;
    }
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

    SDL_Surface *text1 = NULL;
    SDL_Surface *text2 = NULL;
    SDL_Surface *text3 = NULL;
    TTF_Font *police = NULL;
    SDL_Color c = { 255, 255, 255 };

    police = TTF_OpenFont("./edit_font.ttf", 15);
    if (!police)
	printf("TTF_OpenFont: %s\n", TTF_GetError());

    text1 =
	TTF_RenderText_Blended(police,
			       "Appuyez sur A pour placer un arbre, R pour un Rocher, P un personnage",
			       c);
    SDL_Rect Message_rect;
    Message_rect.x = 10;
    Message_rect.y = 50;
    Message_rect.w = text1->w;
    Message_rect.h = text1->h;
    SDL_Texture *Message2 = SDL_CreateTextureFromSurface(renderer, text1);
    SDL_RenderCopy(renderer, Message2, NULL, &Message_rect);

    text2 =
	TTF_RenderText_Blended(police,
			       "Puis cliquez ou vous voulez placer l'objet",
			       c);
    Message_rect.y = 150;
    Message_rect.w = text2->w;
    Message_rect.h = text2->h;
    SDL_Texture *Message3 = SDL_CreateTextureFromSurface(renderer, text2);
    SDL_RenderCopy(renderer, Message3, NULL, &Message_rect);

    text3 =
	TTF_RenderText_Blended(police,
			       "Appuyer sur S pour sauvegarder et quitter ou Q pour quitter sans sauvegarder",
			       c);
    Message_rect.y = 250;
    Message_rect.w = text3->w;
    Message_rect.h = text3->h;
    SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, text3);
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    SDL_RenderPresent(renderer);
    SDL_Event event;

    while (event.key.keysym.sym != SDLK_RETURN) {
	SDL_WaitEvent(&event);
    }

    SDL_DestroyRenderer(renderer);

}

bool add_Element(Forest * f, Objects * r, Point center)
{
    Objects *obj;
    bool ok = 0;

    int r_x = r->getCenter().getX();
    int r_y = r->getCenter().getY();
    int r_d = r->getDiameter() / 2;
    int r_h = r->getHeight() / 2;

    for (int unsigned i = 0; i < f->getList().size() && ok != 1; i++)	// On parcours tous les objets de la foret
    {
	obj = f->getObj(i);
	int obj_x = obj->getCenter().getX();
	int obj_y = obj->getCenter().getY();
	int obj_d = obj->getDiameter() / 2;
	int obj_h = obj->getHeight() / 2;

	if (((r_x + r_d >= (obj_x - (obj_d)) && r_x + r_d <= (obj_x + (obj_d))	//Test de collision entre les objets
	      && (r_y - r_h) <= (obj_y + (obj_h))
	      && (r_y - r_h) >= (obj_y - (obj_h))))
	    ||
	    ((r_x - r_d <= (obj_x + (obj_d))
	      && r_x - r_d >= (obj_x - (obj_d))
	      && (r_y - r_h) <= (obj_y + (obj_h)))
	     && (r_y - r_h) >= (obj_y - (obj_h)))
	    ||
	    ((r_x + r_d >= (obj_x - (obj_d))
	      && r_x + r_d <= (obj_x + (obj_d))
	      && (r_y + r_h) >= (obj_y - (obj_h)))
	     && (r_y + r_h) <= (obj_y + (obj_h)))
	    ||
	    ((r_x - r_d <= (obj_x + (obj_d))
	      && r_x - r_d >= (obj_x - (obj_d))
	      && (r_y + r_h) >= (obj_y - (obj_h)))
	     && (r_y + r_h) <= (obj_y + (obj_h)))
	    ||
	    ((r_x - r_d <= (obj_x - (obj_d))
	      && r_x + r_d >= (obj_x + (obj_d))
	      && (r_y - r_h) <= (obj_y + (obj_h)))
	     && (r_y + r_h) >= (obj_y + (obj_h)))
	    ||
	    ((r_x - r_d <= (obj_x - (obj_d))
	      && r_x + r_d >= (obj_x + (obj_d))
	      && (r_y + r_h) >= (obj_y - (obj_h)))
	     && (r_y + r_h) <= (obj_y + (obj_h)))
	    ||
	    ((r_y + r_h >= (obj_y + (obj_h))
	      && r_y - r_h <= (obj_y - (obj_h))
	      && (r_x + r_d) >= (obj_x - (obj_x)))
	     && (r_x + r_d) <= (obj_x + (obj_x)))) {
	    ok = 1;
	}
    }

    if (ok == 1) {
	cout << "Veuillez cliquer autre part." << endl;
	return false;
    }

    if (ok == 0) {
	if (f->getP1() != NULL)	// Test si on collisionne avec p1
	{
	    ok = collision_perso(f, r, center, 1);
	}

	if (f->getP2() != NULL)	// Test si on collisionne avec p2
	{
	    ok = collision_perso(f, r, center, 2);
	}
    }


    if (ok == 0)		//Si il n'y a eu aucune collision, on ajoute l'objet à la liste de la foret et on return TRUE
    {
	f->addList(r);

	return true;
    }


    return false;
}

bool collision_perso(Forest * f, Objects * r, Point center, int p)
{
    int obj_x = 0;
    int obj_y = 0;
    int obj_d = 0;
    int obj_h = 0;

    if (p == 1) {
	obj_x = f->getP1()->getForme()->getCenter().getX();
	obj_y = f->getP1()->getForme()->getCenter().getY();
	obj_d = f->getP1()->getForme()->getDiametre() / 2;
	obj_h = obj_d;
    }
    if (p == 2) {
	obj_x = f->getP2()->getForme()->getCenter().getX();
	obj_y = f->getP2()->getForme()->getCenter().getY();
	obj_d = f->getP2()->getForme()->getDiametre() / 2;
	obj_h = obj_d;
    }
    int r_x = r->getCenter().getX();
    int r_y = r->getCenter().getY();
    int r_d = r->getDiameter() / 2;
    int r_h = r->getHeight() / 2;

    if (((r_x + r_d >= (obj_x - (obj_d)) && r_x + r_d <= (obj_x + (obj_d))
	  && (r_y - r_h) <= (obj_y + (obj_h))
	  && (r_y - r_h) >= (obj_y - (obj_h))))
	||
	((r_x - r_d <= (obj_x + (obj_d)) && r_x - r_d >= (obj_x - (obj_d))
	  && (r_y - r_h) <= (obj_y + (obj_h)))
	 && (r_y - r_h) >= (obj_y - (obj_h)))
	||
	((r_x + r_d >= (obj_x - (obj_d)) && r_x + r_d <= (obj_x + (obj_d))
	  && (r_y + r_h) >= (obj_y - (obj_h)))
	 && (r_y + r_h) <= (obj_y + (obj_h)))
	||
	((r_x - r_d <= (obj_x + (obj_d)) && r_x - r_d >= (obj_x - (obj_d))
	  && (r_y + r_h) >= (obj_y - (obj_h)))
	 && (r_y + r_h) <= (obj_y + (obj_h)))
	||
	((r_x - r_d <= (obj_x - (obj_d)) && r_x + r_d >= (obj_x + (obj_d))
	  && (r_y - r_h) <= (obj_y + (obj_h)))
	 && (r_y + r_h) >= (obj_y + (obj_h)))
	||
	((r_x - r_d <= (obj_x - (obj_d)) && r_x + r_d >= (obj_x + (obj_d))
	  && (r_y + r_h) >= (obj_y - (obj_h)))
	 && (r_y + r_h) <= (obj_y + (obj_h)))
	||
	((r_y + r_h >= (obj_y + (obj_h)) && r_y - r_h <= (obj_y - (obj_h))
	  && (r_x + r_d) >= (obj_x - (obj_x)))
	 && (r_x + r_d) <= (obj_x + (obj_x))))
	return 1;
    else
	return 0;
}

bool add_Rock(Forest * f, Point center)
{
    center.setX(center.getX() - (f->getField().getWidth() / 2));
    center.setY(center.getY() - (f->getField().getHeight() / 2));
    return add_Element(f, new Rock(center), center);
}

bool add_Tree(Forest * f, Point center)
{

    center.setX(center.getX() - (f->getField().getWidth() / 2));
    center.setY(center.getY() - (f->getField().getHeight() / 2));
    return add_Element(f, new Tree(center), center);
}

bool add_Player(Forest * f, Point center, int i)
{
    center.setX(center.getX() - (f->getField().getWidth() / 2));
    center.setY(center.getY() - (f->getField().getHeight() / 2));
    Character *c = new Character(center);
    cout << "Perso x" << c->getForme()->getCenter().
	getX() << " Y " << c->getForme()->getCenter().getY() << endl;
    Objects *obj;
    bool ok = 0;

    int cx_pr =c->getForme()->getCenter().getX() +(c->getForme()->getDiametre() / 2); 
    int cy_pr =c->getForme()->getCenter().getY() +(c->getForme()->getDiametre() / 2);
    int cx_mr =c->getForme()->getCenter().getX() -(c->getForme()->getDiametre() / 2);
    int cy_mr =c->getForme()->getCenter().getY() -(c->getForme()->getDiametre() / 2);

    for (int unsigned i = 0; i < f->getList().size() && ok != 1; i++)	//Parcours la liste des objet
    {
	obj = (f->getList())[i];
	int rx = obj->getCenter().getX();
	int ry = obj->getCenter().getY();
	int rd = obj->getDiameter() / 2;
	int obj_h = obj->getHeight() / 2;


	if (((cx_pr > (rx - rd) && cx_pr < (rx + rd)
	      && cy_pr < (ry + (obj_h)) && cy_pr > (ry - (obj_h))))
	    || (cx_mr < (rx + rd) && cx_mr > (rx - rd)
		&& cy_mr < (ry + (obj_h))
		&& cy_pr > (ry - (obj_h))) || (cx_mr > (rx - rd)
					       && cx_mr < (rx + rd)
					       && cy_mr > (ry - (obj_h))
					       && cy_pr < (ry + (obj_h)))
	    || (cx_mr < (rx + rd) && cx_mr > (rx - rd)
		&& cy_pr > (ry - (obj_h))
		&& cy_mr < (ry + (obj_h))))
	    ok = 1;
    }

    if (ok == 1) {
	cout << "Veuillez cliquer autre part." << endl;
	return false;
    }

    if (ok == 0 && (i == 1 || i == 2)) {
	if (i == 1) {
	    cout << "ADD 1" << endl;
	    f->setP1(c);
	}
	if (i == 2) {
	    cout << "ADD 2" << endl;
	    f->setP2(c);
	}
	return true;
    }
    return false;
}

void write_Forest(Forest * f)
{
    ofstream file("Saves/personalisee.txt", ios::out | ios::trunc);

    if (file) {
	for (int unsigned i = 0; i < f->getList().size(); i++) { // on parcours tous les objets ajouter à la foret et on les écrit
	    if (dynamic_cast < Rock * >(f->getList()[i]))
		write_Rock(dynamic_cast < Rock * >(f->getList()[i]), file);
	    if (dynamic_cast < Tree * >(f->getList()[i]))
		write_Tree(dynamic_cast < Tree * >(f->getList()[i]), file);
	}

	write_Character(f->getP1(), file, 1); // On ecrit les personnages
	write_Character(f->getP2(), file, 2);

	file.close();
    } else
	std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
}

void write_Rock(Rock * r, ofstream & file) // Ecriture dans le fichier
{
    file << "R" << " " << r->getCenter().getX() << " " << r->
	getCenter().getY();
    file << " " << r->getHeight() << " " << r->
	getDiameter() << " " << r->getAltitude();
    file << " " << r->getLife() << " " << r->getType() << endl;
}

void write_Tree(Tree * t, ofstream & file)
{
    file << "T" << " " << t->getCenter().getX() << " " << t->
	getCenter().getY();
    file << " " << t->getHeight() << " " << t->
	getDiameter() << " " << t->getAltitude();
    file << " " << t->getLife() << " " << t->getType() << endl;
}

void write_Character(Character * c, ofstream & file, int i)
{
    file << "C" << i << " " << c->getForme()->
	getCenter().getX() << " " << c->getForme()->getCenter().
	getY() << endl;
}

Forest *read_File(Forest * f, int type, int map)	//type : 0 joueur/ia ; 1- ia/ia ; 2- joueur/joueur
{

    ifstream file;

    if (map == 1) // On lit le fichier selectionné depuis le menu
	file.open("./Saves/difficile.txt", ios::in);
    if (map == 2)
	file.open("./Saves/normal.txt", ios::in);
    if (map == 3)
	file.open("./Saves/personalisee.txt", ios::in);
    file.seekg(0, ios::beg); // On place le curseur au debut

    char c, t;
    Point center;
    int height, diameter, altitude, life, x, y;
    int i = 0;

    if (file) {
	while (!file.eof()) {
	    file >> c;

	    if (file.tellg() != -1)
		switch (c) { // On lit le premier caractere de chaque ligne, si c'est un R on lit un Rocher, si c'est un T on lit un arbre, un C un personnage
		case 'R':
		    {
			file >> x >> y >> height >> diameter >> altitude >> life >> t;
			cout << "ROCHER --" << x << " " << y << " " << height << " " << diameter << " " << altitude <<" " << life << " " << t << "--ROCHER " << endl;
			center.setX(x);
			center.setY(y);
			Objects *r =
			    new Rock(t, center, height, diameter, altitude, life);
			f->addList(r);
		    }
		    break;

		case 'T':
		    {
			file >> x >> y >> height >> diameter >> altitude >> life >> t;
			cout << "TREE --" << x << " " << y << " " << height << " " << diameter << " " << altitude << " " << life << " " << t << "--TREE" << endl;
			center.setX(x);
			center.setY(y);
			Objects *r =
			    new Tree(t, center, height, diameter, altitude, life);
			f->addList(r);
		    }
		    break;

		case 'C':
		    {
			file >> i >> x >> y;
			cout << "PERSO --" << i << " " << x << " " << y <<"-- PERSO" << endl;
			center.setX(x);
			center.setY(y);
			cout << "TYPE  : " << type << endl;

			if (i == 1 && (type == 1 || type == 3)) { //Si on doit creer au moins un joueur
			    f->setP1(new Player(center));
			}
			if (i == 1 && type == 2) { // Si il y a 2 ia
			    f->setP1(new Ai(center));
			}

			if (i == 2 && (type == 1 || type == 2)) { // Si il y a au moin une ia
			    f->setP2(new Ai(center));
			}
			if (i == 2 && type == 3) { // Si il y a 2 joueurs
			    f->setP2(new Player(center));
			}

			if (i != 1 && i != 2)
			    cout << "ERREUR LECTURE FICHIER PERSO";
		    }

		    break;

		default:
		    cout << "Erreur lecture";

		}
	}

	file.close();
    } else
	cerr << "Impossible d'ouvrir le fichier !" << endl;

    return f;
}
