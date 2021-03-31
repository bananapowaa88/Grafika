#include "brick.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Brick brick;
	double volume;
	double surface;
	int isItCube;
	
		/**
		 * Call the functions, set the size of the object, calculate volume, surface and check if it's a Cube 
		 **/
	set_size(&brick, 1, 5, 10);
	volume = calc_volume(&brick);
	surface = calc_surface(&brick);
	isItCube = isObjCube(&brick);
	
	printf("Brick volume: %lf\n", volume);
	printf("Brick surface: %lf\n", surface);


	/**
	 * I use an integer instead of boolean, because of C language.
	 **/
	printf("Is this object a cube?\n");
	if(isItCube)
	{
		printf("Yes, it's a cube.\n");
	}	else
		{
			printf("Nope, it's not a cube.\n");
		}
	
	return 0;
}
