#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_drawing
{
	int width;
	int height;
	char *matrix;
}t_drawing;

typedef struct s_rectangle
{
	char type;
	float x;
	float y;
	float width;
	float height;
	char color;
}t_rectangle;

int	ft_strlen(char *s)
{
	char *t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

void	error_msg(char *s)
{
	write(1, s, ft_strlen(s));
}

int	get_info(FILE *file, t_drawing *drawing)
{
	char *tmp;
	int i;
	char background;

	if (fscanf(file, "%d %d %c\n", &drawing->width, &drawing->height, &background) == 3)
	{
		if ((drawing->width < 1) || (300 < drawing->width)
			|| (drawing->height < 1) || (300 < drawing->height))
			return (1);
		tmp = (char *)malloc(drawing->width * drawing->height);
		drawing->matrix = tmp;
		if (!drawing->matrix)
			return (1);
		i = 0;
		while (i < drawing->width * drawing->height)
			drawing->matrix[i++] = background;
		return (0);
	}
	return (1);
}

int	is_in_rectangle(float x, float y, t_rectangle *rect)
{
	if ((x < rect->x) || (rect->x + rect->width < x)
		|| (y < rect->y) || (rect->y + rect->height < y))
		return (0);
	if ((x - rect->x < 1.00000000) || (rect->x + rect->width - x < 1.00000000)
		|| (y - rect->y < 1.00000000) || (rect->y + rect->height - y < 1.00000000))
		return (2);
	return (1);
}

void	execute_one(t_rectangle *rect, t_drawing *drawing, int x, int y)
{
	int is_in;

	is_in = is_in_rectangle((float)x, (float)y, rect);
	if ((is_in == 2) || ((is_in == 1) && (rect->type == 'R')))
		drawing->matrix[x + y * drawing->width] = rect->color;
	return ;
}

int	apply_op(t_rectangle *rect, t_drawing *drawing)
{
	int i;
	int j;

	if (((rect->width <= 0.00000000) || (rect->height <= 0.00000000))
		|| ((rect->type != 'R') && (rect->type !='r')))
		return (1);
	i = 0;
	while (i < drawing->width)
	{
		j = 0;
		while (j < drawing->height)
			execute_one(rect, drawing, i, j++);
		i++;
	}
	return (0);
}

void	print_info(t_drawing *zone)
{
	int i;

	i = 0;
	while (i < zone->height)
		printf("%.*s\n", zone->width, zone->matrix + i++ * zone->width);
}

int	execute(FILE *file)
{
	int	scan_ret;
	t_rectangle rect;
	t_drawing drawing;
	
	if (!get_info(file, &drawing))
	{
		scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type,
			&rect.x, &rect.y, &rect.width, &rect.height, &rect.color);
		while (scan_ret == 6)
		{
			if (apply_op(&rect, &drawing))
				return (1);
			scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type,
				&rect.x, &rect.y, &rect.width, &rect.height, &rect.color);
		}
		if (scan_ret == -1)
		{
			print_info(&drawing);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	FILE *file;

	if (--argc == 1)
	{
		file = fopen(argv[1], "r");
		if (file && !execute(file))
			return (0);
		error_msg("Error: Operation file corrupted\n");
	}
	else
		error_msg("Error: argument\n");
	return (1);
}