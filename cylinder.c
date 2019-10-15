/*
 * triangle.c
 *
 *  Created on: Aug 28, 2017
 *      Author: Thumrongsak Kosiyatrakul
 */


#ifdef __APPLE__  // include Mac OS X verions of headers

#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

#else // non-Mac OS X operating systems

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

#endif  // __APPLE__

#include "initShader.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixOperations.h"

#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

typedef GLfloat vec4[4];
typedef GLfloat mat4[16];

int num_vertices = 0;
GLuint ctm_location;
mat4 ctm = {1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0};
GLfloat angle = 0.0;
GLfloat theta = (0.1*M_PI)/180;
//matrixRotateX((36.0*M_PI)/180, ctm);

void getColor(vec4 *colors, int index) {
	vec4 v;
	v[0] = rand()/(GLfloat)RAND_MAX;
	v[1] = rand()/(GLfloat)RAND_MAX;
	v[2] = rand()/(GLfloat)RAND_MAX;
	v[3] = rand()/(GLfloat)RAND_MAX;
	vectorCopy(v, colors[index]);
	vectorCopy(v, colors[index+1]);
	vectorCopy(v, colors[index+2]);
}

void cylinder(vec4 *vertices, vec4 *colors, int num_vertices) {
	GLfloat theta = ((360.0/(num_vertices/12))*M_PI)/180;
	GLfloat angle = theta;
	GLfloat r = 0.5;
	vec4 tside1 = { r, r, 0.0, 1.0};
	vec4 bside1 = { r, -r, 0.0, 1.0};
	vec4 bottom = { 0.0, -r, 0.0, 1.0};
	vec4 top = { 0.0, r, 0.0, 1.0};
	int i;
	for( i = 0 ; i< num_vertices/12 ; i++){
		vec4 bside2 = { r*cos(angle), -r, r*sin(angle), 1.0};
		vec4 tside2;
		vectorCopy(bside2, tside2);
		tside2[1]+=1.0;
		
		vectorCopy(top, vertices[i*12]);
		vectorCopy(tside2, vertices[(i*12)+1]);
		vectorCopy(tside1, vertices[(i*12)+2]);
		vectorCopy(tside1, vertices[(i*12)+3]);
		vectorCopy(bside2, vertices[(i*12)+4]);
		vectorCopy(bside1, vertices[(i*12)+5]);
		vectorCopy(bside2, vertices[(i*12)+6]);
		vectorCopy(tside1, vertices[(i*12)+7]);
		vectorCopy(tside2, vertices[(i*12)+8]);
		vectorCopy(bottom, vertices[(i*12)+9]);
		vectorCopy(bside1, vertices[(i*12)+10]);
		vectorCopy(bside2, vertices[(i*12)+11]);		
		
		vectorCopy(bside2, bside1);
		vectorCopy(tside2, tside1);
		angle += theta;				
		
		getColor(colors, i*12);
		getColor(colors, (i*12)+3);
		getColor(colors, (i*12)+6);	
		getColor(colors, (i*12)+9);
	}
}

void init(void)
{
    srand(time(0));    
    num_vertices = 384;
    vec4 vertices[num_vertices];
    vec4 colors[num_vertices];
    cylinder(vertices, colors, num_vertices);
	
    GLuint program = initShader("vshader_ctm.glsl", "fshader.glsl");
    glUseProgram(program);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);

    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    glEnableVertexAttribArray(vPosition);
    glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

    GLuint vColor = glGetAttribLocation(program, "vColor");
    glEnableVertexAttribArray(vColor);
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *) sizeof(vertices));

    ctm_location = glGetUniformLocation(program, "ctm");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glDepthRange(1,0);
    
    matrixRotateX((45*M_PI)/180, ctm);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
    
    glUniformMatrix4fv(ctm_location, 1, GL_FALSE, ctm);

    glDrawArrays(GL_TRIANGLES, 0, num_vertices);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int mousex, int mousey)
{
    if(key == 'q')
    	exit(0);

    //glutPostRedisplay();
}

void idle(void) {
	angle = (angle+theta);//%((GLfloat)2*M_PI);
	mat4 rotatematrix;
	matrixRotateX(angle, rotatematrix);
	matrixCopy(rotatematrix, ctm);
	
	//printf("%.2f\n",angle);
	//printMatrix(ctm);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Triangle");
    glewInit();
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();

    return 0;
}
