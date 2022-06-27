#include <unistd.h>
#include <stdarg.h>

typedef struct s_form
{
	int pre;
	int dot;
	int width;
}           t_form;

int	ft_strlen(char *s)
{
	char    *t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

void	ft_strnput(char *s, int size)
{
	int i;

	i = -1;
	while (++i < size)
		write(1, s + i, 1);
}

int	print_str(char *s, t_form *f)
{
	int i;
	int len;
	int	rtn;
	
	rtn = 0;
	len = ft_strlen(s);
	if (f->dot)
	{
		if (f->pre > len)
			f->pre = len;
	}
	else
		f->pre = len;
	i = -1;
	while (++i < f->width - f->pre)
	{
		write(1, " ", 1);
		rtn++;
	}
	rtn += f->pre;
	if (f->dot)
		ft_strnput(s, f->pre);
	else
		ft_strnput(s, len);
	return (rtn);
}

int	run_proc(char *s, va_list *ap)
{
	int	rtn;
	t_form	f;

	rtn = 0;
	while (*s)
	{
		if (*s == '%')
		{
			f.pre = 0;
			f.dot = 0;
			f.width = 0;
			while (*s && *s != 's' && *s != 'd' && *s != 'x')
			{
				if (!f.dot && '0' <= *s && *s <= '9')
					f.width = f.width * 10 + (*s - '0');
				else if (*s == '.')
					f.dot = 1;
				else if (f.dot && '0' <= *s && *s <= '9')
					f.pre = f.pre * 10 + (*s - '0');
				s++;
			}
			if (*s == 's')
				rtn += print_str(va_arg(*ap, char *), &f);
			// if (*s == 'd')
				// print_num(va_arg(*ap, int), &f, rtn, 10);
			// if (*s == 'x')
				// print_num(va_arg(*ap, unsigned int), &f, rtn, 16);
		}
		else
		{
			write(1, s, 1);
			rtn++;
		}
		s++;
	}
	return (rtn);
}

int ft_printf(const char *s, ...)
{
	int	rtn;
	va_list	ap;

	rtn = 0;
	va_start(ap, s);
	rtn += run_proc((char *)s, &ap);
	va_end(ap);
	return (rtn);
}