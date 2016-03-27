
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
 
   glBegin(GL_TRIANGLES);              // Bikin Segitiga
      glColor3f(0.0f, 0.0f, 1.0f); // Blue
      glVertex2f(-1.0f, -0.866f);    // x, y

      glColor3f(0.0f, 1.0f, 0.0f); //Green
      glVertex2f( 1.0f,  -0.866f);

      glColor3f(1.0f, 0.0f, 0.0f); //Red
      glVertex2f( 0.0f,  0.866f);

   glEnd();
 
   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("Hello Triangle 2"); // Create a window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}