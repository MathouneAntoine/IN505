#ifndef MENU_H
#define MENU_H
#include <string>
#include "Objects.h"
#include "mes_formes.h"
#include "Forest.h"
#include <GL/glu.h>
#include <SDL2/SDL.h>

using namespace std;
class Menu
{
    public:
    Menu();
    int getGame_Type();
    int getMap();
    bool init_principal();
    bool init_choix_joueur();
    bool init_choix_map();
    void print(SDL_Window* screen);
    void clic(SDL_Event &event,SDL_Window* screen);
    void Boucle_Menu(SDL_Window* screen,Forest *f);

    ~Menu();

    private:

    SDL_Surface * text[3];
    SDL_Rect rect[3];
    SDL_Surface* fond;
    int num_Menu;
    int game_type;
    int map;


};
#endif
