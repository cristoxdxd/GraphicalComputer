#define _USE_MATH_DEFINES
#include <iostream>
#include <GL/freeglut.h>
#include <cmath>

void reshape(GLint w, GLint h);
void initGL();
void displayMorph();
void timer(int valor);
void morphing(int segmentos);

int refreshRate = 300;
int radio = 50;
int segNum = 4;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejercicio Morphing");

    glutDisplayFunc(displayMorph);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    initGL();
    glutMainLoop();

}

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

void initGL() {
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
}

void timer(int valor) {
    glutPostRedisplay();
    glutTimerFunc(refreshRate, timer, 0);
}

void displayMorph() {
    glClear(GL_COLOR_BUFFER_BIT);
    morphing(segNum);
    glutSwapBuffers();
    segNum++;
}

void morphing(int segmentos) {
    float theta = 0.0f;
    float x = 0.0f;
    float y = 0.0f;
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    for (int i = 0; i < segmentos; i++)
    {
        theta = M_PI * 2.0f * float(i) / float(segmentos);
        x = float(radio) * cosf(theta - (M_PI * 45.0f / 180.0f));
        y = float(radio) * sinf(theta - (M_PI * 45.0f / 180.0f));
        glVertex2f(x, y);
    }
    glEnd();
}