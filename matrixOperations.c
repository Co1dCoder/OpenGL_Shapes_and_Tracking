#include "matrixOperations.h"
#include <stdio.h>
#include <math.h>

void printVector(vec4 v) {
	printf("[%.2f, %.2f, %.2f, %.2f]\n",v[0], v[1], v[2], v[3]);
}

void vectorScalarMultiplication(vec4 a, GLfloat s, vec4 v) {
	v[0] = a[0] * s;
	v[1] = a[1] * s;
	v[2] = a[2] * s;
	v[3] = a[3] * s;
}

void vectorAddition(vec4 a, vec4 b, vec4 v) {
	v[0] = a[0] + b[0];
	v[1] = a[1] + b[1];
	v[2] = a[2] + b[2];
	v[3] = a[3] + b[3];
}

void vectorSubtraction(vec4 a, vec4 b, vec4 v) {
	v[0] = a[0] - b[0];
	v[1] = a[1] - b[1];
	v[2] = a[2] - b[2];
	v[3] = a[3] - b[3];
}

void vectorNormalize(vec4 a, vec4 v) {
	GLfloat magnitude = vectorMagnitude(a);
	v[0] = a[0] / magnitude;
	v[1] = a[1] / magnitude;
	v[2] = a[2] / magnitude;
	v[3] = a[3] / magnitude;
}

GLfloat vectorMagnitude(vec4 a) {
	return (GLfloat)(sqrt(powf(a[0],2.0)+powf(a[1],2.0)+powf(a[2],2.0)+powf(a[3],2.0)));
}

GLfloat vectorDotProduct(vec4 a, vec4 b) {
	return ((a[0]*b[0])+(a[1]*b[1])+(a[2]*b[2])+(a[3]*b[3]));
}

void vectorCrossProduct(vec4 a, vec4 b, vec4 v) {
	v[0] = (a[1]*b[2])-(a[2]*b[1]);
	v[1] = (a[2]*b[0])-(a[0]*b[2]);
	v[2] = (a[0]*b[1])-(a[1]*b[0]);
	v[3] = 0;
}

void vectorCopy(vec4 a, vec4 v) {
	v[0] = a[0];
	v[1] = a[1];
	v[2] = a[2];
	v[3] = a[3];
}

void printMatrix(mat4 a) {
	printf("%.2f, %.2f, %.2f, %.2f\n%.2f, %.2f, %.2f, %.2f\n%.2f, %.2f, %.2f, %.2f\n%.2f, %.2f, %.2f, %.2f\n\n",a[0],a[4],a[8],a[12],a[1],a[5],a[9],a[13],a[2],a[6],a[10],a[14],a[3],a[7],a[11],a[15]);
}

void identityMatrix(mat4 m) {
	m[0] = 1.0;	
	m[1] = 0;	
	m[2] = 0;	
	m[3] = 0;	
	m[4] = 0;	
	m[5] = 1.0;	
	m[6] = 0;	
	m[7] = 0;	
	m[8] = 0;	
	m[9] = 0;	
	m[10] = 1.0;	
	m[11] = 0;	
	m[12] = 0;	
	m[13] = 0;	
	m[14] = 0;	
	m[15] = 1.0;
}

void matrixScalarMultiplication(mat4 a, GLfloat s, mat4 m) {
	m[0] = a[0] * s;	
	m[1] = a[1] * s;	
	m[2] = a[2] * s;	
	m[3] = a[3] * s;	
	m[4] = a[4] * s;	
	m[5] = a[5] * s;	
	m[6] = a[6] * s;	
	m[7] = a[7] * s;	
	m[8] = a[8] * s;	
	m[9] = a[9] * s;	
	m[10] = a[10] * s;	
	m[11] = a[11] * s;	
	m[12] = a[12] * s;	
	m[13] = a[13] * s;	
	m[14] = a[14] * s;	
	m[15] = a[15] * s;
}	

void matrixAddition(mat4 a, mat4 b, mat4 m) {
	m[0] = a[0] + b[0];
	m[1] = a[1] + b[1];
	m[2] = a[2] + b[2];
	m[3] = a[3] + b[3];
	m[4] = a[4] + b[4];
	m[5] = a[5] + b[5];
	m[6] = a[6] + b[6];
	m[7] = a[7] + b[7];
	m[8] = a[8] + b[8];
	m[9] = a[9] + b[9];
	m[10] = a[10] + b[10];
	m[11] = a[11] + b[11];
	m[12] = a[12] + b[12];
	m[13] = a[13] + b[13];
	m[14] = a[14] + b[14];
	m[15] = a[15] + b[15];
}

