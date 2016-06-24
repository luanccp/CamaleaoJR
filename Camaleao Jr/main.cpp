/************************* BIBLIOTECAS *******************/
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
/**********************************************************/


/* INCLUDE DOS HEADERFILES */
#include "camaleao.h"
#include "moscas.h"
#include "controles.h"
//#include "cobra.h"
#include "fase.h"

/* VARIAVEIS GLOBAIS CONSTANTES*/
#define espacamento 10
#define PI '3.14'
#define MAXlargura 2000
#define MAXaltura 2000

/* VARIAVEIS GLOBAIS */
using namespace std;
int ciclo = 0;
float v1[10]={0,0,0,0,0,0,0,0,0,0};
int vrand[10],vespacamento[10],buraco;
float v2[10]={10};
int apagaMosca[10] ={1,1,1,1,1,1,1,1,1,1};
bool cria_fase = true;
int posicaoBlocos[10];
int ativa_descolamento_bloco = 0;
int fatorVelocidade = 0;

//teste para gerar varias moscas
int automaticoX[10];
int automaticoY[10];


/**
  
 ESSA FUNCAO FAZ OQ?
 
 */
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
     // função para não desloca a fase; 
   if(cria_fase == true)
   {
       for (int i=0; i<10; i++)
       {
           auxRandomica[i] = (rand() % 3);			
       }
	//geração de moscas
       for(int j=0;j<10;j++){
          automaticoX[j] = 10*(rand() % 30);
          automaticoY[j] = 10*(rand() % 10);
      }
      cria_fase = false;
  }	
  glPushMatrix();
  srand(time(NULL));
  fase_display(desenhaBloco);
  glPopMatrix();



/* EFETUA O DESENHO DO CAMALEAO */
  glPushMatrix();    
  glRotatef(180,0.0,1.0,0.0);	
  glTranslatef(0+dx, 27+dy, 0);	
  camaleao_display();
  glPopMatrix();
  glPushMatrix();   



    //-68 +dx == g + dx

  for(int j=0;j<10;j++)
  {
     if ((volta_lingua + andar_mosca - automaticoX[j]) == ((+78+dx))) 
     {
			//fazer contato no eixo Y		
			//if((27+10 automatico == 27 + dy +  ))        
         apagaMosca[j] = 0;
     }
    	  	/* EFETUA O DESENHO DO MOSCA */
     if  (apagaMosca[j] == 1)
     {
       glPushMatrix();
       glRotatef(180,0.0,1.0,0.0);
       glTranslatef(0 - automaticoX[j], 27 - automaticoY[j], 0);
       mosca_display();
       glPopMatrix();
   }
   if(auxRandomica[j]==0){		
      if((vetor_espacamentoX[1]+90)-andar_fase == (78-dx) ){
			//fazer o contato do Y aqui
			//if((posição camaleao > deslocaChao) && (posição do camaleoa < 80 + deslocaChao)){
        ativa_descolamento_bloco = 1;
			//	}
    }	
}else if(auxRandomica[1]==1){
   if((vetor_espacamentoX[j]+90)-andar_fase == (78-dx)){
    		//fazer o contato do Y aqui
			//if((posição camaleao > deslocaChao) && (posição do camaleoa < 80 + deslocaChao)){
    ativa_descolamento_bloco = 1;
			//	}
}
}else if(auxRandomica[1]==2){
   if((vetor_espacamentoX[j]+90)-andar_fase == (78-dx)){
    		//fazer o contato do Y aqui
			//if((posição camaleao > deslocaChao) && (posição do camaleoa < 80 + deslocaChao)){
    ativa_descolamento_bloco = 1;
			//	}
}
}
} 
	//espacamento

    /* EFETUA O DESENHO DO COBRA */
    //cobra_display();

glutSwapBuffers();
}

void init( void )
{
    //Selecionar cor de fundo
    glClearColor( 255.0, 255.0, 255.0, 1.0 );
    
    //Inicializar sistema de visualizacao
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -250, 250, -250, 250, 100, -100 );
    
    desenhaBloco = true;

}
void idle(){
    static char direction = -2;
    static GLdouble previousTime = 0;
    GLdouble currentTime;
    GLdouble timeDifference;
    
    currentTime  = glutGet(GLUT_ELAPSED_TIME);
    timeDifference = currentTime - previousTime;
    previousTime = currentTime;

    printf("%i\n", fatorVelocidade );
    contecla++;
    if((fatorVelocidade%8) == 0 ){
        theta = 0;
    }
    if((fatorVelocidade%2) == 1 ){
        theta = -45;
    }
    fatorVelocidade++;


    if(vetor['w'] && dy<20) dy+=(0.1*timeDifference);
    if(vetor['s'] && dy>15) dy-=(0.1*timeDifference);

        
        
    //ativa a lingua 
    if(lingua==1){
        volta_lingua-=(0.1*timeDifference);
        //printf("lingua %f, dx: %d \n",g,dx);
        if(volta_lingua<=(dx-100)){
            lingua=0;
            volta_lingua = 0;
        }
    }

    andar_fase+=(0.1*timeDifference);				    
    andar_mosca+=(0.1*timeDifference);
    if (ativa_descolamento_bloco == 1 )  dx+=(0.1*timeDifference);


    if(desloca_nuvem <= (300-andar_fase)) desloca_nuvem +=(0.1*timeDifference);
    else desloca_nuvem = (-300-andar_fase);

    glutPostRedisplay();
 }


 int main(int argc, char *argv[])
 {
    int valor;
    
    printf("\n======== CAMALEAO JUNIOR ========\n\n");
    printf("1) Start game\n");
    printf("2) Select dificulty\n");
    printf("3) Credits\n");
    printf("4) Exit\n");
    printf("\n\t\tselect: ");
    
    
    scanf("%i", &valor);
    
    printf("\n=================================\n\n");
    switch(valor)
    {
        case 1:
        glutInit( &argc, argv );
        glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
        glutInitWindowSize( MAXlargura, MAXaltura );
        glutInitWindowPosition( 0, 50 );
        glutCreateWindow( "Camaleao Jr - FASE 1" );
        init();
        
        glutDisplayFunc( display );
        
        glutKeyboardFunc( keyboard );
        glutKeyboardUpFunc( keyboardup );
        glutIdleFunc(idle);
        
        glutMainLoop();
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        exit(0);
        break;

        default:
        exit(0);
        break;
    }    
    return 0;
}
