#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include "math.h"
#include "matrixOperations.h"
#include "geometricShapes.h"

void matrixVariableCopy(int num, vec4 *a, vec4 *b){
        int i;
        for(i = 0; i<num; i++){
                vectorCopy(a[i], b[i]);
        }
}

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

void generateCap(vec4 *ring, vec4 center, vec4 *vertices, vec4 *colors, int degree_change, int index) {
        int i;
        for(i=0; i< (4*degree_change);i++){
                if( center[1] < 0 ) {
                        vectorCopy(ring[i+1], vertices[index+(i*3)]);
                        vectorCopy(ring[i], vertices[index+(i*3)+1]);
                } else{
                        vectorCopy(ring[i], vertices[index+(i*3)]);
                        vectorCopy(ring[i+1], vertices[index+(i*3)+1]);
                }               
                vectorCopy(center, vertices[index+(i*3)+2]);

                getColor(colors, index+(i*3));
        }
}

void generateRingSphere(GLfloat angleY, GLfloat theta, GLfloat r, vec4 *ring) {
        int index = 0;
        GLfloat angleXZ = 0.0;
        while(angleXZ <= 2*M_PI){ 
                vec4 temp = {r*cos(angleXZ)*sin(angleY), r*cos(angleY), r*sin(angleXZ)*sin(angleY), 1};
                vectorCopy(temp, ring[index]);
                index++;
                angleXZ+=theta;
        }
}


void generateRingTorus(GLfloat angleU, GLfloat theta, GLfloat inner_r, GLfloat outer_r, vec4 *ring) {
        int index = 0;
        GLfloat angleV = 0.0;
        while(angleV <= 2*M_PI){
                vec4 temp = {(outer_r+inner_r*cos(angleV))*cos(angleU), inner_r*sin(angleV), (outer_r+inner_r*cos(angleV))*sin(angleU), 1};
                vectorCopy(temp, ring[index]);
                index++;
                angleV+=theta;
        }
}


