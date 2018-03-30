/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:38:18 by ahuba             #+#    #+#             */
/*   Updated: 2018/03/30 17:38:21 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <libft.h>
# include <fcntl.h>

# define WIDTH 1200
# define HEIGHT 1000

typedef struct		s_image
{
	void			*img;
	int				bit;
	int				size;
	int				end;
	int				image_z;
	int				x_max;
	int				y_max;
	int				z_max;
	int				rot_y;
	int				rot_x;
	int				step;
	float			angle;
	char			*str;
}					t_image;

typedef struct		s_point
{
	char			*data;
	struct s_point	*next;
	int				x;
	int				y;
	int				p_h;
	int				p_w;
}					t_point;

typedef struct		s_map
{
	int				fd;
	int				map_h;
	int				map_w;
	t_point			*rd;
	t_point			*ptr;
	char			**line;
	int				**o3d;
	t_point			**o2d;
}					t_map;

typedef struct		s_window
{
	void			*mlx;
	void			*win;
	int				w_width;
	int				w_height;
}					t_window;

typedef struct		s_env
{
	t_image			*i;
	t_point			*p;
	t_window		*w;
	t_map			*m;
	int				x1;
	int				y1;
}					t_env;

/*
** init.c
*/
t_image				*init_img(t_image *i, t_window *w);
t_image				*ft_update_img(t_image *i, t_window *w);
t_window			*start_window(t_window *w);
t_env				*init_env(t_env *all);
void				start_env(t_env *all);

/*
** parse.c
*/
t_map				*ft_parse_line(t_map *m, int h);
t_map				*ft_parse_file(t_map *m, char **av);

/*
** key.c
*/
void				ft_key_size(int key, t_env *all);
int					ft_key_catch(int key, t_env *all);

/*
** print.c
*/
void				ft_print_info(t_window *w, t_image *i);
void				ft_line(t_env *all, int x0, int y0);
void				ft_redraw(t_env *all, t_map *m, t_image *i, t_window *w);
void				ft_error(char *name, char *msg);

#endif
