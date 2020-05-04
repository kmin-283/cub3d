
#include "cub3d.h"

int worldMap[MAP_HEIGHT][MAP_WIDTH] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};



int hasWallAt(int x, int y)
{
	int mapIndexX;
	int mapIndexY;

	if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
		return TRUE;
	mapIndexX = (int)floor(x / TILE_SIZE);
	mapIndexY = (int)floor(y / TILE_SIZE);
	return (worldMap[mapIndexY][mapIndexX] != 0);
}

double normalizeAngle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = -(2 * M_PI) * angle;
	return (angle);
}

int ray_facing_dir(t_player *p)
{
	p->ray.FacingDown = p->ray.angle > 0 && p->ray.angle < M_PI;
	p->ray.FacingUp = !(p->ray.FacingDown);
	p->ray.FacingRight = p->ray.angle < 0.5 * M_PI || p->ray.angle > 1.5 * M_PI;
	p->ray.FacingLeft = !(p->ray.FacingRight);
}

int ray(t_player *p, int *in_while_loop)
{
	if (*in_while_loop == TRUE)
		p->ray.angle += (double)FOV_ANGLE / NUM_RAYS;
	else
		*in_while_loop = TRUE;
	p->ray.angle = normalizeAngle(p->ray.angle);
	ray_facing_dir(p);
}

int hor(t_player *p)
{
	p->hor.y_intercept = floor(p->unit.y / TILE_SIZE) * TILE_SIZE;
	p->hor.y_intercept += p->ray.FacingDown ? TILE_SIZE : 0;
	p->hor.x_intercept = p->unit.x + ((p->hor.y_intercept - p->unit.y) / tan(p->ray.angle));
	p->hor.y_step = TILE_SIZE;
	p->hor.y_step *= p->ray.FacingUp ? -1 : 1;
	p->hor.x_step = TILE_SIZE / tan(p->ray.angle);
	p->hor.x_step *= (p->ray.FacingLeft && p->hor.x_step > 0) ? -1: 1;
	p->hor.x_step *= (p->ray.FacingRight && p->hor.x_step < 0) ? -1 : 1;
	p->hor.nexttouchX = p->hor.x_intercept;
	p->hor.nexttouchY = p->hor.y_intercept;
	if (p->ray.FacingUp)
		p->hor.nexttouchY--;
	while (p->hor.nexttouchX >= 0 && p->hor.nexttouchX <= SCREEN_WIDTH &&
	p->hor.nexttouchY >=0 && p->hor.nexttouchY <= SCREEN_HEIGHT)
	{
		if (hasWallAt(p->hor.nexttouchX, p->hor.nexttouchY))
		{
			p->hor.foundWallHit = TRUE;
			p->hor.wallHitX = p->hor.nexttouchX;
			p->hor.wallHitY = p->hor.nexttouchY;
			break;
		}
		else
		{
			p->hor.nexttouchX += p->hor.x_step;
			p->hor.nexttouchY += p->hor.y_step;
		}
	}
}

int ver(t_player *p)
{
	p->ver.x_intercept = floor(p->unit.x / TILE_SIZE) * TILE_SIZE;
	p->ver.x_intercept += p->ray.FacingRight ? TILE_SIZE : 0;
	p->ver.y_intercept = p->unit.y + (p->ver.x_intercept - p->unit.x) * tan(p->ray.angle);
	p->ver.x_step = TILE_SIZE;
	p->ver.x_step *= p->ray.FacingLeft ? -1 : 1;
	p->ver.y_step = TILE_SIZE * tan(p->ray.angle);
	p->ver.y_step *= (p->ray.FacingUp && p->ver.y_step > 0) ? -1 : 1;
	p->ver.y_step *= (p->ray.FacingDown && p->ver.y_step < 0) ? -1 : 1;
	p->ver.nexttouchX = p->ver.x_intercept;
	p->ver.nexttouchY = p->ver.y_intercept;
	if (p->ray.FacingLeft)
		p->ver.nexttouchX--;
	while (p->ver.nexttouchX >= 0 && p->ver.nexttouchX <= SCREEN_WIDTH &&
	p->ver.nexttouchY >=0 && p->ver.nexttouchY <= SCREEN_HEIGHT)
	{
		if (hasWallAt(p->ver.nexttouchX, p->ver.nexttouchY))
		{
			p->ver.foundWallHit = TRUE;
			p->ver.wallHitX = p->ver.nexttouchX;
			p->ver.wallHitY = p->ver.nexttouchY;
			break;
		}
		else
		{
			p->ver.nexttouchX += p->ver.x_step;
			p->ver.nexttouchY += p->ver.y_step;
		}
	}
}
double distanceBetweenPoint(int x1, int y1, int x2, int y2)
{
	return (hypot((x2 - x1), (y2- y1)));
}

