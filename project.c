#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
//#include <windows.h>
#include <stdarg.h>
int d = 0;
static int submenu_id;
static int menu_id;
static int window;
static int value = 0;
int window1 = 0;
int window2 = 0;
int window3 = 0;
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

// Nuclear
void *font;
void *currentfont;
int fontType, flag = 0;
int in_about;
int enter;
float i, j;
float x2, y2, r, r1 = 80, r2 = 5.0, r3 = 27.5, r4 = 6, r5 = 6, y, angle_radians, r6 = 23, r7 = 2, r8 = 3, r9 = 6, r10 = 18, r11 = 10, r12 = 26, r13 = 14;
int k = 0;
int p = 0;

void conecting_pipe();

void delay(int x)
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < i * 1000; j++)
			;
	}
}
void drawstring(float x, float y, float z, char *string)
{
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glColor3f(0.0, 1.0, 1.0);
		glutBitmapCharacter(currentfont, *c);
	}
}
void fig1()
{

	glBegin(GL_POINTS);
	glVertex2f(255, 138);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(265, 158);
	glVertex2f(245, 158);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(277, 135);
	glVertex2f(263, 118);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(231, 133);
	glVertex2f(247, 118);
	glEnd();
}

void fig2()
{
	glBegin(GL_POINTS);
	glVertex2f(255, 138);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(275, 150);
	glVertex2f(275, 126);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(250, 115);
	glVertex2f(234, 130);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(253, 160);
	glVertex2f(236, 149);
	glEnd();
}

void fig3()
{

	glBegin(GL_POINTS);
	glVertex2f(255, 138);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(266, 117);
	glVertex2f(244, 117);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(277, 144);
	glVertex2f(261, 160);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(249, 159);
	glVertex2f(233, 144);
	glEnd();
}

void fig4()
{

	glBegin(GL_POINTS);
	glVertex2f(255, 138);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(235, 128);
	glVertex2f(235, 148);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(276, 144);
	glVertex2f(257, 161);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(255, 138);
	glVertex2f(257, 115);
	glVertex2f(275, 127);
	glEnd();
}

void rot1()
{
	glDisable(GL_DEPTH_TEST);
	glColor3f(0.0, 0.0, 0.0);
	fig1();
	glFlush();
	glColor3f(0.3, 0.1, 0.1);
	fig1();
	glFlush();
	//delay(1000);
	glColor3f(0.0, 0.0, 0.0);
	fig1();
	//glFlush();
	//delay(1000);
	glColor3f(0.3, 0.1, 0.1);
	fig2();
	glFlush();
	//delay(1000);
	glColor3f(0.0, 0.0, 0.0);
	fig2();
	//glFlush();
	glColor3f(0.3, 0.1, 0.1);
	fig3();
	glFlush();
	glColor3f(0.0, 0.0, 0.0);
	fig3();
	glFlush();
	glColor3f(0.3, 0.1, 0.1);
	fig4();
	glFlush();
	/*glColor3f(0.0,0.0,0.0);
fig4();
glFlush();
*/
	//delay(1000);

	//glEnable(GL_DEPTH_TEST);
	//flag=2;
}

void turbine()
{
	glLineWidth(6.0);
	glBegin(GL_LINE_LOOP);
	for (angle = 0; angle <= 360; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 255 + r6 * (float)cos(angle_radians);
		y = 138 + r6 * (float)sin(angle_radians);
		glColor3f(0.3, 0.1, 0.1);

		glVertex2f(x, y);
	}
	glEnd();

	glLineWidth(6.0);
	glBegin(GL_LINE_STRIP);
	for (angle = 0; angle <= 360; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 255 + r12 * (float)cos(angle_radians);
		y = 138 + r12 * (float)sin(angle_radians);
		glColor3f(0.3, 0.1, 0.1);

		glVertex2f(x, y);
	}
	glEnd();

	glPointSize(6);

	glBegin(GL_POINTS);
	glVertex2f(255, 138);
	glEnd();
	fig4();
}

