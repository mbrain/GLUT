#define _CRT_SECURE_NO_WARNINGS

#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>

GLuint obj;
float color;
char ch;
int read;

void loadObj(char *fname)
{
	FILE *fp;
	GLfloat x, y, z;
	obj = glGenLists(1);
	fp = fopen(fname,"r");
	if(!fp) exit(1);
	glPointSize(2.0);
	glNewList(obj, GL_COMPILE);
	glPushMatrix();
	glBegin(GL_POINTS);
	while(!(feof(fp))) {
		read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
		if(read==4 && ch=='v') glVertex3f(x,y,z);
	}
	glEnd();
	glPopMatrix();
	glEndList();
	fclose(fp);
}

void reshape(int w,int h)
{    
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
	//glOrtho(-25,25,-2,2,0.1,100);	
	glMatrixMode(GL_MODELVIEW);
}

void drawObj()
{
 	glPushMatrix();
 	glTranslatef(0,-10.00,-105);
 	glColor3f(1.0,0.23,0.27);
 	glScalef(1,1,1);
 	glRotatef(color,0,1,0);
 	glCallList(obj);
 	glPopMatrix();
 	color+=0.6;
 	if(color>360)color-=360;
}

void display(void)
{  
   	glClearColor (0.0,0.0,0.0,1.0); 
   	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	glLoadIdentity();
   	drawObj();
   	glutSwapBuffers();

}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,450);
	glutInitWindowPosition(20,20);
	glutCreateWindow("ObjLoader");
	glutReshapeFunc(reshape);
    glutDisplayFunc(display);
	glutIdleFunc(display);
    loadObj("model.obj");
	glutMainLoop();
	return 0;
}
