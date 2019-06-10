#include<windows.h>
#include<cstdio>
#include<cmath>
#include<GL/glut.h>


using namespace std;

double camera_angle;

void kite()
{
	glBegin(GL_POLYGON);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(-1.0,0.0,0.0);
		glVertex3f(0.0,0.0,1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(-1.0,0.0,0.0);
		glVertex3f(0.0,0.0,-1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(0.0,0.0,1.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(0.0,0.0,-1.0);
	glEnd();

    glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINE_STRIP);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(2.2,0.0,-0.2);
		glVertex3f(2.6,0.0,0.2);
		glVertex3f(2.8,0.0,0.0);
	glEnd();

	glColor3f(0.5,0.5,0.5);
	glBegin(GL_LINE_STRIP);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(-1.0,0.0,0.0);
		glVertex3f(0.0,0.0,1.0);
		glVertex3f(0.0,0.0,-1.0);
	glEnd();



}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
            25.0,25.0,-25.0,
			  0.0,0.0,0.0,
			  0.0,1.0,0.0
		);

glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	#define PI 3.1415926535897932
	double eyex = 25.0*cos(camera_angle*PI/180.0);
	double eyez = 25.0*sin(camera_angle*PI/180.0);
	gluLookAt(
            eyex,20.0,-eyez,
			  0.0,0.0,0.0,
			  0.0,1.0,0.0
		);
   // …..
   // write display codes …
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex3f(-15.0,0.0,15.0);
		glVertex3f(15.0,0.0,15.0);
		glVertex3f(15.0,0.0,-15.0);
		glVertex3f(-15.0,0.0,-15.0);
	glEnd();









glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslated(0.0,5.0,1.0);
	glScalef(5.0,5.0,5.0);
	glRotatef(-35.0,0.0,0.0,1.0);
	kite();
glPopMatrix();




	glutSwapBuffers(); // update display
}



void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0); // black color

  //set up projection mode
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70,1,0.1,100.0);



}

void spinDisplay(void)
{
	camera_angle = camera_angle + 0.2;
	if(camera_angle > 360.0)
		camera_angle = camera_angle - 360.0;
	glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{
		switch(button)
		{
		case GLUT_LEFT_BUTTON:
				if(state==GLUT_DOWN)
					glutIdleFunc(spinDisplay);
				break;
		case GLUT_RIGHT_BUTTON:
			if(state==GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
		}
}



int main(int argc, char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (900,900);
	glutInitWindowPosition (0, 0);
	glutCreateWindow("Hello 3D");
	init(); // init display modes
	glutDisplayFunc(display); // display update
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

