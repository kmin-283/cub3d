/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:13:57 by kmin              #+#    #+#             */
/*   Updated: 2020/05/11 15:05:57 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int fillTexture(t_player * p, double scale)
{
	int color;
	int index;

	if (p->ray.side)
	{
		index = fmod(p->dis.final_wallHitY, 64) + floor(p->tex.y_cor) * 64;
		color = p->ray.FacingRight ? p->tex.ea[index] : p->tex.we[index];
	}
	else
	{
		index = fmod(p->dis.final_wallHitX, 64) + floor(p->tex.y_cor) * 64;
		color = p->ray.FacingDown ? p->tex.so[index] : p->tex.no[index];
	}
	p->tex.y_cor += scale;
	return (color);
}

int render_3d_ProjectionWall(t_player *p)
{
	double wallStripHeight;
	double rayDistance;
	double distanceProjectionPlane;
	int i;
	int start;
	unsigned int color;
	int index;

	i = 0;
	rayDistance = p->dis.final_dis;
	distanceProjectionPlane = (p->scr.width / 2) / tan((double)FOV_ANGLE / 2);
	wallStripHeight = (TILE_SIZE / rayDistance) * distanceProjectionPlane;
	start = (p->scr.height - wallStripHeight) / 2;
	if (start < 0)
		start = 0;
	while (i <= p->scr.height)
	{
		if (i < start)
			color = p->tex.c;
		else if (i > start + wallStripHeight)
			color = p->tex.f;
		else
			color = fillTexture(p, 64 / wallStripHeight);
		p->img_addr[p->ray.id + i * p->scr.width] = color;
		i++;
	}
	p->tex.count = 0;
	p->tex.y_cor = 0;
}

int reset_variables(t_player *p)
{
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
	p->ray.id = 0;
	return (0);
}

int draw(t_player *p)
{
	render(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img1, 0, 0);
	mlx_destroy_image(p->mlx_ptr, p->img1);
	return (0);
}