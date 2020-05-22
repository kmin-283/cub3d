/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmin <kmin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:14:12 by kmin              #+#    #+#             */
/*   Updated: 2020/05/20 21:47:47 by kmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "mlx.h"

#define TRUE 1
#define FALSE 0
#define KEYPRESSMASK (1L << 0)
#define KEYRELEASEMASK (1L << 1)
#define KEYCLOSEMASK (1L << 17)
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
# define FOV_ANGLE (66 * (M_PI / 180))

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
# define BITMAP_OPEN_ERROR 13
# define SPRITE_ALLOCATION_ERROR 14
# define FLOOR_CEILING_ERROR 15
# define MAP_DOUBLE_ERROR 16
# define FILE_EMPTY 17
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
    double wall_strip_height;
	double ray_distance;
	double distance_projection_plane;
	double start;
    int id;
    int side;
    double angle;
    double dirx;
    double diry;
    int FacingDown;
	int FacingUp;
	int FacingLeft;
	int FacingRight;
}               t_ray;

typedef struct  s_unit
{
    int pos;
    double dirx;
    double diry;
    double posx;
    double posy;
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
    int spr_num;
    char **map;
    int *width;
    int max_width;
    int height;
    int wrong_char;
}               t_map;

typedef struct  s_texture
{
    void *n_img;
    void *s_img;
    void *w_img;
    void *e_img;
    void *sp_img;
    void *c_img;
    void *f_img;
    unsigned int *no;
    unsigned int *so;
    unsigned int *we;
    unsigned int *ea;
    unsigned int *sp;
    unsigned int *c;
    unsigned int *f;
    double y_cor;
    double x_cor;
    double cy_cor;
    double fy_cor;
}               t_tex;

typedef struct  s_sprite
{
    double distance_projection_plane;
	double sprite_strip_height;
    int start;
    double x_cor;
    double y_cor;
    double  *wallhit;
}               t_spr;

typedef struct s_key
{
    int w;
    int a;
    int s;
    int d;
    int left;
    int right;
    int esc;
}               t_key;

typedef struct s_spr
{
    double x;
    double y;
    double d;
    double a;
    int     visible;
}               t_sprite;


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
    t_sprite   *sprite;
    t_spr   spr;
    t_key   key;
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
int	ft_close(t_player *p);
int key_release_exc(int key, t_player *p);
/*
**  move.c
*/
int	moveBackandForth(int key, t_player *p);
int	moveLeftandRight(int key, t_player *p);
int	rotate(int key, t_player *p);
int unit_move(t_player *p);
/*
**  main.c
*/
int init(char *argv1, int hasSavefile);
int free_tex(t_player *p, int val);
int	free_img(t_player *p);
/*
**  draw.c
*/
int draw(t_player *p, int has_save_file);
int render(t_player *p);
int render_3d_ProjectionWall(t_player *p);
int reset_variables(t_player *p);
unsigned int fillTexture(t_player *p, double wallstripheight, double start);
/*
**  ray.c
*/
int ray(t_player *p, int *in_while_loop);
int dis(t_player *p);
int ver(t_player *p);
int hor(t_player *p);
int ray_facing_dir(t_player *p);
/*
**  ray2.c
*/
int hor_ray_set(t_player *p);
int ver_ray_set(t_player *p);
/*
**  cub3d.c
*/
double normalizeAngle(double angle);
int hasWallAt(t_player *p, int x, int y);
double distanceBetweenPoint(double x1, double y1, double x2, double y2);
/*
**  map.c
*/
int init_map(t_player *p, char *argv1);
int parsing_cubfile(t_player *p, char *line);
int screenRange(t_player *p, char *line);
int mapTexture(t_player *p, char *line, unsigned int **addr, void **img);
int mapColor(t_player *p, char *line, unsigned int *addr);
/*
**  mapgrid.c
*/
int mapGrid(t_player *p, char *line);
char    *mapCopy1(t_player *p, char *line, int i, int *ret);
int    oneLine_len(t_player *p, char *line, int r, int *error);
int setMapWidth(t_player *p);
/*
**  check.c
*/
int nameCheck(char *name, char *check);
int saveCheck(char *save);
int empty_file(t_player *p);
int check_and_set(t_player *p);
/*
**  mapcheck.c
*/
int mapcheck(t_player *p, int i, int len);
int verify_else(t_player *p, int i, int k);
int verify_space(t_player *p, int i, int k);
/*
**  error.c
*/
int error(int error);
/*
**  utils.c
*/
int isWhitespace(char c);
int setPosition(t_player *p, char c, int i, int r);
int isWall(char c);
int sprite_cor(t_player *p, int row, int col);
/*
**  unit.c
*/
int sprite_list(t_player *p);
int	init_unit(t_player *p);
int setUnitPos(t_player *p);
/*
**  bitmap.c
*/
int init_bitmap(t_player *p);
int bmp_data(t_player *p, int fd, int file_size);
int bmp_header(t_player *p, int fd, int file_size);
/*
**  sprite.c
*/
int sprite(t_player *p);
int sprite_order(t_player *p);
int sprite_locate(t_player *p, int i, double angle);
int sprite_draw(t_player *p, double xloc, double dist, int k);
unsigned int fill_sp_tex(t_player *p, double x, double scale);
#endif