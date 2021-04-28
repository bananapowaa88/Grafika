#include "lights.h"

void set_lights(struct Lights* lights)
{
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    GLfloat light_position1[] = {62, 0, 20, 0};
    GLfloat light_position2[] = {-62, 0, 20, 0};
    GLfloat light_direction1[] = {0, 0, -1, 0};
    GLfloat light_direction2[] = {0, 0, 1, 0};
    GLfloat ambient_light_color[] = {lights->ambient, lights->ambient, lights->ambient, 1};
    GLfloat diffuse_light_color[] = {0.0, 0.0, 0.0, 1};
    GLfloat specular_light_color[] = {0.0, 0.0, 0.0, 1};

    GLfloat a1[] = {0.0, 0.0, 0.0, 1};
    GLfloat d1[] = {0.0, 0.0, lights->blue, 1};
    GLfloat s1[] = {lights->specular, lights->specular, lights->specular, 1};

    GLfloat a2[] = {0.0, 0.0, 0.0, 1};
    GLfloat d2[] = {lights->red, 0.0, 0.0, 1};
    GLfloat s2[] = {lights->specular, lights->specular, lights->specular, 1};    
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light_color);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light_color);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light_color);
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, a1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, d1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, s1);
    
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_direction1);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 40);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.3);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.01);

    glLightfv(GL_LIGHT2, GL_AMBIENT, a2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, d2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, s2);
    
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_direction2);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 40);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
    glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.3);
    glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01);
    
    
}

void set_lights_help(struct Lights* lights)
{
    GLfloat a[] = {lights->ambient, lights->ambient, lights->ambient, 1};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
}


void change_lights_by(struct Lights* lights, GLfloat ambient, GLfloat red, GLfloat blue, GLfloat specular)
{
    lights->ambient += ambient;
    lights->red += red;
    lights->blue += blue;
    lights->specular += specular;
    float min = -0.1;
    if (lights->ambient < min) lights->ambient = min;
    if (lights->red < min) lights->red = min;
    if (lights->blue < min) lights->blue = min;
    if (lights->specular < min) lights->specular = min;
    if (lights->ambient > 1.0) lights->ambient = 1.0;
    if (lights->red > 1.0) lights->red = 1.0;
    if (lights->blue > 1.0) lights->blue = 1.0;
    if (lights->specular > 1.0) lights->specular = 1.0;
}

void init_lights_help(struct Lights* lights)
{
    GLfloat a[] = {-0.15, -0.15, -0.15, 1};
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, a);
    glLightfv(GL_LIGHT0, GL_SPECULAR, a);

    lights->ambient = -0.15;
    lights->red = 0;
    lights->blue = 0;
}

void init_lights(struct Lights* lights)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    lights->ambient = 0.3;
    lights->red = 1.0;
    lights->blue = 1.0;
    lights->specular = 0.2;
}

void reset_lights(struct Lights* lights)
{
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    lights->ambient = -0.1;
    lights->red = 0.0;
    lights->blue = 0.0;
    lights->specular = 0.0;

}

void set_material_box()
{
    float amb[] = {0.3, 0.3, 0.3};
    float diff[] = {0.6, 0.6, 0.6};
    float spec[] = {0.1, 0.1, 0.1};
    float emis[] = {0.0, 0.0, 0.0, 0.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION ,emis);
}

void set_material_character()
{
    float emis[] = {0.0, 0.0, 0.0, 0.0};
    
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION ,emis);
}

void set_material_sky()
{
    float amb[] = {0.9, 0.9, 0.9};
    float diff[] = {0.9, 0.9, 0.9};
    float spec[] = {0.0, 0.0, 0.0};
    float emis[] = {0.0, 0.0, 0.0, 0.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION ,emis);
}


