/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:56:16 by kmin              #+#    #+#             */
/*   Updated: 2020/05/27 21:01:19 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	empty_file(t_player *p)
{
	if (p->unit.posx == 0 && p->unit.posy == 0 && p->scr.height == 0 &&
			p->scr.width == 0 && p->tex.no == NULL && p->tex.so == NULL &&
			p->tex.we == NULL && p->tex.ea == NULL && p->tex.sp == NULL &&
			p->tex.c == 0 && p->tex.f == 0 && p->map.height == 0)
		return (error(FILE_EMPTY));
	if (p->tex.no == NULL || p->tex.so == NULL || p->tex.we == NULL ||
			p->tex.ea == NULL || p->tex.sp == NULL ||
			p->tex.c == 0 || p->tex.f == 0)
		return (error(TEXTURE_ERROR));
	if (p->map.wrong_char)
		return (error(CHAR_IN_MAP_ERROR));
	return (0);
}

int	check_and_set(t_player *p)
{
	int ret;
	int i;

	i = 0;
	ret = empty_file(p);
	if (ret == 0)
		ret = init_unit(p);
	if (ret == 0)
		ret = setmapwidth(p);
	if (ret == 0)
		sprite_list(p);
	if (ret == 0)
	{
		while (i < p->map.spr_num)
		{
			sprite_start_point(p, 64, i);
			i++;
		}
	}
	return (ret);
}

int	namecheck(char *name, char *check)
{
	int i;

	i = 0;
	while (name[i])
		i++;
	if (name[i - 4] == check[0] && name[i - 3] == check[1] &&
			name[i - 2] == check[2] && name[i - 1] == check[3])
		return (1);
	else
	{
		error(NAME_INVALID_ERROR);
		return (0);
	}
}

int	savecheck(char *save)
{
	int i;

	i = 0;
	while (save[i])
		i++;
	if (save[i - 6] == '-' && save[i - 5] == '-' &&
			save[i - 4] == 's' && save[i - 3] == 'a' &&
			save[i - 2] == 'v' && save[i - 1] == 'e')
		return (1);
	else
	{
		error(SAVE_INVALID_ERROR);
		return (0);
	}
}