void matrixSubtraction(mat4 a, mat4 b, mat4 m) {
	m[0] = a[0] - b[0];
	m[1] = a[1] - b[1];
	m[2] = a[2] - b[2];
	m[3] = a[3] - b[3];
	m[4] = a[4] - b[4];
	m[5] = a[5] - b[5];
	m[6] = a[6] - b[6];
	m[7] = a[7] - b[7];
	m[8] = a[8] - b[8];
	m[9] = a[9] - b[9];
	m[10] = a[10] - b[10];
	m[11] = a[11] - b[11];
	m[12] = a[12] - b[12];
	m[13] = a[13] - b[13];
	m[14] = a[14] - b[14];
	m[15] = a[15] - b[15];
}

void matrixMultiplication(mat4 a, mat4 b, mat4 m) {
	m[0] = (a[0] * b[0]) + (a[4] * b[1]) + (a[8] * b[2]) + (a[12] * b[3]);
	m[1] = (a[1] * b[0]) + (a[5] * b[1]) + (a[9] * b[2]) + (a[13] * b[3]);
	m[2] = (a[2] * b[0]) + (a[6] * b[1]) + (a[10] * b[2]) + (a[14] * b[3]);
	m[3] = (a[3] * b[0]) + (a[7] * b[1]) + (a[11] * b[2]) + (a[15] * b[3]);
	m[4] = (a[0] * b[4]) + (a[4] * b[5]) + (a[8] * b[6]) + (a[12] * b[7]);
	m[5] = (a[1] * b[4]) + (a[5] * b[5]) + (a[9] * b[6]) + (a[13] * b[7]);
	m[6] = (a[2] * b[4]) + (a[6] * b[5]) + (a[10] * b[6]) + (a[14] * b[7]);
	m[7] = (a[3] * b[4]) + (a[7] * b[5]) + (a[11] * b[6]) + (a[15] * b[7]);
	m[8] = (a[0] * b[8]) + (a[4] * b[9]) + (a[8] * b[10]) + (a[12] * b[11]);
	m[9] = (a[1] * b[8]) + (a[5] * b[9]) + (a[9] * b[10]) + (a[13] * b[11]);
	m[10] = (a[2] * b[8]) + (a[6] * b[9]) + (a[10] * b[10]) + (a[14] * b[11]);
	m[11] = (a[3] * b[8]) + (a[7] * b[9]) + (a[11] * b[10]) + (a[15] * b[11]);
	m[12] = (a[0] * b[12]) + (a[4] * b[13]) + (a[8] * b[14]) + (a[12] * b[15]);
	m[13] = (a[1] * b[12]) + (a[5] * b[13]) + (a[9] * b[14]) + (a[13] * b[15]);
	m[14] = (a[2] * b[12]) + (a[6] * b[13]) + (a[10] * b[14]) + (a[14] * b[15]);
	m[15] = (a[3] * b[12]) + (a[7] * b[13]) + (a[11] * b[14]) + (a[15] * b[15]);
}

void matrixTranspose(mat4 a, mat4 m) {
	m[0] = a[0];
	m[1] = a[4];
	m[2] = a[8];
	m[3] = a[12];
	m[4] = a[1];
	m[5] = a[5];
	m[6] = a[9];
	m[7] = a[13];
	m[8] = a[2];
	m[9] = a[6];
	m[10] = a[10];
	m[11] = a[14];
	m[12] = a[3];
	m[13] = a[7];
	m[14] = a[11];
	m[15] = a[15];
}

void matrixVectorMultiplication(mat4 a, vec4 b, vec4 v) {
	v[0] = (a[0]*b[0])+(a[4]*b[1])+(a[8]*b[2])+(a[12]*b[3]);
	v[1] = (a[1]*b[0])+(a[5]*b[1])+(a[9]*b[2])+(a[13]*b[3]);
	v[2] = (a[2]*b[0])+(a[6]*b[1])+(a[10]*b[2])+(a[14]*b[3]);
	v[3] = (a[3]*b[0])+(a[7]*b[1])+(a[11]*b[2])+(a[15]*b[3]);
}

