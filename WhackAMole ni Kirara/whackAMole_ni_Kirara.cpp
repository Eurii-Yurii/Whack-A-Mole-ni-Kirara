#include <glut.h>
#include <cmath>
#include <iostream>
using namespace std;


void button(int posX, int posY, int length, int height) {

    glBegin(GL_QUADS);
    glVertex2f(posX, posY);
    glVertex2f(posX, (posY - height));
    glVertex2f((posX - (-length)), (posY - height));
    glVertex2f((posX - (-length)), posY);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f((posX - (-3)), posY);
    glVertex2f((posX - (-3)), (posY - (-5)));
    glVertex2f((posX - (-17)), (posY - (-5)));
    glVertex2f((posX - (-17)), posY);
    glEnd();
}

void RenderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0f, 0.0f, 100.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);

    button(-55, 24, 20, 3);

    glutSwapBuffers();
}

void ChangeSize(int w, int h) {
    //height or width should not be equal to 0
    if (h == 0)
        h = 1;
    float ratio = 1.0 * w / h;
    //fix the matrixmode to projection 
    glMatrixMode(GL_PROJECTION);
    //Reset the value of matrices
    glLoadIdentity();
    //Set the viewport of the window
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    // Get Back to Model View
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    //HelloOpenGL, DoSomething, DoSomething2
   //init GLUT and create a window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1080, 720);
    glutCreateWindow("MyOpenGL");
    //register callbacks
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(RenderScene);

    glEnable(GL_DEPTH_TEST);
    // enter GLUT event processing cycle
    glutMainLoop();
    return 1;
}