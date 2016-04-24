#include "draw.hpp"
#include <SOIL.h>
GLuint theTexture;
GLfloat vertices[][3] = {
    // center
    {-1.f, -1.f, -1.f},
    {1.f, -1.f, -1.f},
    {1.f, 1.f, -1.f},
    {-1.f, 1.f, -1.f},
    {-1.f, -1.f, 1.f},
    {1.f, -1.f, 1.f},
    {1.f, 1.f, 1.f},
    {-1.f, 1.f, 1.f},

    // bottom center
    {-1.f, -3.f, -1.f},
    {1.f, -3.f, -1.f},
    {1.f, -1.f, -1.f},
    {-1.f, -1.f, -1.f},
    {-1.f, -3.f, 1.f},
    {1.f, -3.f, 1.f},
    {1.f, -1.f, 1.f},
    {-1.f, -1.f, 1.f},

    // left center
    {-3.f, -1.f, -1.f},
    {-1.f, -1.f, -1.f},
    {-1.f, 1.f, -1.f},
    {-3.f, 1.f, -1.f},
    {-3.f, -1.f, 1.f},
    {-1.f, -1.f, 1.f},
    {-1.f, 1.f, 1.f},
    {-3.f, 1.f, 1.f},

    // right center
    {1.f, -1.f, -1.f},
    {3.f, -1.f, -1.f},
    {3.f, 1.f, -1.f},
    {1.f, 1.f, -1.f},
    {1.f, -1.f, 1.f},
    {3.f, -1.f, 1.f},
    {3.f, 1.f, 1.f},
    {1.f, 1.f, 1.f},

    // top center
    {-1.f, 1.f, -1.f},
    {1.f, 1.f, -1.f},
    {1.f, 3.f, -1.f},
    {-1.f, 3.f, -1.f},
    {-1.f, 1.f, 1.f},
    {1.f, 1.f, 1.f},
    {1.f, 3.f, 1.f},
    {-1.f, 3.f, 1.f},

    // front center
    {-1.f, -1.f, 1.f},
    {1.f, -1.f, 1.f},
    {1.f, 1.f, 1.f},
    {-1.f, 1.f, 1.f},
    {-1.f, -1.f, 3.f},
    {1.f, -1.f, 3.f},
    {1.f, 1.f, 3.f},
    {-1.f, 1.f, 3.f},

    // back center
    {-1.f, -1.f, -3.f},
    {1.f, -1.f, -3.f},
    {1.f, 1.f, -3.f},
    {-1.f, 1.f, -3.f},
    {-1.f, -1.f, -1.f},
    {1.f, -1.f, -1.f},
    {1.f, 1.f, -1.f},
    {-1.f, 1.f, -1.f},

    // top left center
    {-3.f, 1.f, -1.f},
    {-1.f, 1.f, -1.f},
    {-1.f, 3.f, -1.f},
    {-3.f, 3.f, -1.f},
    {-3.f, 1.f, 1.f},
    {-1.f, 1.f, 1.f},
    {-1.f, 3.f, 1.f},
    {-3.f, 3.f, 1.f},

    // top right center
    {1.f, 1.f, -1.f},
    {3.f, 1.f, -1.f},
    {3.f, 3.f, -1.f},
    {1.f, 3.f, -1.f},
    {1.f, 1.f, 1.f},
    {3.f, 1.f, 1.f},
    {3.f, 3.f, 1.f},
    {1.f, 3.f, 1.f},

    // top front center
    {-1.f, 1.f, 1.f},
    {1.f, 1.f, 1.f},
    {1.f, 3.f, 1.f},
    {-1.f, 3.f, 1.f},
    {-1.f, 1.f, 3.f},
    {1.f, 1.f, 3.f},
    {1.f, 3.f, 3.f},
    {-1.f, 3.f, 3.f},

    // top back center
    {-1.f, 1.f, -3.f},
    {1.f, 1.f, -3.f},
    {1.f, 3.f, -3.f},
    {-1.f, 3.f, -3.f},
    {-1.f, 1.f, -1.f},
    {1.f, 1.f, -1.f},
    {1.f, 3.f, -1.f},
    {-1.f, 3.f, -1.f},

    // bottom left center
    {-3.f, -3.f, -1.f},
    {-1.f, -3.f, -1.f},
    {-1.f, -1.f, -1.f},
    {-3.f, -1.f, -1.f},
    {-3.f, -3.f, 1.f},
    {-1.f, -3.f, 1.f},
    {-1.f, -1.f, 1.f},
    {-3.f, -1.f, 1.f},

    // bottom right center
    {1.f, -3.f, -1.f},
    {3.f, -3.f, -1.f},
    {3.f, -1.f, -1.f},
    {1.f, -1.f, -1.f},
    {1.f, -3.f, 1.f},
    {3.f, -3.f, 1.f},
    {3.f, -1.f, 1.f},
    {1.f, -1.f, 1.f},

    // bottom front center
    {-1.f, -3.f, 1.f},
    {1.f, -3.f, 1.f},
    {1.f, -1.f, 1.f},
    {-1.f, -1.f, 1.f},
    {-1.f, -3.f, 3.f},
    {1.f, -3.f, 3.f},
    {1.f, -1.f, 3.f},
    {-1.f, -1.f, 3.f},

    // bottom back center
    {-1.f, -3.f, -3.f},
    {1.f, -3.f, -3.f},
    {1.f, -1.f, -3.f},
    {-1.f, -1.f, -3.f},
    {-1.f, -3.f, -1.f},
    {1.f, -3.f, -1.f},
    {1.f, -1.f, -1.f},
    {-1.f, -1.f, -1.f},

    // top left back
    {-3.f, 1.f, -3.f},
    {-1.f, 1.f, -3.f},
    {-1.f, 3.f, -3.f},
    {-3.f, 3.f, -3.f},
    {-3.f, 1.f, -1.f},
    {-1.f, 1.f, -1.f},
    {-1.f, 3.f, -1.f},
    {-3.f, 3.f, -1.f},

    // top left front
    {-3.f, 1.f, 1.f},
    {-1.f, 1.f, 1.f},
    {-1.f, 3.f, 1.f},
    {-3.f, 3.f, 1.f},
    {-3.f, 1.f, 3.f},
    {-1.f, 1.f, 3.f},
    {-1.f, 3.f, 3.f},
    {-3.f, 3.f, 3.f},

    // top right back
    {1.f, 1.f, -3.f},
    {3.f, 1.f, -3.f},
    {3.f, 3.f, -3.f},
    {1.f, 3.f, -3.f},
    {1.f, 1.f, -1.f},
    {3.f, 1.f, -1.f},
    {3.f, 3.f, -1.f},
    {1.f, 3.f, -1.f},

    // top right front
    {1.f, 1.f, 1.f},
    {3.f, 1.f, 1.f},
    {3.f, 3.f, 1.f},
    {1.f, 3.f, 1.f},
    {1.f, 1.f, 3.f},
    {3.f, 1.f, 3.f},
    {3.f, 3.f, 3.f},
    {1.f, 3.f, 3.f},

    // center left back
    {-3.f, -1.f, -3.f},
    {-1.f, -1.f, -3.f},
    {-1.f, 1.f, -3.f},
    {-3.f, 1.f, -3.f},
    {-3.f, -1.f, -1.f},
    {-1.f, -1.f, -1.f},
    {-1.f, 1.f, -1.f},
    {-3.f, 1.f, -1.f},

    // center left front
    {-3.f, -1.f, 1.f},
    {-1.f, -1.f, 1.f},
    {-1.f, 1.f, 1.f},
    {-3.f, 1.f, 1.f},
    {-3.f, -1.f, 3.f},
    {-1.f, -1.f, 3.f},
    {-1.f, 1.f, 3.f},
    {-3.f, 1.f, 3.f},

    // center right back
    {1.f, -1.f, -3.f},
    {3.f, -1.f, -3.f},
    {3.f, 1.f, -3.f},
    {1.f, 1.f, -3.f},
    {1.f, -1.f, -1.f},
    {3.f, -1.f, -1.f},
    {3.f, 1.f, -1.f},
    {1.f, 1.f, -1.f},

    // center right front
    {1.f, -1.f, 1.f},
    {3.f, -1.f, 1.f},
    {3.f, 1.f, 1.f},
    {1.f, 1.f, 1.f},
    {1.f, -1.f, 3.f},
    {3.f, -1.f, 3.f},
    {3.f, 1.f, 3.f},
    {1.f, 1.f, 3.f},

    // bottom left back
    {-3.f, -3.f, -3.f},
    {-1.f, -3.f, -3.f},
    {-1.f, -1.f, -3.f},
    {-3.f, -1.f, -3.f},
    {-3.f, -3.f, -1.f},
    {-1.f, -3.f, -1.f},
    {-1.f, -1.f, -1.f},
    {-3.f, -1.f, -1.f},

    // bottom left front
    {-3.f, -3.f, 1.f},
    {-1.f, -3.f, 1.f},
    {-1.f, -1.f, 1.f},
    {-3.f, -1.f, 1.f},
    {-3.f, -3.f, 3.f},
    {-1.f, -3.f, 3.f},
    {-1.f, -1.f, 3.f},
    {-3.f, -1.f, 3.f},

    // bottom right back
    {1.f, -3.f, -3.f},
    {3.f, -3.f, -3.f},
    {3.f, -1.f, -3.f},
    {1.f, -1.f, -3.f},
    {1.f, -3.f, -1.f},
    {3.f, -3.f, -1.f},
    {3.f, -1.f, -1.f},
    {1.f, -1.f, -1.f},

    // bottom right front
    {1.f, -3.f, 1.f},
    {3.f, -3.f, 1.f},
    {3.f, -1.f, 1.f},
    {1.f, -1.f, 1.f},
    {1.f, -3.f, 3.f},
    {3.f, -3.f, 3.f},
    {3.f, -1.f, 3.f},
    {1.f, -1.f, 3.f}
};

