#include <GL/glut.h> 
#include <GL/glu.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int yy = 0, xx = 0; //model x-y
float w = 500, h = 500;
float str[14], str1[14]; //store angles(first-last)
string file_name, namee[100];
ofstream file;


static float right_shoulder = 0, left_shoulder = 0,
             right_elbow = 0, left_elbow = 0,
             right_leg = 0, left_leg = 0,
             right_legelbow = 0, left_legelbow = 0,
             head_rotate = 0, head_side = 0,
             right_shoulder_side = 0, left_shoulder_side = 0,
             left_leg_side = 0, right_leg_side = 0;

float first_head_rotate, first_right_shoulder, first_right_elbow,
      first_left_shoulder, first_left_elbow, first_right_leg,
      first_right_legelbow, first_left_leg, first_left_legelbow,
      first_head_side, first_rightshol_side, first_leftshol_side,
      first_rightleg_side, first_leftleg_side;

int control = 0, choose = 0, i, counter = 0, runControl = 0;
int legcontrol = 0, armcontrol = 0;


void run(int value)
{
	if (runControl) {
		if (right_leg <= 12 && legcontrol == 0)
		{
			right_leg += 1.0;
			right_legelbow += 0.25;
			left_leg -= 1.0;
			left_legelbow -= 0.25;
			glutPostRedisplay();
		}

		else if (right_leg >= 13 || legcontrol == 1)
		{
			right_leg -= 1.0;
			right_legelbow -= 0.25;
			left_leg += 1.0;
			left_legelbow += 0.25;
			glutPostRedisplay();
			legcontrol = 1;
			if (right_leg == (-12))
				legcontrol = 0;
		}

		if (right_shoulder <= 12 && armcontrol == 0)
		{
			right_shoulder += 1.0;
			right_elbow += 1.5;
			left_shoulder -= 1.0;
			left_elbow -= 1.5;
			glutPostRedisplay();
		}

		else if (right_shoulder >= 13.0 || armcontrol == 1)
		{
			right_shoulder -= 1.0;
			right_elbow -= 1.5;
			left_shoulder += 1.0;
			left_elbow += 1.5;
			glutPostRedisplay();
			armcontrol = 1;
			if (right_shoulder == (-13))
				armcontrol = 0;
		}
	}
	glutTimerFunc(120, run, 0);
}

void head()
{
	glColor3f(0.1, 0.2, 0.5);
	glTranslatef(0.0, 3, 0.0);
	glRotatef(head_rotate, -1.0, 0.0, 0.0);
	glTranslatef(0.0, -3, 0.0);
	glTranslatef(0.0, 3, 0.0);
	glRotatef(head_side, 0.0, 0.0, -1.0);
	glTranslatef(0.0, -3, 0.0);

	glTranslatef(0, 3.5, 0.0);
	glScalef(1.15, 1.3, 1.15);
	glutSolidCube(1);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glScalef(0.5, 1, 0.5);
	glutSolidCube(1);
	glPopMatrix();
}

void armRight()
{
	glColor3f(0.3, 0.8, 0.7);
	glTranslatef(-1.85, 1.2, 0.0);
	glRotatef(right_shoulder, -1.0, 0.0, 0.0);
	glTranslatef(1.85, -1.2, 0.0);
	glTranslatef(1.8, 1.5, 0.0);
	glRotatef(right_shoulder_side, 0, 0, -1);
	glTranslatef(-1.8, -1.5, 0.0);

	glPushMatrix();
	glTranslatef(1.85, 1, 0.0);
	glScalef(0.70, 2.30, 0.75);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.9, 0.8, 0.7);
	glTranslatef(-1.85, 0.23, 0.0);
	glRotatef(right_elbow, -1.0, 0.0, 0.0);
	glTranslatef(1.85, -0.23, 0.0);

	glPushMatrix();
	glTranslatef(1.85, -0.82, 0.0);
	glScalef(0.40, 1.35, 0.5);
	glutSolidCube(1);
	glPopMatrix();
}
void armLeft()
{
	glColor3f(0.3, 0.8, 0.7);
	glTranslatef(-1.85, 1.2, 0.0);
	glRotatef(left_shoulder, -1.0, 0.0, 0.0);
	glTranslatef(1.85, -1.2, 0.0);
	glTranslatef(-1.8, 1.5, 0.0);
	glRotatef(left_shoulder_side, 0, 0, -1);
	glTranslatef(1.8, -1.5, 0.0);

	glPushMatrix();
	glTranslatef(-1.85, 1, 0.0);
	glScalef(0.70, 2.30, 0.75);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.9, 0.8, 0.7);
	glTranslatef(-1.85, 0.23, 0.0);
	glRotatef(left_elbow, -1.0, 0.0, 0.0);
	glTranslatef(1.85, -0.23, 0.0);

	glPushMatrix();
	glTranslatef(-1.85, -0.82, 0.0);
	glScalef(0.40, 1.35, 0.5);
	glutSolidCube(1);
	glPopMatrix();
}

