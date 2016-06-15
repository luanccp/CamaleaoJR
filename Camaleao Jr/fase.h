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
int andar;

void fase_display( float *v1, int *vrand, int *vespacamento, float *v2)
{

	glTranslatef(-andar, 0, 0);
      	for (int i=0; i<10; i++) {
	        glBegin(GL_QUADS);
            		glVertex3f(v1[i],0,0.0);
            		glVertex3f(v1[i],30+vrand[i],0.0);
            		glVertex3f(v2[i]+20,30+vrand[i],0.0);
            		glVertex3f(v2[i]+20,0,0.0);
        	glEnd();
	
}

}
