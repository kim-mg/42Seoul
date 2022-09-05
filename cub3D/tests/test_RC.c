#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <sys/time.h>
#include "../mlx/mlx.h"
// #include "../minilibx-linux/mlx.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_DESTROY_NOTIFY	17

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1280
#define screenHeight 1024
#define mini 10

enum e_RGB_color
{
	RGB_Red = 0xFF0000,
	RGB_Green = 0x00FF00,
	RGB_Blue = 0x0000FF,
	RGB_Black = 0x000000,
	RGB_White = 0xFFFFFF,
	RGB_Yellow = 0xFFFF00,
};

enum e_key_setting
{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
};

// enum e_ubuntu_key
// {
// 	KEY_ESC = 0xff1b,
// 	KEY_W = 0x77,
// 	KEY_A = 0x61,
// 	KEY_S = 0x73,
// 	KEY_D = 0x64,
// };

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		w;
	int		h;

	int		size_l;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_player
{
	void	*mlx;
	void	*win;

	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

	double	time;
	double	oldTime;
	double	moveSpeed;
	double	rotSpeed;
	
	t_img	img;
	t_img	mini_map;
}t_player;

int	w = screenWidth;
int	h = screenHeight;

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void print_error(char *err)
{
	printf("%s", err);
	printf("\n");
	exit(1);
}

int	deal_key(int key_code, t_player *p)
{
	//speed modifiers
	double moveSpeed = p->moveSpeed; //the constant value is in squares/second
	double rotSpeed = p->rotSpeed; //the constant value is in radians/second

	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
	{
		if(worldMap[(int)(p->posX + p->dirX * moveSpeed)][(int)(p->posY)] == false) p->posX += p->dirX * moveSpeed;
		if(worldMap[(int)(p->posX)][(int)(p->posY + p->dirY * moveSpeed)] == false) p->posY += p->dirY * moveSpeed;
	}
	//move backwards if no wall behind you
	if (key_code == KEY_S)
	{
		if(worldMap[(int)(p->posX - p->dirX * moveSpeed)][(int)(p->posY)] == false) p->posX -= p->dirX * moveSpeed;
		if(worldMap[(int)(p->posX)][(int)(p->posY - p->dirY * moveSpeed)] == false) p->posY -= p->dirY * moveSpeed;
	}
	//rotate to the right
	if (key_code == KEY_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = p->dirX;
		p->dirX = p->dirX * cos(-rotSpeed) - p->dirY * sin(-rotSpeed);
		p->dirY = oldDirX * sin(-rotSpeed) + p->dirY * cos(-rotSpeed);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(-rotSpeed) - p->planeY * sin(-rotSpeed);
		p->planeY = oldPlaneX * sin(-rotSpeed) + p->planeY * cos(-rotSpeed);
	}
	//rotate to the left
	if (key_code == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = p->dirX;
		p->dirX = p->dirX * cos(rotSpeed) - p->dirY * sin(rotSpeed);
		p->dirY = oldDirX * sin(rotSpeed) + p->dirY * cos(rotSpeed);
		double oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(rotSpeed) - p->planeY * sin(rotSpeed);
		p->planeY = oldPlaneX * sin(rotSpeed) + p->planeY * cos(rotSpeed);
	}
	return (0);
}

bool verLine(int x, int y1, int y2, int color, t_player *p)
{
	if(y2 < y1) {y1 += y2; y2 = y1 - y2; y1 -= y2;} //swap y1 and y2
	if(y2 < 0 || y1 >= h  || x < 0 || x >= w) return 0; //no single point of the line is on screen
	if(y1 < 0) y1 = 0; //clip
	if(y2 >= w) y2 = h - 1; //clip

	for(int y = y1; y <= y2; y++)
		p->img.data[y * screenWidth + x] = color;
	return 1;
}

void	test_img_init(t_player *p)
{
	p->img.ptr = mlx_new_image(p->mlx, screenWidth, screenHeight);
	p->img.data = (int *)mlx_get_data_addr(p->img.ptr, &p->img.bpp, &p->img.size_l, &p->img.endian);
}

