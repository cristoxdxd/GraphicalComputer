#include <GL/freeglut.h>

void reshape(GLint w, GLint h);
void initGL();
void display();
void drawCube();
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void spinDisplayRight();
void spinDisplayLeft();

bool isMouse = false;
int lastMouseX = 0;
int rotationSpeed = 1;

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Animaci�n Mouse");

	initGL();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glutMainLoop();

	return 0;
}

void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 5, 100);
}

void initGL() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MATRIX_MODE);
	glLoadIdentity();
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glEnable(GL_DEPTH_TEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawCube();

	glutSwapBuffers();
}

void mouseMotion(int x, int y) {
	if (isMouse) {
		int deltaX = x - lastMouseX;
		if (deltaX > 0) {
			spinDisplayLeft();
		}
		else if (deltaX < 0) {
			spinDisplayRight();
		}
		lastMouseX = x;
	}
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			isMouse = true;
			lastMouseX = x;
			glutMotionFunc(mouseMotion);
		}
		else if (state == GLUT_UP) {
			isMouse = false;
			glutMotionFunc(NULL);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			isMouse = true;
			lastMouseX = x;
			glutMotionFunc(mouseMotion);
		}
		else if (state == GLUT_UP) {
			isMouse = false;
			glutMotionFunc(NULL);
		}
		break;
	}
}

void spinDisplayLeft() {
	// Realiza la animaci�n de rotaci�n hacia la izquierda
	glRotatef(rotationSpeed, 0.0f, 1.0f, 0.0f);
	glutPostRedisplay();
}

void spinDisplayRight() {
	// Realiza la animaci�n de rotaci�n hacia la derecha
	glRotatef(-rotationSpeed, 0.0f, 1.0f, 0.0f);
	glutPostRedisplay();
}

void drawCube() {
	glBegin(GL_QUADS);
	// Botton
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	//Right
	glColor3f(0.9f, 0.8f, 0.7f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	//Back
	glColor3f(0.95f, 0.8f, 0.4f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	//Front
	glColor3f(1.0f, 0.7f, 0.4f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glColor3f(0.85f, 0.25f, 0.4f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);

	//Left
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glColor3f(0.85f, 0.25f, 0.4f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//Top
	glColor3f(0.85f, 0.25f, 0.4f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();
}