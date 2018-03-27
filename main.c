
#include "minilibx_macos/mlx.h"
#include "gnl/libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>	
#include <mlx.h>

	void *mlx_ptr;
	void *win_ptr;

typedef struct		s_point
{
	char			*data;
	struct s_point	*next;

	int color;
}					t_point;

typedef struct s_dot
{
	int x, y; 

}				t_dot;

void	*img;
int 	bit;
int   	size , img_width = 1000;
int 	end;
char	*str;
int x = 500 / 2;
int y = 0;
int i = 0;
int temp = 0;
int	image_hght, image_wdth = 0;

const int width = 1000; //width of screen
int height = 1000;
int	image_height = -3;
int step = 20;
int	image_size = 50;
int map_size = width / 4; // 
int margin_x ; // смещение от левого края
int margin_y ; // от верха
int rot_y = 20; // вот новій поворот
int rot_x = 20; // градус поворота ю!

//dljay'a lohov
// int x;
	// int y;
	int x_max;
	int y_max;
	int z_max;
	int x_min;
	int y_min;
	int lw = 20;
	int		i;
	int		h;
	int		map_height; // количкство строк карті
	int		map_width; //количество колонок карті
	int		fd;
	t_point	*rd; //для считівания
	t_point	*ptr; //тоже
	char	**word; //хранит разбитую строку
	int		**map;  // rename to object3d
	t_dot 	**object2d;	

void    ft_draw_line(int x0, int y0, int x1, int y1)
{
    float t;

     t = 0.;
     while (t < 1)
     {
        x = x0 * (1.-t) + x1 * t;
		y = y0 *(1.-t) + y1 * t;
        if (x * y <= size * img_width)
        {
            temp = x * 4 + y * size;
	        str[temp] = 255;
        }
         t += 0.0001;
    }

}

void redraw()
{
    mlx_clear_window(mlx_ptr, win_ptr);
   	img = mlx_new_image(mlx_ptr, width, height);
    str = mlx_get_data_addr(img, &bit, &size, &end);
	// mlx_destroy_image(mlx_ptr, img);
	int i = 0;
	while (i < map_height)
	{
		h = 0;
		while (h < map_width)
		{
			y_max =(i * rot_y);
        	x_max =(h * rot_x);
			z_max = map[i][h] * image_height;
		// 	        x_min += width / 2 ;
        // y_min -= height / 8 / 2;
        	object2d[i][h].x = x_max - (2 * y_max) + width / 2 ;
        	object2d[i][h].y = (z_max + (1/ 2) * x_max) +  y_max + height / 4;

		// dot = dot->next;
		
			// novoe_klassnoe_nazvanie2->x =  h * lw + margin_x;
			// novoe_klassnoe_nazvanie2->y =  i * lw + margin_x;
			// 			novoe_klassnoe_nazvanie2->z =  (i+h)%2;
			// res = apply_rotation(novoe_klassnoe_nazvanie2, 0.1, 0, 0);
			// x =  x_min;
			// y = y_min;
			// //ft_draw_line(14, 1, 0,  15, 150, 0);	
			// x = h * lw + margin_x;
			// y = i * lw + margin_x;
			// if (i != map_height - 1)
			// 	ft_draw_line(i , h , 0, x, y + lw, 0);
			// if (h != map_width - 1)
			// 	ft_draw_line(i,  h, 0, x + lw, y, 0);
			if (i > 0)
				ft_draw_line(object2d[i - 1][h].x , object2d[i - 1][h].y, object2d[i][h].x, object2d[i][h].y);
			if (h > 0)
				ft_draw_line(object2d[i][h - 1].x , object2d[i][h - 1].y , object2d[i][h].x, object2d[i][h].y);
			h++;
		}
		i++;
	}	
	printf("bit: %i\tsize: %i\tend:%i\tstr: %s\n", bit, size, end, str);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, image_wdth, image_hght);  
}

int myfun(int key, void *param)
{

    printf("%d\n", key);
//	ft_putchar(&key);
	// printf("%d > ", key);
	if (key == 53) //esc
		exit(1);
	if (key == 78 ||  key == 27 || key == 12) // -
		image_height += 1;	
	if (key == 69 || key == 24 || key == 14) // +
		image_height -= 1;

	if (key == 0 && image_wdth >= 0)				// a
			image_wdth -= step;
	if (key == 2 && image_wdth <= height)				// d
			image_wdth += step;
	if (key == 13 && image_hght >= 0)			// w
			image_hght -= step;
	if (key == 1 && image_hght <= width)				// s
			image_hght += step;
	if (key == 6 && rot_x > 0 && rot_y > 0)	// z
	{
		rot_x -= 2;
		rot_y -= 2;
	}
	if (key == 7 && rot_x < width / 20 && rot_y < height / 20)	// x
	{
		rot_x += 2;
		rot_y += 2;
	}
	// if (key == 123)				//left arrow
	// 		rot_x -= 2;
	// if (key == 124)				//right arrow
	// 		rot_x += 2;
	// if (key == 126)			//up arrow
	// 		rot_y -= 2;
	// if (key == 125)				//down arrow
	// 		rot_y += 2;
	redraw();
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	map_height = 0;
	h = 0;
	rd = malloc(sizeof(rd));
	rd->next = NULL;
	ptr = rd;
	while (get_next_line(fd, &(rd->data)) > 0)
	{
		rd->next = malloc(sizeof(rd));
		rd = rd->next;
		rd->next = NULL;
		map_height++;
	}
	map = malloc(sizeof(int*) * map_height);
	object2d = malloc(sizeof(t_dot*) * map_height);
	rd = ptr;
	while (rd)
	{
		i = 0;
		word = ft_strsplit(rd->data, ' ');
		while (word[i])
			i++;
		map_width = (i == 0) ? map_width : i;
		map[h] = malloc(sizeof(int) * map_width);
		object2d[h] = malloc(sizeof(t_dot) * map_width);
		i = 0;
		while (word[i])
		{
			map[h][i] = ft_atoi(word[i]);
			i++;
		}
		h++;
		rd = rd->next;
	}
	rd = ptr;
	margin_x = (width - map_size) / 2;
	margin_y = (height - map_size) / 2;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "fdf 42");
	redraw();
	mlx_hook(win_ptr, 2, 1 , myfun, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
		
		