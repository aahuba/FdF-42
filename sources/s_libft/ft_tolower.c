/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:14:05 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/24 19:56:43 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/i_libft/libft.h"

int		ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
