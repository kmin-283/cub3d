/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:21:27 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:12:36 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l_ptr;

	if (lst)
	{
		while (*lst)
		{
			l_ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = l_ptr;
		}
	}
}
