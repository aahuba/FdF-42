/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:29:33 by ahuba             #+#    #+#             */
/*   Updated: 2018/03/30 17:29:41 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			main(int ac, char **av)
{
	t_env	*all;

	all = NULL;
	if (ac == 2 && ft_strstr(av[0], "/fdf") && ft_strstr(av[1], ".fdf"))
	{
		if ((all = init_env(all)) == NULL)
			ft_error(av[0], "ENV INIT error");
		if ((all->m = ft_parse_file(all->m, av)) == NULL)
			ft_error(av[1], "<-INVALID MAP");
		start_env(all);
		return (0);
	}
	else
		ft_error("usage", "./fdf [map_name.fdf]");
	return (1);
}
