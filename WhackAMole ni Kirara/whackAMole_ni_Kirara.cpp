#include <glut.h>
#include <cmath>
#include <iostream>
using namespace std;

void button() {

    glColor3f(100,100,100);
    glBegin(GL_QUADS);
    glVertex3f(1, 1, 1);
    glVertex3f(5, 1, 1);
    glVertex3f(5, 5, 1);
    glVertex3f(1, 5, 1);
    // Back
    glVertex3f(1, 1, 0);
    glVertex3f(5, 1, 0);
    glVertex3f(5, 5, 0);
    glVertex3f(1, 5, 0);
    // Left
    glVertex3f(1, 1, 0);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 5, 1);
    glVertex3f(1, 5, 0);
    // Right
    glVertex3f(5, 1, 0);
    glVertex3f(5, 1, 1);
    glVertex3f(5, 5, 1);
    glVertex3f(5, 5, 0);
    // Top
    glVertex3f(1, 5, 0);
    glVertex3f(5, 5, 0);
    glVertex3f(5, 5, 1);
    glVertex3f(1, 5, 1);
    // Bottom
    glVertex3f(1, 1, 0);
    glVertex3f(5, 1, 0);
    glVertex3f(5, 1, 1);
    glVertex3f(1, 1, 1);
    glEnd();

}

void RenderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(
        0.0f, -20.0f, 15.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 10.0f, 0.0f
    );

    button();


    glutSwapBuffers();
}

void ChangeSize(int w, int h) {

    if (h == 0)
        h = 1;
    float ratio = 1.0 * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1080, 720);
    glutCreateWindow("MyOpenGL");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(RenderScene);

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 1;
}