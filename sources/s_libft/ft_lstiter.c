/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:18:27 by ahuba             #+#    #+#             */
/*   Updated: 2017/11/26 02:07:08 by ahuba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/i_libft/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	f(lst);
	if (lst->next)
		ft_lstiter(lst->next, f);
}