void generator()
{

	glColor3f(0.5, 0.5, 0.9);
	glBegin(GL_POLYGON);
	glVertex3i(338, 120, 0);
	glColor3f(0.2, 0.2, 0.6);
	glVertex3i(338, 150, 0);
	glVertex3i(343, 150, 0);
	glVertex3i(343, 120, 0);
	glEnd();

	glColor3f(0.5, 0.5, 0.9);
	glBegin(GL_POLYGON);
	glVertex3i(351, 120, 0);
	glColor3f(0.2, 0.2, 0.6);
	glVertex3i(351, 150, 0);
	glVertex3i(356, 150, 0);
	glVertex3i(356, 120, 0);
	glEnd();

	glColor3f(0.5, 0.5, 0.9);
	glBegin(GL_POLYGON);
	glVertex3i(364, 120, 0);
	glColor3f(0.2, 0.2, 0.6);
	glVertex3i(364, 150, 0);
	glVertex3i(369, 150, 0);
	glVertex3i(369, 120, 0);
	glEnd();

	glColor3f(0.3, 0.1, 0.1);
	glBegin(GL_POLYGON);

	glVertex3i(375, 144, 0);
	glVertex3i(277, 144, 0);
	glVertex3i(277, 137, 0);
	glVertex3i(375, 137, 0);
	glEnd();

	glLineWidth(6.0);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2f(330, 170);
	glVertex2f(385, 170);
	glVertex2f(385, 111);
	glVertex2f(330, 111);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.2, 0.2, 0.6);
	glVertex3i(330, 111, 0);
	glVertex3i(330, 120, 0);

	glColor3f(0.5, 0.5, 0.9);
	glVertex3i(375, 120, 0);
	glVertex3i(375, 111, 0);
	glEnd();
}
void connecting_pipe()
{
	glLineWidth(3.0);
	glColor3f(0.6, 0.3, 0.2);
	glBegin(GL_LINES);
	glVertex2i(150, 104);
	glVertex2i(180, 104);
	glVertex2i(150, 108);
	glVertex2i(180, 108);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(185, 100);
	glVertex2i(185, 50);
	glVertex2i(185, 50);
	glVertex2i(224, 50);
	glVertex2i(189, 100);
	glVertex2i(189, 54);
	glVertex2i(189, 54);
	glVertex2i(224, 54);
	glEnd();
}

void points()
{
	glPointSize(4);
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POINTS);
	glVertex2f(243, 134);
	glVertex2f(249, 128);
	glVertex2f(246, 122);
	glVertex2f(256, 115);
	glVertex2f(251, 110);
	glVertex2f(264, 108);
	glVertex2f(272, 104);
	glVertex2f(242, 110);
	glVertex2f(247, 100);
	glVertex2f(256, 104);
	glVertex2f(230, 100);
	glVertex2f(235, 105);
	glVertex2f(239, 110);
	glVertex2f(264, 104);
	glVertex2f(249, 123);
	glVertex2f(269, 130);
	glVertex2f(264, 128);
	glVertex2f(270, 100);
	glVertex2f(274, 104);
	glVertex2f(272, 90);
	glVertex2f(275, 130);
	glVertex2f(265, 127);
	glVertex2f(255, 133);
	glEnd();
}

void steam()
{

	//steam
	for (i = 0; i < 21; i = i + 1)
	{

		glColor4f(0.4, 0.4, 0.4, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(120, 185.5 + i);
		glVertex2f(120, 189.5 + i);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glVertex2f(124, 189.5 + i);
		glVertex2f(124, 185.5 + i);
		glEnd();
		glFlush();
		delay(200);
	}

	for (i = 0; i < 117; i = i + 1)
	{

		glBegin(GL_QUADS);
		glColor4f(1.0, 1.0, 1.0, 1.0);

		glVertex2f(124 + i, 210);
		glVertex2f(128 + i, 210);
		glColor4f(0.4, 0.4, 0.4, 1.0);

		glVertex2f(128 + i, 206);
		glVertex2f(124 + i, 206);
		glEnd();
		glFlush();
		delay(200);
	}
	for (i = 0; i < 33; i = i + 1)
	{

		glBegin(GL_QUADS);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glVertex2f(240, 206 - i);
		glColor4f(0.4, 0.4, 0.4, 1.0);
		glVertex2f(244, 206 - i);
		glVertex2f(244, 202 - i);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glVertex2f(240, 202 - i);
		glEnd();
		glFlush();
		delay(200);
	}
	//glFlush();

	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_QUADS);
	glVertex2f(240, 170);
	glVertex2f(244, 170);
	glVertex2f(252, 159);
	glVertex2f(232, 159);

	glEnd();
	glFlush();
}

