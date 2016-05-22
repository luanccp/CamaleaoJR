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

void DrawEllipse(float a,float b, float c)
{
      // glColor3f(0,0,0);
	float x,y,z;
	int t;
        glBegin(GL_POLYGON);
        for(t = 0; t <= 360; t +=1)
	{
          x = a*cos(t);
	  y = b*sin(t);
	  z = c;
	 glVertex3f(x,y,z);
       }
       glEnd();
}
void mosca_asa1()
{
	glBegin(GL_QUADS);	
		glColor3f(1,0,0);
		DrawEllipse(45,6,0);
	glEnd();
}
void mosca_asa2()
{
	glBegin(GL_QUADS);	
		glColor3f(1,0,0);
		DrawEllipse(45,8,0);
	glEnd();
}
void mosca_desenhaCorpo()
{
	glBegin(GL_QUADS);	
		glColor3f(0,0,0);
		DrawEllipse(15,30,0);
	glEnd();
	//glBegin(GL_QUADS);
	//	glVertex3f(.0,0.0,0.0);
	//	glVertex3f();
	//	glVertex3f();
	//	glVertex3f();
	//glEnd();
	/*glBegin(GL_POLYGON);
		//glVertex3f(-10.0,0.0,0.0);
		glVertex3f(-13.0,-1.0,0.0);
		glVertex3f(-15.0,-2.0,0.0);
		glVertex3f(-14.0,-3.0,0.0);
		glVertex3f(-12.0,-4.0,0.0);
		glVertex3f(-0.0,-5.0,0.0);
		glVertex3f(12.0,-4.0,0.0);
		glVertex3f(14.0,-3.0,0.0);
		glVertex3f(15.0,-2.0,0.0);
		glVertex3f(13.0,-1.0,0.0);
		//glVertex3f(10.0,0.0,0.0);
		glVertex3f(5.0,13.0,0.0);
		glVertex3f(-5.0,13.0,0.0);
	glEnd();*/
	
}
//void mosca_desenhaAsas()
/*{
	glColor3f(1.0f,0.0f,1.0f);
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
}*/
void mosca_primeiroOlho()
{
	glBegin(GL_QUADS);	
		glColor3f(1,0,1);
		DrawEllipse(8,12,0);
	glEnd();
}
void mosca_segundoOlho()
{
	glBegin(GL_QUADS);	
		glColor3f(1,0,1);
		DrawEllipse(8,12,0);
	glEnd();
}
void mosca_display(void)
{
	glPushMatrix();
	  glTranslatef(dx-70, dy-5, 0);
	  mosca_asa1();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(dx-70, dy-15, 0);
	  mosca_asa2();
	glPopMatrix();	
	glPushMatrix();
	    glTranslatef(dx-70, dy-11, 0);
	    mosca_desenhaCorpo();
	glPopMatrix();	
	glPushMatrix();
	  glTranslatef(dx-78, dy+15, 0);
	  mosca_primeiroOlho();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(dx-62, dy+15, 0);
	  mosca_segundoOlho();
	glPopMatrix();
}
