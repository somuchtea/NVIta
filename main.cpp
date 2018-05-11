#include <GL/glut.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <windows.h>
#include "field.h"
using namespace std;
const int width=700;
const int height=700;
void init () {

	glClearColor ( 0.0, 0.0, 0.0, 0.0 );
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D ( 0, width , height, 0  );
}
field Bfie(rows*columns,mu);

bool hold=0;
int point2ind(int x,int y)
{
    return ((y/(height/rows))*columns)+x/(width/columns)+1;
}
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //srand(time(0));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            glColor3ub(50,50,50);
                if(Bfie.getcells()[point2ind(i*(width/columns),j*(height/rows))].getState())
                    {glColor3ub(100,180,100);
                    if(Bfie.getcells()[point2ind(i*(width/columns),j*(height/rows))].isActive)
                        glColor3ub(100,255,100);}
                else{if(Bfie.getcells()[point2ind(i*(width/columns),j*(height/rows))].isActive)glColor3ub(70,50,50);}
            glBegin(GL_QUADS);
            glVertex2i(i*(width/columns),j*(height/rows));
            glVertex2i((i+1)*(width/columns),j*(height/rows));
            glVertex2i((i+1)*(width/columns),(j+1)*(height/rows));
            glVertex2i(i*(width/columns),(j+1)*(height/rows));
            glEnd();

        }
    }

    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
   if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
     {Bfie.getcells()[point2ind(x,y)].revive();
     //cout<<"ind="<<point2ind(x,y)<<endl;
     }
    if(button==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
        {Bfie.getcells()[point2ind(x,y)].kill();}

}
static void key(unsigned char key, int x, int y)
{
    if(key==' ')
    {
        //cout<<Bfie.getcells()[0].neighboors[0]<<endl;
        Bfie.getLbords();
        Bfie.iteration();
    }
    if(key=='x')hold=!hold;
    glutPostRedisplay();
}
static void idle(void)
{
    if(hold)
    {
        Bfie.getLbords();
        Bfie.iteration();
    }
    glutPostRedisplay();
    Sleep(100);
}
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("NVita");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    init();
    glutMainLoop();
    return 0;//EXIT_SUCCESS;
}
