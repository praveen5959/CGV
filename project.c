#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
int d = 0;
static int submenu_id;
static int menu_id;
static int window;
static int value=0;
void drawText(float x, float y, int r, int g, int b, int d, const char *string)
{
    int j = strlen(string);
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (int i = 0; i < j; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
        for (int k = d; k>0; k--) {
            glFlush();
        }
    }
}

void background(){
    glColor3f(0.8, 0.0, 0.2);
    
}

void win1() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background();
    drawText(600, 700, 0, 0, 0, 0, "WIND ENERGY");
    glFlush();
    
}

void win2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background();
    drawText(600, 700, 0, 0, 0, 0, "SOLAR ENERGY");
    glFlush();
    
}

void win3() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background();
    drawText(600, 700, 0, 0, 0, 0, "HYRDO ENERGY");
    glFlush();
    
}

void menu(int num){
    if(num==0){
        glutDestroyWindow(window);
        exit(0);
    }
    else{
        value=num;
    }
}

void createMenu(void){
    menu_id=glutCreateMenu(menu);
    glutAddMenuEntry("Wind Energy",1);
    glutAddMenuEntry("Solar Energy", 2);
    glutAddMenuEntry("Hydro Energy",3);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Normalkey(unsigned char k, int x, int y)
{
    switch (k)
    {
        case '1':win1();
                break;   
    }
}

void display(){
    glClearColor(1.0,1.0,1.0, 0.0);
    
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
    switch(value){
        case 1: win1();
                break;
        case 2: win2();
                break;
        case 3: win3();
                break;
    }
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);
    glutInitWindowSize(1500, 750);
    glutCreateWindow("Alternate Sources of Energy");
    glClearColor(0.50, 0.88, 0.96, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1500, 0, 750);
    createMenu();
    glutDisplayFunc(display);   
    glutMainLoop();
    return 0;
}