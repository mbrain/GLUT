#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <gl/glut.h>

#define GAP  25

int window_x;
int window_y;

int window_width = 200 * 3 + 4 * GAP;
int window_height = 200 * 2 + 3 * GAP;

char *window_title = "OpenGL Camera";

int main_window, subwindow_1, subwindow_2, subwindow_3, subwindow_4, subwindow_5, subwindow_6;

// true if clicked
int leftButton = 0;
int middleButton = 0;
int rightButton = 0;

// variables to translating and rotating the objects in the scene
float translate_x = 0.0f, translate_y = 0.0f, translate_z = 0.0f;
float rot_x = 0.0f, rot_y = 0.0f, rot_z = 0.0f;
float scale_x = 1.0f, scale_y = 1.0f, scale_z = 1.0f;
float previousX = 0.0f, previousY = 0.0f, previousZ = 0.0f;

// Camera position, look at position, up vector
double eyeX = 0, eyeY = 0, eyeZ = 0;
double centerX = 0, centerY = 0, centerZ = 0;
double upX = 0, upY = 1, upZ = 0;

float subwindow1_x;
float subwindow1_y;
float subwindow1_w = 200;
float subwindow1_h = 200;
float subwindow2_x;
float subwindow2_y;
float subwindow2_w = 200;
float subwindow2_h = 200;
float subwindow3_x;
float subwindow3_y;
float subwindow3_w = 200;
float subwindow3_h = 200;
float subwindow4_x;
float subwindow4_y;
float subwindow4_w = 200;
float subwindow4_h = 200;
float subwindow5_x;
float subwindow5_y;
float subwindow5_w = 200;
float subwindow5_h = 200;
float subwindow6_x;
float subwindow6_y;
float subwindow6_w = 200;
float subwindow6_h = 200;

void main_display (void);
void main_reshape (int w, int h);
void keyboard (unsigned char key, int x, int y);

void display_1 (void);
void display_2 (void);
void display_3 (void);
void display_4 (void);
void display_5 (void);
void display_6 (void);
void display (int id);
void redisplayAll ();
void mouse (int, int, int, int);
void motion (int, int);

void init ();

void centerOnScreen ();
void drawObject ();

GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;

// print to window
void printw (float x, float y, float z, char* format, ...);

void reset()
{
    translate_x = translate_y = translate_z = 0.0f;
    rot_x = rot_y = rot_z = 0.0f;
    scale_x = scale_y = scale_z = 1.0f;
    previousX = previousY = previousZ = 0;
    redisplayAll();
}

void main_display (void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void main_reshape (int w, int h)
{
    //  Disallow window re-sizing
    glutReshapeWindow (window_width, window_height);
}

void keyboard (unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'r':
        reset();
        break;
    }
}

// Redisplays all subwindows
void redisplayAll ()
{
    glutSetWindow (subwindow_1);
    glutPostRedisplay ();
    glutSetWindow (subwindow_2);
    glutPostRedisplay ();
    glutSetWindow (subwindow_3);
    glutPostRedisplay ();
    glutSetWindow (subwindow_4);
    glutPostRedisplay ();
    glutSetWindow (subwindow_5);
    glutPostRedisplay ();
    glutSetWindow (subwindow_6);
    glutPostRedisplay ();
}

// display subwindow ID
void display (int id)
{

    glClearColor(1, 1, 1, 1);
    glClear (GL_COLOR_BUFFER_BIT);

    //  perspective
    glMatrixMode (GL_PROJECTION);
    glOrtho(-1, 1, -1, 1, -2, 2);

    // camera position and view vector
    glMatrixMode (GL_MODELVIEW);
    gluLookAt (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);

    glTranslatef (translate_x, translate_y, translate_z);

    glRotatef (rot_x, 1.0f, 0.0f, 0.0f);
    glRotatef (rot_y, 0.0f, 1.0f, 0.0f);
    glRotatef (rot_z, 0.0f, 0.0f, 1.0f);

    glScalef (scale_x, scale_y, scale_z);
    
    drawObject ();

    // modelView matrix to identity matrix
    glLoadIdentity ();

    // projection matrix to identity matrix
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    switch (id)
    {
    case 1:
        printw (-0.9, -0.9, 0, "Front");
        break;
    case 2:
        printw (-0.9, -0.9, 0, "Top");
        break;
    case 3:
        printw (-0.9, -0.9, 0, "Left");
        break;
    case 4:
        printw (-0.9, -0.9, 0, "Back");
        break;
    case 5:
        printw (-0.9, -0.9, 0, "Bottom");
        break;
    case 6:
        printw (-0.9, -0.9, 0, "Right");
        break;	
    }

    glutSwapBuffers ();
}

// Front
void display1 (void)
{
    glColor3f (1, 0, 0);
    eyeX = 0;
    eyeY = 0;
    eyeZ = 1;
    upX = 0;
    upY = 1;
    upZ = 0;
    display (1);
}

