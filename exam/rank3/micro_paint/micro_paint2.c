#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	wid;
	float	hei;
	char	c;
}t_rect;

typedef struct s_draw
{
	int	wid;
	int	hei;
	char	*mat;
}t_draw;

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
	char	background;
	int	i;

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

int	is_in_rect(float x, float y, t_rect *rect)
{
	if (x < rect->x || rect->x + rect->wid < x || y < rect->y || rect->y + rect->hei < y)
		return (0);
	if (x - rect->x < 1.00000000 || rect->x + rect->wid - x < 1.00000000 || y - rect->y < 1.00000000 || rect->y + rect->hei - y < 1.00000000)
		return (2);
	return (1);
}

void	execute_one(t_rect *rect, t_draw *draw, int x, int y)
{
	int	is_in;

	is_in = is_in_rect((float)x, (float)y, rect);
	if (is_in == 2 || (is_in == 1 && rect->type == 'R'))
		draw->mat[x + y * draw->wid] = rect->c;
}

int	apply_op(t_rect *rect, t_draw *draw)
{
	int	i;
	int	j;

	if (rect->wid <= 0.00000000 || rect->hei <= 0.00000000 || (rect->type != 'R' && rect->type != 'r'))
		return (1);
	i = 0;
	while (i < draw->wid)
	{
		j = 0;
		while (j < draw->hei)
			execute_one(rect, draw, i, j++);
		i++;
	}
	return (0);
}

void	print_info(t_draw *draw)
{
	int	i;

	i = 0;
	while (i < draw->hei)
		printf("%.*s\n", draw->wid, draw->mat + i++ * draw->wid);
}

int	execute(FILE *file)
{
	int	scan;
	t_rect	rect;
	t_draw	draw;

	if (!get_info(file, &draw))
	{
		scan = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.wid, &rect.hei, &rect.c);
		while (scan != 6)
		{
			if (apply_op(&rect, &draw))
				return (1);
			scan = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.wid, &rect.hei, &rect.c);
		}
		if (scan == -1)
		{
			print_info(&draw);
			return (0);
		}
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