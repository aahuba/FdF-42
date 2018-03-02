/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:00:44 by ahuba             #+#    #+#             */
/*   Updated: 2018/02/28 16:00:46 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "fdf.h"
#include "../i_libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# define GREY 0xEEEEEE
# define BLACK 0x222222
# define W_W 1280
# define W_H 720

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
	double			s;
	int				pcol;
}				t_point;

typedef struct  s_window
{
	void		*mlx;
    void        *wind;
	char		*title;
	int			width;
	int			height;
}               t_window;

/*
**	window.c
*/
void			fill_window(t_window *window, int color);
t_window		*create_window(t_window *window, int width, int height, char *title);

/*
**	key.c
*/
int				key_esc(int key, void *param);

/*
**	read_map.c
*/

/*
**	draw.c
*/
int				put_pixel(t_var *v, int color, int type);
void			draw_line(t_var *v, int x, int y, int type);
void			mlx_draw(t_var *v, int x, int y);

#endif
