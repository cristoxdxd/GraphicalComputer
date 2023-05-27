#include <GLFW/glfw3.h>

/*******************************************************************************************
* Author: Cristopher Herrera
* ICCD533 - Graphics Programming
* Date: 29/05/2023
* Description: This is a simple example of using OpenGL with GLFW to draw a triangle

HOW TO INSTALL GLFW:
1. Download the pre-compiled binaries for your platform from
   https://www.glfw.org/download.html
2. Extract the files to a folder of your choice
3. Copy the contents of the include folder to your project's include folder
4. Copy the contents of the lib-vc2022 folder to your project's lib folder
5. Open the project's properties and add the following settings to your project's:
    C/C++ -> General -> Additional Include Directories:
    <path to your project's include folder> (e.g. $(ProjectDir)include)
    Linker -> General -> Additional Library Directories:
    <path to your project's lib folder> (e.g. $(ProjectDir)lib-vc2022)
    Input -> Additional Dependencies:
    glfw3.lib;opengl32.lib;user32.lib;gdi32.lib;shell32.lib
*/

void drawTriangle() {
    glRotated(0.1f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.6f, -0.4f);    // Vertex 1
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex2f(0.6f, -0.4f);     // Vertex 2
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.0f, 0.6f);      // Vertex 3
    glEnd();
}

// Example code from https://www.glfw.org/documentation.html
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello Graphical World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Clear the screen to white
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        
        // Draw a triangle (rotating)
        drawTriangle();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}