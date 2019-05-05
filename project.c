#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>
int d = 0;
static int submenu_id;
static int menu_id;
static int window;
static int value = 0;

// windmill constants
const double PI = 3.141592654;
int frameNumber = 0;

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	drawText(600, 700, 0, 0, 0, 0, "SOLAR ENERGY");
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

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);
	glutInitWindowSize(1500, 750);
	glutCreateWindow("Alternate Sources of Energy");
	glClearColor(0.50, 0.88, 0.96, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1500, 0, 750);
	glutDisplayFunc(display);
	// init();
	createMenu();
	glutTimerFunc(200, doFrame, 0);
	glutMainLoop();
	return 0;
}