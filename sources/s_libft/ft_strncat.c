/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:45:39 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/24 05:19:55 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/i_libft/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int len;

	i = -1;
	len = (int)ft_strlen(s1);
	while (s2[++i] && i < (int)n)
		s1[len++] = s2[i];
	s1[len] = '\0';
	return (s1);
}
