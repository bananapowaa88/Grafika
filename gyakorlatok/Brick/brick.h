#ifndef BRICK_H
#define BRICK_H

/**
 * Data of brick's a, b and c edges
 */
typedef struct Brick
{
	double a;
	double b;
	double c;
} Brick;

/**
 * Set the data of the brick
 */
double set_size(Brick* brick, double a, double b, double c);

/**
 * Calculate the area of the circle.
 */
double calc_volume(const Brick* brick);

double calc_surface(const Brick* brick);

int isObjCube(const Brick* brick);

#endif // BRICK_H
