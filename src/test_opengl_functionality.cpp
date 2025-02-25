#define GLUT_DISABLE_ATEXIT_HACK
#ifdef _WIN32
#include <windows.h>  // Important for Windows!
#endif

#if defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // Add this line
    glutInitWindowSize(500, 500);                 // Add this line
    glutInitWindowPosition(100, 100);             // Add this line
    glutCreateWindow("OpenGL Test");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}