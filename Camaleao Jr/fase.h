//
//  main.cpp
//  Lista2
//
//  Created by Luan Castheloge on 5/4/16.
//  Copyright (c) 2016 Luan Castheloge. All rights reserved.
//

#if defined __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <vector>
#include <iostream>
#include <math.h>


#define PI '3.14'
using namespace std;



void fase_display( float v1, int vrand, int vespacamento, float v2 )
{
        
    /*START CORDENANDAS*/
    glPushMatrix();	
    glColor3f( 0.0, 0.0, 0.0 );
    glBegin( GL_LINES );
        glVertex2f( 0, 400);
        glVertex2f( 0, -400);
    glEnd();
    glPopMatrix();

    glPushMatrix();	
    glColor3f( 0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f( 400, 0);
        glVertex2f( -400, 0);
    glEnd();
    glPopMatrix();	
    /*END CORDENADAS*/

    /*DESENHA FASE*/
glPushMatrix();    
for (int i=0; i<10; i++) {
        vrand = (rand() % 10);
        vespacamento = (rand() % 10);
        v1= v1+10 +vespacamento;
        v2 = v2+10+vespacamento ;
        
	//glPushMatrix();
        glBegin(GL_QUADS);
            glVertex3f(v1,0,0.0);
            glVertex3f(v1,10+vrand,0.0);
            glVertex3f(v2,10+vrand,0.0);
            glVertex3f(v2,0,0.0);
        glEnd();
	glPopMatrix();
    }
    
}
