/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:29:52 by ahuba             #+#    #+#             */
/*   Updated: 2018/03/30 17:29:57 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_image		*init_img(t_image *i, t_window *w)
{
	if ((i = (t_image *)ft_memalloc(sizeof(t_image))))
	{
		i->img = mlx_new_image(w->mlx, w->w_width, w->w_height);
		i->rot_y = 10;
		i->rot_x = 10;
		i->image_z = -3;
		i->step = 30;
		i->str = mlx_get_data_addr(i->img, &(i->bit), &(i->size), &(i->end));
	}
	return (i);
}

t_image		*ft_update_img(t_image *i, t_window *w)
{
	mlx_clear_window(w->mlx, w->win);
	i->img = mlx_new_image(w->mlx, w->w_width, w->w_height);
	i->str = mlx_get_data_addr(i->img, &(i->bit), &(i->size), &(i->end));
	if (i == NULL)
		ft_error("fdf", "Can`t update image");
	return (i);
}

t_window	*start_window(t_window *w)
{
	if ((w = (t_window *)ft_memalloc(sizeof(t_window))))
	{
		w->w_height = HEIGHT;
		w->w_width = WIDTH;
		w->mlx = mlx_init();
		w->win = mlx_new_window(w->mlx, w->w_width, w->w_height, "FDF_42");
	}
	return (w);
}

t_env		*init_env(t_env *all)
{
	if ((all = (t_env *)ft_memalloc(sizeof(t_env))))
	{
		all->i = NULL;
		all->p = NULL;
		all->w = NULL;
		all->m = NULL;
	}
	return (all);
}

void		start_env(t_env *all)
{
	all->w = start_window(all->w);
	if ((all->i = init_img(all->i, all->w)) == NULL)
		ft_error("fdf", "Can`t INIT IMAGE");
	ft_redraw(all, all->m, all->i, all->w);
	mlx_hook(all->w->win, 2, 0, ft_key_catch, all);
	mlx_loop(all->w->mlx);
}