void matrixInverse(mat4 a, mat4 m) {
	m[0] = (a[5]*a[10]*a[15])+(a[9]*a[14]*a[7])+(a[13]*a[6]*a[11])-(a[7]*a[10]*a[13])-(a[11]*a[14]*a[5])-(a[15]*a[6]*a[9]);
	m[1] = -1*((a[4]*a[10]*a[15])+(a[8]*a[14]*a[7])+(a[12]*a[6]*a[11])-(a[7]*a[10]*a[12])-(a[11]*a[14]*a[4])-(a[15]*a[6]*a[8]));
	m[2] = (a[4]*a[9]*a[15])+(a[8]*a[13]*a[7])+(a[12]*a[5]*a[11])-(a[7]*a[9]*a[12])-(a[11]*a[13]*a[4])-(a[15]*a[5]*a[8]);
	m[3] = -1*((a[4]*a[9]*a[14])+(a[8]*a[13]*a[6])+(a[12]*a[5]*a[10])-(a[6]*a[9]*a[12])-(a[10]*a[13]*a[4])-(a[14]*a[5]*a[8]));
	m[4] =-1*( (a[1]*a[10]*a[15])+(a[9]*a[14]*a[3])+(a[13]*a[2]*a[11])-(a[3]*a[10]*a[13])-(a[11]*a[14]*a[1])-(a[15]*a[2]*a[9]));
	m[5] = (a[0]*a[10]*a[15])+(a[8]*a[14]*a[3])+(a[12]*a[2]*a[11])-(a[3]*a[10]*a[12])-(a[11]*a[14]*a[0])-(a[15]*a[2]*a[8]);
	m[6] = -1*((a[0]*a[9]*a[15])+(a[8]*a[13]*a[3])+(a[12]*a[1]*a[11])-(a[3]*a[9]*a[12])-(a[11]*a[13]*a[0])-(a[15]*a[1]*a[8]));
	m[10] = (a[0]*a[9]*a[14])+(a[8]*a[13]*a[2])+(a[12]*a[1]*a[10])-(a[2]*a[9]*a[12])-(a[10]*a[13]*a[0])-(a[14]*a[1]*a[8]);
	m[8] = (a[1]*a[6]*a[15])+(a[5]*a[14]*a[3])+(a[13]*a[2]*a[7])-(a[3]*a[6]*a[13])-(a[7]*a[14]*a[1])-(a[15]*a[2]*a[5]);
	m[9] = -1*((a[0]*a[6]*a[15])+(a[4]*a[14]*a[3])+(a[12]*a[2]*a[7])-(a[3]*a[6]*a[12])-(a[7]*a[14]*a[0])-(a[15]*a[2]*a[4]));
	m[10] = (a[0]*a[5]*a[15])+(a[4]*a[13]*a[3])+(a[12]*a[1]*a[7])-(a[3]*a[5]*a[12])-(a[7]*a[13]*a[0])-(a[15]*a[1]*a[4]);
	m[11] = -1*((a[0]*a[5]*a[14])+(a[4]*a[13]*a[2])+(a[12]*a[1]*a[6])-(a[2]*a[5]*a[12])-(a[6]*a[13]*a[0])-(a[14]*a[1]*a[4]));
	m[12] = -1*((a[1]*a[6]*a[11])+(a[5]*a[10]*a[3])+(a[9]*a[2]*a[7])-(a[3]*a[6]*a[9])-(a[7]*a[10]*a[1])-(a[11]*a[2]*a[5]));
	m[13] = (a[0]*a[6]*a[11])+(a[4]*a[10]*a[3])+(a[8]*a[2]*a[7])-(a[3]*a[6]*a[8])-(a[7]*a[10]*a[0])-(a[11]*a[2]*a[4]);
	m[14] = -1*((a[0]*a[5]*a[11])+(a[4]*a[9]*a[3])+(a[8]*a[1]*a[7])-(a[3]*a[5]*a[8])-(a[7]*a[9]*a[0])-(a[11]*a[1]*a[4]));
	m[15] = (a[0]*a[5]*a[10])+(a[4]*a[9]*a[2])+(a[8]*a[1]*a[6])-(a[2]*a[5]*a[8])-(a[6]*a[9]*a[0])-(a[10]*a[1]*a[4]);

	mat4 t;
	matrixTranspose(m, t);
	GLfloat determinant= (a[0]*t[0])+(a[4]*t[1])+(a[8]*t[2])+(a[12]*t[3]);

	m[0] = t[0] / determinant;
	m[1] = t[1] / determinant;
	m[2] = t[2] / determinant;
	m[3] = t[3] / determinant;
	m[4] = t[4] / determinant;
	m[5] = t[5] / determinant;
	m[6] = t[6] / determinant;
	m[7] = t[7] / determinant;
	m[8] = t[8] / determinant;
	m[9] = t[9] / determinant;
	m[10] = t[10] / determinant;
	m[11] = t[11] / determinant;
	m[12] = t[12] / determinant;
	m[13] = t[13] / determinant;
	m[14] = t[14] / determinant;
	m[15] = t[15] / determinant;
}

