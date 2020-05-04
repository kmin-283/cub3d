/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:53:28 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:09:32 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l_ptr;

	l_ptr = *lst;
	if (l_ptr && new && lst)
	{
		while (l_ptr->next)
			l_ptr = l_ptr->next;
		l_ptr->next = new;
	}
	else if (lst && new && !l_ptr)
		*lst = new;
}
