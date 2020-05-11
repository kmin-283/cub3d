/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:25:46 by kmin              #+#    #+#             */
/*   Updated: 2020/05/11 16:59:35 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_img(t_player *p)
{
	int i;

	i = p->map.height;
	while (i--)
		free(p->map.map[i]);
	free(p->map.map);
	mlx_destroy_image(p->mlx_ptr, p->tex.n_img);
	mlx_destroy_image(p->mlx_ptr, p->tex.s_img);
	mlx_destroy_image(p->mlx_ptr, p->tex.w_img);
	mlx_destroy_image(p->mlx_ptr, p->tex.e_img);
	mlx_destroy_image(p->mlx_ptr, p->tex.sp_img);
	free(p->mlx_ptr);
	while (p->map.height--)
		free(p->map.width[p->map.height]);
	free(p->map.width);
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