void points1()
{
	glPointSize(5.0);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(46, 124);
	glVertex2f(44, 130);
	glVertex2f(48, 135);
	glVertex2f(49, 126);
	glVertex2f(42, 140);
	glVertex2f(46, 139);
	glVertex2f(54, 128);
	glVertex2f(38, 148);
	glVertex2f(32, 143);
	glVertex2f(57, 124);
	glVertex2f(61, 138);
	glVertex2f(51, 134);
	glEnd();
}

void points2()
{
	glPointSize(3.0);
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POINTS);
	glVertex2f(107, 117);
	glVertex2f(109, 120);
	glVertex2f(110, 123);
	glVertex2f(106, 125);
	glVertex2f(113, 120);
	glVertex2f(113, 131);
	glVertex2f(108, 141);
	glVertex2f(111, 130);
	glVertex2f(107, 127);
	glVertex2f(111, 131);
	glVertex2f(123, 145);
	glVertex2f(131, 145);
	glVertex2f(142, 151);
	glVertex2f(133, 148);
	glVertex2f(137, 133);
	glVertex2f(139, 157);
	glVertex2f(128, 160);
	glVertex2f(146, 163);
	glVertex2f(149, 170);
	glVertex2f(150, 124);
	glVertex2f(153, 119);
	glVertex2f(148, 136);
	glVertex2f(137, 115);
	glVertex2f(149, 127);
	glVertex2f(108, 170);
	glVertex2f(104, 145);
	glVertex2f(109, 175);
	glVertex2f(111, 156);
	glVertex2f(118, 164);
	glVertex2f(127, 166);
	glVertex2f(129, 169);
	glVertex2f(126, 132);
	glVertex2f(123, 128);
	glVertex2f(126, 140);
	glVertex2f(119, 141);
	glVertex2f(127, 151);
	glVertex2f(126, 155);
	glVertex2f(121, 171);
	glVertex2f(126, 180);
	glVertex2f(133, 185);
	glVertex2f(141, 190);
	glVertex2f(138, 176);

	glEnd();
}

