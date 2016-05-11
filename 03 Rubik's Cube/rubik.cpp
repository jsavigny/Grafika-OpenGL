#include <vector>
#include <iostream>

#include <GL/glut.h>
#include <SOIL.h>
#include "draw.hpp"

using namespace std;

const GLfloat speed = 2.5f;

volatile GLint rotation = 0;
volatile GLboolean inverse = false;
volatile GLint rotation_complete = 0;
volatile GLboolean key_pressed = false;
volatile GLfloat theta = 0.f;
volatile GLfloat p = 0.f, q = 0.f, r = 0.f;
volatile GLint x_begin = 0, y_begin = 0;

const GLchar KEY_ROTATE_TOP = 'a';
const GLchar KEY_ROTATE_TOP_REVERSE = 'q';
const GLchar KEY_ROTATE_BOTTOM = 's';
const GLchar KEY_ROTATE_BOTTOM_REVERSE = 'w';
const GLchar KEY_ROTATE_RIGHT = 'd';
const GLchar KEY_ROTATE_RIGHT_REVERSE = 'e';
const GLchar KEY_ROTATE_LEFT = 'f';
const GLchar KEY_ROTATE_LEFT_REVERSE = 'r';
const GLchar KEY_ROTATE_FRONT = 'g';
const GLchar KEY_ROTATE_FRONT_REVERSE = 't';
const GLchar KEY_ROTATE_BACK = 'h';
const GLchar KEY_ROTATE_BACK_REVERSE = 'y';
const GLchar KEY_LIGHT = 'l';

const GLchar KEY_RESET_CUBE = 'z';
const GLchar KEY_RESET_SCREEN = 'x';

vector<GLchar> key_mapping {
    KEY_ROTATE_TOP, KEY_ROTATE_TOP_REVERSE,
    KEY_ROTATE_BOTTOM, KEY_ROTATE_BOTTOM_REVERSE,
    KEY_ROTATE_RIGHT, KEY_ROTATE_RIGHT_REVERSE,
    KEY_ROTATE_LEFT, KEY_ROTATE_LEFT_REVERSE,
    KEY_ROTATE_FRONT, KEY_ROTATE_FRONT_REVERSE,
    KEY_ROTATE_BACK, KEY_ROTATE_BACK_REVERSE
};

int ambient=0,diffuse=0,specular=0;
int ambientIntensity=0;

void display() {
    draw_cube(theta, p, q, r, rotation, inverse, ambient, diffuse, specular, ambientIntensity);
}

void spin_cube() {
    if (!key_pressed)
        return;

    theta += 0.5f + speed;
    while (theta >= 360.f)
        theta -= 360.f;

    if (theta < 90.f) {
        glutPostRedisplay();
        return;
    }

    rotation_complete = 1;
    glutIdleFunc(NULL);

    int apply = inverse ? 3 : 1;
    switch (rotation) {
        case 1:
            while (apply--)
                rotate_top();
        break;

        case 2:
            while (apply--)
                rotate_bottom();
        break;

        case 3:
            while (apply--)
                rotate_right();
        break;

        case 4:
            while (apply--)
                rotate_left();
        break;

        case 5:
            while (apply--)
                rotate_front();
        break;

        case 6:
            while (apply--)
                rotate_back();
        break;
    }

    rotation = 0;
    theta = 0;
    key_pressed = false;

    glutPostRedisplay();
}


void motion(int x, int y) {
    q += x - x_begin;
    p += y - y_begin;
    x_begin = x;
    y_begin = y;
    glutPostRedisplay();
}


void mouse(int btn, int state, int x, int y) {
    x_begin = x;
    y_begin = y;
}

static void keyboard(unsigned char key, int x, int y) {
    if (key_pressed)
        return;

    key_pressed = true;
    for (vector<char>::size_type i = 0; i < key_mapping.size(); ++i) {
        if (key != key_mapping[i])
            continue;

        rotation = (i >> 1) + 1;
        inverse = i & 1;
        rotation_complete = 0;
        glutIdleFunc(spin_cube);
        return;
    }

    switch (key) {
        case KEY_RESET_CUBE:
            reset_cube();
            glutIdleFunc(spin_cube);
        return;

        case KEY_RESET_SCREEN:
            p = q = r = 0.f;
            glutIdleFunc(spin_cube);
        return;

        case '1':
            if (ambient==0){
                ambient=1;
            } else {
                ambient=0;
            }
            glutIdleFunc(spin_cube);
        return;

        case '2':
            if (diffuse==0){
                diffuse=1;
            } else {
                diffuse=0;
            }
            glutIdleFunc(spin_cube);
        return;

        case '3':
            if (specular==0){
                specular=1;
            } else {
                specular=0;
            }
            glutIdleFunc(spin_cube);
        return;

        case '=':
            ambientIntensity++;
            ambientIntensity%=10;
            glutIdleFunc(spin_cube);
        return;

        case '-':
            ambientIntensity--;
            ambientIntensity%=10;
            glutIdleFunc(spin_cube);
        return;

    }

    key_pressed = false;
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-10.f, 10.f, -10.f*(GLfloat)h/(GLfloat)w, 10.f*(GLfloat)h/(GLfloat)w, -10.f, 10.f);
    else
        glOrtho(-10.f*(GLfloat)w/(GLfloat)h, 10.f*(GLfloat)w/(GLfloat)h, -10.f, 10.f, -10.f, 10.f);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutCreateWindow ("Rubik's Cube");
    glutReshapeFunc (reshape);
    glutIdleFunc(spin_cube);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc (display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}
