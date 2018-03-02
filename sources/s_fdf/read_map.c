
#include "../../includes/i_fdf/fdf.h"

t_point     *new_point(int x, int y, int z)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

