
#include "minilibx_macos/mlx.h"
#include "gnl/libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>

#define WIDTH 1500
#define HEIGHT 1000

typedef struct	s_image
{
	void	*img;
	int		bit;
	int		size;
	int		end;
	int		image_z;
	int		x_max;
	int		y_max;
	int		z_max;
	int		pos_h; // image position - height
	int		pos_w; // image position - width
	int		rot_y; // градус поворота!
	int		rot_x; // вот новій поворот
	int		step;
	char	*str;
}				t_image;

typedef struct	s_point
{
	char			*data;
	struct s_point	*next;
	int				x;
	int				y;
	int				color;
	int				p_h;
	int				p_w;
}				t_point;

typedef struct	s_map
{
	int		fd;
	int		map_h; // количкство строк карті
	int		map_w; //количество колонок карті
	t_point	*rd; //для считівания
	t_point	*ptr; //тоже
	char	**line; //хранит разбитую строку
	int		**o3d; // obj3d
	t_point	**o2d; // obj2d
}				t_map;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	int			w_width;
	int			w_height;
}				t_window;

typedef struct	s_env
{
	t_image		*i; // image
	t_point		*p; // point
	t_window	*w; // window
	t_map		*m; // map
	int			x1;
	int			y1;
}				t_env;

void		error(char *name, char *msg)
{
	if (msg == NULL)
		msg = "Unrecognized error, mudak tupoy";
	printf("%s: %s\n", name, msg);
	exit(1);
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
		error("fdf", "CHOT NE MOGU INITNUT`SA");
	return (i);
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
			m->o2d[j][h].x = i->x_max - (2 * i->y_max) + w->w_width / 4;
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
	mlx_put_image_to_window(w->mlx, w->win, i->img, i->pos_w, i->pos_h);
}

int		key_catch(int key, t_env *all)
{
	if (key == 53) //esc
		exit(1);
	if (key == 78 || key == 27 || key == 12) // - q
		all->i->image_z += 1;
	if (key == 69 || key == 24 || key == 14) // + e
		all->i->image_z -= 1;
	if (key == 0 || key == 123) // a
		all->p->p_w -= all->i->step;
	if (key == 2 || key == 124) // d
		all->p->p_w += all->i->step;
	if (key == 13 || key == 126) // w
		all->p->p_h -= all->i->step;
	if (key == 1 || key == 125) // s
		all->p->p_h += all->i->step;
	if (key == 6 && all->i->rot_x >= 4 && all->i->rot_y >= 4) // z
	{
		all->i->rot_x -= 2;
		all->i->rot_y -= 2;
	}
	if (key == 7) // x
	{
		all->i->rot_x += 2;
		all->i->rot_y += 2;
	}
	ft_redraw(all, all->m, all->i, all->w);
	return (0);
}

t_window	*start_window(t_window *w)
{
	if ((w = (t_window *)ft_memalloc(sizeof(t_window))))
	{
		w->w_height = HEIGHT;
		w->w_width = WIDTH;
		w->mlx = mlx_init();
		w->win = mlx_new_window(w->mlx, w->w_width, w->w_height, "fdf 42");
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

t_map		*ft_count_l(t_map *m, int h)
{
	int		i;

	m->o3d = malloc(sizeof(int *) * m->map_h * 10);
	m->o2d = malloc(sizeof(t_point *) * m->map_h * 10);
	m->rd = m->ptr;
	while (m->rd)
	{
		i = 0;
		m->line = ft_strsplit(m->rd->data, ' ');
		while (m->line[i])
			i++;
		m->map_w = (i == 0) ? m->map_w : i;
		m->o3d[h] = malloc(sizeof(int) * m->map_w);
		m->o2d[h] = malloc(sizeof(t_point) * m->map_w);
		i = 0;
		while (m->line[i])
		{
			m->o3d[h][i] = ft_atoi(m->line[i]);
			i++;
		}
		h++;
		m->rd = m->rd->next;
	}
	return (m);
}

t_map		*parse_file(t_map *m, char **av)
{
	int		h;

	if ((m = (t_map *)ft_memalloc(sizeof(t_map))))
	{
		if ((m->fd = open(av[1], O_RDONLY)) == -1)
			return (0);
		m->map_h = 0;
		h = 0;
		m->rd = malloc(sizeof(m->rd));
		m->rd->next = NULL;
		m->ptr = m->rd;
		while (get_next_line(m->fd, &(m->rd->data)) > 0)
		{
			m->rd->next = malloc(sizeof(m->rd));
			m->rd = m->rd->next;
			m->rd->next = NULL;
			m->map_h++;
		}
		m = ft_count_l(m, h);
		m->rd = m->ptr;
	}
	return (m);
}

void		start_env(t_env *all)
{
	all->w = start_window(all->w);
	if ((all->i = init_img(all->i, all->w)) == NULL)
		error("fdf", "DAZHE NE MOZHESH INIT IMAGE, DEBIL");
	ft_redraw(all, all->m, all->i, all->w);
	mlx_hook(all->w->win, 2, 0, key_catch, all);
	mlx_loop(all->w->mlx);
}

int			main(int ac, char **av)
{
	t_env	*all;

	all = NULL;
	if (ac == 2)
	{
		if ((all = init_env(all)) == NULL)
			error(av[0], "TVOI ENV NE PASHET VASHE");
		if ((all->m = parse_file(all->m, av)) == NULL)
			error(av[1], "<-Invalid map and INVALID TY");
		start_env(all);
		return (0);
	}
	else
		printf("\n!!!USAGE SMATRI LALKA!!!\n\n");
	return (1);
}
