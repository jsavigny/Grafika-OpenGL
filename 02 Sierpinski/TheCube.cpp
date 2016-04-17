
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */

double rotate_y=0; 
double rotate_x=0;

void display() {
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();
   glRotatef( rotate_x, 1.0, 0.0, 0.0 );
   glRotatef( rotate_y, 0.0, 1.0, 0.0 );

      // FRONT
   glBegin(GL_POLYGON);
      glColor3f(1.0,1.0,1.0);
      glVertex3f( -0.5, -0.5, -0.5);       // P1
      glVertex3f( -0.5,  0.5, -0.5);       // P2
      glVertex3f(  0.5,  0.5, -0.5);       // P3
      glVertex3f(  0.5, -0.5, -0.5);       // P4
   glEnd();

      // BACK
   glBegin(GL_POLYGON);
      glColor3f(   1.0,  1.0, 0.0 );
      glVertex3f(  0.5, -0.5, 0.5 );
      glVertex3f(  0.5,  0.5, 0.5 );
      glVertex3f( -0.5,  0.5, 0.5 );
      glVertex3f( -0.5, -0.5, 0.5 );
   glEnd();
    
   // RIGHT
   glBegin(GL_POLYGON);
      glColor3f(  1.0,  0.5,  0.0 );
      glVertex3f( 0.5, -0.5, -0.5 );
      glVertex3f( 0.5,  0.5, -0.5 );
      glVertex3f( 0.5,  0.5,  0.5 );
      glVertex3f( 0.5, -0.5,  0.5 );
   glEnd();
    
   // LEFT
   glBegin(GL_POLYGON);
      glColor3f(   1.0,  0.0,  0.0 );
      glVertex3f( -0.5, -0.5,  0.5 );
      glVertex3f( -0.5,  0.5,  0.5 );
      glVertex3f( -0.5,  0.5, -0.5 );
      glVertex3f( -0.5, -0.5, -0.5 );
   glEnd();
    
   // TOP
   glBegin(GL_POLYGON);
      glColor3f(   0.0,  1.0,  0.0 );
      glVertex3f(  0.5,  0.5,  0.5 );
      glVertex3f(  0.5,  0.5, -0.5 );
      glVertex3f( -0.5,  0.5, -0.5 );
      glVertex3f( -0.5,  0.5,  0.5 );
   glEnd();
    
   // BOTTOM
   glBegin(GL_POLYGON);
      glColor3f(   0.0,  0.0,  1.0 );
      glVertex3f(  0.5, -0.5, -0.5 );
      glVertex3f(  0.5, -0.5,  0.5 );
      glVertex3f( -0.5, -0.5,  0.5 );
      glVertex3f( -0.5, -0.5, -0.5 );
   glEnd();
    
   glFlush();
   glutSwapBuffers();
}

void specialKeys( int key, int x, int y ) {
 
//  Right arrow - increase rotation by 5 degree
if (key == GLUT_KEY_RIGHT)
  rotate_y += 5;
 
//  Left arrow - decrease rotation by 5 degree
else if (key == GLUT_KEY_LEFT)
  rotate_y -= 5;
 
else if (key == GLUT_KEY_UP)
  rotate_x += 5;
 
else if (key == GLUT_KEY_DOWN)
  rotate_x -= 5;
 
//  Request display update
glutPostRedisplay();
 
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Kubus"); // Create a window with the given title
   glEnable(GL_DEPTH_TEST);
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutSpecialFunc(specialKeys);
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}