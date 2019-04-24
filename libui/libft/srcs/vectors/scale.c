#include "vectors.h"

t_vec2	scale_v2(double a, t_vec2 b)
{
	return ((t_vec2){b.x * a, b.y * a});
}

t_vec3	scale_v3(double a, t_vec3 b)
{
	return ((t_vec3){b.x * a, b.y * a, b.z * a});
}
