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



void display( void )
{
    float v1=0;
    int vrand,vespacamento;
    float v2=10;
    
    //Limpar todos os pixels
    glClear( GL_COLOR_BUFFER_BIT );
    
    /*START CORDENANDAS*/
    glColor3f( 119.0, 2.0, 1.0 );
    glBegin( GL_LINES );
        glVertex2f( 0, 400);
        glVertex2f( 0, -400);
    glEnd();
    
    glColor3f( 1.0, 222.0, 1.0);
    glBegin(GL_LINES);
        glVertex2f( 400, 0);
        glVertex2f( -400, 0);
    glEnd();
    /*END CORDENADAS*/

    /*DESENHA FASE*/
    for (int i=0; i<10; i++) {
        vrand = (rand() % 10);
        vespacamento = (rand() % 10);
        v1= v1+10 +vespacamento;
        v2 = v2+10+vespacamento ;
        
        glBegin(GL_QUADS);
            glVertex3f(v1,0,0.0);
            glVertex3f(v1,10+vrand,0.0);
            glVertex3f(v2,10+vrand,0.0);
            glVertex3f(v2,0,0.0);
        glEnd();

    }
    glutSwapBuffers();
}

void init( void )
{
    //Selecionar cor de fundo preto
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    
    //Inicializar sistema de visualizaÁao
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -250, 250, -250, 250, 100, -100 );
}


int main(int argc, char *argv[])
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 400, 400 );
    glutInitWindowPosition( 250, 50 );
    glutCreateWindow( "Fase 1 - CamaleaoJR" );
    
    init();
    
    glutDisplayFunc( display );
    
    glutMainLoop();
    return 0;
}
