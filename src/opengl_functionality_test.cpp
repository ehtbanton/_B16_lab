#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a simple red triangle
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Test");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}