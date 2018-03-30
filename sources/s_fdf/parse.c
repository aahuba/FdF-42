/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:30:18 by ahuba             #+#    #+#             */
/*   Updated: 2018/03/30 17:30:48 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_map		*ft_parse_line(t_map *m, int h)
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

t_map		*ft_parse_file(t_map *m, char **av)
{
	int		h;

	if ((m = (t_map *)ft_memalloc(sizeof(t_map))))
	{
		if ((m->fd = open(av[1], O_RDONLY)) == -1)
			return (0);
		h = 0;
		m->rd = malloc(sizeof(m->rd));
		m->rd->next = NULL;
		m->ptr = m->rd;
		while (ft_get_next_line(m->fd, &(m->rd->data)) > 0)
		{
			m->rd->next = malloc(sizeof(m->rd));
			m->rd = m->rd->next;
			m->rd->next = NULL;
			m->map_h++;
		}
		m = ft_parse_line(m, h);
		m->rd = m->ptr;
	}
	return (m);
}