void working()
{

	//control rods
	glClearColor(0, 0, 0, 0);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex3i(48, 122, 1);
	glVertex3i(48, 140, 1);
	glVertex3i(50, 122, 1);
	glVertex3i(50, 140, 1);
	glVertex3i(52, 122, 1);
	glVertex3i(52, 140, 1);
	glEnd();

	glColor3f(0.6, 0.6, 0.4);

	glBegin(GL_LINES);
	glVertex2i(48, 140);
	glVertex2i(48, 185);
	glVertex2i(50, 140);
	glVertex2i(50, 185);
	glVertex2i(52, 140);
	glVertex2i(52, 185);
	glEnd();
	delay(500);

	for (i = 0, j = 0; i < 40, j < 40; i = i + 1, j = i + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(70 + i, 117);

		glVertex2f(74 + i, 117);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(74 + i, 121);

		glVertex2f(70 + i, 121);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(350 - j, 89);
		glVertex2f(280 - j, 89);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(280 - j, 85);
		glVertex2f(350 - j, 85);
		glEnd();
		glFlush();
		delay(200);
	}

	for (i = 0, j = 0; i < 32, j < 25; i = i + 1, j = j + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(111, 117 + i);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(114, 117 + i);

		glVertex2f(114, 136 + i);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(111, 136 + i);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(240, 89 - j);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(244, 89 - j);
		glVertex2f(244, 85 - j);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(240, 85 - j);
		glEnd();

		glFlush();
		delay(200);
	}

	for (i = 0, j = 0; i < 25, j < 25; i = i + 1, j = j + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(111 + i, 160);
		glVertex2f(115 + i, 160);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(115 + i, 163.5);
		glVertex2f(111 + i, 163.5);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(244 + j, 65);
		glVertex2f(326 + j, 65);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(326 + j, 61);
		glVertex2f(244 + j, 61);
		glEnd();

		glFlush();
		delay(200);
	}

	for (i = 0; i < 112; i = i + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(135.2, 160 - i);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(138.9, 160 - i);
		glVertex2f(138.9, 156 - i);

		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(135.2, 156 - i);
		glEnd();
		glFlush();
		delay(200);
	}
	for (i = 0; i < 40; i = i + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(131 - i, 47.5);
		glVertex2f(135.3 - i, 47.5);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(135.3 - i, 44.5);
		glVertex2f(131 - i, 44.5);
		glEnd();
		glFlush();
		delay(200);
	}
	delay(500);
	for (i = 0; i < 58; i = i + 1)
	{

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_QUADS);
		glVertex2f(80 - i, 47.5);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(80 - i, 44.5);

		glVertex2f(76 - i, 44.5);
		glColor3f(1.0, 1.0, 1.0);

		glVertex2f(76 - i, 47.5);
		glEnd();
		glFlush();
		delay(200);
	}

	for (i = 0; i < 92; i = i + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(16.5, 47.5 + i);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(19.5, 47.5 + i);

		glVertex2f(19.5, 44.5 + i);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(16.5, 44.5 + i);
		glEnd();
		glFlush();
		delay(200);
	}

	for (i = 0; i < 8; i = i + 1)
	{

		glColor3f(0.0, 0.6, 0.8);
		glBegin(GL_QUADS);
		glVertex2f(19.5 + i, 138.5);
		glVertex2f(23 + i, 138.5);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(23 + i, 135.5);
		glVertex2f(19.5 + i, 135.5);
		glEnd();
		glFlush();
		delay(200);
	}

	points2();

	steam();

	glPushMatrix();
	while (p < 200)
	{
		flag = 1;
		if (flag == 1)
		{
			rot1();
		}
		/*
if(flag==2)
{
rot2();
}

if(flag==3)
{
	rot3();
}
if(flag==4)
{
	rot4();
}
*/
		p++;
		if (p == 199)
			glEnable(GL_DEPTH_TEST);
	}
	glPopMatrix();
	//delay(1000);
	points();
	conecting_pipe();
	glFlush();
}

