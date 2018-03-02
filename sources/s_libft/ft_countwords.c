/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:19:10 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/23 21:23:34 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/i_libft/libft.h"

int		ft_countwords(char const *s, char c)
{
	int	num;
	int i;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			num++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (num);
}
