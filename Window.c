#include <gl/glut.h>
#include <stdio.h>

void init ();
void display (void);
void reshape (int w, int h);
void mouse (int button, int state, int x, int y);
void motion (int x, int y);
void pmotion (int x, int y);
void keyboard (unsigned char key, int x, int y);
void special (int key, int x, int y);
void centerOnScreen ();
void drawObject ();

int window_x;
int window_y;
int window_width = 480;
int window_height = 480;
char *window_title = "GLUT Window Template";
int full_screen = 0;

void init ()
{	 
	glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	drawObject ();
	glutSwapBuffers ();
}

void drawObject ()
{
	printf ("Displaying object...\n");
	glutWireIcosahedron ();
}

void reshape (int w, int h)
{
	window_width = w;
	window_height = h;
	glViewport(0, 0, window_width, window_height);
	printf ("Window Width: %d, Window Height: %d.\n", window_width, window_height);
}

void mouse (int button, int state, int x, int y)
{
	switch (button)
	{
		case GLUT_LEFT_BUTTON:
			switch (state)
			{ 
				case GLUT_DOWN:
					printf ("Mouse Left Button Pressed (Down)...\n");
					break;
				case GLUT_UP:
					printf ("Mouse Left Button Released (Up)...\n");
					break;
			}
			break;
		case GLUT_MIDDLE_BUTTON:			
			switch (state)
			{
				case GLUT_DOWN:
					printf ("Mouse Middle Button Pressed (Down)...\n");
					break;
				case GLUT_UP:
					printf ("Mouse Middle Button Released (Up)...\n");
					break;
			}
			break;
		case GLUT_RIGHT_BUTTON:
			switch (state)
			{
				case GLUT_DOWN:
					printf ("Mouse Right Button Pressed (Down)...\n");
					break;
				case GLUT_UP:
					printf ("Mouse Right Button Released (Up)...\n");
					break;
			}
			break;
	}
}

void motion (int x, int y)
{
	printf ("Mouse Drag Position: %d, %d.\n", x, y);
}

void pmotion (int x, int y)
{
	printf ("Mouse Move Position: %d, %d.\n", x, y);
}

void keyboard (unsigned char key, int x, int y)
{
	printf ("User is hitting the '%c' key.\n", key);
	printf ("ASCII code is %d.\n", key);
	switch (key)
	{
		case 'a':
			break;
		case 'A':
			break;
		case '\r':
			printf ("User is hitting the Return key.\n"); 
			break;
		case ' ':
			printf ("User is hitting the Space key.\n"); 
			break;
		case 8:
			printf ("User is hitting the Back Space key.\n"); 
			break;
		case 27:
			exit (1);
			break;
	}
	glutPostRedisplay ();
}

void special (int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_F1 :
			printf ("F1 function key.\n"); 
			break;
		case GLUT_KEY_F2 :
			printf ("F2 function key. \n");  
			break;
		case GLUT_KEY_F3 :
			printf ("F3 function key. \n");  
			break;
		case GLUT_KEY_F4 :
			printf ("F4 function key. \n");  
			break;
		case GLUT_KEY_F5 :
			printf ("F5 function key. \n");  
			break;
		case GLUT_KEY_F6 :
			printf ("F6 function key. \n");  
			break;
		case GLUT_KEY_F7 :
			printf ("F7 function key. \n");  
			break;
		case GLUT_KEY_F8 :
			printf ("F8 function key. \n");  
			break;
		case GLUT_KEY_F9 :
			printf ("F9 function key. \n");  
			break;
		case GLUT_KEY_F10 :
			printf ("F10 function key. \n");  
			break;
		case GLUT_KEY_F11 :
			printf ("F11 function key. \n");  
			break;
		case GLUT_KEY_F12 :
			printf ("F12 function key. \n");  
			break;
		case GLUT_KEY_LEFT :
			printf ("Left directional key. \n");  
			break;
		case GLUT_KEY_UP :
			printf ("Up directional key. \n");  
			break;
		case GLUT_KEY_RIGHT :
			printf ("Right directional key. \n");  
			break;
		case GLUT_KEY_DOWN :
			printf ("Down directional key. \n");  
			break;
		case GLUT_KEY_PAGE_UP :
			printf ("Page up directional key. \n");  
			break;
		case GLUT_KEY_PAGE_DOWN :
			printf ("Page down directional key. \n");  
			break;
		case GLUT_KEY_HOME :
			printf ("Home directional key. \n");  
			break;
		case GLUT_KEY_END :
			printf ("End directional key. \n");  
			break;
		case GLUT_KEY_INSERT :
			printf ("Inset directional key. \n");  
			break;
	}	
	glutPostRedisplay ();
}

void centerOnScreen ()
{
	window_x = (glutGet (GLUT_SCREEN_WIDTH) - window_width)/2;
	window_y = (glutGet (GLUT_SCREEN_HEIGHT) - window_height)/2;
}

void main (int argc, char **argv)
{
	glutInit(&argc, argv);
	centerOnScreen();
	glutInitWindowSize (window_width, window_height);
	glutInitWindowPosition (window_x, window_y);
	glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow (window_title);
	if (full_screen) glutFullScreen ();
	init();
	glutDisplayFunc (display);
	glutReshapeFunc  (reshape);
	glutMouseFunc (mouse);
	glutMotionFunc (motion);
	glutPassiveMotionFunc (pmotion);
	glutKeyboardFunc (keyboard);
	glutSpecialFunc (special);
	glutMainLoop();
}