void legRight()
{
	glColor3f(0.3, 0.8, 0.7);
	glTranslatef(-0.75, -2.20, 0.0);
	glRotatef(right_leg, -1.0, 0.0, 0.0);
	glTranslatef(0.75, 2.20, -0.0);
	glTranslatef(0.75, -2.20, 0.0);
	glRotatef(right_leg_side, 0.0, 0.0, -1.0);
	glTranslatef(-0.75, 2.20, -0.0);

	glPushMatrix(); 
	glTranslatef(0.75, -3.15, -0.0);
	glScalef(1.0, 1.8, 1.0);
	glutSolidCube(1);
	glPopMatrix(); 

	glColor3f(0.9, 0.8, 0.7);
	glTranslatef(-0.75, -3.75, 0.0);
	glRotatef(right_legelbow, -1.0, 0.0, 0.0);
	glTranslatef(0.75, 3.75, 0.0);

	glPushMatrix();
	glTranslatef(0.75, -4.90, -0.0);
	glScalef(0.40, 1.75, 0.45);
	glutSolidCube(1);
	glPopMatrix();
}
void legLeft()
{
	glColor3f(0.3, 0.8, 0.7);
	glTranslatef(-0.75, -2.20, 0.0);
	glRotatef(left_leg, -1.0, 0.0, 0.0);
	glTranslatef(0.75, 2.20, 0.0);
	glTranslatef(-0.75, -2.20, 0.0);
	glRotatef(left_leg_side, 0.0, 0.0, -1.0);
	glTranslatef(0.75, 2.20, -0.0);

	glPushMatrix();
	glTranslatef(-0.75, -3.15, -0.0);
	glScalef(1.0, 1.8, 1.0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0.9, 0.8, 0.7);
	glTranslatef(-0.75, -3.75, 0.0);
	glRotatef(left_legelbow, -1.0, 0.0, 0.0);
	glTranslatef(0.75, 3.75, 0.0);

	glPushMatrix();   
	glTranslatef(-0.75, -4.90, -0.0);
	glScalef(0.40, 1.75, 0.45);
	glutSolidCube(1);
	glPopMatrix();
}

