#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
using namespace std;

int windowWidth = 500, windowHeight = 500;

int projectionMode = 0; //0=orthogonal,1=perspective
int yy = 0, xx = 0; //camera coordinates

void drawCube()
{
	glBegin(GL_QUADS);
	//red
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	//yellow
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	//blue
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	//green
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	//mixed
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.5, 0.5, -0.5);
	glColor3f(0.5, 1.0, 1.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glColor3f(0.0, 1.0, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	//mixed-2
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glColor3f(0.5, 0.5, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glColor3f(0.5, 1.0, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();

	if (projectionMode) { //perspective
		double Px = -6.0*sin(0.0174 * yy)*cos(0.0174 * xx);
		double Py = +6.0*sin(0.0174 * xx);
		double Pz = +6.0*cos(0.0174 * yy)*cos(0.0174 * xx);
		gluLookAt(Px, Py, Pz, 0, 0, 0, 0, cos(0.0174 * xx), 0);
	}
	else //orthogonal
	{ 
		glRotatef(xx, 1, 0, 0);
		glRotatef(yy, 0, 1, 0);
	}
	drawCube();

	glFlush();
	glutSwapBuffers();
}
void projection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (projectionMode) //perspective
	{
		gluPerspective(57, 1, 0.75, 12.0);
	}
	else //orthogonal
	{
		glOrtho(-3.0, +3.0, -3.0, +3.0, -3.0, +3.0);
	}
	glMatrixMode(GL_MODELVIEW);
}

void reshape(int width, int height)
{
	if (height > width) {
		glViewport(0, (height - width) / 2, width, width);
	}
	else
	{
		glViewport((width - height) / 2, 0, height, height);
	}

	projection();
}

void keyboard(unsigned char c, int x, int y)
{
	switch (c) {
	case 'A':case 'a'://left
		yy -= 5;
		break;
	case 'S':case 's'://down
		xx += 5;
		break;
	case 'D':case 'd'://right
		yy += 5;
		break;
	case 'W':case 'w'://up
		xx -= 5;
		break;
	case 'P': case 'p'://switch projection mode
		projectionMode = !projectionMode;
		break;
	}

	yy %= 360; //one cycle finished
	xx %= 360; //one cycle finished
	projection();
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Project-2");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}