GLfloat color[][3] = {
    {1.f, 1.f, 1.f}, // white
    {1.f, 0.5f, 0.f}, // orange
    {0.f, 0.f, 1.f}, // blue
    {0.f, 1.f, 0.f}, // green
    {1.f, 1.f, 0.f}, // yellow
    {1.f, 0.f, 0.f}, // red
    {0.5f, 0.5f, 0.5}, // grey (uncolored)
};

int
    top[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    right[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
    front[3][3] = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}},
    back[3][3] = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}},
    bottom[3][3] = {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
    left[3][3] = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};

void polygon(int indexColor, int a, int b, int c, int d) {

   //GLuint theTexture;
   
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, theTexture);
   glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
   glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );



    glColor3f(0, 0, 0);
    glLineWidth(3.f);
    glBegin(GL_LINE_LOOP);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
    glEnd();

    glColor3fv(color[indexColor]);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0,0.0); glVertex3fv(vertices[a]);
    glTexCoord2d(1.0,0.0); glVertex3fv(vertices[b]);
    glTexCoord2d(1.0,1.0); glVertex3fv(vertices[c]);
    glTexCoord2d(0.0,1.0); glVertex3fv(vertices[d]);
    glEnd();
}

// center
void draw_cube_center() {
    polygon(6, 0, 3, 2, 1);
    polygon(6, 2, 3, 7, 6);
    polygon(6, 0, 4, 7, 3);
    polygon(6, 1, 2, 6, 5);
    polygon(6, 4, 5, 6, 7);
    polygon(6, 0, 1, 5, 4);
}