void body()//BODY AND OTHER ELEMENTS WITH HIERARCHY
{
	glColor3f(0.4, 0.8, 0.3);

	glPushMatrix();
	glScalef(1, 1.7, 1);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();//HEAD PUSH
	head();
	glPopMatrix();//HEAD POP

	glPushMatrix();//RIGHT ARM PUSH
	armRight();
	glPopMatrix();//RIGHT ARM POP

	glPushMatrix();//LEFT ARM PUSH
	armLeft();
	glPopMatrix();//LEFT ARM POP

	glPushMatrix();//LEFT LEG PUSH
	legRight();
	glPopMatrix();//LEFT LEG POP

	glPushMatrix();//RIGHT LEG PUSH
	legLeft();
	glPopMatrix();//RIGHT LEG POP
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();

	glRotatef(xx, 1, 0, 0);
	glRotatef(yy, 0, 1, 0);

	glPushMatrix();
	body();          //BODY
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	if (w >= h)
		glViewport((w - h) / 2, 0, h, h);

	else
		glViewport(0, (h - w) / 2, w, w);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-8.0, +8.0, -8.0, +8.0, -8.0, +8.0);
	glMatrixMode(GL_MODELVIEW);
}
void fileUp(string name)
{
	file.open("C:\\Users\\asuspc\\Documents\\Visual Studio 2015\\Projects\\openglStart\\openglStart\\" + name + ".txt");
	file << head_rotate << " " << right_shoulder << " " << right_elbow << " "
		<< left_shoulder << " " << left_elbow << " " << right_leg << " "
		<< right_legelbow << " " << left_leg << " " << left_legelbow << " "
		<< head_side << " " << left_shoulder_side << " " << right_shoulder_side << " "
		<< left_leg_side << " " << right_leg_side << " ";
	file.close();
}
void fileName(string name)
{
	file.open("C:\\Users\\asuspc\\Documents\\Visual Studio 2015\\Projects\\openglStart\\openglStart\\fileName.txt");
	for (int j = 0; j < counter; j++)
	{
		file << namee[j] << " ";
	}
	file << name;
	namee[counter] = name;
	counter++;
	file.close();
}
void readFileName()
{
	ifstream input;
	input.open("C:\\Users\\asuspc\\Documents\\Visual Studio 2015\\Projects\\openglStart\\openglStart\\fileName.txt");
	for (i = 0; i < 100; i++)
	{
		input >> namee[i];
		if (namee[i] != "")counter++;
	}
	input.close();
}
void createFile(string name)//create a new file
{
	ofstream file2;
	file2.open("C:\\Users\\asuspc\\Documents\\Visual Studio 2015\\Projects\\openglStart\\openglStart\\" + name + ".txt");
	file2 << head_rotate << " " << right_shoulder << " " << right_elbow << " "
		<< left_shoulder << " " << left_elbow << " " << right_leg << " "
		<< right_legelbow << " " << left_leg << " " << left_legelbow << " "
		<< head_side << " " << left_shoulder_side << " " << right_shoulder_side << " "
		<< left_leg_side << " " << right_leg_side << " ";
	file2.close();

	cout << "The new animation is saved : " + name << "    You can play this later\n";
}
void fileUpReset(string name)//file reset
{
	file.open("C:\\Users\\asuspc\\Documents\\Visual Studio 2015\\Projects\\openglStart\\openglStart\\" + name + ".txt");
	file << 0 << " " << 0 << " " << 0 << " " << 0 << " "
		<< 0 << " " << 0 << " " << 0 << " " << 0 << " "
		<< 0 << " " << 0 << " " << 0 << " " << 0 << " "
		<< 0 << " " << 0 << " ";
	file.close();
}

