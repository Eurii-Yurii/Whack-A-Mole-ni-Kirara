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

void ground(float posX, float posY, float posZ) {

    glBegin(GL_QUADS);
    glColor3ub(102, 0, 0);
    glVertex3f(-posX, posY, posZ);
    glVertex3f(-posX, -posY, posZ);
    glVertex3f(posX, -posY, posZ);
    glVertex3f(posX, posY, posZ);

    glEnd();
}

void button(float posX, float posY, float posZ) {

    glBegin(GL_QUADS);
    glColor3ub(32, 32, 32);
    glVertex3f(posX, posY, posZ);
    glVertex3f((posX - (-4)), posY, posZ);
    glVertex3f((posX - (-4)), (posY - (-4)), posZ);
    glVertex3f(posX, (posY - (-4)), posZ);

    glColor3ub(32, 32, 32);
    glVertex3f(posX, posY, (posZ - 1));
    glVertex3f((posX - (-4)), posY, (posZ - 1));
    glVertex3f((posX - (-4)), (posY - (-4)), (posZ - 1));
    glVertex3f(posX, (posY - (-4)), (posZ - 1));

    glColor3ub(32, 32, 32);
    glVertex3f(posX, posY, (posZ - 1));
    glVertex3f(posX, posY, posZ);
    glVertex3f(posX, (posY - (-4)), posZ);
    glVertex3f(posX, (posY - (-4)), (posZ - 1));

    glColor3ub(32, 32, 32);
    glVertex3f((posX - (-4)), posY, (posZ - 1));
    glVertex3f((posX - (-4)), posY, posZ);
    glVertex3f((posX - (-4)), (posY - (-4)), posZ);
    glVertex3f((posX - (-4)), (posY - (-4)), (posZ - 1));

    glColor3ub(32, 32, 32);
    glVertex3f(posX, (posY - (-4)), (posZ - 1));
    glVertex3f((posX - (-4)), (posY - (-4)), (posZ - 1));
    glVertex3f((posX - (-4)), (posY - (-4)), posZ);
    glVertex3f(posX, (posY - (-4)), posZ);

    glColor3ub(32, 32, 32);
    glVertex3f(posX, posY, (posZ - 0));
    glVertex3f((posX - (-4)), posY, (posZ - 1));
    glVertex3f((posX - (-4)), posY, posZ);
    glVertex3f(posX, posY, posZ);
    glEnd();

    //Pressy Part
    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex3f(posX - (-0.5), posY - (-3.5), posZ + 1.5);
    glVertex3f(posX - (-0.5), posY - (-0.5), posZ + 1.5);
    glVertex3f(posX - (-3.5), posY - (-0.5), posZ + 1.5);
    glVertex3f(posX - (-3.5), posY - (-3.5), posZ + 1.5);

    glVertex3f(posX - (-0.5), posY - (-3.5), posZ + 0.1);
    glVertex3f(posX - (-3.5), posY - (-3.5), posZ + 0.1);
    glVertex3f(posX - (-3.5), posY - (-0.5), posZ + 0.1);
    glVertex3f(posX - (-0.5), posY - (-0.5), posZ + 0.1);

    glVertex3f(posX - (-0.5), posY - (-3.5), posZ + 1.5);
    glVertex3f(posX - (-0.5), posY - (-3.5), posZ + 0.1);
    glVertex3f(posX - (-0.5), posY - (-0.5), posZ + 0.1);
    glVertex3f(posX - (-0.5), posY - (-0.5), posZ + 1.5);

    glVertex3f(posX - (-3.5), posY - (-3.5), posZ + 1.5);
    glVertex3f(posX - (-3.5), posY - (-0.5), posZ + 1.5);
    glVertex3f(posX - (-3.5), posY - (-0.5), posZ + 0.1);
    glVertex3f(posX - (-3.5), posY - (-3.5), posZ + 0.1);

    glVertex3f(posX - (-0.5), posY - (-0.5), posZ + 1.5);
    glVertex3f(posX - (-3.5), posY - (-0.5), posZ + 1.5);
    glVertex3f(posX - (-3.5), posY - (-0.5), posZ + 0.1);
    glVertex3f(posX - (-0.5), posY - (-0.5), posZ + 0.1);

    glVertex3f(posX - (-0.5), posY - (-3.5), posZ + 1.5);
    glVertex3f(posX - (-0.5), posY - (-3.5), posZ + 0.1);
    glVertex3f(posX - (-3.5), posY - (-3.5), posZ + 0.1);
    glVertex3f(posX - (-3.5), posY - (-3.5), posZ + 1.5);

    glEnd();
}

void makeABox(float posX, float posY, float posZ, float length, float width, int height) {

    glBegin(GL_QUADS);
    glVertex3f(posX, posY, posZ);
    glVertex3f(posX, (posY + length), posZ);
    glVertex3f((posX + width), (posY + length), posZ);
    glVertex3f((posX + width), posY, posZ);

    glVertex3f(posX, posY, (posZ + height));
    glVertex3f(posX, (posY + length), (posZ + height));
    glVertex3f((posX + width), (posY + length), (posZ + height));
    glVertex3f((posX + width), posY, (posZ + height));

    glVertex3f(posX, posY, posZ);
    glVertex3f(posX, posY, (posZ + height));
    glVertex3f(posX, (posY + length), (posZ + height));
    glVertex3f(posX, (posY + length), posZ);

    glVertex3f(posX, posY, posZ);
    glVertex3f(posX, posY, (posZ + height));
    glVertex3f(posX - (-width), posY, (posZ - (-height)));
    glVertex3f(posX - (-width), posY, posZ);

    glVertex3f(posX, posY, posZ);
    glVertex3f(posX, posY, (posZ - (-height)));
    glVertex3f((posX - (-width)), posY, (posZ - (-height)));
    glVertex3f((posX - (-width)), posY, posZ);

    glVertex3f((posX - (-width)), posY, posZ);
    glVertex3f((posX - (-width)), posY, (posZ - (-height)));
    glVertex3f((posX - (-width)), (posY - (-length)), (posZ - (-height)));
    glVertex3f((posX - (-width)), (posY - (-length)), posZ);
    glEnd();

}

void RenderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(
        0.0f, -15.0f, 20.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 10.0f, 0.0f
    );

    
    ground(15, 10,-1);

    button(-13, 2, 1);
    button(-2, 2.5, 1);
    button(8, 2, 1);

    button(-8, -5, 1);
    button(3.5, -5, 1);

    //makeABox(1,5,0,5,5,5);
    
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
    glutMainLoop();
    return 1;
}