void generateRingSpring(GLfloat angleU, GLfloat theta, GLfloat Y_change, GLfloat inner_r, GLfloat outer_r, vec4 *ring) {
        int index = 0;
        GLfloat angleV = 0.0;
        while(angleV <= 2*M_PI){ 
                vec4 temp = {(outer_r+inner_r*cos(angleV))*cos(angleU), (inner_r*sin(angleV))+Y_change, (outer_r+inner_r*cos(angleV))*sin(angleU), 1};
                vectorCopy(temp, ring[index]);
                index++;
                angleV+=theta;
        }
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


void sphere(vec4 *vertices, vec4 *colors, int num_vertices, int degree_change) {
        GLfloat theta = ((90.0/degree_change)*M_PI)/180;
        GLfloat phi = ((90.0/degree_change)*M_PI)/180;
        GLfloat angleY = M_PI;
        GLfloat r = 1.0;
        vec4 ring1[(degree_change*4)+1];
        generateRingSphere(angleY, theta, r, ring1);
        int i, j;
        for( i = 0 ; i< (2*degree_change); i++){
                angleY += phi;
                vec4 ring2[(degree_change*4)+1];
                generateRingSphere(angleY, theta, r, ring2);
                for(j=0;j<(4*degree_change);j++){
                        int row_points = degree_change*4*6;
                        vectorCopy(ring2[j], vertices[(i*row_points)+j*6]);
                        vectorCopy(ring1[j+1], vertices[(i*row_points)+(j*6)+1]);
                        vectorCopy(ring1[j], vertices[(i*row_points)+(j*6)+2]);
                        vectorCopy(ring2[j], vertices[(i*row_points)+(j*6)+3]);
                        vectorCopy(ring2[j+1], vertices[(i*row_points)+(j*6)+4]);
                        vectorCopy(ring1[j+1], vertices[(i*row_points)+(j*6)+5]);

                        getColor(colors, (i*row_points)+(j*6));
                        getColor(colors, (i*row_points)+(j*6)+3);
                }
                matrixVariableCopy((degree_change*4)+1,ring2,ring1);
        }
}

void torus(vec4 *vertices, vec4 *colors, int num_vertices, int degree_change) {
        GLfloat theta = ((90.0/degree_change)*M_PI)/180;
        GLfloat phi = ((90.0/degree_change)*M_PI)/180;
        GLfloat angleU = 0;
        GLfloat inner_r = 0.25;
        GLfloat outer_r = 0.5;
        vec4 ring1[(degree_change*4)+1];
        generateRingTorus(angleU, theta,inner_r,outer_r, ring1);
        int i, j;
        for( i = 0 ; i< (4*degree_change); i++){
                angleU += phi;
                vec4 ring2[(degree_change*4)+1];
                generateRingTorus(angleU, theta,inner_r, outer_r,ring2);
                for(j=0;j<(4*degree_change);j++){
                        int row_points = degree_change*4*6;
                        vectorCopy(ring2[j], vertices[(i*row_points)+j*6]);
                        vectorCopy(ring1[j], vertices[(i*row_points)+(j*6)+1]);
                        vectorCopy(ring2[j+1], vertices[(i*row_points)+(j*6)+2]);
                        vectorCopy(ring1[j], vertices[(i*row_points)+(j*6)+3]);
                        vectorCopy(ring1[j+1], vertices[(i*row_points)+(j*6)+4]);
                        vectorCopy(ring2[j+1], vertices[(i*row_points)+(j*6)+5]);

                        getColor(colors, (i*row_points)+(j*6));
                        getColor(colors, (i*row_points)+(j*6)+3);
                }
                matrixVariableCopy((degree_change*4)+1,ring2,ring1);
        }
}

void spring(vec4 *vertices, vec4 *colors, int num_vertices, int degree_change) {
        GLfloat theta = ((90.0/degree_change)*M_PI)/180;
        GLfloat phi = ((90.0/degree_change)*M_PI)/180;
        GLfloat angleU = 0;
        GLfloat inner_r = 0.1;
        GLfloat outer_r = 0.25;
        GLfloat Y_change = -1.0+inner_r;
        vec4 ring1[(degree_change*4)+1];
        vec4 ring2[(degree_change*4)+1];
        generateRingSpring(angleU, theta, Y_change, inner_r,outer_r, ring1);
        int i, j;
        for( i = 0 ; i< 4*(4*degree_change); i++){
                Y_change += 0.01;
                angleU += phi;
                generateRingSpring(angleU, theta, Y_change, inner_r, outer_r,ring2);
                for(j=0;j<(4*degree_change);j++){
                        int row_points = degree_change*4*6;
                        vectorCopy(ring2[j], vertices[(i*row_points)+j*6]);
                        vectorCopy(ring1[j], vertices[(i*row_points)+(j*6)+1]);
                        vectorCopy(ring2[j+1], vertices[(i*row_points)+(j*6)+2]);
                        vectorCopy(ring1[j], vertices[(i*row_points)+(j*6)+3]);
                        vectorCopy(ring1[j+1], vertices[(i*row_points)+(j*6)+4]);
                        vectorCopy(ring2[j+1], vertices[(i*row_points)+(j*6)+5]);

                        getColor(colors, (i*row_points)+(j*6));
                        getColor(colors, (i*row_points)+(j*6)+3);
                }
                matrixVariableCopy((degree_change*4)+1,ring2,ring1);
        }
        vec4 temp = {ring2[0][0]-inner_r,ring2[0][1],ring2[0][2],1.0};
        generateCap(ring2, temp, vertices, colors, degree_change, (64*degree_change*degree_change*6));
        generateRingSpring(0, theta, -1.0+inner_r, inner_r, outer_r, ring2);
        vec4 temp1 = {ring2[0][0]-inner_r, ring2[0][1],ring2[0][2],1.0};
        generateCap(ring2, temp1, vertices, colors, degree_change, (64*degree_change*degree_change*6)+(4*degree_change*3));
}

