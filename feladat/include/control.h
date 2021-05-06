#ifndef CONTROL_H
#define CONTROL_H

#include "camera.h"
#include "character.h"
#include <GL/glut.h>
#include "lights.h"

struct Camera camera;

struct Action
{
    int move_forward;
    int move_backward;
    int turn_left;
    int turn_right;
    int throw_start;
    int throw_end;
};

typedef enum {ALL, AMBIENT, RED, GREEN, SPECULAR} light_setting_type;
typedef enum {RUN, TURN_TO_HELP, HELP, TURN_FROM_HELP} game_mode_type;
game_mode_type game_mode;

void key_handler(unsigned char key, int x, int y);

void key_up_handler(unsigned char key, int x, int y);

void motion_handler(int x, int y);

void mouse_handler(int button, int state, int x, int y);

void f1_handler(int key, int x, int y);

void update_player_character(struct Character* character);



#endif // CONTROL_H
