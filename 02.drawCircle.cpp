#include <GLFW/glfw3.h>
#include <math.h>

void drawCircle() {
    glRotated(0.1f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
		float degInRad = i * 3.14159 / 180;
        glColor3f(cos(degInRad), sin(degInRad), 0.85f);
		glVertex2f(cos(degInRad) * 0.5, sin(degInRad) * 0.5);
	}
    glEnd();
}

int main(void) {
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Hello Graphical World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        drawCircle();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}