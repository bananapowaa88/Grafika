#include "texture.h"

GLuint load_texture(char* filename)
{
    Pixel* image;
    GLuint texture_name;
    glGenTextures(1, &texture_name);

    int width;
    int height;

    image = (Pixel*)SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGB);

    glBindTexture(GL_TEXTURE_2D, texture_name);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (Pixel*)image);    
    
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

    return texture_name;
}

void init_textures()
{
    box_texture.brick = load_texture("data/img/brick.png");
    box_texture.grass = load_texture("data/img/grass.png");
    character_texture.skin = load_texture("data/img/skin.png");
    character_texture.white_cloth = load_texture("data/img/white_cloth.png");
    character_texture.red_cloth = load_texture("data/img/red_cloth.png");
    character_texture.plain_black = load_texture("data/img/plain_black.png");
    character_texture.plain_white = load_texture("data/img/plain_white.png");
    ball_texture.cloudy_sky = load_texture("data/img/clsky.png");
    help_texture = load_texture("data/img/F1_HELP.jpg");
    
    glEnable(GL_TEXTURE_2D);
}
