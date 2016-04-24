#ifndef _RUBIK_DRAW_H
#define _RUBIK_DRAW_H

#include <GL/glut.h>

void draw_cube(GLfloat theta, GLfloat p, GLfloat q, GLfloat r, GLint rotation, GLboolean inverse);
void reset_cube();
void rotate_top();
void rotate_bottom();
void rotate_right();
void rotate_left();
void rotate_front();
void rotate_back();
#endif
