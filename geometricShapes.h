#ifndef GEOMETRICSHAPES_H
#define GEOMETRICSHAPES_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
typedef GLfloat vec4[4];
typedef GLfloat mat4[16];

void cylinder(vec4 *vertices, vec4 *color, int num_vertices);
void sphere(vec4 *vertices, vec4 *colors, int num_vertices, int degree_change);
void torus(vec4 *vertices, vec4 *colors, int num_vertices, int degree_change);
void spring(vec4 *vertices, vec4 *colors, int num_vertices, int degree_change);
void matrixVariableCopy(int num, vec4 *a, vec4 *b);
void generateRingSphere(GLfloat angleY, GLfloat theta, GLfloat r, vec4 *ring);
void generateRingTorus(GLfloat angleU, GLfloat theta, GLfloat inner_r, GLfloat outer_r, vec4 *ring); 
void generateRingSpring(GLfloat angleU, GLfloat theta, GLfloat Y_change, GLfloat inner_r, GLfloat outer_r, vec4 *ring);
void getColor(vec4 *colors, int index);
void generateCap(vec4 *ring, vec4 center, vec4 *vertices, vec4 *colors, int degree_change, int index);

#endif
