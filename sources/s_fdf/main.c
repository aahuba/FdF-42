/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:08:16 by ahuba             #+#    #+#             */
/*   Updated: 2018/02/27 18:45:52 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/i_fdf/fdf.h"

void	error(t_window *window, int err_type, void *err_msg)
{
	if (window)
		mlx_destroy_window(window->mlx, window->wind);
	window = create_window(window, 400, 200, "FdF_ERROR");
	fill_window(window, GREY);
	if (err_type == 1)
		mlx_string_put(window->mlx, window->wind, (200 - (ft_strlen(err_msg) * 5)),
			100, BLACK, (char *)err_msg);
	else
		mlx_string_put(window->mlx, window->wind, 80, 80, BLACK,
			"An unknown error ocurred");
	mlx_key_hook(window->wind, key_esc, (void *)0);
	mlx_loop(window->mlx);
}

int		main(int argc, char **argv)
{
	t_window	*window;

	if (argc == 2 && ft_strstr(argv[1], ".fdf"))
	{
		window = malloc(sizeof(t_window));
		// window = NULL;
		if (window == NULL)
			error(window, 1, "Some malloc error");
		window = create_window(window, W_W, W_H, "FdF");
		fill_window(window, GREY);
		mlx_key_hook(window->wind, key_esc, (void *)0);
		mlx_loop(window->mlx);
	}
	else
		ft_putstr("usage: \t ./fdf [source_file.fdf]\n");
	return (0);
}