// bottom center
void draw_cube_bottom_center() {
    polygon(6, 8, 11, 10, 9);
    polygon(6, 10, 11, 15, 14);
    polygon(6, 8, 12, 15, 11);
    polygon(6, 9, 10, 14, 13);
    polygon(6, 12, 13, 14, 15);
    polygon(bottom[1][1], 8, 9, 13, 12);
}

// left center
void draw_cube_left_center() {
    polygon(6, 16, 19, 18, 17);
    polygon(6, 18, 19, 23, 22);
    polygon(left[1][1], 16, 20, 23, 19);
    polygon(6, 17, 18, 22, 21);
    polygon(6, 20, 21, 22, 23);
    polygon(6, 16, 17, 21, 20);
}

// right center
void draw_cube_right_center() {
    polygon(6, 24, 27, 26, 25);
    polygon(6, 26, 27, 31, 30);
    polygon(6, 24, 28, 31, 27);
    polygon(right[1][1], 25, 26, 30, 29);
    polygon(6, 28, 29, 30, 31);
    polygon(6, 24, 25, 29, 28);
}

// top center
void draw_cube_top_center() {
    polygon(6, 32, 35, 34, 33);
    polygon(top[1][1], 34, 35, 39, 38);
    polygon(6, 32, 36, 39, 35);
    polygon(6, 33, 34, 38, 37);
    polygon(6, 36, 37, 38, 39);
    polygon(6, 32, 33, 37, 36);
}

// front center
void draw_cube_front_center() {
    polygon(6, 40, 43, 42, 41);
    polygon(6, 42, 43, 47, 46);
    polygon(6, 40, 44, 47, 43);
    polygon(6, 41, 42, 46, 45);
    polygon(front[1][1], 44, 45, 46, 47);
    polygon(6, 40, 41, 45, 44);
}

// back center
void draw_cube_back_center() {
    polygon(back[1][1], 48, 51, 50, 49);
    polygon(6, 50, 51, 55, 54);
    polygon(6, 48, 52, 55, 51);
    polygon(6, 49, 50, 54, 53);
    polygon(6, 52, 53, 54, 55);
    polygon(6, 48, 49, 53, 52);
}

