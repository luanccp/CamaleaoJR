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


typedef struct mosca {
    char * cor;
    int bonus;
} Mosca ;

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

void DrawEllipse2(float a,float b, float c)
{
      // glColor3f(0,0,0);
	float x,y,z;
	int t;
        glBegin(GL_POINTS);
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
		glColor3f(0.7f,0.7f,0.7f);
		DrawEllipse(13,4,0);
	glEnd();
}
void mosca_asa2()
{
	glBegin(GL_QUADS);	
		glColor3f(0.7f,0.7f,0.7f);
		DrawEllipse(12,8,0);
	glEnd();
}
void mosca_desenhaCorpo()
{
	glBegin(GL_QUADS);	
		glColor3f(0,0,0);
		DrawEllipse(5,15,0);
	glEnd();
	
}

void mosca_primeiroOlho()
{
	glBegin(GL_QUADS);	
		glColor3f(0,0,0);
		DrawEllipse(3,7,0);
	glEnd();
}
void mosca_segundoOlho()
{
	glBegin(GL_QUADS);	
		glColor3f(0,0,0);
		DrawEllipse(3,7,0);
	glEnd();
}
void mosca_desenhaPe1()
{
	glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(-2.0,6.0,0.0);		
	glEnd();
}
void mosca_desenhaPe2()
{
	glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(2.0,6.0,0.0);	
	glEnd();
}
void mosca_desenhaMao1()
{
	glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(3.0,6.0,0.0);	
	glEnd();
}
void mosca_desenhaMao2()
{
	glBegin(GL_LINES);
		glColor3f(0,0,0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(-3.0,6.0,0.0);	
	glEnd();
}
//mosca_detalheOlho1(){
	

//}
void mosca_display(void)
{
	glPushMatrix();
	  glTranslatef(andar_mosca-70, -5, 0);
	  mosca_asa1();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(andar_mosca-70, -10, 0);
	  mosca_asa2();
	glPopMatrix();	
	glPushMatrix();
	    glTranslatef(andar_mosca-70, -11, 0);
	    mosca_desenhaCorpo();
	glPopMatrix();	
	glPushMatrix();
	  glTranslatef(andar_mosca-72, +3, 0);
	  mosca_primeiroOlho();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(andar_mosca-68, +3, 0);
	  mosca_segundoOlho();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(andar_mosca-65, -25, 0);
	  mosca_desenhaPe1();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(andar_mosca-68, -28, 0);
	  mosca_desenhaPe1();
	glPopMatrix();		
	glPushMatrix();
	  glTranslatef(andar_mosca-72, -28, 0);
	  mosca_desenhaPe2();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(andar_mosca-75, -25, 0);
	  mosca_desenhaPe2();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(andar_mosca-78, -14, 0);
	  mosca_desenhaMao1();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(andar_mosca-62, -14, 0);
	  mosca_desenhaMao2();
	glPopMatrix();	
	
}
