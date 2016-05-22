//
//  personagens.h
//  Camaleao Jr
//
//  Created by Luan Castheloge on 5/22/16.
//  Copyright (c) 2016 Luan Castheloge. All rights reserved.
//

#ifndef Camaleao_Jr_personagens_h
#define Camaleao_Jr_personagens_h


#endif

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

using namespace std;
int dx,dy;
int theta;
int contecla = 0;
int lingua = 0, salta = 0;
float g = 0;
int vetor[256]= {0};

void drawHollowCircle(float x, float y, float radius)
{
    int i;
    int lineAmount = 1000;
    GLfloat twicePi = 2.0f * 3.1415926f;
    glLineWidth(3);
    glEnable(GL_LINE_STIPPLE);
    //glLineStipple(1,0x00FF);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    for (i = 0; i<= lineAmount; i++){
        glVertex2f(
                   x + (radius * cos(i*twicePi / lineAmount)),
                   y + (radius * sin(i*twicePi / lineAmount))
                   );
    }
    glEnd();
    glPopMatrix();
}


void desenhaRabo(void)
{
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(-10.0,-15.0,0.0);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,5.0,0.0);
    glVertex3f(-10.0,-5.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(20.0,-8.0,0.0);
    glVertex3f(20.0,0.0,0.0);
    glVertex3f(0.0,5.0,0.0);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(20.0,-8.0,0.0);
    glVertex3f(19.0,-14.0,0.0);
    glVertex3f(22.0,-14,0.0);
    glVertex3f(24.0,-8.0,0.0);
    glVertex3f(20.0,0.0,0.0);
    glEnd();
    
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(19.0,-14.0,0.0);
    glVertex3f(16.0,-8.0,0.0);
    glVertex3f(14.0,-10.0,0.0);
    glVertex3f(14.0,-12.0,0.0);
    glVertex3f(19.0,-14.0,0.0);
    glEnd();
    
}
void desenhaCorpo1()
{
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    glBegin(GL_POLYGON);
    glVertex3f(-5.0,-15.0,0.0);
    glVertex3f(5.0,-15.0,0.0);
    glVertex3f(5.0,-15.0,0.0);
    glVertex3f(5.0,2.0,0.0);
    glVertex3f(0.0,15.0,0.0);
    glVertex3f(-5.0,15.0,0.0);
    glEnd();
    
}
void desenhaCorpo2()
{
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    glBegin(GL_POLYGON);
    glVertex3f(-15.0,-15.0,0.0);
    glVertex3f(15.0,-15.0,0.0);
    glVertex3f(15.0,15.0,0.0);
    glVertex3f(0.0,19.0,0.0);
    glVertex3f(-15.0,15.0,0.0);
    glEnd();
}
void desenhaCabeca1()
{
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0,-5.0,0.0);
    glVertex3f(10.0,-5.0,0.0);
    glVertex3f(10.0,15.0,0.0);
    glVertex3f(0.0,17.0,0.0);
    glVertex3f(-5.0,12.0,0.0);
    glVertex3f(-7.0,8.0,0.0);
    glVertex3f(-9.0,3.0,0.0);
    glVertex3f(-9.0,0.0,0.0);
    glVertex3f(-10.0,-3.0,0.0);
    glVertex3f(-11.0,-5.0,0.0);
    glEnd();
    
}
void desenhaCabeca2()
{
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0,-5.0,0.0);
    glVertex3f(-8.0,-10.0,0.0);
    glVertex3f(-3.0,-15.0,0.0);
    glVertex3f(0.0,-15.0,0.0);
    glVertex3f(10.0,-15.0,0.0);
    glVertex3f(10,-5.0,0.0);
    
    glEnd();
}
void desenhaPe1()
{
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    glBegin(GL_QUADS);
    glVertex3f(0.0,5.0,0.0);
    glVertex3f(2.0,-5.0,0.0);
    glVertex3f(7.0,-5.0,0.0);
    glVertex3f(5.0,5.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(2.0,-5.0,0.0);
    glVertex3f(0.0,-10.0,0.0);
    glVertex3f(5.0,-10.0,0.0);
    glVertex3f(7.0,-5.0,0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-5.0,-10.0,0.0);
    glVertex3f(10.0,-10.0,0.0);
    glEnd();
}
void desenhaPe2()
{
    glColor3f(0.0f, 0.0f, 1.0f); // azul
    glBegin(GL_QUADS);
    glVertex3f(0.0,5.0,0.0);
    glVertex3f(0.0,-10.0,0.0);
    glVertex3f(5.0,-10.0,0.0);
    glVertex3f(5.0,5.0,0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(-5.0,-10.0,0.0);
    glVertex3f(10.0,-10.0,0.0);
    glEnd();
}
void desenhaOlho()
{
    glColor3f( 0.0, 0.0, 0.0 );
    drawHollowCircle(0,0,2);
    drawHollowCircle(0,0,4);
}

void desenhaLingua(){
    glColor3f(1.0f, 0.0f, 0.0f); //VERMELHO
    glBegin(GL_LINES);
    glVertex3f(-2.0,-7.0,0.0);
    glVertex3f(g,-7.0,0.0);
    glEnd();
}

void camaleao_display(void)
{
    glPushMatrix();
    glTranslatef(dx+70, dy+11, 0);
    desenhaRabo();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(dx+60, dy, 0);
    desenhaCorpo1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(dx+45, dy, 0);
    desenhaCorpo2();
    glPopMatrix();
    
    if(lingua == 1){
        glPushMatrix();
        glTranslatef(dx+25, dy, 0);
        desenhaLingua();
        glPopMatrix();
    }
    
    glPushMatrix();
    glTranslatef(dx+25, dy, 0);
    desenhaCabeca1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(dx+25, dy, 0);
    desenhaCabeca2();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(dx+55, dy-15, 0);
    glRotatef(-theta,0,0,1);
    desenhaPe1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(dx+35, dy-15, 0);
    glRotatef(-theta,0,0,1);
    desenhaPe2();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(dx+25, dy+7, 0);
    desenhaOlho();
    glPopMatrix();
}
