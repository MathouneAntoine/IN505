#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
int Screen_Init(int argc,char *argv[])
{

    int g_nWindowID;
    const int nWidth = 600;
    const int nHeight = 500;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(200,100);
    g_nWindowID = glutCreateWindow("Foret");
    return g_nWindowID;
}

