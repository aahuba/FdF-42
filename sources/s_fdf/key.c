/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:30:08 by ahuba             #+#    #+#             */
/*   Updated: 2018/03/30 17:30:11 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_key_size(int key, t_env *all)
{
	if (key == 6 && all->i->rot_x >= 4 && all->i->rot_y >= 4)
	{
		all->i->rot_x -= 2;
		all->i->rot_y -= 2;
	}
	if (key == 7)
	{
		all->i->rot_x += 2;
		all->i->rot_y += 2;
	}
	if (key == 15)
	{
		all->i->image_z = -3;
		all->p->p_w = 0;
		all->p->p_h = 0;
		all->i->rot_x = 10;
		all->i->rot_y = 10;
	}
}

int		ft_key_catch(int key, t_env *all)
{
	if (key == 53)
		exit(1);
	if (key == 78 || key == 27 || key == 12)
		all->i->image_z += 1;
	if (key == 69 || key == 24 || key == 14)
		all->i->image_z -= 1;
	if (key == 0 || key == 123)
		all->p->p_w -= all->i->step;
	if (key == 2 || key == 124)
		all->p->p_w += all->i->step;
	if (key == 13 || key == 126)
		all->p->p_h -= all->i->step;
	if (key == 1 || key == 125)
		all->p->p_h += all->i->step;
	ft_key_size(key, all);
	ft_redraw(all, all->m, all->i, all->w);
	return (0);
}
