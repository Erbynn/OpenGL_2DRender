/*
INDEX: PS/CSC/15/0006
NAME: JOHN KWESI ERBYNN
DATE: 21st December, 2018
COMPUTER GRAPHICS ASSIGNMENT

OpenGL - Rendering Rectangle

TANSFORMATIONS
Shearing 2 points to right
Rotating by 45 degrees clockwise
Scaling by 3

NB: Please add these linkers - glew32, freeglut, opengl32
to run this in different file
    right click on cdb file
    select build options...
    linker settings....add glew32, freeglut, opengl32 these files
*/

#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>



// FUNCTION FOR RECTANGLE
static void draw_rectangle(){   // original triangle
    glBegin(GL_QUADS);
        glVertex2f(0.2f, 0.1f);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(0.2f, -0.2f);
    glEnd();
}

static void draw_shear_rectangle(){ // sheared triangle
    glBegin(GL_QUADS);
        glVertex2f(0.2f + 0.3, 0.1f);
        glVertex2f(-0.2 + 0.3f, 0.1f);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(0.2f, -0.2f);
    glEnd();
}




static void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // enabling blending
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //DRAWING TRIANGLE
    glLoadIdentity();
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    draw_rectangle();

    // Shearing
    glColor4f(0.0f, 0.0f, 1.0f, 0.9f);
    draw_shear_rectangle();

    // rotating by 45 degrees clockwise
    glColor4f(0.0f, 0.9f, 0.0f, 0.8f);
    glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
    draw_shear_rectangle();
    // scaling by 3 points
    glScalef(3.0f, 3.0f, 0.0f);
    glColor4f(0.9f, 0.0f, 0.0f, 0.5f);
    draw_shear_rectangle();

    glutSwapBuffers();
}




int main(int argc, char **argv){    // for command input
    // initialize the GLUT library
    glutInit(&argc, argv);
    //  sets the initial display mode
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Drawing Primitives");
    // set the initial window size
    glutInitWindowSize(500, 500);
    // set the initial window size
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);
    // background of glut window
    glClearColor(0.0, 0.0, 0.0, 0.1);
    // start the main loop all program
    glutMainLoop();

    return 0;
}

