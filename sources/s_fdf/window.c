/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:59:51 by ahuba             #+#    #+#             */
/*   Updated: 2018/02/28 15:59:54 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/i_fdf/fdf.h"

t_window	*create_window(t_window *window, int width, int height, char *title)
{
	window = malloc(sizeof(t_window));
	if (window == NULL)
		exit(1);
	window->mlx = mlx_init();
	window->title = title;
	window->width = width;
	window->height = height;
	window->wind = mlx_new_window(window->mlx, 
									   window->width, 
									   window->height,
									   window->title);
   return (window);
}

void	fill_window(t_window *window, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			mlx_pixel_put(window->mlx, window->wind, x, y, color);
			x++;
		}
		y++;
	}
}