// top left center
void draw_cube_top_left_center() {
    polygon(6, 56, 59, 58, 57);
    polygon(top[1][0], 58, 59, 63, 62);
    polygon(left[0][1], 56, 60, 63, 59);
    polygon(6, 57, 58, 62, 61);
    polygon(6, 60, 61, 62, 63);
    polygon(6, 56, 57, 61, 60);
}

// top right center
void draw_cube_top_right_center() {
    polygon(6, 64, 67, 66, 65);
    polygon(top[1][2], 66, 67, 71, 70);
    polygon(6, 64, 68, 71, 67);
    polygon(right[0][1], 65, 66, 70, 69);
    polygon(6, 68, 69, 70, 71);
    polygon(6, 64, 65, 69, 68);
}

// top front center
void draw_cube_top_front_center() {
    polygon(6, 72, 75, 74, 73);
    polygon(top[2][1], 74, 75, 79, 78);
    polygon(6, 72, 76, 79, 75);
    polygon(6, 73, 74, 78, 77);
    polygon(front[0][1], 76, 77, 78, 79);
    polygon(6, 72, 73, 77, 76);
}

// top back center
void draw_cube_top_back_center() {
    polygon(back[0][1], 80, 83, 82, 81);
    polygon(top[0][1], 82, 83, 87, 86);
    polygon(6, 80, 84, 87, 83);
    polygon(6, 81, 82, 86, 85);
    polygon(6, 84, 85, 86, 87);
    polygon(6, 80, 81, 85, 84);
}

// bottom left center
void draw_cube_bottom_left_center() {
    polygon(6, 80+8, 83+8, 82+8, 81+8);
    polygon(6, 82+8, 83+8, 87+8, 86+8);
    polygon(left[2][1], 80+8, 84+8, 87+8, 83+8);
    polygon(6, 81+8, 82+8, 86+8, 85+8);
    polygon(6, 84+8, 85+8, 86+8, 87+8);
    polygon(bottom[1][0], 80+8, 81+8, 85+8, 84+8);
}

// bottom right center
void draw_cube_bottom_right_center() {
    polygon(6, 80+16, 83+16, 82+16, 81+16);
    polygon(6, 82+16, 83+16, 87+16, 86+16);
    polygon(6, 80+16, 84+16, 87+16, 83+16);
    polygon(right[2][1], 81+16, 82+16, 86+16, 85+16);
    polygon(6, 84+16, 85+16, 86+16, 87+16);
    polygon(bottom[1][2], 80+16, 81+16, 85+16, 84+16);
}

// bottom front center
void draw_cube_bottom_front_center() {
    polygon(6, 80+24, 83+24, 82+24, 81+24);
    polygon(6, 82+24, 83+24, 87+24, 86+24);
    polygon(6, 80+24, 84+24, 87+24, 83+24);
    polygon(6, 81+24, 82+24, 86+24, 85+24);
    polygon(front[2][1], 84+24, 85+24, 86+24, 87+24);
    polygon(bottom[0][1], 80+24, 81+24, 85+24, 84+24);
}

// bottom back center
void draw_cube_bottom_back_center() {
    polygon(back[2][1], 112, 115, 114, 113);
    polygon(6, 114, 115, 119, 118);
    polygon(6, 112, 116, 119, 115);
    polygon(6, 113, 114, 118, 117);
    polygon(6, 116, 117, 118, 119);
    polygon(bottom[2][1], 112, 113, 117, 116);
}

// top left back
void draw_cube_top_left_back() {
    polygon(back[0][2], 120, 123, 122, 121);
    polygon(top[0][0], 122, 123, 127, 126);
    polygon(left[0][0], 120, 124, 127, 123);
    polygon(6, 121, 122, 126, 125);
    polygon(6, 124, 125, 126, 127);
    polygon(6, 120, 121, 125, 124);
}

// top left front
void draw_cube_top_left_front() {
    polygon(6, 128, 131, 130, 129);
    polygon(top[2][0], 130, 131, 135, 134);
    polygon(left[0][2], 128, 132, 135, 131);
    polygon(6, 129, 130, 134, 133);
    polygon(front[0][0], 132, 133, 134, 135);
    polygon(6, 128, 129, 133, 132);
}

// top right back
void draw_cube_top_right_back() {
    polygon(back[0][0], 136, 139, 138, 137);
    polygon(top[0][2], 138, 139, 143, 142);
    polygon(6, 136, 140, 143, 139);
    polygon(right[0][2], 137, 138, 142, 141);
    polygon(6, 140, 141, 142, 143);
    polygon(6, 136, 137, 141, 140);
}

