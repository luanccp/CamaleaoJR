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
#include "camaleao.h"
#include "moscas.h"
#include "controles.h"
//#include "cobra.h"


void display( void )
{
    //Limpar todos os pixels
    glClear( GL_COLOR_BUFFER_BIT );
    
    /* EFETUA O DESENHO DO CAMALEAO */
    camaleao_display();
    
    /* EFETUA O DESENHO DO MOSCA */
    mosca_display();
    
    /* EFETUA O DESENHO DO COBRA */
    //cobra_display();
    
    glutSwapBuffers();
}


void init( void )
{
    //Selecionar cor de fundo preto
    glClearColor( 1.0, 1.0, 1.0, 1.0 );
    
    //Inicializar sistema de visualizacao
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -250, 250, -250, 250, 100, -100 );
}
void idle(){
    static char direction = -2;
    static GLdouble previousTime = 0;
    GLdouble currentTime;
    GLdouble timeDifference;
    
    currentTime  = glutGet(GLUT_ELAPSED_TIME);
    timeDifference = currentTime - previousTime;
    previousTime = currentTime;
    
    if(vetor['a'])
        dx-=(0.1*timeDifference);
    if(salta==0){
        if(vetor['w']){
            salta = 1;
        }
        else dy = 0;
    }
    if(vetor['s'])
        dy-=(0.1*timeDifference);
    if(vetor['d'])
        dx+=(0.1*timeDifference);
    if((salta == 1)){
        dy+=(0.1*timeDifference);
        if(dy==100){
            salta = 2;
            exit;
        }
    }
    if(salta == 2){
        dy-=(0.1*timeDifference);
        if(dy == 0){
            salta = 0;
            exit;
        }
    }
    if (salta ==0)
        dy = 0;
    if(lingua==1){
        g-=(0.1*timeDifference);
        //printf("lingua %f, dx: %d ",g,dx);
        if(g<=(dx-100)){
            lingua=0;
            g=-2;
        }
    }
    
    //if(dy>250)
    //	dy=-350;
    //else
    //	dy+=(0.4*timeDifference);
    
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 400, 400 );
    glutInitWindowPosition( 250, 50 );
    glutCreateWindow( "Hello" );
    
    init();
    
    glutDisplayFunc( display );
    
    glutKeyboardFunc( keyboard );
    glutKeyboardUpFunc( keyboardup );	
    glutIdleFunc(idle);
    
    glutMainLoop();
    return 0;
}
