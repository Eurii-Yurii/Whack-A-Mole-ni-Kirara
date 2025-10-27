#include <glut.h>
#include <cmath>
#include <iostream>
using namespace std;

/*
TODO
- Randomizer
- Make Buttons Press
- Score
- ACTUALLY MAKE IT WHACK A MOLE
*/

void Box(float posX, float posY, float posZ, float length, float width, int height) {

    glBegin(GL_QUADS);

    glVertex3f(posX, posY, posZ);
    glVertex3f(posX + width, posY, posZ);
    glVertex3f(posX + width, posY + length, posZ);
    glVertex3f(posX, posY + length, posZ);

    glVertex3f(posX, posY, posZ + height);
    glVertex3f(posX + width, posY, posZ + height);
    glVertex3f(posX + width, posY + length, posZ + height);
    glVertex3f(posX, posY + length, posZ + height);

    glVertex3f(posX, posY, posZ);
    glVertex3f(posX, posY, posZ + height);
    glVertex3f(posX, posY + length, posZ + height);
    glVertex3f(posX, posY + length, posZ);

    glVertex3f(posX + width, posY, posZ);
    glVertex3f(posX + width, posY, posZ + height);
    glVertex3f(posX + width, posY + length, posZ + height);
    glVertex3f(posX + width, posY + length, posZ);

    glVertex3f(posX, posY + length, posZ);
    glVertex3f(posX + width, posY + length, posZ);
    glVertex3f(posX + width, posY + length, posZ + height);
    glVertex3f(posX, posY + length, posZ + height);

    glVertex3f(posX, posY, posZ);
    glVertex3f(posX + width, posY, posZ);
    glVertex3f(posX + width, posY, posZ + height);
    glVertex3f(posX, posY, posZ + height);
    glEnd();

}

void ground(float posX, float posY, float posZ) {

    glBegin(GL_QUADS);
    glColor3ub(102, 0, 0);
    glVertex3f(-posX, posY, posZ);
    glVertex3f(-posX, -posY, posZ);
    glVertex3f(posX, -posY, posZ);
    glVertex3f(posX, posY, posZ);

    glEnd();
}


void button(float posX, float posY, float posZ, float length, float width, int height) {

    glColor3ub(32,32,32);
    Box(posX,posY,posZ,length,width,height);

    glColor3ub(255, 0, 0);
    Box((posX + 0.5), (posY + 0.5), (posZ + 0.5), (length - 1), (width - 1), (height + 1.5));
}



void RenderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(
        0.0f, -20, 15.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 10.0f, 0.0f
    );

    
    ground(15, 10,-1);

    button(-13, 2, 0, 5, 5, 1);
    button(-2, 2, 0, 5, 5, 1);
    button(8, 2, 0, 5, 5, 1);
    button(-8, -5, 0, 5, 5, 1);
    button(3.5, -5, 0, 5, 5, 1);

    
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
    glutCreateWindow("Whack a Mole ni Kirara");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(RenderScene);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat light_pos[] = { 0.0f, 20, 15.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    glClearColor(0.1, 0.1, 0.1, 1.0);

    glutMainLoop();
    return 1;
}