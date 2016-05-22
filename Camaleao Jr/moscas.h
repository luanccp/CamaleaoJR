#if defined __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <math.h>
#include <stdio.h>

#ifndef Camaleao_Jr_moscas_h
#define Camaleao_Jr_moscas_h


#endif


void mosca_desenhaCorpo()
{

	glBegin(GL_POLYGON);
		glVertex3f(-5,0.0,0.0);
		glVertex3f(-8.0,-1.0,0.0);
		glVertex3f(-10.0,-2.0,0.0);
		glVertex3f(-9.0,-3.0,0.0);
		glVertex3f(-7.0,-4.0,0.0);
		glVertex3f(-0.0,-5.0,0.0);
		glVertex3f(7.0,-4.0,0.0);
		glVertex3f(9.0,-3.0,0.0);
		glVertex3f(10.0,-2.0,0.0);
		glVertex3f(8.0,-1.0,0.0);
		glVertex3f(5,0.0,0.0);
	glEnd();
	
}
void mosca_desenhaAsas()
{
	glBegin(GL_POLYGON);
		glVertex3f(-5.0,0.0,0.0);
		glVertex3f(-10.0,-5.0,0.0);
		glVertex3f(-8.0,-6.0,0.0);
		glVertex3f(-6.0,-7.0,0.0);
		glVertex3f(-4.0,-8.0,0.0);
		glVertex3f(-2.0,-7.0,0.0);		
		glVertex3f(-1.0,-6.0,0.0);		
		glVertex3f(-0.0,-5.0,0.0);	
	glEnd();
}

void mosca_display(void)
{
	glPushMatrix();
	    glTranslatef(dx-70, dy-11, 0);
	    mosca_desenhaCorpo();
	glPopMatrix();	
	glPushMatrix();
	    glTranslatef(dx-70, dy-11, 0);
	    mosca_desenhaAsas();
	glPopMatrix();
}
