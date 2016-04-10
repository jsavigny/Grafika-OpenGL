/* Sierpinski Triangle 02 */

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <ctime>

using namespace std;
//*******************************************************
// Function from class to draw the Sierpinski fractal


struct Point {
	float x;
	float y;
}; // end Point

struct Color{
	float R;
	float G;
	float B;
};

// Draws a triangle
void drawTriangle(Point a, Point b, Point c, Color color)
{  
	glColor3f(color.R,color.G,color.B);
	glBegin(GL_TRIANGLES);
     glVertex2f(a.x,a.y);
     glVertex2f(b.x,b.y);
     glVertex2f(c.x,c.y);
   glEnd();
} // end draw triangle

void drawSierpinski(Point a, Point b, Point c, int level)
{  
	Point m0, m1, m2;
	Color color;
	color.R = (float) (rand() % 100)/100;
	color.G = (float) (rand() % 100)/100;
	color.B = (float) (rand() % 100)/100;

	if (level > 0) {
		m0.x = (a.x+b.x) /2.0;
		m0.y = (a.y+b.y) /2.0;
		m1.x = (a.x+c.x) /2.0;
		m1.y = (a.y+c.y) /2.0;
		m2.x = (b.x+c.x) /2.0;
		m2.y = (c.y+b.y) /2.0;
		drawSierpinski(a,m0,m1,level-1);
		drawSierpinski(b,m2,m0,level-1);
		drawSierpinski(c,m1,m2,level-1);
	} else drawTriangle(a,b,c,color);
} // end draw Sierpinski



 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glColor3f( 1.0, 0.0, 0.0 );
   	Point a,b,c;
	a.x=-1.0; a.y=-0.866f;
	b.x=1.0; b.y=-0.866f;
	c.x=0.0; c.y=0.866f;
	drawSierpinski(a,b,c,3);
 
   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
	srand(time(0));
	glutInit(&argc, argv);                 // Initialize GLUT
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Sierpinski Triangle 02"); // Create a window with the given title
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}