// top right front
void draw_cube_top_right_front() {
    polygon(6, 144, 147, 146, 145);
    polygon(top[2][2], 146, 147, 151, 150);
    polygon(6, 144, 148, 151, 147);
    polygon(right[0][0], 145, 146, 150, 149);
    polygon(front[0][2], 148, 149, 150, 151);
    polygon(6, 144, 145, 149, 148);
}

//center left back
void draw_cube_center_left_back() {
    polygon(back[1][2], 152, 155, 154, 153);
    polygon(6, 154, 155, 159, 158);
    polygon(left[1][0], 152, 156, 159, 155);
    polygon(6, 153, 154, 158, 157);
    polygon(6, 156, 157, 158, 159);
    polygon(6, 152, 153, 157, 156);
}

// center left front
void draw_cube_center_left_front() {
    polygon(6, 160, 163, 162, 161);
    polygon(6, 162, 163, 167, 166);
    polygon(left[1][2], 160, 164, 167, 163);
    polygon(6, 161, 162, 166, 165);
    polygon(front[1][0], 164, 165, 166, 167);
    polygon(6, 160, 161, 165, 164);
}

// center right back
void draw_cube_center_right_back() {
    polygon(back[1][0], 168, 171, 170, 169);
    polygon(6, 170, 171, 175, 174);
    polygon(6, 168, 172, 175, 171);
    polygon(right[1][2], 169, 170, 174, 173);
    polygon(6, 172, 173, 174, 175);
    polygon(6, 168, 169, 173, 172);
}

// center right front
void draw_cube_center_right_front() {
    polygon(6, 176, 179, 178, 177);
    polygon(6, 178, 179, 183, 182);
    polygon(6, 176, 180, 183, 179);
    polygon(right[1][0], 177, 178, 182, 181);
    polygon(front[1][2], 180, 181, 182, 183);
    polygon(6, 176, 177, 181, 180);
}

// bottom left back
void draw_cube_bottom_left_back() {
    polygon(back[2][2], 184, 187, 186, 185);
    polygon(6, 186, 187, 191, 190);
    polygon(left[2][0], 184, 188, 191, 187);
    polygon(6, 185, 186, 190, 189);
    polygon(6, 188, 189, 190, 191);
    polygon(bottom[2][0], 184, 185, 189, 188);
}

// bottom left front
void draw_cube_bottom_left_front() {
    polygon(6, 192, 195, 194, 193);
    polygon(6, 194, 195, 199, 198);
    polygon(left[2][2], 192, 196, 199, 195);
    polygon(6, 193, 194, 198, 197);
    polygon(front[2][0], 196, 197, 198, 199);
    polygon(bottom[0][0], 192, 193, 197, 196);
}

// bottom right back
void draw_cube_bottom_right_back() {
    polygon(back[2][0], 200, 203, 202, 201);
    polygon(6, 202, 203, 207, 206);
    polygon(6, 200, 204, 207, 203);
    polygon(right[2][2], 201, 202, 206, 205);
    polygon(6, 204, 205, 206, 207);
    polygon(bottom[2][2], 200, 201, 205, 204);
}

// bottom right front
void draw_cube_bottom_right_front() {
    polygon(6, 208, 211, 210, 209);
    polygon(6, 210, 211, 215, 214);
    polygon(6, 208, 212, 215, 211);
    polygon(right[2][0], 209, 210, 214, 213);
    polygon(front[2][2], 212, 213, 214, 215);
    polygon(bottom[0][2], 208, 209, 213, 212);
}