void	draw_line(t_player *p, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY) ? fabs(deltaX) : fabs(deltaY));
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		p->img.data[(int)floor(y1) * screenWidth + (int)floor(x1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_lines(t_player *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mapWidth)
		draw_line(p, i * screenWidth / mini / mapWidth, 0, i * screenWidth / mini / mapWidth, screenHeight / mini);
	draw_line(p, screenWidth / mini - 1, 0, screenWidth / mini - 1, screenHeight / mini);
	j = -1;
	while (++j < mapHeight)
		draw_line(p, 0, j * screenHeight / mini / mapHeight, screenWidth / mini, j * screenHeight / mini / mapHeight);
	draw_line(p, 0, screenHeight / mini - 1, screenWidth / mini, screenHeight / mini - 1);
}

void	draw_rectangle(t_player *p, int x, int y)
{
	int	i;
	int	j;

	x *= screenWidth / mini / mapWidth;
	y *= screenHeight / mini / mapHeight;
	i = -1;
	while (++i < screenHeight / mini / mapHeight)
	{
		j = -1;
		while (++j < screenWidth / mini / mapWidth)
			p->img.data[(y + i) * screenWidth + x + j] = RGB_White;
	}
}

// void	draw_player(t_player *p, int x, int y)
// {
// 	int	i;
// 	int	j;
// 	double	p_x;
// 	double	p_y;
	
// 	p_x = (p->player.x - x) * TILE_SIZE;
// 	p_y = (p->player.y - y) * TILE_SIZE;
// 	// printf("x : %d\ty : %d\tpx : %f\tpy : %f\n", x, y, p_x, p_y);
// 	x *= TILE_SIZE;
// 	y *= TILE_SIZE;
// 	i = -1;
// 	while (++i < TILE_SIZE)
// 	{
// 		j = -1;
// 		while (++j < TILE_SIZE)
// 		{
// 			if (p_y < i && i < p_y + 8 && p_x < j && j < p_x + 8)
// 				p->mini_map.data[(y + i) * screenWidth + x + j] = 0xFF0000;
// 			else
// 				p->mini_map.data[(y + i) * screenWidth + x + j] = 0xFFFFFF;
// 		}
// 	}
// }

void	draw_rectangles(t_player *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mapHeight)
	{
		j = -1;
		while (++j < mapWidth)
		{
			if (worldMap[i][j] != 0)
				draw_rectangle(p, j, i);
			// if (ft_strchr("NSWE", worldMap[i][j]))
			// 	draw_player(p, j, i);
		}
	}
}

int	main_loop(t_player *p)
{
	for(int x = 0; x < w; ++x)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = p->dirX + p->planeX * cameraX;
		double rayDirY = p->dirY + p->planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)p->posX;
		int mapY = (int)p->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		//these are derived as:
		//deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
		//deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
		//which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
		//where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
		//unlike (dirX, dirY) is not 1, however this does not matter, only the
		//ratio between deltaDistX and deltaDistY matters, due to the way the DDA
		//stepping further below works. So the values can be computed as below.
		// Division through zero is prevented, even though technically that's not
		// needed in C++ with IEEE 754 floating point values.
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (p->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - p->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (p->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - p->posY) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(worldMap[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) drawEnd = h - 1;

		//choose wall color
		int color;	
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = RGB_Red;    break; //red
			case 2:  color = RGB_Green;  break; //green
			case 3:  color = RGB_Blue;   break; //blue
			case 4:  color = RGB_White;  break; //white
			default: color = RGB_Yellow; break; //yellow
		}

		//give x and y sides different brightness
		if(side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		verLine(x, drawStart, drawEnd, color, p);
	}
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	p->oldTime = p->time;
	p->time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	double frameTime = (p->time - p->oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
	// print(1.0 / frameTime); //FPS counter
	p->moveSpeed = frameTime * 5.0 * 2.0;
	p->rotSpeed = frameTime * 3.0 * 2.0;

	draw_rectangles(p);
	draw_lines(p);

	mlx_put_image_to_window(p->mlx, p->win, p->img.ptr, 0, 0);
	mlx_destroy_image(p->mlx, p->img.ptr);
	test_img_init(p);
	// int	i = -1;
	// while (++i < mapHeight * screenWidth)
	// 	p->img.data[i] = RGB_Black;
	// clear_img(p);
	return (0);
}

int main(void)
{
	t_player	p;

	p.mlx = mlx_init();
	p.posX = 22;
	p.posY = 12;
	p.dirX = -1;
	p.dirY = 0;
	p.planeX = 0;
	p.planeY = 0.66;
	p.time = 0; //time of current frame
	p.oldTime = 0; //time of previous frame
	p.moveSpeed = 0;
	p.rotSpeed = 0;

	p.mlx = mlx_init();
	if (!p.mlx)
		print_error("mlx init fail");
	p.win = mlx_new_window(p.mlx, screenWidth, screenHeight, "test_RC");
	test_img_init(&p);
	mlx_hook(p.win, X_EVENT_KEY_PRESS, 1, &deal_key, &p);
	mlx_loop_hook(p.mlx, &main_loop, &p);
	mlx_loop(p.mlx);
	return (0);
}