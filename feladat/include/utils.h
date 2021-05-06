#ifndef UTILS_H
#define UTILS_H

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

struct Point
{
  double x;
  double y;
  double z;
};

struct Vector
{
  double x;
  double y;
  double z;  
};

typedef enum {FLYING, ROLLING, STOPPED, HELD} object_state_type;

typedef enum {ELEMENT ,HEAD} linked_list_element_type;

struct Color {
	GLfloat r,g,b,a;
};

double degree_to_radian(double degree);

double absolute_value(double number);

double sign(double number);

double vector_length(struct Vector v);

double vector_length_squared(struct Vector v);

double point_distance(struct Point a, struct Point b);

double point_distance_squared(struct Point a, struct Point b);

double clamp(double value, double min, double max);

double DotProduct(struct Vector v1, struct Vector v2);

double vectors_are_equal(struct Vector v1, struct Vector v2);

void multipy_by_scalar(struct Vector* v, double c);

#endif /* UTILS_H */

