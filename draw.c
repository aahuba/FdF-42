
#include "../../includes/i_fdf/fdf.h"

typedef struct	s_var
{
	void		*img;
	void		*mlx;
	void		*win;
	char		**fls;
	char		*fln;
	char		*nam;
	char		*lgr;
	char		*c;
	char		*d;
	char		*s;
	int			****tab;
	int			**mov;
	int			**val;
	int			*clr;
	int			*dlr;
	int			*rtx;
	int			*rty;
	int			*rtz;
	int			*zmv;
	int			*zom;
	int			add;
	int			bpp;
	int			end;
	int			lns;
	int			nbr;
	int			wth;
	int			max;
	int			len;
	int			inv;
	int			sl;
	int			p;
	int			y;
	int			x;
}				t_var;

int		put_pixel(t_var *v, int color, int type)
{
	int		i;
	int		x;
	int		y;
	char	*rgb;

	x = v->x;
	y = v->y;
	if (type == 1)
	{
		x = v->tab[v->p][v->y][v->x][0] + v->mov[v->p][0];
		y = v->tab[v->p][v->y][v->x][1] + v->mov[v->p][1];
	}
	if (((type == 1 && x > 213) || (type != 1 && x >= 0))
	&& x < WIN_W && y >= 0 && y < WIN_H)
	{
		i = ((int)v->x * (v->bpp / 8)) + ((int)v->y * v->sl);
		rgb = (char*)&color;
		v->d[i] = rgb[0];
		v->d[++i] = rgb[1];
		v->d[++i] = rgb[2];
	}
	return (0);
}

void	draw_line(t_var *v, int x, int y, int type)
{
	double	tx;
	double	dist_x;
	double	dist_y;

	tx = 0.0;
	dist_x = v->tab[v->p][y][x + 1][0] - v->tab[v->p][y][x][0];
	dist_y = v->tab[v->p][y][x + 1][1] - v->tab[v->p][y][x][1];
	if (type == 1)
	{
		dist_x = v->tab[v->p][y + 1][x][0] - v->tab[v->p][y][x][0];
		dist_y = v->tab[v->p][y + 1][x][1] - v->tab[v->p][y][x][1];
	}
	while (tx <= 1)
	{
		v->x = v->tab[v->p][y][x][0] + (dist_x * tx) + v->mov[v->p][0];
		v->y = v->tab[v->p][y][x][1] + (dist_y * tx) + v->mov[v->p][1];
		put_pixel(v, face_color(v), 0);
		tx += 1. / sqrt((dist_x * dist_x) + (dist_y * dist_y));
	}
}

void	mlx_draw(t_var *v, int x, int y)
{
	int tmp1;
	int tmp2;

	tmp1 = v->x;
	tmp2 = v->y;
	while (v->x <= x && put_pixel(v, UI_COLOR, 0) == 0)
		v->x++;
	while (v->y <= y && put_pixel(v, UI_COLOR, 0) == 0)
		v->y++;
	while (v->x >= tmp1 && put_pixel(v, UI_COLOR, 0) == 0)
		v->x--;
	while (v->y >= tmp2 && put_pixel(v, UI_COLOR, 0) == 0)
		v->y--;
}
