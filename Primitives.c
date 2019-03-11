#include <GL/glut.h>

GLfloat X = 0.0f;        // Translate screen to x direction (left or right)
GLfloat Y = 0.0f;        // Translate screen to y direction (up or down)

// A function to draw a line 
#define drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES); \
glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(-1.1, 1.1, -1.1, 1.1);   	// Displays the OpenGL window area 
					// from (x1,y1,x2,y2)
	glTranslatef(X, Y, 0.0f);               	// Moves (translates) the screen left 
					// to right and up or down
	glutPostRedisplay();
	glColor3f(1.0, 1.0, 1.0);

	// This lines are the two main lines for the coordinate system
	// The crossing point of the line is the (0,0,0)
	// Since its just 2 dimensional z is 0
	glBegin(GL_LINES);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(1, 0.0, 0.0);
	glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glEnd();

	// Example of some line stipple 
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0101); /* dotted */
	drawOneLine(-0.1, 1, -1, 1);
	glLineStipple(1, 0x00FF); /* dashed */
	drawOneLine(-0.1, 0.9, -1, 0.9);
	glLineStipple(1, 0x1C47); /* dash/dot/dash */
	drawOneLine(-0.1, 0.8, -1, 0.8);
	/* in 2nd row, 3 wide lines, each with different stipple */
	glLineWidth(5.0);
	glLineStipple(1, 0x0101); /* dotted */
	drawOneLine(-0.1, 0.7, -1, 0.7);
	glLineStipple(1, 0x00FF); /* dashed */
	drawOneLine(-0.1, 0.6, -1, 0.6);
	glLineStipple(1, 0x1C47); /* dash/dot/dash */
	drawOneLine(-0.1, 0.5, -1, 0.5);
	glLineWidth(1.0);
	glDisable(GL_LINE_STIPPLE);

	// Just basic lines (wrote E my names initial)
	glBegin(GL_LINES);
	glVertex2f(-1.0, 0.4);
	glVertex2f(-1.0, 0.1);
	glVertex2f(-1.0, 0.4);
	glVertex2f(-0.8, 0.4);
	glVertex2f(-1.0, 0.25);
	glVertex2f(-0.8, 0.25);
	glVertex2f(-1.0, 0.1);
	glVertex2f(-0.8, 0.1);
	glEnd();

	// Example of Line Strip
	// The end of the previous line is the beginning of the next line
	// The program connects the points for you basically you save time
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.6, 0.3);
	glVertex2f(-0.3, 0.2);
	glVertex2f(-.65, 0.2);
	glVertex2f(-0.4, 0.05);
	glEnd();

	// Example of Line Loop
	// Its similar to the line strip however at the end it connects the last point
	// with the beginning point
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.65, 0.45);
	glVertex2f(-0.1, 0.4);
	glVertex2f(-0.1, 0.1);
	glVertex2f(-0.4, 0.4);
	glEnd();

	// Example of points
	glBegin(GL_POINTS);
	glVertex3f(0.1, 0.1, 0.0);
	glVertex3f(0.1, 0.2, 0.0);
	glVertex3f(0.1, 0.3, 0.0);
	glVertex3f(0.1, 0.4, 0.0);
	glVertex3f(0.1, 0.5, 0.0);
	glVertex3f(0.1, 0.6, 0.0);
	glVertex3f(0.1, 0.7, 0.0);
	glVertex3f(0.1, 0.8, 0.0);
	glVertex3f(0.1, 0.9, 0.0);
	glVertex3f(0.1, 1.0, 0.0);
	glEnd();

	// Example of triangles
	glBegin(GL_TRIANGLES);
	glVertex3f(0.2, 1.0, 0.0);
	glVertex3f(0.5, 1.0, 0.0);
	glVertex3f(0.35, 0.6, 0.0);
	glEnd();

	// Example of triangle strip
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.2, 0.5, 0.0);
	glVertex3f(0.2, 0.1, 0.0);
	glVertex3f(0.4, 0.3, 0.0);
	glVertex3f(0.5, 0.4, 0.0);
	glVertex3f(0.4, 0.1, 0.0);
	glEnd();

	// Example of triangle fan
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.7, 0.0);
	glVertex3f(0.6, 0.6, 0.0);
	glVertex3f(0.7, 0.5, 0.0);
	glVertex3f(0.6, 0.4, 0.0);
	glEnd();

	// Example of quads
	glBegin(GL_QUADS);
	glVertex3f(-1, -0.2, 0.0);
	glVertex3f(-0.6, -0.2, 0.0);
	glVertex3f(-0.5, -0.50, 0.0);
	glVertex3f(-0.8, -0.75, 0.0);
	glEnd();

	// Example of quad strips
	glBegin(GL_QUAD_STRIP);
	glVertex3f(-0.1, -0.1, 0.0);
	glVertex3f(-0.3, -0.1, 0.0);
	glVertex3f(-0.124, -0.4, 0.0);
	glVertex3f(-0.27, -0.3, 0.0);
	glVertex3f(-0.35, -0.6, 0.0);
	glVertex3f(-0.4, -0.5, 0.0);
	glEnd();

	// Example of polygon
	glBegin(GL_POLYGON);
	glVertex3f(0.10, -0.25, 0.0);
	glVertex3f(0.7, -0.3, 0.0);
	glVertex3f(1, -0.50, 0.0);
	glVertex3f(0.6, -0.8, 0.0);
	glVertex3f(0.3, -0.6, 0.0);
	glEnd();

	// Don't wait start processing buffered OpenGL routines
	glFlush();
}

// Function to determine which key is pressed 
// Will be passed  to glutKeyboardFunc(keyCB);
void keyCB(unsigned char key, int x, int y)    /* called on key press */
{
	// if 'q' is pressed exit the program
	if (key == 'q' || key == 'Q')
		exit(0);
}

// Similar function like keyCB; determines which special key is pressed
// Will be passed to glutSpecialFunc(specialKey);
void specialKey(int key, int x, int y) { // called on special key pressed

	// Check which (arrow) key is pressed
	switch (key) {
	case GLUT_KEY_LEFT: 	// Arrow key left is pressed
		X -= 0.1f;
		break;
	case GLUT_KEY_RIGHT:    	// Arrow key right is pressed
		X += 0.1f;
		break;
	case GLUT_KEY_UP:        	// Arrow key up is pressed
		Y += 0.1f;
		break;
	case GLUT_KEY_DOWN:    	// Arrow key down is pressed
		Y -= 0.1f;
		break;
	}

}

// Main point of the program
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);  	// Size of the OpenGL window
	glutCreateWindow("OpenGL 2 Dimensional Geometries"); // Creates OpenGL Window    
	glutDisplayFunc(display);
	glutKeyboardFunc(keyCB);        	// set window's key callback 
	glutSpecialFunc(specialKey);    	// set window's to specialKey callback
	glutMainLoop();

	return 0;
}