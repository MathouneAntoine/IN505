#include "Screen.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
#include "Rock.h"
#include "./mesformes/Point.h"
using namespace std;
/**
 * Call this function in the main entry point with
 * glutKeyboardFunc(keyboard);
 */

/**
 * x - mouse pointer position - zero to corner of window
 * y - mouse pointer position - zero to corner of window
 */
void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'a':
            cout << "You type a" << endl;
            break;
        case 'b':
            cout << "You type b" << endl;
            break;
    }
}

void init();
void display();

float a[4] = {10.0, 10.0, 100.0, 100.0};
float b[4] = {10.0, 100.0, 100.0, 10.0};

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void display()
{


    glClear( GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);


    Field* f= new Field(250,250);
    Rock* R= new Rock(f, 100, 100, 0, 0,5);

    R->print_Rock();
    R->print();
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

int main(int argc,char *argv[]){
    Screen_Init(argc,argv);
    init();
    //glutDisplayFunc(display);
    //glutMotionFunc(drag);
       glClear( GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);


    Field* f= new Field(250,250);
    Rock* R= new Rock(f, 100, 100, 0, 0, 5);

    R->print_Rock();
    R->print();
    glFlush();

    glutMainLoop();

    return 0;

}
