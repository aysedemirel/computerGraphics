#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>

using namespace std;

GLsizei WINDOW_HEIGHT = 360, WINDOW_WIDTH = 640;

float red = 0.0, green = 0.0, blue = 1.0;
float x1_1, x2_2, y1_1, y2_2; //rectangle max and min position
float rectangle_position[2] = { 0.0, 0.0 };
bool left_button = false;

	
bool isInside(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Px, int Py)//is inside the triangle
{
	float bx = Bx - Ax;
	float by = By - Ay;
	float cx = Cx - Ax;
	float cy = Cy - Ay;
	float x = Px - Ax;
	float y = Py - Ay;

	float d = (bx*cy) - (cx*by);
	float WA = (x*(by - cy) + y*(cx - bx) + bx*cy - cx*by) / d;
	float WB = (x*cy - y*cx) / d;
	float WC = (y*bx - x*by) / d;

	if (WA > 0 && WA < 1) {
		if (WB > 0 && WB < 1) {
			if (WC > 0 && WC < 1) {
				return true;
			}
		}
	}

	return false;
}

void draw_rectangle(float cx, float cy)
{
	glColor3f(0,0,0); //black
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	x1_1 = 270 + cx;
	y1_1 = 150 + cy;
	x2_2 = 70 + cx;
	y2_2 = 250 + cy;
	glLineWidth(2);

	glBegin(GL_POLYGON);
	     glVertex2f(270 + cx, 150 + cy);
	     glVertex2f(270 + cx, 250 + cy);
	     glVertex2f(70 + cx, 250 + cy);
	     glVertex2f(70 + cx, 150 + cy);
	glEnd();

	glFlush();
}

void draw_triangle()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	   glColor3f(red, green, blue);
	   glVertex2i(520, 130);
	   glVertex2i(470, 230);
	   glVertex2i(565, 230);
	glEnd();

	glFlush();
}


void reshape(GLsizei w, GLsizei h) {
	glClearColor(1.0, 1.0, 1.0, 1.0); //background (white)
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, w, h);         // update the viewport
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();

	gluOrtho2D(0, 640, 360,0);  //ortogonal projection (2D)
	glMatrixMode(GL_MODELVIEW); 

	glutPostRedisplay();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	draw_triangle();
	draw_rectangle(rectangle_position[0], rectangle_position[1]);

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON)//for rectangle
	{
		if (x <= x1_1  && x >= x2_2 && y <= y2_2 && y >= y1_1)
		{
			if (state == GLUT_DOWN) {	
				left_button = true;
			}
			else if (state == GLUT_UP) {
				left_button = false;
			}
		}
	}

	if (isInside(520, 130, 470, 230, 565, 230, x, y))//for triangle
	{
		if (state == GLUT_DOWN) {
			red = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			green = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			blue = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

			if (red == 1.0 && green == 1.0 && blue == 1.0)//if color is white,set black
			{
				red = 0.0;
				green = 0.0;
				blue = 0.0;
			}
		}
	
	}

	glutPostRedisplay();

}

void keyboard(unsigned char c, int x, int y) {
	switch (c) {
	case 'q': case 'Q':
		exit(0);			
	}
	glutPostRedisplay();
}

void drag(int x, int y) {
	
	float new_x = ((float)x);
	float new_y = ((float)y);

	new_x = new_x - 170;
	new_y = new_y - 200;

	glClear( GL_COLOR_BUFFER_BIT );

	if (left_button) {
		rectangle_position[0] = new_x;
		rectangle_position[1] = new_y;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Project-1");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(drag);
	glutKeyboardFunc(keyboard);

	
	glutMainLoop();
	return 0;
}


