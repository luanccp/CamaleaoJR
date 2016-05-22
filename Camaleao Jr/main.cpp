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
#include <personagens.h>


void display( void )
{
    //Limpar todos os pixels
    glClear( GL_COLOR_BUFFER_BIT );
    
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
    
    glutSwapBuffers();
}
void keyboardup(unsigned char tecla, int x, int y)
{
    switch(tecla)
    {
        case 'w':
            
            vetor[(int)('w')] = 0;
            break;
        case 's':
            
            vetor[(int)('s')] = 0;
            break;
        case 'a':
            
            vetor[(int)('a')] = 0;
            break;
        case 'd':
            
            vetor[(int)('d')] = 0;
            break;
        case 'z':
            vetor[(int)('z')] = 0;
            break;
    }
    
    glutPostRedisplay();
}

void init( void )
{
    //Selecionar cor de fundo preto
    glClearColor( 1.0, 1.0, 1.0, 1.0 );
    
    //Inicializar sistema de visualizaçao
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

void keyboard(unsigned char tecla, int x, int y)
{
    switch(tecla)
    {
        case 27:
            exit(0);
            break;
        case 'w':
            vetor[(int)('w')] = 1;
            //dy+=2;
            break;
        case 's':
            vetor[(int)('s')] = 1;
            //dy-=2;
            break;
        case 'a':
            vetor[(int)('a')] = 1;
            //dx-=2;
            contecla++;
            if((contecla%2) == 0 ){
                theta = 0;
            }
            if((contecla%2) == 1 ){
                theta = -45;
            }
            break;
        case 'd':
            vetor[(int)('d')] = 1;
            //dx+=2;
            contecla++;
            if((contecla%2) == 0 ){
                theta = 0;
            }
            if((contecla%2) == 1 ){
                theta = 45;
            }
            break;			
        case 'z':
            vetor[(int)('z')] = 1;
            lingua = 1;
            //g-=2;			
            break;
        case 'x':
            lingua = 0;
            g=-2;
            break;
            
    }
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