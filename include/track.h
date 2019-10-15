#ifndef TRACK_H
#define TRACK_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>

typedef GLfloat vec4[4];
typedef GLfloat mat4[16];

struct trackState {
        int mdown;
        vec4 start;
        mat4 track;
        vec4 xyTrigVals;
        GLfloat rotateTheta;
	mat4 *ctm;
};

void trackMouse(struct trackState *tk, int button, int state, int x, int y);
void trackMotion(struct trackState *tk, int x, int y);
void trackIdle(struct trackState *tk);

#endif
