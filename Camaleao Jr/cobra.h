//
//  cobra.h
//  Camaleao Jr
//
//  Created by Luan Castheloge on 5/22/16.
//  Copyright (c) 2016 Luan Castheloge. All rights reserved.
//

#ifndef Camaleao_Jr_cobra_h
#define Camaleao_Jr_cobra_h


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
int dx = 0;
int dy = 0;
int theta;
int contecla = 0;
int lingua = 0, salta = 0;
float g = 0;
int vetor[256]= {0};


void cobra_display(void)
{
    glPushMatrix();
    glTranslatef(dx+70, dy+11, 0);
    cobra_desenhaCorpo();
    glPopMatrix();
    
    //    glPushMatrix();
    //    glTranslatef(dx+60, dy, 0);
    //    desenhaCorpo1();
    //    glPopMatrix();
    //    glPushMatrix();
    //    glTranslatef(dx+45, dy, 0);
    //    desenhaCorpo2();
    //    glPopMatrix();
    //
    //    if(lingua == 1){
    //        glPushMatrix();
    //        glTranslatef(dx+25, dy, 0);
    //        desenhaLingua();
    //        glPopMatrix();
    //    }
    //
    //    glPushMatrix();
    //    glTranslatef(dx+25, dy, 0);
    //    desenhaCabeca1();
    //    glPopMatrix();
    //    glPushMatrix();
    //    glTranslatef(dx+25, dy, 0);
    //    desenhaCabeca2();
    //    glPopMatrix();
    //    glPushMatrix();
    //    glTranslatef(dx+55, dy-15, 0);
    //    glRotatef(-theta,0,0,1);
    //    desenhaPe1();
    //    glPopMatrix();
    //    glPushMatrix();
    //    glTranslatef(dx+35, dy-15, 0);
    //    glRotatef(-theta,0,0,1);
    //    desenhaPe2();
    //    glPopMatrix();
    //    
    //    glPushMatrix();
    //    glTranslatef(dx+25, dy+7, 0);
    //    desenhaOlho();
    //    glPopMatrix();
}


void cobra_desenhaCorpo(void)
{
    glColor3f(0.0f, 1.0f, 1.0f);
    
    
    
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
    
<<<<<<< HEAD
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(19.0,-14.0,0.0);
    glVertex3f(16.0,-8.0,0.0);
    glVertex3f(14.0,-10.0,0.0);
    glVertex3f(14.0,-12.0,0.0);
    glVertex3f(19.0,-14.0,0.0);
    glEnd();
=======
>>>>>>> origin/master
}
