/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:25:46 by kmin              #+#    #+#             */
/*   Updated: 2020/05/14 22:08:28 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int free_tex(t_player *p)
{
	if (p->tex.n_img)
		mlx_destroy_image(p->mlx_ptr, p->tex.n_img);
	if (p->tex.s_img)
		mlx_destroy_image(p->mlx_ptr, p->tex.s_img);
	if (p->tex.w_img)
		mlx_destroy_image(p->mlx_ptr, p->tex.w_img);
	if (p->tex.e_img)
		mlx_destroy_image(p->mlx_ptr, p->tex.e_img);
	if (p->tex.sp_img)
		mlx_destroy_image(p->mlx_ptr, p->tex.sp_img);
	free(p->mlx_ptr);
}

int	free_img(t_player *p)
{
	int i;

	i = p->map.height;
	if (p->map.map)
	{
		while (i--)
			free(p->map.map[i]);
		free(p->map.map);
	}
	free_tex(p);
	if (p->map.width)
	{
		while (p->map.height--)
			free(p->map.width[p->map.height]);
		free(p->map.width);
	}
	if (p->spr.cor_dis)
	{
		while (p->spr.n--)
			free(p->spr.cor_dis[p->spr.n]);
		free(p->spr.cor_dis);
	}
	exit(0);
	return (0);
}

int init(char *argv1, int hasSavefile)
{
	t_player p;

	ft_memset(&p, 0, sizeof(p));
	p.mlx_ptr = mlx_init();
	if (init_map(&p, argv1) == -1)
	{
		free_img(&p);
		return (0);
	}
	p.win_ptr = mlx_new_window(p.mlx_ptr, p.scr.width, p.scr.height, "cub3d");
	draw(&p, hasSavefile);
 	mlx_hook(p.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &p);
	mlx_loop_hook(p.mlx_ptr, unit_move, &p);
	mlx_hook(p.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &p);
	mlx_loop(p.mlx_ptr);
}

int main(int argc, char **argv)
{
	int hasSavefile;

	hasSavefile = FALSE;
	if (argc == 2 && nameCheck(argv[1], ".cub"))
		init(argv[1], hasSavefile);
	else if (argc == 3 && nameCheck(argv[1], ".cub") && saveCheck(argv[2]))
	{
		hasSavefile = TRUE;
		init(argv[1], hasSavefile);
	}
	else if (argc < 2)
		error(LITTLE_ARG_ERROR);
	else if (argc > 3)
		error(MANY_ARG_ERROR);
	return (0);
}
