/* gasket.c   */

/* E. Angel, Interactive Computer Graphics */
/* A Top-Down Approach with OpenGL, Third Edition */
/* Addison-Wesley Longman, 2003 */

/* Two-Dimensional Sierpinski Gasket          */
/* Generated Using Randomly Selected Vertices */
/* And Bisection                              */

/* modified to add comments & viewport stuff, */
/*  and package code slightly differently -lizb 1/03 */

#include <GL/glut.h>

/* initialization: */
void myinit(void)
{
 
/* attributes */

      glClearColor(0.0, 0.0, 0.0, 0.0); /* white background */
      glColor3f(1.0, 0.0, 0.0); /* draw in red */

/* set up viewing: */
/* 500 x 500 window with origin lower left */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, 500.0, 0.0, 500.0);
      glMatrixMode(GL_MODELVIEW);
}

/* draw a 5000-point 2D Sierpinski gasket in the square (0,0) to (500,500) */
void drawGasket()
{

/* define a point data type */

    typedef GLfloat point2[2];     

    /* use it to define the three vertices of a triangle */
    point2 vertices[3]={{0.0,0.0},{250.0,500.0},{500.0,0.0}}; 

    int i, j, k;
    int rand();       /* standard random number generator */
    point2 p ={75.0,50.0};  /* An arbitrary initial point inside triangle */

    /* compute and plot 5000 points on the gasket: */
    for( k=0; k<10000; k++)
    {
      /* first, pick a vertex at random */
         j=rand()%3; 

      /* then, compute point halfway between selected vertex and old point */
         p[0] = (p[0]+vertices[j][0])/2.0; 
         p[1] = (p[1]+vertices[j][1])/2.0;

   
     /* plot new point */
          glBegin(GL_POINTS);
              glVertex2fv(p); 
          glEnd();
     /* etc. */
     }
}

/* the display callback: */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */


    /* send the gasket points to the frame buffer */
    drawGasket();

    /* and flush that buffer to the screen */
    glFlush(); 
 }

int main(int argc, char** argv)
{

/* Standard GLUT initialization */

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* default, not needed */
    glutInitWindowSize(500,500); /* 500 x 500 pixel window */
    glutInitWindowPosition(0,0); /* place window top left on display */
    glutCreateWindow("Sierpinski Triangle 01"); /* window title */
    glutDisplayFunc(display); /* display callback invoked when window opened */
    myinit(); /* set attributes */
    glutMainLoop(); /* enter event loop */
}
