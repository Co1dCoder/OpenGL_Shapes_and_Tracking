#include "math.h"
#include "matrixOperations.h"
#include "track.h"

void trackMouse(struct trackState *tk, int button, int state, int x, int y) {
	if( button == 3 || button == 4) {
		GLfloat zoom = 1.0;
		if( button == 3){
			zoom = 1.02;
		}else{
			zoom = (1/1.02);
		}
		mat4 temp;
		matrixScale(zoom, zoom, zoom, temp);
		matrixMultiplication(tk->track, temp, *tk->ctm);
		matrixCopy(*tk->ctm, tk->track);
		glutPostRedisplay();
	}
	else if( button == GLUT_LEFT_BUTTON) {
		if(state == GLUT_DOWN) {
			tk->rotateTheta = 0.0;
			vec4 temp = {-1.0, 0.0, 0.0, 0.0};
			temp[0] = (x-256)/256.0;
			temp[1] = -1*(y-256)/256.0;
			GLfloat operand = 1-pow(temp[0],2)-pow(temp[1],2);
			if(operand < 0) return;
			temp[2] = sqrt(operand);
			vectorCopy(temp, tk->start);
			tk->mdown = 1;
		}else {
			tk->mdown = 0;
		}
	}
}

void trackMotion(struct trackState *tk, int x, int y) {
	if(tk->mdown) {
		vec4 temp = {0.0, 0.0, 1.0, 0.0};
		temp[0] = (x-256)/256.0;
		temp[1] = -1*(y-256)/256.0;
		GLfloat operand = 1-pow(temp[0],2)-pow(temp[1],2);
		if(operand < 0) {
			tk->mdown = 0;
			tk->rotateTheta = 0.0;
			return;
		}
		temp[2] = sqrt(operand);

		vec4 rotate;
		vectorCrossProduct(tk->start, temp, rotate);
		vectorNormalize(rotate, rotate);
		if( isnan(rotate[0])) return;
		GLfloat d = sqrt(pow(rotate[1],2)+pow(rotate[2],2));
		GLfloat sinx = 0.0, cosx = 0.0;
		if(d != 0) {
			sinx = rotate[1]/d;
			cosx = rotate[2]/d;
		}
		GLfloat cosy = d, siny = rotate[0];
		GLfloat theta = acos(vectorDotProduct(tk->start, temp)/(vectorMagnitude(tk->start)*vectorMagnitude(temp)));

		mat4 rotation,temp_matrix;
		vec4 point = {0.0,0.0,0.0, 1.0};
		matrixRotateVector(point, theta, cosx, sinx, cosy, siny, rotation);
		matrixMultiplication(rotation, tk->track, temp_matrix);
		matrixCopy(temp_matrix, *tk->ctm);

		vectorCopy(temp, tk->start);
		matrixCopy(temp_matrix, tk->track);
		tk->rotateTheta = theta;
		tk->xyTrigVals[0] = cosx;
		tk->xyTrigVals[1] = sinx;
		tk->xyTrigVals[2] = cosy;
		tk->xyTrigVals[3] = siny;

		glutPostRedisplay();
	}
}

void trackIdle(struct trackState *tk){
	if(!tk->mdown && tk->rotateTheta != 0.0){
		mat4 rotatematrix, copy_matrix;
		vec4 point = {0.0, 0.0, 0.0, 1.0};
		matrixRotateVector(point, tk->rotateTheta, tk->xyTrigVals[0], tk->xyTrigVals[1], tk->xyTrigVals[2], tk->xyTrigVals[3],rotatematrix);
		matrixMultiplication(rotatematrix, tk->track, copy_matrix);
		matrixCopy(copy_matrix, *tk->ctm);
		matrixCopy(copy_matrix, tk->track);
		glutPostRedisplay();
	}
}
