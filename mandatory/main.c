/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:25:46 by kmin              #+#    #+#             */
/*   Updated: 2020/05/31 16:05:46 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_tex(t_player *p, int val)
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
	if (val == 1 && p->win_ptr)
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	free(p->mlx_ptr);
	return (0);
}

int	free_img(t_player *p)
{
	int i;

	i = p->map.height;
	if (p->map.map)
	{
		while (i--)
		{
			free(p->map.map[i]);
		}
		free(p->map.map);
	}
	free_tex(p, 0);
	if (p->map.width)
		free(p->map.width);
	free(p->sprite);
	exit(0);
	return (0);
}

int	init(char *argv1, int hassavefile)
{
	t_player p;

	ft_memset(&p, 0, sizeof(p));
	p.mlx_ptr = mlx_init();
	if (init_map(&p, argv1) != 0)
	{
		free_img(&p);
		return (0);
	}
	if (!hassavefile)
		p.win_ptr = mlx_new_window(p.mlx_ptr, p.scr.width,
				p.scr.height, "cub3d");
	draw(&p, hassavefile);
	if (!hassavefile)
	{
		mlx_hook(p.win_ptr, KEYPRESS, 1L << 0, key_press, &p);
		mlx_loop_hook(p.mlx_ptr, unit_move, &p);
		mlx_hook(p.win_ptr, KEYRELEASE, 1L << 1, key_release, &p);
		mlx_hook(p.win_ptr, KEYCLOSE, 1L << 17, ft_close, &p);
		mlx_loop(p.mlx_ptr);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int hassavefile;

	hassavefile = FALSE;
	if (argc == 2 && namecheck(argv[1], ".cub"))
		init(argv[1], hassavefile);
	else if (argc == 3 && namecheck(argv[1], ".cub") && savecheck(argv[2]))
	{
		hassavefile = TRUE;
		init(argv[1], hassavefile);
	}
	else if (argc < 2)
		error(LITTLE_ARG_ERROR);
	else if (argc > 3)
		error(MANY_ARG_ERROR);
	return (0);
}
