#include "brick.h"

#include "math.h"


/**
 * Function to set the size of the object 
 **/
double set_size(Brick* brick, double a, double b, double c)
{
	brick->a = a;
	brick->b = b;
	brick->c = c;
}

/**
 * Function to calculate the volume of the object 
 **/
double calc_volume(const Brick* brick)
{
	double volume = brick->a * brick->b * brick->c;
	return volume;
}

/**
 * Function to calculate the surface of the object 
 **/
double calc_surface(const Brick* brick)
{
	double surface = 2 * brick->a * brick->b + 2 * brick->b * brick->c + 2 * brick->c * brick->a;
	return surface;
}

/**
 * Function to check if the object's all edges are the same, so it's a Cube 
 **/
int isObjCube(const Brick* brick)
{
	int boolean;
	if(brick->a == brick->b && brick->b == brick->c){
		boolean = 1;
	}	else {
		boolean = 0;
	}
	return boolean;
	
}
