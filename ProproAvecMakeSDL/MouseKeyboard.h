#ifndef MOUSEKEYBOARD_H
#define MOUSEKEYBOARD_H

#include "mes_formes.h"

void MouseKeyboard(SDL_Event &event);
int Menu1or2(SDL_Event &event);
char editor_Key(SDL_Event &event);
void clic(SDL_Event &event,Point* clic);

#endif