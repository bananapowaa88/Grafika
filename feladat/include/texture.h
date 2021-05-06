#ifndef TEXTURE_H
#define TEXTURE_H

#include <SOIL/SOIL.h>
#include <GL/glut.h>

typedef GLubyte Pixel[3];

struct ball_textures
{
    GLuint cloudy_sky;
} ball_texture;

struct box_textures
{
    GLuint grass;
    GLuint brick;
    GLuint wood;
} box_texture;

struct character_textures
{
    GLuint skin;
    GLuint white_cloth;
    GLuint red_cloth;
    GLuint plain_black;
    GLuint plain_white;
    
} character_texture;

GLuint help_texture;

GLuint load_texture(char* filename);

void init_textures();


#endif // TEXTURE_H
