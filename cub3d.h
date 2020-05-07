/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:14:12 by kmin              #+#    #+#             */
/*   Updated: 2020/05/07 19:13:55 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"

#define TILE_SIZE 64

#define TRUE 1
#define FALSE 0
#define KEYPRESSMASK 1
#define KEYRELEASEMASK 10
#define KEYCLOSEMASK 4
#define KEYPRESS 2
#define KEYRELEASE 3
#define KEYCLOSE 17
/*
**  keys
*/
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_ESC 65307
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
#define MINIMAP_SCALE_FACTOR 0.2

#define FOV_ANGLE (66 * (M_PI / 180))

/*
**  ERROR
*/
# define OPEN_ERROR 1
# define LITTLE_ARG_ERROR 2
# define MANY_ARG_ERROR 3
# define NAME_INVALID_ERROR 4
# define SAVE_INVALID_ERROR 5
# define R_ERROR 6
# define TEXTURE_ERROR 7
# define COLOR_ERROR 8
# define MAP_OPEN_ERROR 9
# define CHAR_IN_MAP_ERROR 10
# define MAP_ALLOCATION_ERROR 11
# define WIDTH_ALLOCATION_ERROR 12
/*
**  struct
*/
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

typedef struct  s_ray
{
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

typedef struct  s_screen
{
    int width;
    int height;
}               t_scr;

typedef struct  s_map
{
    char **map;
    int **width;
    int height;
}               t_map;

typedef struct  s_texture
{
    unsigned int *no;
    unsigned int *so;
    unsigned int *we;
    unsigned int *ea;
    unsigned int *sp;
    unsigned int c;
    unsigned int f;
}               t_tex;

typedef struct  s_player
{
    t_ray   ray;
    t_unit  unit;
    t_hor   hor;
    t_ver   ver;
    t_dis   dis;
    t_map   map;
    t_tex   tex;
    t_scr   scr;
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
int	ft_close(int key, t_player *p);
/*
**  move.c
*/
int	moveBackandForth(int key, t_player *p);
int	moveLeftandRight(int key, t_player *p);
int	rotate(int key, t_player *p);
/*
**  main.c
*/
void init(char *argv1, int hasSavefile);
/*
**  draw.c
*/
int draw(t_player *p);
int render(t_player *p);
int render_3d_ProjectionWall(t_player *p);
int reset_variables(t_player *p);
/*
**  ray.c
*/
int ray(t_player *p, int *in_while_loop);
int dis(t_player *p);
int ver(t_player *p);
int hor(t_player *p);
int ray_facing_dir(t_player *p);
/*
**  cub3d.c
*/
double normalizeAngle(double angle);
int hasWallAt(t_player *p, int x, int y);
double distanceBetweenPoint(int x1, int y1, int x2, int y2);
/*
**  map.c
*/
int init_map(t_player *p, char *argv1);
int parsing_cubfile(t_player *p, char *line);
int screenRange(t_player *p, char *line);
/*
**  mapgrid.c
*/
int mapGrid(t_player *p, char *line);
char    *mapCopy1(t_player *p, char *line);
int    oneLine_len(t_player *p, char *line);
int setMapWidth(t_player *p);
/*
**  check.c
*/
int nameCheck(char *name, char *check);
int saveCheck(char *save);
/*
**  error.c
*/
int error(int error);
/*
**  utils.c
*/
int isWhitespace(char c);
int setPosition(t_player *p, char c);
int isWall(char c);
/*
**  unit.c
*/
int	init_unit(t_player *p);
int setUnitPos(t_player *p);
#endif