void reset()//reset features
{
	head_rotate = 0;
	left_leg = 0;
	right_leg = 0;
	left_elbow = 0;
	right_elbow = 0;
	left_shoulder = 0;
	right_shoulder = 0;
	left_legelbow = 0;
	right_legelbow = 0;
	head_side = 0;
	left_shoulder_side = 0;
	right_shoulder_side = 0;
	left_leg_side = 0;
	right_leg_side = 0;
	xx = 0;
	yy = 0;
}
void animStart(string name, string name2)//start animation
{
	//------------last positions----------
	ifstream input;
	input.open("C:\\Users\\asuspc\\Documents\\Visual Studio 2015\\Projects\\openglStart\\openglStart\\" + name + ".txt");
	//animLast
	for (int i = 0; i < 14; i++)
	{
		input >> str[i];
	}
	input.close();
    //if they change after record animation's last position 
	head_rotate = str[0];
	right_shoulder = str[1];
	right_elbow = str[2];
	left_shoulder = str[3];
	left_elbow = str[4];
	right_leg = str[5];
	right_legelbow = str[6];
	left_leg = str[7];
	left_legelbow = str[8];
	head_side = str[9];
	left_shoulder_side = str[10];
	right_shoulder_side = str[11];
	left_leg_side = str[12];
	right_leg_side = str[13];

	//--------first positions-----------
	ifstream input1;
	input1.open("C:\\Users\\asuspc\\Documents\\Visual Studio 2015\\Projects\\openglStart\\openglStart\\" + name2 + ".txt");
	//animFirst
	for (int i = 0; i < 14; i++)
	{
		input1 >> str1[i];
	}
	input1.close();

	first_head_rotate = str1[0];
	first_right_shoulder = str1[1];
	first_right_elbow = str1[2];
	first_left_shoulder = str1[3];
	first_left_elbow = str1[4];
	first_right_leg = str1[5];
	first_right_legelbow = str1[6];
	first_left_leg = str1[7];
	first_left_legelbow = str1[8];
	first_head_side = str1[9];
	first_leftshol_side = str1[10];
	first_rightshol_side = str1[11];
	first_leftleg_side = str1[12];
	first_rightleg_side = str1[13];
}
void menu()
{
	cout << "-----------MENU:-------------\n"
		<< "l-L: left shoulder back-front\n"
		<< "r-R: Right shoulder back-front\n"
		<< "f-F: Left shoulder elbow back-front\n"
		<< "g-G: Right shoulder elbow back-front\n"
		<< "t-T: Right leg back-front\n"
		<< "y-Y: Left leg back-front\n"
		<< "h-H: Right leg elbow back-front\n"
		<< "j-J: Left leg elbow back-front\n"
		<< "e-E: Head back-front\n"
		<< "k: save first posture\n"
		<< "K: save second posture\n"
		<< "n: start animation\n"
		<< "N: stop animation\n"
		<< "q: go back first posture\n"
		<< "Q: reset everything\n"
		<< "M: show menu\n"
		<< "U: create file and load animation\n"
		<< "b-B: right shoulder ->bent to the side \n"
		<< "i-I: left shoulder ->bent to the side \n"
		<< "p-p: right leg ->bent to the side \n"
		<< "o-O: left leg ->bent to the side \n"
		<< "v-V: head ->bent to the side \n"
		<< "x: Play a animation(you saved before) \n"
		<< "3: Run animation stop \n"
		<< "2: Run animation start\n"
		<< "------------------------------------------\n";
}
void animation(int value)
{
	if (control) {
		//------right shoulder control--------
		if (right_shoulder < first_right_shoulder)
		{
			right_shoulder = int(right_shoulder + 5) % 360;
		}
		if (right_shoulder == first_right_shoulder)
		{
			int temp = first_right_shoulder;
			first_right_shoulder = str[1];
			str[1] = temp;
		}
		if (right_shoulder > first_right_shoulder)
		{
			right_shoulder = int(right_shoulder - 5) % 360;
		}
		//------left shoulder control--------
		if (left_shoulder < first_left_shoulder)
		{
			left_shoulder = int(left_shoulder + 5) % 360;
		}
		if (left_shoulder == first_left_shoulder)
		{
			int temp = first_left_shoulder;
			first_left_shoulder = str[3];
			str[3] = temp;
		}
		if (left_shoulder > first_left_shoulder)
		{
			left_shoulder = int(left_shoulder - 5) % 360;
		}
		//------left leg control--------
		if (left_leg < first_left_leg)
		{
			left_leg = int(left_leg + 5) % 360;
		}
		if (left_leg == first_left_leg)
		{
			int temp = first_left_leg;
			first_left_leg = str[7];
			str[7] = temp;
		}
		if (left_leg > first_left_leg)
		{
			left_leg = int(left_leg - 5) % 360;
		}
		//------right leg control--------
		if (right_leg < first_right_leg)
		{
			right_leg = int(right_leg + 5) % 360;
		}
		if (right_leg == first_right_leg)
		{
			int temp = first_right_leg;
			first_right_leg = str[5];
			str[5] = temp;
		}
		if (right_leg > first_right_leg)
		{
			right_leg = int(right_leg - 5) % 360;
		}
		//------right leg elbow control--------
		if (right_legelbow < first_right_legelbow)
		{
			right_legelbow = int(right_legelbow + 10) % 360;
		}
		if (right_legelbow == first_right_legelbow)
		{
			int temp = first_right_legelbow;
			first_right_legelbow = str[6];
			str[6] = temp;
		}
		if (right_legelbow > first_right_legelbow)
		{
			right_legelbow = int(right_legelbow - 10) % 360;
		}
		//------left leg elbow control--------
		if (left_legelbow < first_left_legelbow)
		{
			left_legelbow = int(left_legelbow + 10) % 360;
		}
		if (left_legelbow == first_left_legelbow)
		{
			int temp = first_left_legelbow;
			first_left_legelbow = str[8];
			str[8] = temp;
		}
		if (left_legelbow > first_left_legelbow)
		{
			left_legelbow = int(left_legelbow - 10) % 360;
		}
		//------right elbow control--------
		if (right_elbow < first_right_elbow)
		{
			right_elbow = int(right_elbow + 10) % 360;
		}
		if (right_elbow == first_right_elbow)
		{
			int temp = first_right_elbow;
			first_right_elbow = str[2];
			str[2] = temp;
		}
		if (right_elbow > first_right_elbow)
		{
			right_elbow = int(right_elbow - 10) % 360;
		}
		//------left elbow control--------
		if (left_elbow < first_left_elbow)
		{
			left_elbow = int(left_elbow + 10) % 360;
		}
		if (left_elbow == first_left_elbow)
		{
			int temp = first_left_elbow;
			first_left_elbow = str[4];
			str[4] = temp;
		}
		if (left_elbow > first_left_elbow)
		{
			left_elbow = int(left_elbow - 10) % 360;
		}
		//------head control--------
		if (head_rotate < first_head_rotate)
		{
			head_rotate = int(head_rotate + 5) % 360;
		}
		if (head_rotate == first_head_rotate)
		{
			int temp = first_head_rotate;
			first_head_rotate = str[0];
			str[0] = temp;
		}
		if (head_rotate > first_head_rotate)
		{
			head_rotate = int(head_rotate - 5) % 360;
		}
		//------head side control--------
		if (head_side < first_head_side)
		{
			head_side = int(head_side + 5) % 360;
		}
		if (head_side == first_head_side)
		{
			int temp = first_head_side;
			first_head_side = str[9];
			str[9] = temp;
		}
		if (head_side > first_head_side)
		{
			head_side = int(head_side - 5) % 360;
		}
		//------left shoulder side control--------
		if (left_shoulder_side < first_leftshol_side)
		{
			left_shoulder_side = int(left_shoulder_side + 5) % 360;
		}
		if (left_shoulder_side == first_leftshol_side)
		{
			int temp = first_leftshol_side;
			first_leftshol_side = str[10];
			str[10] = temp;
		}
		if (left_shoulder_side > first_leftshol_side)
		{
			left_shoulder_side = int(left_shoulder_side - 5) % 360;
		}
		//------right shoulder side control--------
		if (right_shoulder_side < first_rightshol_side)
		{
			right_shoulder_side = int(right_shoulder_side + 5) % 360;
		}
		if (right_shoulder_side == first_rightshol_side)
		{
			int temp = first_rightshol_side;
			first_rightshol_side = str[11];
			str[11] = temp;
		}
		if (right_shoulder_side > first_rightshol_side)
		{
			right_shoulder_side = int(right_shoulder_side - 5) % 360;
		}
		//------left leg side control--------
		if (left_leg_side < first_leftleg_side)
		{
			left_leg_side = int(left_leg_side + 5) % 360;
		}
		if (left_leg_side == first_leftleg_side)
		{
			int temp = first_leftleg_side;
			first_leftleg_side = str[12];
			str[12] = temp;
		}
		if (left_leg_side > first_leftleg_side)
		{
			left_leg_side = int(left_leg_side - 5) % 360;
		}
		//------right leg side control--------
		if (right_leg_side < first_rightleg_side)
		{
			right_leg_side = int(right_leg_side + 5) % 360;
		}
		if (right_leg_side == first_rightleg_side)
		{
			int temp = first_rightleg_side;
			first_rightleg_side = str[13];
			str[13] = temp;
		}
		if (right_leg_side > first_rightleg_side)
		{
			right_leg_side = int(right_leg_side - 5) % 360;
		}

		//---------------------------
		glutPostRedisplay();
		glutTimerFunc(120, animation, 0);
	}
}
void inValue()
{
	cin >> file_name;

	createFile(file_name);
	createFile(file_name + "2");
	
	cout << "please enter the first postures for the animation \n";
	cout << "head_rotate: ";
	cin >> head_rotate;
	cout << "right_shoulder: ";
	cin >> right_shoulder;
	cout << "right_elbow: ";
	cin >> right_elbow;
	cout << "left_shoulder: ";
	cin >> left_shoulder;
	cout << "left_elbow: ";
	cin >> left_elbow;
	cout << "right_leg: ";
	cin >> right_leg;
	cout << "right_legelbow: ";
	cin >> right_legelbow;
	cout << "left_leg: ";
	cin >> left_leg;
	cout << "left_legelbow: ";
	cin >> left_legelbow;
	cout << "head_side: ";
	cin >> head_side;
	cout << "left_shoulder_side: ";
	cin >> left_shoulder_side;
	cout << "right_shoulder_side: ";
	cin >> right_shoulder_side;
	cout << "left_leg_side: ";
	cin >> left_leg_side;
	cout << "right_leg_side: ";
	cin >> right_leg_side;
	fileUp(file_name);
	
	cout << "please enter the second postures for the animation \n";
	cout << "head_rotate: ";
	cin >> head_rotate;
	cout << "right_shoulder: ";
	cin >> right_shoulder;
	cout << "right_elbow: ";
	cin >> right_elbow;
	cout << "left_shoulder: ";
	cin >> left_shoulder;
	cout << "left_elbow: ";
	cin >> left_elbow;
	cout << "right_leg: ";
	cin >> right_leg;
	cout << "right_legelbow: ";
	cin >> right_legelbow;
	cout << "left_leg: ";
	cin >> left_leg;
	cout << "left_legelbow: ";
	cin >> left_legelbow;
	cout << "head_side: ";
	cin >> head_side;
	cout << "left_shoulder_side: ";
	cin >> left_shoulder_side;
	cout << "right_shoulder_side: ";
	cin >> right_shoulder_side;
	cout << "left_leg_side: ";
	cin >> left_leg_side;
	cout << "right_leg_side: ";
	cin >> right_leg_side;
	fileUp(file_name + "2");
}

