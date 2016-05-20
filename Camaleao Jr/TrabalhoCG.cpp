#include <GL/glut.h>
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
