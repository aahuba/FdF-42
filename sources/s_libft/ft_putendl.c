/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:39:09 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/24 02:41:21 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/i_libft/libft.h"

void	ft_putendl(char const *s)
{
	while (s && *s)
		ft_putchar(*s++);
	ft_putchar('\n');
}
