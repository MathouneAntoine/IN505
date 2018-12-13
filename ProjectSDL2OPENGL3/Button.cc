#include "Button.h"
#include "./mesformes/Point.h"
#include "./mesformes/Rectangle.h"
#include <iostream>
#include "Objects.h"
#include "mes_formes.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;


Button::Button()
{
    Point center(200,200);
    this->rect = new Rectangle(center, 50, 20);;
}




void Button::print()
{
    cout << "Bouton" << endl;
    this->rect->afficher();

}
void Button::vBitmapOutput(int x, int y, char *string, void *font)  //from http://mperriss.free.fr/opengl/Guide_2D/texte.htm
{
    int len,i; // len donne la longueur de la chaîne de caractères

    glRasterPos2f(x,y); // Positionne le premier caractère de la chaîne
    len = (int) strlen(string); // Calcule la longueur de la chaîne
    for (i = 0; i < len; i++) glutBitmapCharacter(font,string[i]); // Affiche chaque caractère de la chaîne
}

void Button::vStrokeOutput(GLfloat x, GLfloat y, char *string, void *font)  // from http://mperriss.free.fr/opengl/Guide_2D/texte.htm
{
    char *p;

    glPushMatrix();	// glPushMatrix et glPopMatrix sont utilisées pour sauvegarder
    // et restaurer les systèmes de coordonnées non translatés
    glTranslatef(x, y, 0); // Positionne le premier caractère de la chaîne
    for (p = string; *p; p++) glutStrokeCharacter(font, *p); // Affiche chaque caractère de la chaîne
    glPopMatrix();
}

void Button::print_button()
{

    //glColor3f(0.0, 1.28, 0.0);
    //glBindTexture(GL_TEXTURE_2D,TextureID);
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glTexCoord2d(0,1);
    glVertex2i(rect->getP1().getX(),rect->getP1().getY());
    glTexCoord2d(0,0);
    glVertex2i(rect->getP2().getX(),rect->getP2().getY());
    glTexCoord2d(1,0);
    glVertex2i(rect->getP3().getX(),rect->getP3().getY());
    glTexCoord2d(1,1);
    glVertex2i(rect->getP4().getX(),rect->getP4().getY());
    glEnd();

    glColor3f(0, 0, 0);

    glDisable(GL_TEXTURE_2D);

    //glClear(GL_COLOR_BUFFER_BIT);

   // glColor3d(0,0,0); // Texte en blanc
    //vBitmapOutput(this->rect->getCenter().getX() +5 - this->rect->getDiameter(),this->rect->getCenter().getY(),"Niveau 1",GLUT_BITMAP_HELVETICA_18);
   // glFlush();

    //glFlush();
}

Button::Etat Button::lectureEtatBouton(void)
{
    // Lecture de l'etat de la souris
    int x = 10;
    int y = 10;
    if( 0 != (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) )
    {
        cout << "Clic gauche" << endl;
        if(x >= this->rect->getP1().getX() && x <= this->rect->getP4().getX() && y >= this->rect->getP2().getY() && y <= this->rect->getP1().getY())
        {
            cout << "ENFONCE"<<endl;
            return ENFONCE;

        }
        else
        {
            cout << "SURVOLE"<<endl;
            return SURVOLE;
        }
    }

    else
    {
        cout << "PAS_SURVOLE"<<endl;
        cout <<x<<endl;
        cout<<y<<endl;
        return PAS_SURVOLE;
    }

}

Button::~Button()
{

}
