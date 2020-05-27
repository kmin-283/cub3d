/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:13:05 by kmin              #+#    #+#             */
/*   Updated: 2020/05/24 14:07:34 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	unit_move(t_player *p)
{
	if (p->key.w)
		movebackandforth(KEY_UP, p);
	if (p->key.s)
		movebackandforth(KEY_DOWN, p);
	if (p->key.d)
		moveleftandright(KEY_RIGHT, p);
	if (p->key.a)
		moveleftandright(KEY_LEFT, p);
	if (p->key.esc)
		ft_close(p);
	if (p->key.left)
		rotate(LEFT_ARROW, p);
	if (p->key.right)
		rotate(RIGHT_ARROW, p);
	draw(p, FALSE);
	return (0);
}

int	rotate(int key, t_player *p)
{
	double dist;

	if (key == RIGHT_ARROW)
		p->unit.turndirection = 1;
	else if (key == LEFT_ARROW)
		p->unit.turndirection = -1;
	p->unit.dirx = p->unit.dirx * cos(p->unit.turndirection *
			p->unit.rotationspeed) - p->unit.diry *
		sin(p->unit.turndirection * p->unit.rotationspeed);
	p->unit.diry = p->unit.diry * cos(p->unit.turndirection *
			p->unit.rotationspeed) + p->unit.dirx *
		sin(p->unit.turndirection * p->unit.rotationspeed);
	dist = hypot(p->unit.dirx, p->unit.diry);
	p->unit.dirx /= dist;
	p->unit.diry /= dist;
	p->unit.angle += p->unit.turndirection * p->unit.rotationspeed;
	return (0);
}

int	movebackandforth(int key, t_player *p)
{
	if (key == KEY_UP)
		p->unit.walkdirection = 1;
	else if (key == KEY_DOWN)
		p->unit.walkdirection = -1;
	p->unit.posx += p->unit.walkdirection *
		(p->unit.dirx * p->unit.movespeed / 100);
	if (p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '1'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '2'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '3'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '4')
		p->unit.posx -= p->unit.walkdirection *
			(p->unit.dirx * p->unit.movespeed / 100);
	p->unit.posy += p->unit.walkdirection *
		(p->unit.diry * p->unit.movespeed / 100);
	if (p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '1'
			|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '2'
			|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '3'
			|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '4')
		p->unit.posy -= p->unit.walkdirection *
			(p->unit.diry * p->unit.movespeed / 100);
	return (0);
}

int	mouse(int x, int y, t_player *p)
{
	double dist;

	if (x > p->unit.mouse_x)
		p->unit.turndirection = 1;
	else if (x < p->unit.mouse_x)
		p->unit.turndirection = -1;
	p->unit.mouse_x = x;
	p->unit.dirx = p->unit.dirx * cos(p->unit.turndirection *
			p->unit.rotationspeed) - p->unit.diry *
		sin(p->unit.turndirection * p->unit.rotationspeed);
	p->unit.diry = p->unit.diry * cos(p->unit.turndirection *
			p->unit.rotationspeed) + p->unit.dirx *
		sin(p->unit.turndirection * p->unit.rotationspeed);
	dist = hypot(p->unit.dirx, p->unit.diry);
	p->unit.dirx /= dist;
	p->unit.diry /= dist;
	p->unit.angle += p->unit.turndirection * p->unit.rotationspeed;
	return (0);
}

int	moveleftandright(int key, t_player *p)
{
	if (key == KEY_LEFT)
		p->unit.walkdirection = -1;
	else if (key == KEY_RIGHT)
		p->unit.walkdirection = 1;
	p->unit.posx -= p->unit.walkdirection *
		(p->unit.diry * p->unit.movespeed / 100);
	if (p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '1'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '2'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '3'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '4')
		p->unit.posx += p->unit.walkdirection *
			(p->unit.diry * p->unit.movespeed / 100);
	p->unit.posy += p->unit.walkdirection *
		(p->unit.dirx * p->unit.movespeed / 100);
	if (p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '1'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '2'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '3'
		|| p->map.map[(int)p->unit.posy][(int)p->unit.posx] == '4')
		p->unit.posy -= p->unit.walkdirection *
			(p->unit.dirx * p->unit.movespeed / 100);
	return (0);
}
