#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

typedef GLfloat vec4[4];

typedef GLfloat mat4[16];

void printVector(vec4 v);

void vectorScalarMultiplication(vec4 a, GLfloat s, vec4 v);

void vectorAddition(vec4 a, vec4 b, vec4 v);

void vectorSubtraction(vec4 a, vec4 b, vec4 v);

void vectorNormalize(vec4 a, vec4 v);

GLfloat vectorMagnitude(vec4 a);

GLfloat vectorDotProduct(vec4 a, vec4 b);

void vectorCrossProduct(vec4 a, vec4 b, vec4 v);

void vectorCopy(vec4 a, vec4 v);

void printMatrix(mat4 a);

void identityMatrix(mat4 m);

void matrixScalarMultiplication(mat4 a, GLfloat s, mat4 m);

void matrixAddition(mat4 a, mat4 b, mat4 m);

void matrixSubtraction(mat4 a, mat4 b, mat4 m);

void matrixMultiplication(mat4 a, mat4 b, mat4 m);

void matrixInverse(mat4 a, mat4 m);

void matrixTranspose(mat4 a, mat4 m);

void matrixVectorMultiplication(mat4 a, vec4 b, vec4 v);

void matrixCopy(mat4 a, mat4 m);

void matrixTranslation(GLfloat a, GLfloat b, GLfloat c, mat4 m);

void matrixScale(GLfloat a, GLfloat b, GLfloat c, mat4 m);

void matrixRotateX(GLfloat theta, mat4 m);

void matrixRotateY(GLfloat theta, mat4 m);

void matrixRotateZ(GLfloat theta, mat4 m);

void matrixRotateVector(vec4 point, GLfloat theta, GLfloat cosX, GLfloat sinX, GLfloat cosY, GLfloat sinY, mat4 m);

#endif