void conecting_pipe()
{
	//coolant water
	for (i = 0; i < 31; i = i + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(215 - i, 54);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(215 - i, 50);
		glVertex2f(225 - i, 50);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(225 - i, 54);
		glEnd();
		glFlush();
		delay(200);
	}

	for (i = 0; i < 43; i = i + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(185, 54 + i);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(189, 54 + i);
		glVertex2f(189, 58 + i);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(185, 58 + i);
		glEnd();
		glFlush();
		delay(200);
	}

	delay(500);
	for (i = 0; i < 28; i = i + 1)
	{

		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(180 - i, 108);
		glColor3f(0.0, 0.6, 0.8);
		glVertex2f(180 - i, 104);
		glVertex2f(176 - i, 104);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(176 - i, 108);
		glEnd();
		glFlush();
		delay(200);
	}
}

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
void setFont(void *font)
{
	currentfont = font;
}
void background2()
{
	glLineWidth(6.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2i(10, 200);
	glColor3f(0.1, 0.3, 0.0);
	glVertex2i(10, 30);
	glVertex2i(170, 30);
	glColor3f(0.6, 0.6, 0.6);

	glVertex2i(170, 200);
	glEnd();
	//draw semicircle

	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_LINE_STRIP);
	for (angle = 0; angle <= 180; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 90 + r1 * (float)cos(angle_radians);
		y = 200 + r1 * (float)sin(angle_radians);
		glLineWidth(6.0);
		glVertex2f(x, y);
	}

	glEnd();
	//draw 1st inner container
	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(42.0, 98.0, 0.0, "core");

	glColor3f(0.6, 0.6, 0.6);

	glBegin(GL_LINE_LOOP);
	glVertex2i(25, 150);
	glVertex2i(25, 75);
	glVertex2i(75, 75);
	glVertex2i(75, 150);
	glEnd();

	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_LINES);
	glVertex2i(100, 100);
	glVertex2i(100, 170);

	glVertex2i(155, 100);

	glVertex2i(155, 170);

	glEnd();

	glBegin(GL_LINE_STRIP);
	for (angle = 0; angle <= 180; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 127.5 + r3 * (float)cos(angle_radians);
		y = 170 + r3 * (float)sin(angle_radians);
		glLineWidth(6.0);
		glVertex2f(x, y);
	}

	glEnd();
	glBegin(GL_LINE_STRIP);
	for (angle = 180; angle <= 360; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 127.5 + r3 * (float)cos(angle_radians);
		y = 100 + r3 * (float)sin(angle_radians);
		glLineWidth(6.0);
		glVertex2f(x, y);
	}

	glEnd();

	//core container
	glLineWidth(5.0);
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_LINE_LOOP);
	glVertex2i(42, 105);

	glVertex2i(57, 105);
	glVertex2i(57, 120);
	glVertex2i(42, 120);
	glEnd();

	//draw core
	glBegin(GL_POLYGON);
	for (angle = 0; angle <= 360; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 49 + r2 * (float)cos(angle_radians);
		y = 112.5 + r2 * (float)sin(angle_radians);
		glColor3f(1.0, 0.4, 0.2);
		glLineWidth(6.0);
		glVertex2f(x, y);
	}
	glEnd();

	//2nd outer container
	glLineWidth(6.0);
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_LINE_LOOP);
	glVertex2i(220, 170);
	glColor3f(0.1, 0.3, 0.0);

	glVertex2i(220, 30);
	glVertex2i(330, 30);
	glColor3f(0.6, 0.6, 0.6);
	glVertex2i(330, 220);
	glEnd();
	//pipe frm cont1
	glLineWidth(3.0);
	glColor3f(0.6, 0.3, 0.2);
	glBegin(GL_LINE_STRIP);
	glVertex2i(30, 135);
	glVertex2i(20, 135);
	glVertex2i(20, 48);
	glVertex2i(80, 48);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2i(80, 44);
	glVertex2i(16, 44);
	glVertex2i(16, 139);
	glVertex2i(30, 139);
	glEnd();
	//pipe frm con2
	glColor3f(0.6, 0.3, 0.2);
	glBegin(GL_LINE_STRIP);
	glVertex2i(70, 117);
	glVertex2i(115, 117);
	glVertex2i(115, 160);
	glVertex2i(135, 160);
	glVertex2i(135, 48);
	glVertex2i(92, 48);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2i(92, 44);
	glVertex2i(139, 44);
	glVertex2i(139, 164);
	glVertex2i(111, 164);
	glVertex2i(111, 121);
	glVertex2i(70, 121);
	glEnd();

	glColor3f(0.6, 0.3, 0.2);
	//pump1
	glBegin(GL_POLYGON);
	for (angle = 0; angle <= 360; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 86 + r4 * (float)cos(angle_radians);
		y = 46 + r4 * (float)sin(angle_radians);

		glVertex2f(x, y);
	}
	glEnd();

	glColor4f(0.0, 0.0, 0.0, 1.0);
	glLineWidth(6.0);
	glBegin(GL_LINES);
	glVertex2i(80, 48);
	glVertex2i(92, 44);
	glVertex2i(80, 44);
	glVertex2i(92, 48);
	glEnd();
	//upper pipe
	glLineWidth(3.0);
	glColor3f(0.6, 0.3, 0.2);
	glBegin(GL_LINES);
	glVertex2i(240, 170);
	glVertex2f(240, 178);
	glVertex2f(240, 180);
	glVertex2i(240, 206);
	glVertex2i(240, 206);
	glVertex2i(124, 206);
	glVertex2i(124, 206);
	glVertex2f(124, 198);
	glVertex2f(124, 196);
	glVertex2i(124, 185);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(120, 185);
	glVertex2i(120, 195);
	glVertex2i(120, 197);
	glVertex2i(120, 210);
	glVertex2i(120, 210);
	glVertex2i(244, 210);
	glVertex2i(244, 210);
	glVertex2i(244, 182);
	glVertex2i(244, 180);
	glVertex2i(244, 170);
	glEnd();
	//coolant pipe
	glBegin(GL_LINES);
	glVertex2i(350, 85);
	glVertex2f(331, 85);
	glVertex2f(329, 85);
	glVertex2i(244, 85);
	glVertex2i(244, 85);
	glVertex2i(244, 65);
	glVertex2i(244, 65);
	glVertex2i(329, 65);
	glVertex2i(331, 65);
	glVertex2i(350, 65);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(350, 89);
	glVertex2i(331, 89);

	glVertex2i(329, 89);
	glVertex2i(240, 89);
	glVertex2i(240, 89);
	glVertex2i(240, 61);
	glVertex2i(240, 61);
	glVertex2i(329, 61);
	glVertex2i(331, 61);
	glVertex2i(350, 61);
	glEnd();
	//control rods
	glColor3f(0.6, 0.6, 0.4);

	glBegin(GL_LINES);
	glVertex2i(48, 120);
	glVertex2i(48, 165);
	glVertex2i(50, 120);
	glVertex2i(50, 165);
	glVertex2i(52, 120);
	glVertex2i(52, 165);
	glEnd();

	glColor3f(0.3, 0.1, 0.1);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(42.0, 98.0, 0.0, "core");

	turbine();
	generator();
	connecting_pipe();
	//pump2
	glColor3f(0.6, 0.3, 0.2);

	glBegin(GL_POLYGON);
	for (angle = 0; angle <= 360; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 186 + r5 * (float)cos(angle_radians);
		y = 106 + r5 * (float)sin(angle_radians);
		glLineWidth(6.0);
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(60.0, 250.0, 0.0, "constraint structure");

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(54.0, 160.0, 0.0, "control rods");

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(30.0, 60.0, 0.0, "reactor vessel");

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(250.0, 105.0, 0.0, "turbine");

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(180.0, 120.0, 0.0, "pump");
	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(180.0, 215.0, 0.0, "steam line");

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(102.0, 170.0, 0.0, "steam generator");

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(80.0, 55.0, 0.0, "pump");

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(290.0, 150.0, 0.0, "generator");

	glColor3f(1.0, 1.0, 1.0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	drawstring(248.0, 70.0, 0.0, "condensor cooling water");

	//blended water

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(26, 122);
	glColor3f(0.0, 0.6, 0.8);
	glVertex2f(26, 76);
	glVertex2f(74, 76);
	glColor3f(0.0, 0.0, 0.5);
	glVertex2f(74, 122);
	glEnd();
	//blended container
	glColor3f(0.0, 0.6, 0.8);

	glBegin(GL_POLYGON);
	glVertex2i(100, 100);
	glVertex2i(155, 100);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(155, 113);

	glVertex2i(100, 113);
	glEnd();

	glColor3f(0.0, 0.6, 0.8);

	glBegin(GL_POLYGON);
	for (angle = 180; angle <= 360; angle = angle + 5)
	{
		angle_radians = angle * (float)3.14159 / (float)180;
		x = 127.5 + r3 * (float)cos(angle_radians);
		y = 100 + r3 * (float)sin(angle_radians);
		glLineWidth(6.0);
		glVertex2f(x, y);
	}

	glEnd();
	glFlush();
	//water in cont2

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.6, 0.8);
	glVertex2f(221, 31);
	glVertex2f(329, 31);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(329, 57);
	glVertex2f(221, 57);
	glEnd();
	glFlush();
	delay(1000);
	points1();
	delay(1000);
	working();

	glFlush();
}
void mykey(unsigned char key, int x, int y)
{

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
		//glutIdleFunc(background1);
	}
	if (key == 'z' || key == 'Z')
	{
		glutHideWindow();
	}
}

