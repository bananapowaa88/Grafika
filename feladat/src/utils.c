#include "utils.h"

double degree_to_radian(double degree)
{
  return degree * M_PI / 180.0;
}

double sign(double number)
{
  if (number > 0){ return 1;}
  else if (number < 0) { return -1;}
  return 0;
}

double absolute_value(double number)
{
  if (number > 0) return number;
  return -1*number;
}

double vector_length(struct Vector v)
{
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

double vector_length_squared(struct Vector v)
{
    return v.x*v.x + v.y*v.y + v.z*v.z;
}

double point_distance(struct Point a, struct Point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z) );
}

double point_distance_squared(struct Point a, struct Point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}

double clamp(double value, double min, double max)
{
    if(value < min)
    {
        return min;
    } else if (value > max)
    {
        return max;
    }
    return value;
}

double DotProduct(struct Vector v1, struct Vector v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

double vectors_are_equal(struct Vector v1, struct Vector v2)
{
    return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v1.z);
}

void multipy_by_scalar(struct Vector* v, double c)
{
    v->x *=c;
    v->y *=c;
    v->z *=c;
}