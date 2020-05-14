/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:23:02 by kmin              #+#    #+#             */
/*   Updated: 2020/05/14 19:51:30 by kmin             ###   ########.fr       */
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
	while (p->spr.n--)
		free(p->spr.cor_dis[p->spr.n]);
	free(p->spr.cor_dis);
	mlx_destroy_image(p->mlx_ptr, p->tex.n_img);
	mlx_destroy_image(p->mlx_ptr, p->tex.s_img);
	mlx_destroy_image(p->mlx_ptr, p->tex.w_img);
	mlx_destroy_image(p->mlx_ptr, p->tex.e_img);
	mlx_destroy_image(p->mlx_ptr, p->tex.sp_img);
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

int key_release(int key, t_player *p)
{
	if (key == KEY_UP)
	{
		p->key.w = 0;
		p->unit.walkDirection = 0;
	}
	else if (key == KEY_LEFT)
	{
		p->key.a = 0;
		p->unit.walkDirection = 0;
	}
	else if (key == KEY_RIGHT)
	{
		p->key.d = 0;
		p->unit.walkDirection = 0;
	}
	else if (key == KEY_DOWN)
	{
		p->key.s = 0;
		p->unit.walkDirection = 0;
	}
	else if (key == LEFT_ARROW)
	{
		p->key.left = 0;
		p->unit.turnDirection = 0;
	}
	else if (key == RIGHT_ARROW)
	{
		p->key.right = 0;
		p->unit.turnDirection = 0;
	}
	return (0);
}