void doFrame(int v)
{
	frameNumber++;
	glutPostRedisplay();
	glutTimerFunc(30, doFrame, 0);
}

void mykey1(unsigned char key, int x, int y)
{
	if (key == 'z' || key == 'Z')
	{
		glutHideWindow();
	}
}

void win1()
{
	glClearColor(0.5f, 0.5f, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glutKeyboardFunc(mykey1);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background();
	drawText(600, 700, 0, 0, 0, 0, "WIND ENERGY");
	glFlush();
}

void win2()
{
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
	// glutKeyboardFunc(mykey1);
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
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, 1750, 750);
	glutKeyboardFunc(mykey1);
	background2();
	glFlush();
}
void mainKey(unsigned char key, int x, int y)
{
	if (key == '1')
	{
		window1 = glutCreateWindow("wind");
		glutDisplayFunc(win1);
	}
	else if (key == '2')
	{
		window2 = glutCreateWindow("Solar");
		glutDisplayFunc(win2);
	}
	else if (key == '3')
	{
		window3 = glutCreateWindow("Nuclear");
		glutDisplayFunc(win3);
	}
	else if (key == 'q' || key == 'Q')
	{
		glutLeaveMainLoop();
		exit(0);
	}
}
// void menu(int num)
// {
// 	if (num == 0)
// 	{
// 		glutDestroyWindow(window);
// 		exit(0);
// 	}
// 	else
// 	{
// 		value = num;
// 	}
// }

