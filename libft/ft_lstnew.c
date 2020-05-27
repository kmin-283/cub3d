/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:35:36 by kmin              #+#    #+#             */
/*   Updated: 2020/04/16 19:53:52 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_ptr;

	l_ptr = (t_list *)ft_calloc(1, sizeof(t_list));
	if (l_ptr)
	{
		l_ptr->content = content;
		l_ptr->next = NULL;
	}
	return (l_ptr);
}
