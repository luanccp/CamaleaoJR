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
int andar_fase;
int deslocaChao = -250;
bool desenhaBloco = false;
int auxRandomica[10] ;
int posicaoAltura, espacamentoX, espacamentoY;
int vetor_espacamentoX[10];

/* FUNCAO QUE DESENHA UMA ELIPSE */
void DrawEllipsee(float a,float b, float c)
{
    // glColor3f(0,0,0);
    float x,y,z;
    int t;
    glBegin(GL_POLYGON);
    for(t = 0; t <= 360; t +=1)
    {
        x = a*cos(t);
        y = b*sin(t);
        z = c;
        glVertex3f(x,y,z);
    }
    glEnd();
}
/* FUNCAO QUE DESENHA O SOL */
void DesenhaSol()
{
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);  
    DrawEllipsee(30,30,0);
    glEnd();    
}

/* FUNCAO QUE DESENHA NUVEM*/
void DesenhaNuvem()
{
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    DrawEllipsee(20,9,0);
    DrawEllipsee(8,15,0);
    glEnd();   
}

/*FUNCAO QUE DESENHA PIRAMIDE*/
void DesenhaPiramide(float altura, float comprimento){
    glBegin(GL_TRIANGLES);
    glColor3f(0.6f,0.5f,0.4f);
    glVertex3f(-comprimento,0,0);
    glVertex3f(0,altura,0);
    glVertex3f(comprimento,0,0);
    glEnd();
}

/*FUNCAO QUE DESENHA O CEU DA FASE*/
void DesenhaCeu()
{
    glBegin(GL_QUADS);
    glColor3ub(197,251,247);
    glVertex3f(-400,-400,0);
    glVertex3f(-400,400,0);
    glVertex3f(400,400,0);
    glVertex3f(400,-400,0);
    glEnd();
}
/* FUNCAO QUE DESENHA A AREIA DA FASE*/
void DesenhaAreia()
{
    glBegin(GL_QUADS);
    glColor3ub(203,187,142);
    glVertex3f(-400,-400,0);
    glVertex3f(-400,100,0);
    glVertex3f(400,100,0);
    glVertex3f(400,-400,0);
    glEnd();
    
}

void fase_display( bool desenhaBloco)
{
    //int posicaoAltura, espacamentoX, espacamentoY;
    espacamentoX = 150;
    espacamentoY = 55;
    //int auxRandomica;
    
    /* DESENHA O CEU */
    glPushMatrix();
    DesenhaCeu();
    glPopMatrix();
    
    /* DESENHA A AREIA */
    glPushMatrix();
    DesenhaAreia();
    glPopMatrix();
    
    /*desennha sol*/
    glPushMatrix();
    glTranslatef(0,200,0);      
    DesenhaSol();
    glPopMatrix();
    
        
    glTranslatef(-andar_fase, 0, 0);
    vetor_espacamentoX[0]= espacamentoX;        
    if (desenhaBloco == true) {
        for (int i=0; i<10; i++)
        {
                    //auxRandomica[10] = (rand() % 3);
            glColor3f(0.6f,0.5f,0.4f);
		
            if (auxRandomica[i] == 0) {
                glBegin(GL_QUADS);
                glVertex3f(espacamentoX,+deslocaChao,0.0);
                glVertex3f(espacamentoX,80+deslocaChao,0.0);
                glVertex3f(espacamentoX +80,80+deslocaChao,0.0);
                glVertex3f(espacamentoX +80,deslocaChao,0.0);
                glEnd();
            }
            else if (auxRandomica[i] == 1){
                glBegin(GL_QUADS);
                glVertex3f(espacamentoX,100+deslocaChao+ espacamentoY,0.0);
                glVertex3f(espacamentoX,180+deslocaChao+ espacamentoY,0.0);
                glVertex3f(espacamentoX +80,180+deslocaChao+ espacamentoY,0.0);
                glVertex3f(espacamentoX +80,100+deslocaChao+ espacamentoY,0.0);
                glEnd();
            }
            else{
                glBegin(GL_QUADS);
                glVertex3f(espacamentoX,160+deslocaChao+ (2*espacamentoY),0.0);
                glVertex3f(espacamentoX,240+deslocaChao+ (2*espacamentoY),0.0);
                glVertex3f(espacamentoX +80,240+deslocaChao+ (2*espacamentoY),0.0);
                glVertex3f(espacamentoX +80,160+deslocaChao+ (2*espacamentoY),0.0);
                glEnd();
            }
            espacamentoX += 100;
            vetor_espacamentoX[i+1]= espacamentoX;

        /* DESENHA UMA NUVEM EM UM DETERMINADO INTERVALO */
            if (i%3==0) {
                glPushMatrix();
                glTranslatef(-desloca_nuvem, 200, 0);
                DesenhaNuvem();
                glPopMatrix();
            }
            
        }
    }
    /*ATUALIZA A FLAG*/
    desenhaBloco = false;
    
    /*DESENHA PIRAMADE*/
    glPushMatrix();
    DesenhaPiramide(80,100);
    glPopMatrix();
    
}
