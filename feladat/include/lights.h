#ifndef LIGHTS_H
#define LIGHTS_H

#include <GL/glut.h>

void init_lights();

void set_material_box();

void set_material_character();

struct Lights
{
    GLfloat ambient;
    GLfloat green;
    GLfloat red;
    GLfloat specular;
} lights, help_lights;

void set_lights(struct Lights* lights);

void change_lights_by(struct Lights* lights, GLfloat ambient, GLfloat red, GLfloat green, GLfloat specular);

void init_lights_help(struct Lights* lights);

void set_lights_help();

void reset_lights(struct Lights* lights);

#endif // LIGHTS_H
