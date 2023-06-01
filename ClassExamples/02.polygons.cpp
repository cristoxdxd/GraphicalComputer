#include <freeglut.h>

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
    //gluOrtho2D(0, 0, 0, 0);
    gluOrtho2D(-100, 100, -100, 100);
}

void triangulos() {
    /* Color for cleaning the screen */
    glClearColor(0.89f, 0.79f, 0.62f, 1.0f);               // R, G, B, transparency
    glClear(GL_COLOR_BUFFER_BIT);           // Empty the screen

    /* Default coordinate system, in which x, y, and z are limited to the range -1 to 1 */
    glBegin(GL_TRIANGLES);

    glColor4f(0.41f, 0.65f, 0.68f, 1.0f); // Triangles color

    /* Triangle 1 */
    glVertex2f(0.75f,  0.80f);      // top
    glVertex2f(0.10f,  0.00f);      // center
    glVertex2f(0.75f, -0.80f);      //bottom

    /* Triangle 2 */
    glVertex2f(-0.75f,  0.80f);     // top
    glVertex2f(-0.10f,  0.00f);     // center
    glVertex2f(-0.75f, -0.80f);     // bottom

    /* Ends the color and vertex definition process */
    glEnd();

    /* Swaps the front and back buffers */
    glutSwapBuffers();

}

void puntos() {

    glClear(GL_COLOR_BUFFER_BIT);
    //glClearColor(0, 0, 0, 1);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(50.0f, 40.0f, 0.0f);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(50.0f, 50.0f);//, 50.0f);
    glEnd ( );
    glutSwapBuffers();
}

void lineas(){
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1);
    glBegin (GL_LINES) ;
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i (50, -50);
        glVertex2i (-45, 45);
    glEnd ( );

    glLineWidth(10);
    glBegin (GL_LINES) ;
        glColor3f(1.0, 0, 0);
        glVertex2i (-50, -50);
        glVertex2i (45, 1);
    glEnd ( );
    glutSwapBuffers();

}

int main(int argc, char** argv) {
    /* Initializing glut */
    glutInit(&argc, argv);

    /* Use single color buffer instead of a depth buffer */
    glutInitDisplayMode(GLUT_RGB);

    /* Windows dimensions - width and height */
    glutInitWindowSize(640, 480);

    /* Location of window - screen coordinates */
    glutInitWindowPosition(100, 100);

    /* Sets the window object name */
    glutCreateWindow("Ejemplos");

    /* Redraws the window */
    glutDisplayFunc(triangulos);
    glutReshapeFunc(reshape);

    /* Render loop */
    glutMainLoop(); // The program closes when user closes the window

    return 0;

}