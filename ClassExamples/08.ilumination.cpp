#include <iostream>
#include <GL/freeglut.h>

void reshape(int w, int h);
void initGL();
void display();

int main(int argc, char** argv) {
    //setenv("DISPLAY", ":0", false);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ejemplo iliminación");
    initGL();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void initGL() {
    glClearColor(0.7, 0.7, 0.7, 0.0);
    glEnable(GL_DEPTH_TEST);

    GLfloat ambient[] = { 0.0,0.0,0.0,1.0 };
    GLfloat diffuse[] = { 1.0,1.0,1.0,1.0 };
    GLfloat position[] = { 2.0,3.0,2.0,0.0 };
    GLfloat model_ambient[] = { 0.5,0.5,0.5,1.0 };
    GLfloat local_view[] = { 0.0 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat noMat[] = { 0.0,0.0,0.0,1.0 };
    GLfloat matAmb[] = { 0.3,0.2,0.0,1.0 };
    GLfloat matAmb2[] = { 0.3,0.2,0.8,1.0 };
    GLfloat matDiff[] = { 0.8,0.5,0.11,1.0 };
    GLfloat matSpec[] = { 1.0,1.0,1.0,1.0 };
    GLfloat noShin[] = { 0.0 };
    GLfloat lowShin[] = { 5.0 };
    GLfloat highShin[] = { 100.0 };

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, noShin);
    glTranslatef(-4.5, 2.5, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, lowShin);
    glTranslatef(0.0, 2.5, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, noMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, highShin);
    glTranslatef(4.5, 2.5, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, noShin);
    glTranslatef(-4.5, 0.0, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, lowShin);
    glTranslatef(0.0, 0.0, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, highShin);
    glTranslatef(4.5, 0.0, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, noMat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, noShin);
    glTranslatef(-4.5, -2.5, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, noMat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, lowShin);
    glTranslatef(0.0, -2.5, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, noMat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, highShin);
    glTranslatef(4.5, -2.5, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    //Nuevo material amb
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, noMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, noShin);
    glTranslatef(-4.5, -5.0, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, lowShin);
    glTranslatef(0.0, -5.0, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, highShin);
    glTranslatef(4.5, -5.0, 0);
    glutSolidSphere(1, 16, 16);
    glPopMatrix();

    glutSwapBuffers();
}