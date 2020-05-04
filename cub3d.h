/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:14:12 by kmin              #+#    #+#             */
/*   Updated: 2020/05/04 17:30:15 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include "./libft/libft.h"
#include <math.h>
#include <unistd.h>
#include "mlx.h"

#define TILE_SIZE 64

#define MAP_WIDTH 15
#define MAP_HEIGHT 11

#define TRUE 1
#define FALSE 0
#define KEYPRESSMASK 1
#define KEYRELEASEMASK 10
#define KEYPRESS 2
#define KEYRELEASE 3
#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define SCREEN_WIDTH (MAP_WIDTH * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_HEIGHT * TILE_SIZE)

#define MINIMAP_SCALE_FACTOR 0.2

#define FOV_ANGLE (66 * (M_PI / 180))
#define NUM_RAYS SCREEN_WIDTH

typedef struct  s_horizontal
{
    double x_intercept;
	double y_intercept;
    double x_step;
	double y_step;
	double nexttouchX;
	double nexttouchY;
    int foundWallHit;
    double wallHitX;
    double wallHitY;

}               t_hor;

typedef struct  s_vertical
{
    double x_intercept;
	double y_intercept;
    double x_step;
	double y_step;
	double nexttouchX;
	double nexttouchY;
    int foundWallHit;
    double wallHitX;
    double wallHitY;

}               t_ver;

typedef struct  s_dis
{
    double horDis;
    double verDis;
    double final_wallHitX;
    double final_wallHitY;
    double final_dis;
    int wasHitVer;
}               t_dis;

typedef struct  s_ray{
    int id;
    double angle;
    int FacingDown;
	int FacingUp;
	int FacingLeft;
	int FacingRight;
}               t_ray;

typedef struct  s_unit
{
    int x;
    int y;
    int radius;
    int turnDirection;
    int walkDirection;
    double rotationAngle;
    int moveSpeed;
    double rotationSpeed;
}               t_unit;

typedef struct  s_player{
    t_ray   ray;
    t_unit  unit;
    t_hor   hor;
    t_ver   ver;
    t_dis   dis;
	void *mlx_ptr;
	void *win_ptr;
    void *img1;
    unsigned int *img_addr;
}               t_player;
/*
**  keys.c
*/
int key_press(int key, t_player *p);
int key_release(int key, t_player *p);
/*
**  main.c
*/
void init();
int	init_unit(t_player *p);
/*
**  draw.c
*/
int draw(t_player *p);
int render(t_player *p);
int ver(t_player *p);
int hor(t_player *p);
int	free_img(t_player *p);
/*
**  ray.c
*/
int ray(t_player *p, int *in_while_loop);
int ray_facing_dir(t_player *p);
double normalizeAngle(double angle);
/*
**  map
*/
int hasWallAt(int x, int y);
#endif