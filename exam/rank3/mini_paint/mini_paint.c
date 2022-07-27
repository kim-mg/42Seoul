#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

typedef struct s_draw
{
	int	wid;
	int	hei;
	char	*mat;
}t_draw;

typedef struct s_cir
{
	char	type;
	float	x;
	float	y;
	float	rad;
	char	c;
}t_cir;

int	ft_strlen(char *s)
{
	char	*t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

void	error_printnl(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

int	get_info(FILE *file, t_draw *draw)
{
	char	*tmp;
	int	i;
	char	background;

	if (fscanf(file, "%d %d %c\n", &draw->wid, &draw->hei, &background) == 3)
	{
		if (draw->wid < 1 || 300 < draw->wid || draw->hei < 1 || 300 < draw->hei)
			return (1);
		tmp = (char *)malloc(draw->wid * draw->hei);
		draw->mat = tmp;
		if (!draw->mat)
			return (1);
		i = 0;
		while (i < draw->wid * draw->hei)
			draw->mat[i++] = background;
		return (0);
	}
	return (1);
}

float	square(float a)
{
	return (a * a);
}

float	sq_dist(float x1, float y1, float x2, float y2)
{
	float	dist_x;
	float	dist_y;

	dist_x = square(x1 - x2);
	dist_y = square(y1 - y2);
	return (dist_x + dist_y);
}

int	is_in_cir(float x, float y, t_cir *cir)
{
	float	dist;
	float	dist_sqrt;

	dist_sqrt = sqrtf(sq_dist(x, y, cir->x, cir->y));
	dist = dist_sqrt - cir->rad;
	if (dist <= 0.00000000)
	{
		if (dist <= -1.00000000)
			return (1);
		return (2);
	}
	return (0);
}

void	execute_one(t_cir *cir, t_draw *draw, int x, int y)
{
	int	is_in;

	is_in = is_in_cir((float)x, (float)y, cir);
	if (is_in == 2 || (is_in == 1 && cir->type == 'C'))
		draw->mat[x + y * draw->wid] = cir->c;
}

int	apply_op(t_cir *cir, t_draw *draw)
{
	int	i;
	int	j;

	if (cir->rad <= 0.00000000 || (cir->type != 'C' && cir->type != 'c'))
		return (1);
	i = 0;
	while (i < draw->wid)
	{
		j = 0;
		while (j < draw->hei)
			execute_one(cir, draw, i, j++);
		i++;
	}
	return (0);
}

void	print_info(t_draw *draw)
{
	int	i;

	i = 0;
	while (i < draw->hei)
	{
		write(1, draw->mat + i++ * draw->wid, draw->wid);
		write(1, "\n", 1);
	}
}

int	execute(FILE *file)
{
	int	scan;
	t_cir	cir;
	t_draw	draw;

	if (!get_info(file, &draw))
	{
		scan = fscanf(file, "%c %f %f %f %c\n", &cir.type, &cir.x, &cir.y, &cir.rad, &cir.c);
		while (scan == 5)
		{
			if (apply_op(&cir, &draw))
				return (1);
			scan = fscanf(file, "%c %f %f %f %c\n", &cir.type, &cir.x, &cir.y, &cir.rad, &cir.c);
		}
		if (scan == -1)
		{
			print_info(&draw);
			return (0);
		}
		return (1);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	FILE	*file;

	if (--argc == 1)
	{
		file = fopen(argv[1], "r");
		if (file && !execute(file))
			return (0);
		error_printnl("Error: Operation file corrupted");
	}
	else
		error_printnl("Error: argument");
	return (1);
}