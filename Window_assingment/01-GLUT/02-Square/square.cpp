#include <GL/freeglut.h>

bool bFullscreen = false;

int main(int argc, char** argv)
{
    //code
    //function declartions
    void initialize(void);
    void resize(int, int);
    void display(void);
    void keyboard(unsigned char, int, int);
    void mouse(int, int, int, int);
    void uninitialize(void);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT:ANIKET KADAM");

    initialize();

    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutCloseFunc(uninitialize);
    glutMainLoop();
    return(0);//This line is not necessary
}
void initialize(void)
{
    //code
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void resize(int width, int height)
{
    //code
    if (height <= 0)
        height = 1;
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}
void display(void)
{
    //code
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.1f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);

    glColor3f(2.0f, 0.5f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);

    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);

    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
    //code
    switch (key)
    {
    case 27:
        glutLeaveMainLoop();
        break;
    case 'F':
    case 'f':
        if (bFullscreen == false)
        {
            glutFullScreen();
            bFullscreen = true;
        }
        else
        {
            glutLeaveFullScreen();
            bFullscreen = false;
        }
        break;
    default:
        break;
    }
}
void mouse(int button, int state, int x, int y)
{
    //code
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        break;
    case GLUT_RIGHT_BUTTON:
        glutLeaveMainLoop();
        break;
    default:
        break;
    }
}
void uninitialize(void)
{
    //code
}

