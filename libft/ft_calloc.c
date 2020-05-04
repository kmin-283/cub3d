/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:39:35 by kmin              #+#    #+#             */
/*   Updated: 2020/04/07 21:08:33 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void *ptr;

	if (number == 0 || size == 0)
	{
		number = 1;
		size = 1;
	}
	ptr = malloc(size * number);
	if (ptr)
		ft_memset(ptr, 0, number * size);
	return (ptr);
}
