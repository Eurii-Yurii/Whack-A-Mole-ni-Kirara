#include <glut.h>
#include <cmath>
#include <iostream>
using namespace std;


    bool buttonStatus[5] = { false };

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


    void button(float posX, float posY, float posZ, float length, float width, float height, int index) {

        float pressedHeight = 1.5;
        int R, G, B;
        R = 255;
        G = 0;
        B = 0;

        if (buttonStatus[index] == true) {
            pressedHeight = 0.5;
            R = 200;
            G = 0;
            B = 0;
        }

        glColor3ub(32, 32, 32);
        Box(posX, posY, posZ, length, width, height);


        glColor3ub(R, G, B);
        Box((posX + 0.5), (posY + 0.5), (posZ + 0.5), (length - 1), (width - 1), (height + pressedHeight));

    }

    void camera() {
        gluLookAt(
            0.0f, -20, 15.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 10.0f, 0.0f
        );
    }

    void RenderScene(void) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        camera();


        ground(15, 10, -1);

        button(-13, 2, 0, 5, 5, 1, 0);
        button(-2, 2, 0, 5, 5, 1, 1);
        button(8, 2, 0, 5, 5, 1, 2);
        button(-8, -5, 0, 5, 5, 1, 3);
        button(3.5, -5, 0, 5, 5, 1, 4);


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

    void keyUp(unsigned char key, int x, int y) {

        switch (key) {
        case 'q':
            buttonStatus[0] =  false;
            glutPostRedisplay();
            break;
        case 'w':
            buttonStatus[3] = false;
            glutPostRedisplay();
            break;
        case 32:
            buttonStatus[1] = false;
            glutPostRedisplay();
            break;
        case 0:
        case 'o':
            buttonStatus[4] = false;
            glutPostRedisplay();
            break;
        case 'p':
            buttonStatus[2] = false;
            glutPostRedisplay();
            break;
        }
    }

    void keyDown(unsigned char key, int x, int y) {

        switch (key) {
        case 'q':
            buttonStatus[0] = true;
            glutPostRedisplay();
            break;
        case 'w':
            buttonStatus[3] = true;
            glutPostRedisplay();
            break;
        case 32:
            buttonStatus[1] = true;
            glutPostRedisplay();
            break;
        case 0:
        case 'o':
            buttonStatus[4] = true;
            glutPostRedisplay();
            break;
        case 'p':
            buttonStatus[2] = true;
            glutPostRedisplay();
            break;
        }
    }

    void controls() {

        glutKeyboardUpFunc(keyUp);
        glutKeyboardFunc(keyDown);
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

    controls();

    glEnable(GL_DEPTH_TEST);


    glutMainLoop();
    return 1;
}