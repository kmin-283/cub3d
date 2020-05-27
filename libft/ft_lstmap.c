/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:38:16 by kmin              #+#    #+#             */
/*   Updated: 2020/04/16 20:03:40 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start_ptr;
	t_list	*add_ptr;

	if (lst)
	{
		start_ptr = ft_lstnew(f(lst->content));
		lst = lst->next;
		if (!start_ptr)
			ft_lstclear(&start_ptr, del);
		while (lst && start_ptr)
		{
			add_ptr = ft_lstnew(f(lst->content));
			if (!add_ptr)
			{
				ft_lstclear(&start_ptr, del);
				return (NULL);
			}
			ft_lstadd_back(&start_ptr, add_ptr);
			lst = lst->next;
		}
		return (start_ptr);
	}
	return (NULL);
}
