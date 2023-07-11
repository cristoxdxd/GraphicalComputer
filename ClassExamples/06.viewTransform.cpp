#define _USE_MATH_DEFINES
#include <iostream>
#include <GL/freeglut.h>
#include <cmath>

void reshape(GLint w, GLint h);
void initGL();
void display3D();
void dibujarCubo();
void timer(int valor);
void spinDisplayIzq();
void spinDisplayDer();
void moverCamara(int key, int, int);
void orbitarCamara(int key, int, int);

float camX = 5.0f, camY = 0.0f;
float radio = 20.0f;
float angleX = 0.0f, angleY = 0.0f;
float centerX = 0.0f, centerY = 0.0f;
float rotAng = 0.0f, spin = 0.0f;
int refreshRate = 5;
float cameraSpeed = 0.1f;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejercicio Transformaci�n de la vista");

    glutDisplayFunc(display3D);
    glutReshapeFunc(reshape);
    glutSpecialFunc(orbitarCamara);
    glutTimerFunc(0, timer, 0);
    initGL();
    glutMainLoop();

}

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, 1, 5, 100);
}

void initGL() {
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void moverCamara(int key, int,int) {
    switch (key)
    {
    case GLUT_KEY_LEFT:
        camX-=cameraSpeed;
        centerX -= cameraSpeed/2;
        break;
    case GLUT_KEY_RIGHT:
        camX+=cameraSpeed;
        centerX += cameraSpeed/2;
        break;
    case GLUT_KEY_UP:
        camY+=cameraSpeed;
        centerY += cameraSpeed/2;
        break;
    case GLUT_KEY_DOWN:
        camY-=cameraSpeed;
        centerY -= cameraSpeed/2;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void orbitarCamara(int key, int, int) {
    switch (key)
    {
    case GLUT_KEY_LEFT:
        angleY -= cameraSpeed;
        centerX -= cameraSpeed / 2;
        break;
    case GLUT_KEY_RIGHT:
        angleY += cameraSpeed;
        centerX += cameraSpeed / 2;
        break;
    case GLUT_KEY_UP:
        angleX += cameraSpeed;
        centerY += cameraSpeed / 2;
        break;
    case GLUT_KEY_DOWN:
        angleX -= cameraSpeed;
        centerY -= cameraSpeed / 2;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void display3D() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float camPosX = radio * sin(angleY) * cos(angleX);
    float camPosY = radio * sin(angleX);
    float camPosZ = radio * cos(angleY) * cos(angleX);
    float upY = 1.0;

    

        upY = -1.0;

    gluLookAt(camPosX, camPosY, camPosZ, centerX, centerY, 0, 0, upY, 0);

    glPushMatrix();
    glScalef(1.5f, 1.5f, 1.5f);
    dibujarCubo();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-rotAng, 0, 0, 1);
    glTranslatef(0.0f, 0.0f, -6.0f);
    dibujarCubo();
    glPopMatrix();

    glutSwapBuffers();
    rotAng += 0.05f;
    if (angleX >= 2 * M_PI)
        angleX = 0.0f;
}

void timer(int valor) {
    glutPostRedisplay();
    glutTimerFunc(refreshRate, timer, 0);
}

void dibujarCubo() {
    glBegin(GL_QUADS);
    //Izq
    glColor3f(0.9f, 0.8, 0.7);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);
    //Der
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    //Abajo
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, -1);
    //Arriba
    glColor3f(0.85f, 0.25f, 0.4f);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);
    //Atr�s
    glColor3f(0.95f, 0.8f, 0.4f);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);
    //Frontal
    glColor3f(1.0f, 0.7f, 0.4f);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);
    glEnd();
}