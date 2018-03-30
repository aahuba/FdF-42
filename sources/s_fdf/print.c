/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:30:58 by ahuba             #+#    #+#             */
/*   Updated: 2018/03/30 17:31:04 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_error(char *name, char *msg)
{
	ft_putstr(name);
	ft_putstr(": ");
	ft_putendl(msg);
	exit(1);
}

void		ft_print_info(t_window *w, t_image *i)
{
	mlx_put_image_to_window(w->mlx, w->win, i->img, 0, 0);
	mlx_string_put(w->mlx, w->win, 20, 20, 0xFFFFFF, "Arrows or WASD to move");
	mlx_string_put(w->mlx, w->win, 20, 40, 0xFFFFFF, "ZX to zoom");
	mlx_string_put(w->mlx, w->win, 20, 60, 0xFFFFFF, "+/- or QE to height");
	mlx_string_put(w->mlx, w->win, 20, 80, 0xFFFFFF, "ESC to quit");
	mlx_string_put(w->mlx, w->win, 20, 100, 0xFFFFFF, "R to reset");
}

void		ft_line(t_env *all, int x0, int y0)
{
	float	t;
	int		x;
	int		y;
	int		temp;

	t = 0.;
	if (all->p == NULL)
		all->p = (t_point *)ft_memalloc(sizeof(t_point));
	while (t < 1)
	{
		x = (x0 * (1. - t) + all->x1 * t) + all->p->p_w;
		y = (y0 * (1. - t) + all->y1 * t) + all->p->p_h;
		if (x < 0 || x >= all->w->w_width || y < 0 || y >= all->w->w_height)
			return ;
		temp = x * 4 + y * all->i->size;
		all->i->str[temp] = (char)255;
		t += 0.01;
	}
}

void		ft_redraw(t_env *all, t_map *m, t_image *i, t_window *w)
{
	int		j;
	int		h;

	i = ft_update_img(i, w);
	j = -1;
	while (++j < m->map_h)
	{
		h = -1;
		while (++h < m->map_w)
		{
			i->y_max = (j * i->rot_y);
			i->x_max = (h * i->rot_x);
			i->z_max = m->o3d[j][h] * i->image_z;
			m->o2d[j][h].x = i->x_max - (i->y_max) + w->w_width / 4;
			m->o2d[j][h].y = (i->z_max + (1 / 2) * i->x_max)
			+ i->y_max + w->w_height / 4;
			all->x1 = m->o2d[j][h].x;
			all->y1 = m->o2d[j][h].y;
			if (j > 0)
				ft_line(all, m->o2d[j - 1][h].x, m->o2d[j - 1][h].y);
			if (h > 0)
				ft_line(all, m->o2d[j][h - 1].x, m->o2d[j][h - 1].y);
		}
	}
	ft_print_info(w, i);
}