void matrixCopy(mat4 a, mat4 m) {
	m[0] = a[0];
	m[1] = a[1];
	m[2] = a[2];
	m[3] = a[3];
	m[4] = a[4];
	m[5] = a[5];
	m[6] = a[6];
	m[7] = a[7];
	m[8] = a[8];
	m[9] = a[9];
	m[10] = a[10];
	m[11] = a[11];
	m[12] = a[12];
	m[13] = a[13];
	m[14] = a[14];
	m[15] = a[15];
}

void matrixTranslation(GLfloat a, GLfloat b, GLfloat c, mat4 m) {
	m[0] = 1.0;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1.0;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1.0;
	m[11] = 0;
	m[12] = a;
	m[13] = b;
	m[14] = c;
	m[15] = 1.0;
}

void matrixScale(GLfloat a, GLfloat b, GLfloat c, mat4 m) {
	m[0] = a;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = b;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = c;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1.0;
}

void matrixRotateX(GLfloat theta, mat4 m) {
	m[0] = 1.0;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = cos(theta);
	m[6] = sin(theta);
	m[7] = 0;
	m[8] = 0;
	m[9] = -sin(theta);
	m[10] = cos(theta);
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1.0;
}

void matrixRotateY(GLfloat theta, mat4 m) {
	m[0] = cos(theta);
	m[1] = 0;
	m[2] = -sin(theta);
	m[3] = 0;
	m[4] = 0;
	m[5] = 1.0;
	m[6] = 0;
	m[7] = 0;
	m[8] = sin(theta);
	m[9] = 0;
	m[10] = cos(theta);
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1.0;
}

void matrixRotateZ(GLfloat theta, mat4 m) {
	m[0] = cos(theta);
	m[1] = sin(theta);
	m[2] = 0;
	m[3] = 0;
	m[4] = -sin(theta);
	m[5] = cos(theta);
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1.0;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1.0;
}

void matrixRotateVector(vec4 point, GLfloat theta, GLfloat cosX, GLfloat sinX, GLfloat cosY, GLfloat sinY, mat4 m){
	mat4 temp1, temp2, temp3;
	matrixTranslation(-point[0],-point[1],-point[2], temp1);

	identityMatrix(temp2);
	temp2[5] = cosX;
	temp2[6] = -sinX;
	temp2[9] = sinX;
	temp2[10] = cosX;
	matrixMultiplication(temp1, temp2, temp3);
	
	identityMatrix(temp1);
	temp1[0] = cosY;
	temp1[2] = -sinY;
	temp1[8] = sinY;
	temp1[10] = cosY;
	matrixMultiplication(temp3, temp1, temp2);
	
	matrixRotateZ(theta, temp1);
	matrixMultiplication(temp2, temp1, temp3);
	
	identityMatrix(temp1);
	temp1[0] = cosY;
	temp1[2] = sinY;
	temp1[8] = -sinY;
	temp1[10] = cosY;
	matrixMultiplication(temp3, temp1, temp2);
	
	identityMatrix(temp1);
	temp1[5] = cosX;
	temp1[6] = sinX;
	temp1[9] = -sinX;
	temp1[10] = cosX;
	matrixMultiplication(temp2, temp1, temp3);
	
	matrixTranslation(point[0],point[1],point[2], temp1);
	matrixMultiplication(temp3, temp1,  m);
}
