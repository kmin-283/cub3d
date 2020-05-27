/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:23:02 by kmin              #+#    #+#             */
/*   Updated: 2020/05/24 11:18:58 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_close(t_player *p)
{
	int i;

	i = p->map.height;
	if (p->map.map)
	{
		while (i-- > 0)
			free(p->map.map[i]);
		free(p->map.map);
	}
	free_tex(p, 1);
	free(p->map.width);
	free(p->sprite);
	exit(0);
	return (0);
}

int	key_press(int key, t_player *p)
{
	if (key == KEY_UP)
		p->key.w = 1;
	if (key == KEY_DOWN)
		p->key.s = 1;
	if (key == KEY_RIGHT)
		p->key.d = 1;
	if (key == KEY_LEFT)
		p->key.a = 1;
	if (key == KEY_ESC)
		p->key.esc = 1;
	if (key == LEFT_ARROW)
		p->key.left = 1;
	if (key == RIGHT_ARROW)
		p->key.right = 1;
	return (0);
}

int	key_release_exc(int key, t_player *p)
{
	if (key == KEY_UP)
		p->key.w = 0;
	else if (key == KEY_LEFT)
		p->key.a = 0;
	else if (key == KEY_RIGHT)
		p->key.d = 0;
	else if (key == KEY_DOWN)
		p->key.s = 0;
	p->unit.walkdirection = 0;
	return (0);
}

int	key_release(int key, t_player *p)
{
	if (key == KEY_UP || key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN)
		key_release_exc(key, p);
	else if (key == LEFT_ARROW)
	{
		p->key.left = 0;
		p->unit.turndirection = 0;
	}
	else if (key == RIGHT_ARROW)
	{
		p->key.right = 0;
		p->unit.turndirection = 0;
	}
	return (0);
}
