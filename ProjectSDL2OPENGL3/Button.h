#ifndef BUTTON_H
#define BUTTON_H
#include "./mesformes/Rectangle.h"
#include <string>
#include "Objects.h"
#include "mes_formes.h"
#include <GL/glu.h>

using namespace std;
class Button
{
    public:
    Button();
    void print();
    void print_button();
    void vBitmapOutput(int x, int y, char *string, void *font);
    void vStrokeOutput(GLfloat x, GLfloat y, char *string, void *font);

    ~Button();

    private:
    string message;
    Rectangle * rect;

    enum Etat {SURVOLE, ENFONCE, PAS_SURVOLE};
    Button::Etat etat;
    Button::Etat lectureEtatBouton(void);


};
#endif