void draw_cube(GLfloat theta, GLfloat p, GLfloat q, GLfloat r, GLint rotation, GLboolean inverse) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3fv(color[0]);
    theTexture = SOIL_load_OGL_texture
   (
      "steel.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
   );
    glPushMatrix();
    glRotatef(25.f + p, 1.f, 0.f, 0.f);
    glRotatef(-30.f + q, 0.f, 1.f, 0.f);
    glRotatef(0.f + r, 0.f, 0.f, 1.f);

    switch (rotation) {
        // no rotation
        case 0:
            draw_cube_center();
            draw_cube_bottom_center();
            draw_cube_left_center();
            draw_cube_right_center();
            draw_cube_top_center();
            draw_cube_front_center();
            draw_cube_back_center();
            draw_cube_top_left_center();
            draw_cube_top_right_center();
            draw_cube_top_front_center();
            draw_cube_top_back_center();
            draw_cube_bottom_left_center();
            draw_cube_bottom_right_center();
            draw_cube_bottom_front_center();
            draw_cube_bottom_back_center();
            draw_cube_top_left_back();
            draw_cube_top_left_front();
            draw_cube_top_right_back();
            draw_cube_top_right_front();
            draw_cube_center_left_back();
            draw_cube_center_left_front();
            draw_cube_center_right_back();
            draw_cube_center_right_front();
            draw_cube_bottom_left_back();
            draw_cube_bottom_left_front();
            draw_cube_bottom_right_back();
            draw_cube_bottom_right_front();
        break;

        // top
        case 1:
            draw_cube_center();
            draw_cube_bottom_center();
            draw_cube_left_center();
            draw_cube_right_center();
            draw_cube_front_center();
            draw_cube_back_center();
            draw_cube_bottom_left_center();
            draw_cube_bottom_right_center();
            draw_cube_bottom_front_center();
            draw_cube_bottom_back_center();
            draw_cube_center_left_back();
            draw_cube_center_left_front();
            draw_cube_center_right_back();
            draw_cube_center_right_front();
            draw_cube_bottom_left_back();
            draw_cube_bottom_left_front();
            draw_cube_bottom_right_back();
            draw_cube_bottom_right_front();

            glPushMatrix();
            glColor3fv(color[0]);
            glPopMatrix();
            glRotatef(inverse ? theta : -theta, 0.f, 1.f, 0.f);

            draw_cube_top_center();
            draw_cube_top_left_center();
            draw_cube_top_right_center();
            draw_cube_top_front_center();
            draw_cube_top_back_center();
            draw_cube_top_left_back();
            draw_cube_top_left_front();
            draw_cube_top_right_back();
            draw_cube_top_right_front();
        break;

        // bottom
        case 2:
            draw_cube_center();
            draw_cube_left_center();
            draw_cube_right_center();
            draw_cube_top_center();
            draw_cube_front_center();
            draw_cube_back_center();
            draw_cube_top_left_center();
            draw_cube_top_right_center();
            draw_cube_top_front_center();
            draw_cube_top_back_center();
            draw_cube_top_left_back();
            draw_cube_top_left_front();
            draw_cube_top_right_back();
            draw_cube_top_right_front();
            draw_cube_center_left_back();
            draw_cube_center_left_front();
            draw_cube_center_right_back();
            draw_cube_center_right_front();

            glPushMatrix();
            glColor3fv(color[0]);
            glPopMatrix();
            glRotatef(inverse ? -theta : theta, 0.f, 1.f, 0.f);

            draw_cube_bottom_center();
            draw_cube_bottom_left_center();
            draw_cube_bottom_right_center();
            draw_cube_bottom_front_center();
            draw_cube_bottom_back_center();
            draw_cube_bottom_left_back();
            draw_cube_bottom_left_front();
            draw_cube_bottom_right_back();
            draw_cube_bottom_right_front();
        break;

        // right
        case 3:
            draw_cube_center();
            draw_cube_bottom_center();
            draw_cube_left_center();
            draw_cube_top_center();
            draw_cube_front_center();
            draw_cube_back_center();
            draw_cube_top_left_center();
            draw_cube_top_front_center();
            draw_cube_top_back_center();
            draw_cube_bottom_left_center();
            draw_cube_bottom_front_center();
            draw_cube_bottom_back_center();
            draw_cube_top_left_back();
            draw_cube_top_left_front();
            draw_cube_center_left_back();
            draw_cube_center_left_front();
            draw_cube_bottom_left_back();
            draw_cube_bottom_left_front();

            glPushMatrix();
            glColor3fv(color[0]);
            glPopMatrix();
            glRotatef(inverse ? theta : -theta, 1.f, 0.f, 0.f);

            draw_cube_right_center();
            draw_cube_top_right_center();
            draw_cube_bottom_right_center();
            draw_cube_top_right_back();
            draw_cube_top_right_front();
            draw_cube_center_right_back();
            draw_cube_center_right_front();
            draw_cube_bottom_right_back();
            draw_cube_bottom_right_front();
        break;

        // left
        case 4:
            draw_cube_center();
            draw_cube_bottom_center();
            draw_cube_right_center();
            draw_cube_top_center();
            draw_cube_front_center();
            draw_cube_back_center();
            draw_cube_top_right_center();
            draw_cube_top_front_center();
            draw_cube_top_back_center();
            draw_cube_bottom_right_center();
            draw_cube_bottom_front_center();
            draw_cube_bottom_back_center();
            draw_cube_top_right_back();
            draw_cube_top_right_front();
            draw_cube_center_right_back();
            draw_cube_center_right_front();
            draw_cube_bottom_right_back();
            draw_cube_bottom_right_front();

            glPushMatrix();
            glColor3fv(color[0]);
            glPopMatrix();
            glRotatef(inverse ? -theta : theta, 1.f, 0.f, 0.f);

            draw_cube_left_center();
            draw_cube_top_left_center();
            draw_cube_bottom_left_center();
            draw_cube_top_left_back();
            draw_cube_top_left_front();
            draw_cube_center_left_back();
            draw_cube_center_left_front();
            draw_cube_bottom_left_back();
            draw_cube_bottom_left_front();
        break;

        // front
        case 5:
            draw_cube_center();
            draw_cube_bottom_center();
            draw_cube_left_center();
            draw_cube_right_center();
            draw_cube_top_center();
            draw_cube_back_center();
            draw_cube_top_left_center();
            draw_cube_top_right_center();
            draw_cube_top_back_center();
            draw_cube_bottom_left_center();
            draw_cube_bottom_right_center();
            draw_cube_bottom_back_center();
            draw_cube_top_left_back();
            draw_cube_top_right_back();
            draw_cube_center_left_back();
            draw_cube_center_right_back();
            draw_cube_bottom_left_back();
            draw_cube_bottom_right_back();

            glPushMatrix();
            glColor3fv(color[0]);
            glPopMatrix();
            glRotatef(inverse ? theta : -theta, 0.f, 0.f, 1.f);

            draw_cube_front_center();
            draw_cube_top_front_center();
            draw_cube_bottom_front_center();
            draw_cube_top_left_front();
            draw_cube_top_right_front();
            draw_cube_center_left_front();
            draw_cube_center_right_front();
            draw_cube_bottom_left_front();
            draw_cube_bottom_right_front();
        break;

        // back
        case 6:
            draw_cube_center();
            draw_cube_bottom_center();
            draw_cube_left_center();
            draw_cube_right_center();
            draw_cube_top_center();
            draw_cube_front_center();
            draw_cube_top_left_center();
            draw_cube_top_right_center();
            draw_cube_top_front_center();
            draw_cube_bottom_left_center();
            draw_cube_bottom_right_center();
            draw_cube_bottom_front_center();
            draw_cube_top_left_front();
            draw_cube_top_right_front();
            draw_cube_center_left_front();
            draw_cube_center_right_front();
            draw_cube_bottom_left_front();
            draw_cube_bottom_right_front();

            glPushMatrix();
            glColor3fv(color[0]);
            glPopMatrix();
            glRotatef(inverse ? -theta : theta, 0.f, 0.f, 1.f);

            draw_cube_back_center();
            draw_cube_top_back_center();
            draw_cube_bottom_back_center();
            draw_cube_top_left_back();
            draw_cube_top_right_back();
            draw_cube_center_left_back();
            draw_cube_center_right_back();
            draw_cube_bottom_left_back();
            draw_cube_bottom_right_back();
        break;
    }

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void reset_cube() {
    const int x = 3, y = 3;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            top[i][j] = 0;
            right[i][j] = 1;
            front[i][j] = 2;
            back[i][j] = 3;
            bottom[i][j] = 4;
            left[i][j] = 5;
        }
    }
}

