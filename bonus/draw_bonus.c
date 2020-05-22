/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:13:57 by kmin              #+#    #+#             */
/*   Updated: 2020/05/22 20:12:45 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

unsigned int fillTexture(t_player * p, double scale, double t_start)
{
	unsigned int color;
	int index;
	int start;

	t_start *= scale;
	if (p->tex.y_cor + t_start < 0)
		t_start = p->tex.y_cor;
	if (p->ray.side)
	{
		index = (p->dis.final_wallHitY - floor(p->dis.final_wallHitY)) * 64 + floor(p->tex.y_cor + t_start) * 64;
		color = p->ray.FacingRight ? p->tex.ea[index] : p->tex.we[index];
	}
	else
	{
		index = (p->dis.final_wallHitX - floor(p->dis.final_wallHitX)) * 64 + floor(p->tex.y_cor + t_start) * 64;
		color = p->ray.FacingDown ? p->tex.so[index] : p->tex.no[index];
	}
	p->tex.y_cor += scale;
	return (color);
}

int render_3d_ProjectionWall(t_player *p)
{
	int i;
	unsigned int color;
	int index;
	double texture_start;

	i = 0;
	p->ray.ray_distance = p->dis.final_dis * (cos(p->ray.angle - p->unit.rotationAngle));
	p->ray.distance_projection_plane = (p->scr.width / 2) / tan((double)FOV_ANGLE / 2);
	p->ray.wall_strip_height = (1 / p->ray.ray_distance) * p->ray.distance_projection_plane;
	p->ray.start = ((double)p->scr.height / 2 - p->ray.wall_strip_height / 2);
	if (p->ray.start < 0)
		p->ray.start = 0;
	texture_start = p->ray.start - p->scr.height / 2 + p->ray.wall_strip_height / 2;
	while (i <= p->scr.height)
	{
		if (i < p->ray.start)
			color = sky(p);
		else if (i > p->ray.start && i < p->ray.start + p->ray.wall_strip_height)
			color = fillTexture(p, 64 / p->ray.wall_strip_height, texture_start);
		else
			color = 0xFFFFFF;
		p->img_addr[p->ray.id + i * p->scr.width] = color;
		i++;
	}
	p->tex.y_cor = 0;
	p->tex.sky_ycor = 0;
	return (0);
}

int reset_variables(t_player *p)
{
	if (p->tex.sky_xcor > 1024)
        p->tex.sky_xcor = 0;
	else
        p->tex.sky_xcor += (double)1024 / p->scr.width;
	p->hor.foundWallHit = FALSE;
	p->ver.foundWallHit = FALSE;
}

int render(t_player *p)
{
	int bpp1;
	int sl1;
	int endian1;
	int	in_WhileLoop;

	p->img1 = mlx_new_image(p->mlx_ptr, p->scr.width, p->scr.height);
	p->img_addr = (unsigned int *)mlx_get_data_addr(p->img1, &bpp1, &sl1, &endian1);
	p->ray.angle = p->unit.rotationAngle - ((double)FOV_ANGLE / 2);
	in_WhileLoop = FALSE;
	p->spr.wallhit = (double *)ft_calloc(p->scr.width, sizeof(double));
	while (p->ray.id < p->scr.width)
	{
		ray(p, &in_WhileLoop);
		hor(p);
		ver(p);
		dis(p);
		render_3d_ProjectionWall(p);
		reset_variables(p);
		p->ray.id++;
	}
	sprite(p);
	p->tex.sky_xcor = 0;
	p->ray.id = 0;
	return (0);
}

int draw(t_player *p, int has_save_file)
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