// void createMenu(void)
// {
// 	menu_id = glutCreateMenu(menu);
// 	glutAddMenuEntry("Wind Energy", 1);
// 	glutAddMenuEntry("Solar Energy", 2);
// 	glutAddMenuEntry("Nuclear Energy", 3);
// 	glutAddMenuEntry("Quit", 0);
// 	glutAttachMenu(GLUT_RIGHT_BUTTON);
// }

void display()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutDestroyWindow(window1);
	drawText(500, 650, 1, 0, 0.2, d, "PROJECT THEME: ");
	drawText(750, 650, 0.8, 0, 0.2, d, "HUMAN AND NATURE INTERACTION");
	drawText(500, 600, 1, 0, 0.2, d, "PROJECT TITLE: ");
	drawText(750, 600, 0.8, 0, 0.2, d, "ALTERNATE SOURCES OF ENERGY");
	drawText(600, 550, 0.5, 0, 0.1, d, "PRAVEEN K B");
	drawText(600, 520, 0.5, 0, 0.1, d, "(1BI16CS105)");
	drawText(600, 480, 0.5, 0, 0.1, d, "PRATEEK J");
	drawText(600, 450, 0.5, 0, 0.1, d, "(1BI16CS105)");
	drawText(500.0, 350.0, 1, 1, 1, d, "UNDER THE GUIDENCE OF");
	drawText(500.0, 230, 1, 1, 0, d, "BIT, Bangalore");

	// switch (value)
	// {
	// case 1:

	// 	window1 = glutCreateWindow("wind");
	// 	glutDisplayFunc(win1);
	// 	glutDestroyMenu(menu_id);
	// 	//win1();
	// 	break;
	// case 2:
	// 	// glutDestroyWindow(window1);
	// 	glutCreateWindow("solar");
	// 	glutDisplayFunc(win2);
	// 	// win2();
	// 	break;
	// case 3:
	// 	glutKeyboardFunc(NULL);
	// 	win3();
	// 	break;
	// }
	glFlush();
}

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
	// createMenu();
	glutDisplayFunc(display);
	glutKeyboardFunc(mainKey);
	glutTimerFunc(200, doFrame, 0);
	//glutSetOption( GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION );
	glutMainLoop();
	return 0;
}
