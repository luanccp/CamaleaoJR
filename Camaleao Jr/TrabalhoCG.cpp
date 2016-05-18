#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
int dx,dy;
int theta;

void DesenhaRetangulo(float largura, float altura, float r,float g, float b)
{
	/*glBegin(GL_QUADS);
		glColor3f(r, g, b);	
		glVertex2f(-largura/2,0.0);
		glVertex2f(largura,0.0);
		glVertex2f(largura,altura);
		glVertex2f(0.0,altura);
	glEnd();*/
}


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

void DesenhaRabo(void)
{

	//drawHollowCircle(0.0, 0.0, 20.0);
		

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
void DesenhaCorpo1()
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
void DesenhaCorpo2()
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
void DesenhaCabeca1()
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
void DesenhaCabeca2()
{
	//LINGUA
	glColor3f(1.0f, 0.0f, 0.0f); //VERMELHO
	glBegin(GL_LINES);
		glVertex3f(-2.0,-7.0,0.0);
		glVertex3f(-20.0,-7.0,0.0);
		
	glEnd();	

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
void DesenhaPe1()
{
	glColor3f(0.0f, 0.0f, 1.0f); // azul
	glBegin(GL_QUADS);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(2.0,-5.0,0.0);
		glVertex3f(7.0,-5.0,0.0);
		glVertex3f(5.0,-0.0,0.0);
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
void DesenhaPe2()
{
	glColor3f(0.0f, 0.0f, 1.0f); // azul
	glBegin(GL_QUADS);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,-10.0,0.0);
		glVertex3f(5.0,-10.0,0.0);
		glVertex3f(5.0,0.0,0.0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-5.0,-10.0,0.0);	
		glVertex3f(10.0,-10.0,0.0);
	glEnd();
}
void olho()
{
	glColor3f( 0.0, 0.0, 0.0 );
	drawHollowCircle(0,0,2);
	drawHollowCircle(0,0,4);
}

void desenhaQuadrado (float largura, float altura, float r,float g, float b)
{
	/*//desenhaQuadrado(100.0,40.0,0.0,1.0,1.0,1.0)
	glBegin(GL_QUADS);
		glColor3f(r, g, b);
		glVertex2f( -largura/2, 0);
		glVertex2f( largura/2, 0);
		glVertex2f( largura/2, altura);
		glVertex2f( -largura/2, altura);
	glEnd();
	  */  
}

void display( void )
{
    //Limpar todos os pixels
    glClear( GL_COLOR_BUFFER_BIT );
    
    
    glColor3f( 0.0, 0.0, 0.0 );
    glBegin(GL_LINES);
		glVertex2f(400, 0);
		glVertex2f(-400, 0);
	glEnd();
	glColor3f( 0.0, 1.0, 1.0 );
    glBegin(GL_LINES);
		glVertex2f(0, -400);
		glVertex2f(0, 400);
	glEnd();
	
	glPushMatrix();
		
		glTranslatef(dx, dy, 0);	
		desenhaQuadrado(100.0,40.0,0.0,1.0,1.0);	
	glPopMatrix();	
		
	glPushMatrix();
		glTranslatef(dx-40, dy, 0);		
		glRotatef(-dx,0,0,1);		
		glColor3f(0.0,0.0,0.0);
		//drawHollowCircle(0,0,15);	
	glPopMatrix();

	glPushMatrix();
		glTranslatef(dx+40, dy, 0);		
		glColor3f(0.0,0.0,0.0);
		glRotatef(-dx,0,0,1);
		//drawHollowCircle(0,0,15);	
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(dx-25, dy+40, 0);		
		glRotatef(-theta,0,0,1);
		desenhaQuadrado(10.0,80.0,0.0,0.0,0.0);	
	glPopMatrix();

		glPushMatrix();
		glTranslatef(dx, dy+40, 0);		
		glRotatef(-theta,0,0,1);
		desenhaQuadrado(10.0,80.0,0.0,0.0,0.0);
	glPopMatrix();

		glPushMatrix();
		glTranslatef(dx+25, dy+40, 0);		
		glRotatef(-theta,0,0,1);
		desenhaQuadrado(10.0,80.0,0.0,0.0,0.0);	
	glPopMatrix();

	glPushMatrix();	
		glTranslatef(dx+70, dy+11, 0);
		DesenhaRabo();	
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(dx+60, dy, 0);
		DesenhaCorpo1();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(dx+45, dy, 0);
		DesenhaCorpo2();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(dx+25, dy, 0);
		DesenhaCabeca1();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(dx+25, dy, 0);
		DesenhaCabeca2();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(dx+55, dy-15, 0);
		DesenhaPe1();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(dx+35, dy-15, 0);
		DesenhaPe2();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(dx+25, dy+7, 0);
		olho();
	glPopMatrix();

	glutSwapBuffers();
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
 

void keyboard(unsigned char tecla, int x, int y)
{
	switch(tecla)
	{
		case 27:
			exit(0);
			break;
		case 'w':
			dy+=2;
			break;
		case 's':
			dy-=2;
			break;
		case 'a':
			dx-=2;
			break;
		case 'd':
			dx+=2;
			break;
		case 'f':
			theta+=2;
			if(theta > 90){theta = 90;}				
			break;
		case 'e':
			theta-=2;
			if(theta < -90){theta = -90;}
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
    
    glutMainLoop();
    return 0;
}
