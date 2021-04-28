#include "control.h"

#define TURN_SPEED 4.0
#define LIGHT_STEP 0.05

struct Action action;
light_setting_type light_setting;
int mouse_x, mouse_y;

void update_player_character(struct Character* character)
{
    if(action.move_forward == TRUE)
    { character->speed = NORMAL_SPEED; }
    else
    { character->speed = STOP_SPEED;
        if(action.move_backward == TRUE)
        { character->speed = -1*NORMAL_SPEED; }
        else
        { character->speed = STOP_SPEED; }
    }
    
    if(action.turn_left == TRUE)
    { character->face += TURN_SPEED; }
    if(action.turn_right == TRUE)
    { character->face -= TURN_SPEED; }
    

}

void mouse_handler(int button, int state, int x, int y)
{
	mouse_x = x;
	mouse_y = y;
}

void motion_handler(int x, int y)
{
	double vertical;

	vertical = mouse_y - y;

	rotate_camera(&camera, vertical);

	mouse_x = x;
	mouse_y = y;

    glutPostRedisplay();
}

void key_handler(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
        action.move_forward = TRUE;
		break;
	case 's':
        action.move_backward = TRUE;
		break;
	case 'a':
        action.turn_left = TRUE;
		break;
	case 'd':
        action.turn_right = TRUE;
		break;
        
    case 'z':
        light_setting = ALL;
        break;
    case 'u':
        light_setting = AMBIENT;
        break;
    case 'i':
        light_setting = RED;
        break;
    case 'o':
        light_setting = BLUE;
        break;
    case 'p':
        light_setting = SPECULAR;
        break;
            
    case '+':
        switch (light_setting)
        {
            case ALL:
                change_lights_by(&lights,LIGHT_STEP,LIGHT_STEP,LIGHT_STEP,LIGHT_STEP);
                break;
            case AMBIENT:
                change_lights_by(&lights,LIGHT_STEP,0,0,0);
                break;
            case RED:
                change_lights_by(&lights,0,LIGHT_STEP,0,0);
                break;
            case BLUE:
                change_lights_by(&lights,0,0,LIGHT_STEP,0);
                break;
            case SPECULAR:
                change_lights_by(&lights,0,0,0,LIGHT_STEP);
                break;
        }
        
        break;
    case '-':
        switch (light_setting)
        {
            case ALL:
                change_lights_by(&lights,-1*LIGHT_STEP,-1*LIGHT_STEP,-1*LIGHT_STEP, -1*LIGHT_STEP);
                break;
            case AMBIENT:
                change_lights_by(&lights,-1*LIGHT_STEP,0,0,0);
                break;
            case RED:
                change_lights_by(&lights,0,-1*LIGHT_STEP,0,0);
                break;
            case BLUE:
                change_lights_by(&lights,0,0,-1*LIGHT_STEP,0);
                break;
            case SPECULAR:
                change_lights_by(&lights,0,0,0,-1*LIGHT_STEP);
                break;
        }
        
        break;
    case 27:
        if (game_mode == HELP){
            game_mode = TURN_FROM_HELP;
        }
        break;

        		
	}
	

	glutPostRedisplay();
}

void f1_handler(int key, int x, int y)
{
    switch (key) {
	case GLUT_KEY_F1:
        if (game_mode == RUN){
            game_mode = TURN_TO_HELP;
        }
		break;
	}
    
}

void key_up_handler(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
        action.move_forward = FALSE;
		break;
	case 's':
        action.move_backward = FALSE;
		break;
	case 'a':
        action.turn_left = FALSE;
		break;
	case 'd':
        action.turn_right = FALSE;
		break;
	case ' ':
        action.throw_start = FALSE;
        break;
	}

	glutPostRedisplay();
}
