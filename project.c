//comment
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
// #include <windows.h>
#include <stdarg.h>
int d = 0;
static int submenu_id;
static int menu_id;
static int window;
static int value = 0;

// windmill constants
const double PI = 3.141592654;
int frameNumber = 0;

// solar constants
static double x = 0.0;

static float help1 = 1;
static bool day = false;
static int grow = 0;
static double angle = 0;
static float lightIntensity = 0;

void stroke_output(GLfloat x, GLfloat y, char *format, ...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

void doInit()
{

	/* Background and foreground color */

	if (day)
	{
		glClearColor(0.9, 0.9, 0.9, 0.0);
	}
	else
	{
		glClearColor(0.3, 0.3, 0.3, 0.0);
	}
	glColor3f(.0, 1.0, 1.0);
	glViewport(0, 0, 1700, 750);

	/* Select the projection matrix and reset it then
     setup our view perspective */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0f, (GLfloat)1700 / (GLfloat)750, 0.1f, 200.0f);
	/* Select the modelview matrix, which we alter with rotatef() */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearDepth(2.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glDepthFunc(GL_LEQUAL);
}

void help()
{

	glPushMatrix();
	glScaled(0.7, 0.7, 0.7);

	stroke_output(-2, 3, "Solar Power");
	stroke_output(-5, 2, "A project by Student name");
	stroke_output(-2, 1, "S -----> Toggle Day / Night");
	stroke_output(-2, 0, "H -----> Toggle help");
	glPopMatrix();
}

void drawHouse(int x, int y, int z)
{

	glPushMatrix();
	glTranslatef(x, y, z);
	glScaled(0.5, 0.5, 0.5);
	glColor3f(1, 1, 1);

	//House
	glPushMatrix();
	glTranslatef(0, 0, -15);
	glScaled(1, 1, 1);
	glColor3f(1, 1, 1);
	glutSolidCube(8);
	glPopMatrix();

	//House Door
	glPushMatrix();
	glTranslatef(0, -1.5, -8);
	glScaled(.5, 1.5, 0.1);

	if (day)
	{
		glColor3f(0, 0, 0);
	}
	else
	{
		glColor3f(1, 1, 0);
	}
	glutSolidCube(2);
	glPopMatrix();

	//House window1
	glPushMatrix();
	glTranslatef(2, -1.5, -8);
	glScaled(.5, 0.5, 0.1);
	if (day)
	{
		glColor3f(0, 0, 0);
	}
	else
	{
		glColor3f(1, 1, 0);
	}
	glutSolidCube(2);
	glPopMatrix();

	//House window2
	glPushMatrix();
	glTranslatef(-2, -1.5, -8);
	glScaled(.5, 0.5, 0.1);
	if (day)
	{
		glColor3f(0, 0, 0);
	}
	else
	{
		glColor3f(1, 1, 0);
	}
	glutSolidCube(2);
	glPopMatrix();

	//House roof
	glPushMatrix();
	glTranslatef(0, 5, -15);
	glScaled(1, .2, 1);
	glColor3f(0, 0, 1);
	glutSolidCube(8);
	glPopMatrix();

	glPopMatrix();
}

void drawSolarPanel(float x, float y, float z)
{

	glPushMatrix();
	glTranslatef(x, y, z);

	//Top panel
	glPushMatrix();
	glTranslatef(5, 0, -15);
	glRotatef(45, 1, 0, 0);
	glScaled(1, 2, 0.2);
	glColor3f(0.3, 0.3, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 0, -14.5);
	glRotatef(45, 1, 0, 0);
	glScaled(.5, 2, 0);
	glColor3f(1, 1, 0);
	glutWireCube(1);
	glPopMatrix();

	//horizontal wire frame on solar
	glPushMatrix();
	glTranslatef(4.9, 0, -14.5);
	glRotatef(45, 1, 0, 0);
	glScaled(1, 1, 0);
	glColor3f(1, 1, 0);
	glutWireCube(1);
	glPopMatrix();

	//Stand

	glPushMatrix();
	glTranslatef(5.5, -1, -16);
	glScaled(0.1, 2, 0.2);
	glColor3f(0, 0.3, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void draw()
{

	if (day)
	{
		glClearColor(0.9, 0.9, 0.9, 0.0);
	}
	else
	{
		glClearColor(0.3, 0.3, 0.3, 0.0);
	}

	glPushMatrix();
	glRotatef(angle, 1, 0, 0);
	glTranslatef(-10, 20, -155);
	glScaled(1, 1, 0.6);
	if (day)
	{
		glColor3f(1, 1, 0);
	}
	else
	{
		glColor3f(1, 1, 1);
	}
	glutSolidSphere(5, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -10, 5);
	glScaled(500, 10, 1000);
	glColor3f(0.8, 0.7, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	drawHouse(-3, 0, -55);
	drawHouse(-4, 0, -35);
	drawHouse(-5, 0, -15);

	drawHouse(-10, 0, -15);

	//Solar Panels
	for (int i = -1; i < 3; i++)
	{
		for (int j = 5; j > -2; j--)

			drawSolarPanel(i * 2, 1, j);
	}

	//draw power station.
	stroke_output(0.8, 1.8, "Power Station");

	// transformer
	glPushMatrix();
	glTranslatef(15, 5, -100);
	//glScaled(0,2,0.2);
	glColor3f(1, 0.3, 0.3);
	glutSolidCube(15);
	glPopMatrix();

	//Transformer Power levels

	// y axis from 5 to 18 and show growth in one second delay

	if (day)
	{
		if (grow <= 15000)
		{
			grow++;
			angle += 0.002;
		}
	}
	else
	{
		if (grow >= 0)
		{
			grow--;
			angle -= 0.002;
		}
	}

	if (grow > 1000)
	{

		glPushMatrix();
		glTranslatef(14.8, -2, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 2000)
	{

		glPushMatrix();
		glTranslatef(14.8, -1, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 3000)
	{

		glPushMatrix();
		glTranslatef(14.8, 0, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 4000)
	{

		glPushMatrix();
		glTranslatef(14.8, 1, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 5000)
	{

		glPushMatrix();
		glTranslatef(14.8, 2, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 6000)
	{

		glPushMatrix();
		glTranslatef(14.8, 3, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 7000)
	{

		glPushMatrix();
		glTranslatef(14.8, 4, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 8000)
	{

		glPushMatrix();
		glTranslatef(14.8, 5, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 9000)
	{

		glPushMatrix();
		glTranslatef(14.8, 6, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 10000)
	{

		glPushMatrix();
		glTranslatef(14.8, 7, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 11000)
	{

		glPushMatrix();
		glTranslatef(14.8, 8, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 12000)
	{

		glPushMatrix();
		glTranslatef(14.8, 9, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 13000)
	{

		glPushMatrix();
		glTranslatef(14.8, 10, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 14000)
	{

		glPushMatrix();
		glTranslatef(14.8, 11, -99.8);
		glScaled(1, 0.05, 1);
		glColor3f(1, 1, 0);
		glutSolidCube(15);
		glPopMatrix();
	}

	if (grow > 15000)
	{
	}
}

void drawDisk(double radius)
{
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++)
	{
		double angle = 2 * PI / 32 * d;
		glVertex2d(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}

void drawWheel()
{
	int i;
	glColor3f(0, 0, 0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0, 0, 0);
	drawDisk(0.2);
	glRotatef(frameNumber * 20, 0, 0, 1);
	glBegin(GL_LINES);
	for (i = 0; i < 15; i++)
	{
		glVertex2f(0, 0);
		glVertex2d(cos(i * 2 * PI / 15), sin(i * 2 * PI / 15));
	}
	glEnd();
}

void drawCart()
{
	glPushMatrix();
	glTranslatef(-1.5f, -0.1f, 0);
	glScalef(0.8f, 0.8f, 1);
	drawWheel();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5f, -0.1f, 0);
	glScalef(0.8f, 0.8f, 1);
	drawWheel();
	glPopMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-2.5f, 0);
	glVertex2f(2.5f, 0);
	glVertex2f(2.5f, 2);
	glVertex2f(-2.5f, 2);
	glEnd();
}

void drawSun()
{
	int i;
	glColor3f(1, 1, 0);
	for (i = 0; i < 13; i++)
	{								  // Draw 13 rays, with different rotations.
		glRotatef(360 / 13, 0, 0, 1); // Note that the rotations accumulate!
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0.75f, 0);
		glEnd();
	}
	drawDisk(0.5);
	glColor3f(0, 0, 0);
}

void drawWindmill()
{
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0 / 46), 0, 0, 1);
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++)
	{
		glRotated(120, 0, 0, 1); // Note: These rotations accumulate.
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f, 0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}

void drawText(float x, float y, int r, int g, int b, int d, const char *string)
{
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
		for (int k = d; k > 0; k--)
		{
			glFlush();
		}
	}
}

void background()
{
	glColor3f(0.8, 0.0, 0.2);

	/* Draw three green triangles to form a ridge of hills in the background */

	glColor3f(0, 0.6f, 0.2f);
	glBegin(GL_POLYGON);
	glVertex2f(-3, -1);
	glVertex2f(1.5f, 1.65f);
	glVertex2f(5, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-3, -1);
	glVertex2f(3, 2.1f);
	glVertex2f(7, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0, -1);
	glVertex2f(6, 1.2f);
	glVertex2f(20, -1);
	glEnd();

	/* Draw a bluish-gray rectangle to represent the road. */

	glColor3f(0.4f, 0.4f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(0, -0.4f);
	glVertex2f(7, -0.4f);
	glVertex2f(7, 0.4f);
	glVertex2f(0, 0.4f);
	glEnd();

	/* Draw a white line to represent the stripe down the middle
	 * of the road. */

	glLineWidth(6); // Set the line width to be 6 pixels.
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(7, 0);
	glEnd();
	glLineWidth(1); // Reset the line width to be 1 pixel.

	/* Draw the sun.  The drawSun method draws the sun centered at (0,0).  A 2D translation
	 * is applied to move the center of the sun to (5,3.3).   A rotation makes it rotate*/

	glPushMatrix();
	glTranslated(5.8, 3, 0);
	glRotated(-frameNumber * 0.7, 0, 0, 1);
	drawSun();
	glPopMatrix();

	/* Draw three windmills.  The drawWindmill method draws the windmill with its base 
	 * at (0,0), and the top of the pole at (0,3).  Each windmill is first scaled to change
	 * its size and then translated to move its base to a different paint.  In the animation,
	 * the vanes of the windmill rotate.  That rotation is done with a transform inside the
	 * drawWindmill method. */

	glPushMatrix();
	glTranslated(0.75, 1, 0);
	glScaled(0.6, 0.6, 1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.2, 1.6, 0);
	glScaled(0.4, 0.4, 1);
	drawWindmill();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.7, 0.8, 0);
	glScaled(0.7, 0.7, 1);
	drawWindmill();
	glPopMatrix();

	/* Draw the cart.  The drawCart method draws the cart with the center of its base at
	 * (0,0).  The body of the cart is 5 units long and 2 units high.  A scale is first
	 * applied to the cart to make its size more reasonable for the picture.  Then a
	 * translation is applied to move the cart horizontally.  The amount of the translation
	 * depends on the frame number, which makes the cart move from left to right across
	 * the screen as the animation progresses.  The cart animation repeats every 300 
	 * frames.  At the beginning of the animation, the cart is off the left edge of the
	 * screen. */

	glPushMatrix();
	glTranslated(-3 + 13 * (frameNumber % 300) / 300.0, 0, 0);
	glScaled(0.3, 0.3, 1);
	drawCart();
	glPopMatrix();

	glutSwapBuffers();
}
void background1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glColor3f(0.8, 0.0, 0.2);

	//if (help1)
	//{
	//	help();
	//}
	//else
	//{
		draw();
	//}

	GLfloat mat_ambient[] = {0.0f, 1.0f, 2.0f, 1.0f};
	GLfloat mat_diffuse[] = {0.0f, 1.5f, .5f, 1.0f};
	GLfloat mat_specular[] = {5.0f, 1.0f, 1.0f, 1.0f};
	GLfloat mat_shininess[] = {100.0f};
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat lightIntensity[] = {1.7f, 1.7f, 1.7f, 1.0f};
	GLfloat light_position[] = {2.0f, 0.0f, 0.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	GLfloat light_position2[] = {0.0f, 0.0f, 8.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position2);

	GLfloat light_position3[] = {0.0f, 5.0f, 15.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position3);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glFlush();
	glutSwapBuffers();
}

void mykey(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q')
	{
		exit(0);
	}

	if (key == 'h' || key == 'H')
	{
		help1 = !help1;
		glutPostRedisplay();
	}

	if (key == 's' || key == 'S')
	{

		if (day)
		{
			day = false;
		}
		else
		{
			day = true;
		}
		glutPostRedisplay();
		glutIdleFunc(background1);
	}
}


void doFrame(int v)
{
	frameNumber++;
	glutPostRedisplay();
	glutTimerFunc(30, doFrame, 0);
}

void win1()
{
	glClearColor(0.5f, 0.5f, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	drawText(600, 700, 0, 0, 0, 0, "WIND ENERGY");
	glFlush();
}

void win2()
{
	// glClearColor(1, 1, 1, 1);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// glOrtho(0, 7, -1, 4, -1, 1);
	// glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (day)
	{
		glClearColor(0.9, 0.9, 0.9, 0.0);
	}
	else
	{
		glClearColor(0.3, 0.3, 0.3, 0.0);
	}
	glColor3f(.0, 1.0, 1.0);
	glViewport(0, 0, 1700, 750);
	
	glutKeyboardFunc(mykey);
	/* Select the projection matrix and reset it then
     setup our view perspective */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0f, (GLfloat)1700 / (GLfloat)750, 0.1f, 200.0f);
	/* Select the modelview matrix, which we alter with rotatef() */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearDepth(2.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glDepthFunc(GL_LEQUAL);
	background1();
	drawText(600, 700, 0, 0, 0, 0, "Solar ENERGY");
	glFlush();
}

void win3()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	drawText(600, 700, 0, 0, 0, 0, "HYRDO ENERGY");
	glFlush();
}

void menu(int num)
{
	if (num == 0)
	{
		glutDestroyWindow(window);
		exit(0);
	}
	else
	{
		value = num;
	}
}

void createMenu(void)
{
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Wind Energy", 1);
	glutAddMenuEntry("Solar Energy", 2);
	glutAddMenuEntry("Hydro Energy", 3);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Normalkey(unsigned char k, int x, int y)
{
	switch (k)
	{
	case '1':
		win1();
		break;
	}
}

void init()
{
	// glClearColor(0.5f, 0.5f, 1, 1);
	// The next three lines set up the coordinates system.
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// glOrtho(0, 7, -1, 4, -1, 1);
	// glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawText(500, 650, 1, 0, 0.2, d, "PROJECT THEME: ");
	drawText(750, 650, 0.8, 0, 0.2, d, "HUMAN AND NATURE INTERACTION");
	drawText(500, 600, 1, 0, 0.2, d, "PROJECT TITLE: ");
	drawText(750, 600, 0.8, 0, 0.2, d, "ALTERNATE SOURCES OF ENERGY");
	drawText(600, 550, 0.5, 0, 0.1, d, "PRAVEEN K B");
	drawText(600, 520, 0.5, 0, 0.1, d, "(1BI16CS105)");
	drawText(600, 480, 0.5, 0, 0.1, d, "PRATEEK J");
	drawText(600, 450, 0.5, 0, 0.1, d, "(1BI16CS105)");
	drawText(500.0, 350.0, 1, 1, 1, d, "UNDER THE GUIDENCE OF");
	// drawText(500.0, 290.0, 1, 1, 0, d, "Prof.Ravichandra H");
	// drawText(500.0, 260.0, 1, 1, 0, d, "Assistant Professor, Dept of CSE");
	drawText(500.0, 230, 1, 1, 0, d, "BIT, Bangalore");
	// drawText(500, 150, 0, 1, 0, d, "PRESS '1' TO START");
	switch (value)
	{
	case 1:
		glutKeyboardFunc(NULL);
		win1();
		break;
	case 2:
		win2();
		break;
	case 3:
		win3();
		break;
	}
	glFlush();
}
/*
void mykey(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q')
	{
		exit(0);
	}

	if (key == 'h' || key == 'H')
	{
		help1 = !help1;
		glutPostRedisplay();
	}

	if (key == 's' || key == 'S')
	{

		if (day)
		{
			day = false;
		}
		else
		{
			day = true;
		}
		glutPostRedisplay();
		glutIdleFunc(background1);
	}
}
*/
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);
	glutInitWindowSize(1500, 750);
	glutCreateWindow("Alternate Sources of Energy");
	// glClearColor(0.50, 0.88, 0.96, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1500, 0, 750);
	glutDisplayFunc(display);
	// init();
	// doInit();
	createMenu();

	glutTimerFunc(200, doFrame, 0);
	//glutKeyboardFunc(mykey);
	// doInit();
	glutMainLoop();
	return 0;
}
