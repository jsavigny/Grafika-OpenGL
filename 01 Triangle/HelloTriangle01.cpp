
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 
   glBegin(GL_TRIANGLES);              // Bikin Segitiga
      glColor3f(0.0f, 0.0f, 1.0f); // Blue
      glVertex2f(-01.0f, -0.866f);    // x, y
      glVertex2f( 0.0f, -0.866f);
      glVertex2f( -0.5f,  0.0f);
   glEnd();

   glBegin(GL_TRIANGLES);              // Bikin Segitiga
      glColor3f(0.0f, 1.0f, 0.0f); // Green
      glVertex2f(0.5f, 0.0f);    // x, y
      glVertex2f( 0.0f, -0.866f);
      glVertex2f( 1.0f,  -0.866f);
   glEnd();

   glBegin(GL_TRIANGLES);              // Bikin Segitiga
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.5f, 0.0f);    // x, y
      glVertex2f( 0.5f, 0.0f);
      glVertex2f( 0.0f,  0.866f);
   glEnd();
 
   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Hello Triangle 1"); // Create a window with the given title
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}