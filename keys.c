/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:23:02 by kmin              #+#    #+#             */
/*   Updated: 2020/05/07 19:38:30 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(int key, t_player *p)
{
	int i;

	i = p->map.height;
	while (i--)
		free(p->map.map[i]);
	free(p->map.map);
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	free(p->mlx_ptr);
	while (p->map.height--)
		free(p->map.width[p->map.height]);
	free(p->map.width);
	exit(0);
	return (0);
}

int key_press(int key, t_player *p)
{
	if (key == KEY_UP)
		moveBackandForth(key, p);
	else if (key == KEY_DOWN)
        moveBackandForth(key, p);
	else if (key == KEY_RIGHT)
		moveLeftandRight(key, p);
	else if (key == KEY_LEFT)
		moveLeftandRight(key, p);
	else if (key == KEY_ESC)
		ft_close(1, p);
	else if (key == LEFT_ARROW)
		rotate(key, p);
	else if (key == RIGHT_ARROW)
		rotate(key, p);
    draw(p);
	return (0);
}

int key_release(int key, t_player *p)
{
	if (key == KEY_UP)
		p->unit.walkDirection = 0;
	else if (key == KEY_LEFT)
		p->unit.walkDirection = 0;
	else if (key == KEY_RIGHT)
		p->unit.walkDirection = 0;
	else if (key == KEY_DOWN)
		p->unit.walkDirection = 0;
	else if (key == LEFT_ARROW || key == RIGHT_ARROW)
		p->unit.turnDirection = 0;
	return (0);
}