int dis(t_player *p)
{
	p->dis.horDis = (p->hor.foundWallHit) ?
	distanceBetweenPoint(p->unit.x, p->unit.y, p->hor.wallHitX, p->hor.wallHitY)
	: __INT_MAX__;
	p->dis.verDis = (p->ver.foundWallHit) ?
	distanceBetweenPoint(p->unit.x, p->unit.y, p->ver.wallHitX, p->ver.wallHitY)
	: __INT_MAX__;
	p->dis.final_wallHitX = (p->dis.horDis < p->dis.verDis) ? p->hor.wallHitX : p->ver.wallHitX;
	p->dis.final_wallHitY = (p->dis.horDis < p->dis.verDis) ? p->hor.wallHitY : p->ver.wallHitY;
	p->dis.final_dis = (p->dis.horDis < p->dis.verDis) ? p->dis.horDis : p->dis.verDis;
	p->dis.wasHitVer = (p->dis.verDis < p->dis.horDis);
}

int render_3d_ProjectionWall(t_player *p)
{
	int wallStripHeight;
	double rayDistance;
	int distanceProjectionPlane;
	int i;
	int j;
	int start;

	i = 0;
	rayDistance = p->dis.final_dis;
	distanceProjectionPlane = (SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wallStripHeight = (TILE_SIZE / rayDistance) * distanceProjectionPlane;
	start = (SCREEN_HEIGHT / 2) - (wallStripHeight / 2);
	while (i < NUM_RAYS)
	{
		j = 0;
		while (j < wallStripHeight)
		{
			p->img_addr[i + j * start * SCREEN_WIDTH] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

int render(t_player *p)
{
	int bpp1;
	int sl1;
	int endian1;
	int	in_WhileLoop;

	p->img1 = mlx_new_image(p->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	p->img_addr = (unsigned int *)mlx_get_data_addr(p->img1, &bpp1, &sl1, &endian1);
	p->ray.angle = p->unit.rotationAngle - (FOV_ANGLE / 2);
	in_WhileLoop = FALSE;
	while (p->ray.id < SCREEN_WIDTH)
	{
		ray(p, &in_WhileLoop);
		hor(p);
		ver(p);
		dis(p);
		render_3d_ProjectionWall(p);
		p->ray.id++;
	}
	p->ray.id = 0;
	return (0);
}

int draw(t_player *p)
{
	render(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img1, 0, 0);
	return (0);
}

int	free_img(t_player *p)
{

}

int	init_unit(t_player *p)
{
	p->unit.x = SCREEN_WIDTH / 2;
	p->unit.y = SCREEN_HEIGHT / 7;
	p->unit.radius = 4;
	p->unit.turnDirection = 0;
	p->unit.walkDirection = 0;
	p->unit.rotationAngle = M_PI / 2;
	p->unit.moveSpeed = 4;
	p->unit.rotationSpeed = (3 * (M_PI / 180));
}

void init()
{
	t_player p;

	ft_memset(&p, 0, sizeof(p));
	init_unit(&p);
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	draw(&p);
 	mlx_hook(p.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &p);
	mlx_hook(p.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &p);
	mlx_loop(p.mlx_ptr);
}

int main()
{
	init();
	return (0);
}
