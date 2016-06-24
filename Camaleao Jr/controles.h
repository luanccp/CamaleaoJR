//
//  controles.h
//  Camaleao Jr
//
//  Created by Luan Castheloge on 5/22/16.
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

#include <iostream>
#include <math.h>
#include <stdio.h>




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

        case 'd':
        vetor[(int)('d')] = 0;
        break;

        case 'a':
        vetor[(int)('a')] = 0;
        break;   
             
        case 'z':
        vetor[(int)('z')] = 0;
        break;
    }
    
    glutPostRedisplay();
}

void keyboard(unsigned char tecla, int x, int y)
{
    switch(tecla)
    {
        case 27:
        exit(0);
        break;

        case 's':
        // vetor[(int)('s')] = 1;
        dy-=2;
        break;

        case 'w':
        vetor[(int)('w')] = 1;
        break;

        
        case 'z':
        vetor[(int)('z')] = 1;
        lingua = 1;
        break;

        case 'x':
        lingua = 0;
        volta_lingua =0;
        break;

    }
    glutPostRedisplay();
}
