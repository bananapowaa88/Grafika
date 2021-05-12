#include "camera.h"

#define CAMERA_DISTANCE 9

void init_camera(struct Camera* camera)
{
    camera->position.x = 0;
    camera->position.y = 0;
    camera->position.z = 6;

    camera->pose.x = 0;
    camera->pose.y = 0;
    camera->pose.z = 0;
}

void set_camera_speed(struct Camera* camera, double speed)
{
    camera->pose.y = speed;
}

void set_camera_side_speed(struct Camera* camera, double speed)
{
    camera->pose.x = speed;
}

void set_camera_on_character(struct Camera* camera, struct Character* character)
{
    camera->position.x = character->pos.x -
                    sin(degree_to_radian(character->face))*CAMERA_DISTANCE;
    camera->position.y = character->pos.y +
                    cos(degree_to_radian(character->face))*CAMERA_DISTANCE;
    camera->position.z = character->pos.z + 6 - 5*(camera->pose.x/(double)VERTICAL_MAX_DEGREE);

    camera->pose.z = character->face - 90;
}

void set_view_point(const struct Camera* camera)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(-(camera->pose.x + 90), 1.0, 0, 0);
	glRotatef(-(camera->pose.z - 90), 0, 0, 1.0);
	glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

void rotate_camera(struct Camera* camera, double vertical)
{
	if (camera->pose.x + vertical < VERTICAL_MAX_DEGREE)
	{
	    if (camera->pose.x + vertical > -1*VERTICAL_MAX_DEGREE)
	    {
	        camera->pose.x += vertical;
        }
        else
        {
            camera->pose.x = -1*VERTICAL_MAX_DEGREE; 
        }
    }
    else
    {
        camera->pose.x = VERTICAL_MAX_DEGREE;
    }
    
}

double normalize_number_to_one(double number, double max)
{
    return number/max;
}