// Top
void display2 (void)
{
    glColor3f (0, 1, 0);
    eyeX = 0;
    eyeY = 1;
    eyeZ = 0;
    upX = 0;
    upY = 0;
    upZ = -1;
    display (2);
}

//  Left
void display3 (void)
{
    glColor3f (0, 0, 1);
    eyeX = -1;
    eyeY = 0;
    eyeZ = 0;
    upX = 0;
    upY = 1;
    upZ = 0;
    display (3);
}

// Back
void display4 (void)
{
    glColor3f (1, 0, 0);
    eyeX = 0;
    eyeY = 0;
    eyeZ = -1;
    upX = 0;
    upY = 1;
    upZ = 0;
    display (4);
}

// Bottom
void display5 (void)
{
    glColor3f (0, 1, 0);
    eyeX = 0;
    eyeY = -1;
    eyeZ = 0;
    upX = 0;
    upY = 0;
    upZ = 1;
    display (5);
}

// Right
void display6 (void)
{
    glColor3f (0, 0, 1);
    eyeX = 1;
    eyeY = 0;
    eyeZ = 0;
    upX = 0;
    upY = 1;
    upZ = 0;
    display (6);
}

//  Draw the object
void drawObject ()
{
    glutWireTeapot (0.5);
}

// Mouse function that lets the user rotate or translate the object
void mouse (int button, int state, int x, int y) 
{	
    if (button == GLUT_LEFT_BUTTON) 
    {
        leftButton = state == GLUT_DOWN;
    } 
    else if (button == GLUT_MIDDLE_BUTTON) 
    {
        middleButton = state == GLUT_DOWN;
    } 
    else if (button == GLUT_RIGHT_BUTTON) 
    {
        rightButton = state == GLUT_DOWN;
    }

    previousX = x;
    previousY = y;
    previousZ = y;
}

// when dragging the mouse
void motion (int x, int y) 
{
    if (rightButton) 
    {
        translate_x += (x - previousX) * 0.005;
        translate_y -= (y - previousY) * 0.005;
    }
    if (middleButton) 
    {
        scale_x -= (y - previousZ) * 0.005;
        scale_y -= (y - previousZ) * 0.005;
        scale_z -= (y - previousZ) * 0.005;
    }
    if (leftButton) 
    {
        if ((y - previousY) >= 0)
            rot_x += (y - previousY);
        else 
            rot_x += (y - previousY);
        if ((x - previousX) >= 0)
            rot_y += (x - previousX);
        else
            rot_y += (x - previousX);
    }	

    previousX = (float)x;
    previousY = (float)y;
    previousZ = (float)y;

    redisplayAll ();
}

void centerOnScreen ()
{
    window_x = (glutGet (GLUT_SCREEN_WIDTH) - window_width)/2;
    window_y = (glutGet (GLUT_SCREEN_HEIGHT) - window_height)/2;
}

void printw (float x, float y, float z, char* format, ...)
{
    va_list args;	//  Variable argument list
    int len;		//	String length
    int i;			//  Iterator
    char * text;	//	Text

    va_start(args, format);
    len = _vscprintf(format, args) + 1; 
    text = malloc(len * sizeof(char));
    vsprintf_s(text, len, format, args); 
    va_end(args);

    glRasterPos3f (x, y, z);
    for (i = 0; text[i] != '\0'; i++) glutBitmapCharacter(font_style, text[i]);

    free(text);
}

void main (int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize (window_width, window_height);

    centerOnScreen ();
    
    glutInitWindowPosition (window_x, window_y);

    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);

    main_window = glutCreateWindow (window_title);

    glutDisplayFunc (main_display);
    glutReshapeFunc  (main_reshape);
    glutKeyboardFunc (keyboard);

    subwindow_1 = glutCreateSubWindow (main_window, GAP, GAP, 200, 200);
    glutDisplayFunc (display1);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_2 = glutCreateSubWindow (main_window, 200 + GAP*2, GAP, 200, 200);
    glutDisplayFunc (display2);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_3 = glutCreateSubWindow (main_window, 400 + GAP*3, GAP, 200, 200);
    glutDisplayFunc (display3);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_4 = glutCreateSubWindow (main_window, GAP, 200 + GAP * 2, 200, 200);
    glutDisplayFunc (display4);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_5 = glutCreateSubWindow (main_window, 200 + GAP*2, 200 + GAP * 2, 200, 200);
    glutDisplayFunc (display5);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);
    subwindow_6 = glutCreateSubWindow (main_window, 400 + GAP*3, 200 + GAP * 2, 200, 200);
    glutDisplayFunc (display6);
    glutMouseFunc (mouse);
    glutMotionFunc (motion);
    glutKeyboardFunc (keyboard);

    glutMainLoop();
}

