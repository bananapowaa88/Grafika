#ifndef CAMERA_H
#define CAMERA_H

#include "model.h"
#include "utils.h"
#include "character.h"
#include <GL/glut.h>
#include <math.h>

struct Camera
{
	struct Vertex position;
	struct Vertex pose;
};

void set_camera_on_character(struct Camera* camera, struct Character* character);

void init_camera(struct Camera* camera);

void set_view_point(const struct Camera* camera);

void rotate_camera(struct Camera* camera, double vertical);

#endif // CAMERA_H

