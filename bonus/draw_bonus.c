/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:13:57 by kmin              #+#    #+#             */
/*   Updated: 2020/05/24 11:39:31 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

unsigned int	filltexture(t_player *p, double scale, double t_start)
{
	int color;
	int index;
	int start;

	t_start *= scale;
	if (p->tex.y_cor + t_start < 0)
		t_start = p->tex.y_cor;
	if (p->ray.side)
	{
		index = (p->dis.hity - floor(p->dis.hity)) *
			64 + floor(p->tex.y_cor + t_start) * 64;
		color = p->ray.facingright ? p->tex.ea[index] : p->tex.we[index];
		color = (color >> 1) & 8355711;
	}
	else
	{
		index = (p->dis.hitx - floor(p->dis.hitx)) *
			64 + floor(p->tex.y_cor + t_start) * 64;
		color = p->ray.facingdown ? p->tex.so[index] : p->tex.no[index];
	}
	p->tex.y_cor += scale;
	return (color);
}

void			render_3d_projectionwall(t_player *p)
{
	int				i;
	unsigned int	color;
	int				index;
	double			texture_start;

	i = 0;
	p->ray.distance = p->dis.dis * (cos(p->ray.angle - p->unit.angle));
	p->ray.dis_plane = (p->scr.width / 2) / tan((double)FOV_ANGLE / 2);
	p->ray.strip_h = (1 / p->ray.distance) * p->ray.dis_plane;
	p->ray.start = ((double)p->scr.height / 2 - p->ray.strip_h / 2);
	if (p->ray.start < 0)
		p->ray.start = 0;
	texture_start = p->ray.start - p->scr.height / 2 + p->ray.strip_h / 2;
	while (i <= p->scr.height)
	{
		if (i < p->ray.start)
			color = sky(p);
		else if (i > p->ray.start + p->ray.strip_h)
			color = 0xFFFFFF;
		else
			color = filltexture(p, 64 / p->ray.strip_h, texture_start);
		p->img_addr[p->ray.id + i * p->scr.width] = color;
		i++;
	}
	p->tex.y_cor = 0;
}

int				reset_variables(t_player *p)
{
	if (p->tex.sky_xcor > 1024)
		p->tex.sky_xcor = 0;
	else
		p->tex.sky_xcor += (double)1024 / p->scr.width;
	p->tex.sky_ycor = 0;
	p->hor.found_hit = FALSE;
	p->ver.found_hit = FALSE;
	return (0);
}

int				render(t_player *p)
{
	int bpp1;
	int sl1;
	int endian1;
	int	in_whileloop;

	p->img1 = mlx_new_image(p->mlx_ptr, p->scr.width, p->scr.height);
	p->img_addr =
		(unsigned int *)mlx_get_data_addr(p->img1, &bpp1, &sl1, &endian1);
	p->ray.angle = p->unit.angle - ((double)FOV_ANGLE / 2);
	in_whileloop = FALSE;
	p->spr.wallhit = (double *)ft_calloc(p->scr.width, sizeof(double));
	while (p->ray.id < p->scr.width)
	{
		ray(p, &in_whileloop);
		hor(p);
		ver(p);
		dis(p);
		render_3d_projectionwall(p);
		reset_variables(p);
		p->ray.id++;
	}
	sprite(p);
	p->ray.id = 0;
	return (0);
}

int				draw(t_player *p, int has_save_file)
{
	render(p);
	if (has_save_file)
		init_bitmap(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img1, 0, 0);
	free(p->spr.wallhit);
	mlx_destroy_image(p->mlx_ptr, p->img1);
	p->img1 = NULL;
	p->img_addr = NULL;
	return (0);
}
