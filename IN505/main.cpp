/*#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL2/SDL.h>
#include "Rock.h"
#include "Screen.h"
#include <iostream>


#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>


// Includes


int main ( int argc, char** argv )
{
    SDL_Window* window = Init_Screen();
    SDL_Event evenements;

                // Variables

    bool terminer(false);
    float vertices[] = {-0.5, -0.5,   0.0, 0.5,   0.5, -0.5};

    SDL_GLContext contexteOpenGL; // SDL de créer un contexte OpenGL.
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); //Spécifie la version OpenGL que SDL va utiliser
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  //Double buffering
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    contexteOpenGL = SDL_GL_CreateContext(window);  //Création contexte OPENGL dans la fenetre SDL
    if(contexteOpenGL == 0)
    {
        std::cout << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }


    Field* f= new Field(0,0);
    Rock* R= new Rock(f,10, 30, 200, 200, 50, 50);

     // Boucle principale

    while(!terminer)
    {
        SDL_WaitEvent(&evenements);

	if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
	    terminer = true;

	       // Nettoyage de l'écran
        glClear(GL_COLOR_BUFFER_BIT);
        float vertices[] = {
     0.0f,  0.5f, // Sommet 1 (X, Y)
     0.5f, -0.5f, // Sommet 2 (X, Y)
    -0.5f, -0.5f  // Sommet 3 (X, Y)
};

        glDrawArrays(GL_TRIANGLES, 0, 3);
        // Actualisation de la fenêtre

        SDL_GL_SwapWindow(window);
    }
    //R->sdl_print(window);

    // DRAWING ENDS HERE


    //free loaded rectangle
    //SDL_FreeSurface(rectangle);



    printf("Exited cleanly\n");
    // On quitte la SDL
    SDL_GL_DeleteContext(contexteOpenGL);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>

using namespace std;

void init();
void display();

float a[4] = {10.0, 10.0, 100.0, 100.0};
float b[4] = {10.0, 100.0, 100.0, 10.0};

void setTree(float *x, float *y){
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(x[0], y[0]);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(x[1], y[1]);
        glColor3f(1.0, 0.5, 0.0);
        glVertex2f(x[2], y[2]);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(x[3], y[3]);
    glEnd();
}

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void display(){
    glClear( GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);


    setTree(a,b);

    glFlush();
}


void drag(int x, int y){
    y = 300.0 - y;


        a[0] = x - 50.0;
        a[1] = x - 50.0;
        a[2] = x + 50.0;
        a[3] = x + 50.0;


        b[0] = y - 50.0;
        b[1] = y + 50.0;
        b[2] = y + 50.0;
        b[3] = y - 50.0;

    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(200,100);
    glutCreateWindow("OpenGL Program");

    init();
    glutDisplayFunc(display);
    glutMotionFunc(drag);

    glutMainLoop();

    return 0;

}