void special(int key, int x, int y)//rotate model
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		yy -= 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		yy += 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		xx -= 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		xx += 5;
		glutPostRedisplay();
		break;
	}
}
void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'L': // L key rotates at leftshoulder 
		if (left_shoulder<200)
			left_shoulder = int(left_shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'l': // l key rotates at leftshoulder
		if (left_shoulder>-60)
			left_shoulder = int(left_shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'F': // rotates at left elbow
		if (left_elbow<140)
			left_elbow = int(left_elbow + 10) % 360;
		glutPostRedisplay();
		break;
	case 'f': // rotates at left elbow
		if (left_elbow>0)
			left_elbow = int(left_elbow - 10) % 360;
		glutPostRedisplay();
		break;
	case 'R': // R key rotates at rightshoulder 
		if (right_shoulder<200)
			right_shoulder = int(right_shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'r': // r key rotates at rightshoulder 
		if (right_shoulder>-60)
			right_shoulder = int(right_shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'G': // rotates at right elbow
		if (right_elbow<140)
			right_elbow = int(right_elbow + 10) % 360;
		glutPostRedisplay();
		break;
	case 'g': // rotates at right elbow
		if (right_elbow>0)
			right_elbow = int(right_elbow - 10) % 360;
		glutPostRedisplay();
		break;
	case 'T': //rotates at right leg
		if (right_leg<90)
			right_leg = int(right_leg + 5) % 360;
		glutPostRedisplay();
		break;
	case 't': //rotates at right leg
		if (right_leg>-90)
			right_leg = int(right_leg - 5) % 360;
		glutPostRedisplay();
		break;
	case 'H': //rotate right leg elbow
		if (right_legelbow<0)
			right_legelbow = int(right_legelbow + 10) % 360;
		glutPostRedisplay();
		break;
	case 'h': //rotate right leg elbow
		if (right_legelbow>-120)
			right_legelbow = int(right_legelbow - 10) % 360;
		glutPostRedisplay();
		break;
	case 'Y': //rotates left leg
		if (left_leg<90)
			left_leg = int(left_leg + 5) % 360;
		glutPostRedisplay();
		break;
	case 'y': //rotates left leg
		if (left_leg>-90)
			left_leg = int(left_leg - 5) % 360;
		glutPostRedisplay();
		break;
	case 'J': //rotate left leg elbow
		if (left_legelbow<0)
			left_legelbow = int(left_legelbow + 10) % 360;
		glutPostRedisplay();
		break;
	case 'j': //rotate left leg elbow
		if (left_legelbow>-120)
			left_legelbow = int(left_legelbow - 10) % 360;
		glutPostRedisplay();
		break;
	case 'E': //rotate head
		if (head_rotate < 20)
			head_rotate = int(head_rotate + 5) % 360;
		glutPostRedisplay();
		break;
	case 'e': //rotate head
		if (head_rotate >-20)
			head_rotate = int(head_rotate - 5) % 360;
		glutPostRedisplay();
		break;
	case 'b':
		if(right_shoulder_side > -180)
		   right_shoulder_side = int(right_shoulder_side - 5) % 360;
		glutPostRedisplay();
		break;
	case 'B':
		if(right_shoulder_side < 0)
		   right_shoulder_side = int(right_shoulder_side + 5) % 360;
		glutPostRedisplay();
		break;
	case 'i':
		if (left_shoulder_side > 0)
		    left_shoulder_side = int(left_shoulder_side - 5) % 360;
		glutPostRedisplay();
		break;
	case 'I':
		if (left_shoulder_side < 180)
		    left_shoulder_side = int(left_shoulder_side + 5) % 360;
		glutPostRedisplay();
		break;
	case 'p':
		if(right_leg_side > -45)
		   right_leg_side = int(right_leg_side - 5) % 360;
		glutPostRedisplay();
		break;
	case 'P':
		if (right_leg_side < 30)
		   right_leg_side = int(right_leg_side + 5) % 360;
		glutPostRedisplay();
		break;
	case 'o':
		if(left_leg_side > -30)
		   left_leg_side = int(left_leg_side - 5) % 360;
		glutPostRedisplay();
		break;
	case 'O':
		if(left_leg_side < 45)
		   left_leg_side = int(left_leg_side + 5) % 360;
		glutPostRedisplay();
		break;
	case 'v':
		if(head_side > -25)
		   head_side = int(head_side - 5) % 360;
		glutPostRedisplay();
		break;
	case 'V':
		if(head_side < 25)
		   head_side = int(head_side + 5) % 360;
		glutPostRedisplay();
		break;
	case 'k': //save first posture
		fileUp("anim");
		break;
	case 'K': //save second posture
		fileUp("anim2");
		break;
	case 'n': //animation is started
		animStart("anim2", "anim");
		control = 1;
		cout << "animation is started\n";
		glutTimerFunc(100, animation, 0);
		break;
	case 'N': //animation is stoped
		control = 0;
		cout << "animation is stoped\n" << "you can create a new posture but if you will create a new posture please press Q\n";
		break;
	case 'q': //reset posture
		control = 0;
		reset();
		cout << "go back first position but you can play your old animation\n";
		glutPostRedisplay();
		break;
	case 'Q': //reset everything
		fileUpReset("anim");
		fileUpReset("anim2");
		reset();
		control = 0;
		cout << "go back first position and delete the old animation\n";
		glutPostRedisplay();
		break;
	case 'U':
		inValue();
		fileName(file_name);
		animStart(file_name, file_name + "2");
		control = 1;
		glutTimerFunc(100, animation, 0);
		break;
	case 'x':
		cout << "which one do you like to play ?\n";
		for (int i = 0; i < 100; i++)
		{
			if (namee[i] != "")cout << i + 1 << "-" << namee[i] << endl;
		}
		cin >> choose;
		animStart(namee[choose - 1] + "2", namee[choose - 1]);
		control = 1;
		glutTimerFunc(100, animation, 0);
		break;
	case '2':
		runControl = 1;
		glutTimerFunc(100, run, 0);
		break;
	case '3':
		runControl = 0;
		break;
	case 'M':
		menu();
		break;
	}

	yy %= 360;
	xx %= 360;
}

int main(int argc, char * argv[]) {

	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(w, h);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow("Project-3");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	readFileName();

	menu();

	glutMainLoop();

	return 0;
}