void rotate_top() {
    int temp;

    temp = top[0][0];
    top[0][0] = top[2][0];
    top[2][0] = top[2][2];
    top[2][2] = top[0][2];
    top[0][2] = temp;

    temp = top[1][0];
    top[1][0] = top[2][1];
    top[2][1] = top[1][2];
    top[1][2] = top[0][1];
    top[0][1] = temp;

    int temp1 = front[0][0];
    int temp2 = front[0][1];
    int temp3 = front[0][2];

    front[0][0] = right[0][0];
    front[0][1] = right[0][1];
    front[0][2] = right[0][2];

    right[0][0] = back[0][0];
    right[0][1] = back[0][1];
    right[0][2] = back[0][2];

    back[0][0] = left[0][0];
    back[0][1] = left[0][1];
    back[0][2] = left[0][2];

    left[0][0] = temp1;
    left[0][1] = temp2;
    left[0][2] = temp3;
}

void rotate_front() {
    int temp;

    temp = front[0][0];
    front[0][0] = front[2][0];
    front[2][0] = front[2][2];
    front[2][2] = front[0][2];
    front[0][2] = temp;

    temp = front[1][0];
    front[1][0] = front[2][1];
    front[2][1] = front[1][2];
    front[1][2] = front[0][1];
    front[0][1] = temp;

    int temp1 = left[0][2];
    int temp2 = left[1][2];
    int temp3 = left[2][2];

    left[0][2] = bottom[0][0];
    left[1][2] = bottom[0][1];
    left[2][2] = bottom[0][2];

    bottom[0][0] = right[2][0];
    bottom[0][1] = right[1][0];
    bottom[0][2] = right[0][0];

    right[2][0] = top[2][2];
    right[1][0] = top[2][1];
    right[0][0] = top[2][0];

    top[2][2] = temp1;
    top[2][1] = temp2;
    top[2][0] = temp3;
}

