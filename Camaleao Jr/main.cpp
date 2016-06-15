
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
#include <stdio.h>
#include <ctime>
#include "camaleao.h"
#include "moscas.h"
#include "controles.h"
//#include "cobra.h"
#include "fase.h"
#define espacamento 10
#define PI '3.14'
using namespace std;
int ciclo = 0;

float v1[10]={0,0,0,0,0,0,0,0,0,0};
int vrand[10],vespacamento[10],buraco;
float v2[10]={10};   
bool diferente(int i){
	for(int j=0;j<i;j++)
		if(vrand[i]==vrand[j])
			return false;
}

void display( void )
{
       
	//Limpar todos os pixels
    glClear( GL_COLOR_BUFFER_BIT );
	/*EFETUA O DESENHO DA FASE*/	
	glPushMatrix();
		srand(time(NULL));
		if(ciclo == 0){
			for (int i=0; i<10; i++) {
				buraco = rand() %10;
				buraco++;
	      			vrand[i] = (rand() % 10);
				vespacamento[i] = (rand() % 30);
        			if(i==0){
					v1[i]= 0 ;
        				v2[i]=espacamento+vespacamento[i];
				}else{
					v1[i]=40+v2[i-1]+buraco ;
        				v2[i]=40+v1[i]+espacamento+vespacamento[i];
				}		 
			}		
			ciclo++;		
		}    
				
		fase_display(v1,vrand,vespacamento,v2);
	glPopMatrix();    


    /* EFETUA O DESENHO DO CAMALEAO */
	glPushMatrix();    
		glRotatef(180,0.0,1.0,0.0);	
		camaleao_display();
    	glPopMatrix();
    /* EFETUA O DESENHO DO MOSCA */
    glPushMatrix();
    	glRotatef(180,0.0,1.0,0.0);
	mosca_display();
    glPopMatrix();
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
    
    if(vetor['d'])
        //dx-=(0.1*timeDifference);
        andar+=(0.1*timeDifference); 
    if(salta==0){
        if(vetor['w']){
            salta = 1;
        }
        else dy = 0;
    }
    if(vetor['s'])
        dy-=(0.1*timeDifference);
    if(vetor['a'])
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
			    
    //andar+=(0.1*timeDifference);
    
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 400, 400 );
    glutInitWindowPosition( 0, 50 );
    glutCreateWindow( "Hello" );
    init();
    
    glutDisplayFunc( display );
   
    glutKeyboardFunc( keyboard );
    glutKeyboardUpFunc( keyboardup );	
    glutIdleFunc(idle);
    
    glutMainLoop();
    return 0;
}