void rotate_right() {
    int temp;

    temp = right[0][0];
    right[0][0] = right[2][0];
    right[2][0] = right[2][2];
    right[2][2] = right[0][2];
    right[0][2] = temp;

    temp = right[1][0];
    right[1][0] = right[2][1];
    right[2][1] = right[1][2];
    right[1][2] = right[0][1];
    right[0][1] = temp;

    int temp1 = top[0][2];
    int temp2 = top[1][2];
    int temp3 = top[2][2];

    top[0][2] = front[0][2];
    top[1][2] = front[1][2];
    top[2][2] = front[2][2];

    front[0][2] = bottom[0][2];
    front[1][2] = bottom[1][2];
    front[2][2] = bottom[2][2];

    bottom[0][2] = back[2][0];
    bottom[1][2] = back[1][0];
    bottom[2][2] = back[0][0];

    back[2][0] = temp1;
    back[1][0] = temp2;
    back[0][0] = temp3;
}

void rotate_left() {
    int temp;

    temp = left[0][0];
    left[0][0] = left[2][0];
    left[2][0] = left[2][2];
    left[2][2] = left[0][2];
    left[0][2] = temp;

    temp = left[1][0];
    left[1][0] = left[2][1];
    left[2][1] = left[1][2];
    left[1][2] = left[0][1];
    left[0][1] = temp;

    int temp1 = front[0][0];
    int temp2 = front[1][0];
    int temp3 = front[2][0];

    front[0][0] = top[0][0];
    front[1][0] = top[1][0];
    front[2][0] = top[2][0];

    top[0][0] = back[2][2];
    top[1][0] = back[1][2];
    top[2][0] = back[0][2];

    back[2][2] = bottom[0][0];
    back[1][2] = bottom[1][0];
    back[0][2] = bottom[2][0];

    bottom[0][0] = temp1;
    bottom[1][0] = temp2;
    bottom[2][0] = temp3;
}

void rotate_back() {
    int temp;

    temp = back[0][0];
    back[0][0] = back[2][0];
    back[2][0] = back[2][2];
    back[2][2] = back[0][2];
    back[0][2] = temp;

    temp = back[1][0];
    back[1][0] = back[2][1];
    back[2][1] = back[1][2];
    back[1][2] = back[0][1];
    back[0][1] = temp;

    int temp1 = top[0][0];
    int temp2 = top[0][1];
    int temp3 = top[0][2];

    top[0][0] = right[0][2];
    top[0][1] = right[1][2];
    top[0][2] = right[2][2];

    right[0][2] = bottom[2][2];
    right[1][2] = bottom[2][1];
    right[2][2] = bottom[2][0];

    bottom[2][2] = left[2][0];
    bottom[2][1] = left[1][0];
    bottom[2][0] = left[0][0];

    left[2][0] = temp1;
    left[1][0] = temp2;
    left[0][0] = temp3;
}

void rotate_bottom() {
    int temp;

    temp = bottom[0][0];
    bottom[0][0] = bottom[2][0];
    bottom[2][0] = bottom[2][2];
    bottom[2][2] = bottom[0][2];
    bottom[0][2] = temp;

    temp = bottom[1][0];
    bottom[1][0] = bottom[2][1];
    bottom[2][1] = bottom[1][2];
    bottom[1][2] = bottom[0][1];
    bottom[0][1] = temp;

    int temp1 = front[2][0];
    int temp2 = front[2][1];
    int temp3 = front[2][2];

    front[2][0] = left[2][0];
    front[2][1] = left[2][1];
    front[2][2] = left[2][2];

    left[2][0] = back[2][0];
    left[2][1] = back[2][1];
    left[2][2] = back[2][2];

    back[2][0] = right[2][0];
    back[2][1] = right[2][1];
    back[2][2] = right[2][2];

    right[2][0] = temp1;
    right[2][1] = temp2;
    right[2][2] = temp3;
}
