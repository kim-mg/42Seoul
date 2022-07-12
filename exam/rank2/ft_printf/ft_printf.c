#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_form
{
	int pre;
	int dot;
	int wid;
}t_form;

int	ft_strlen(char *s)
{
	char	*t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

char	*ft_strdup(char *s)
{
	int	i;
	char	*rtn;

	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	while (*(s + i))
	{
		*(rtn + i) = *(s + i);
		i++;
	}
	return (rtn);
}

int	print_str(va_list ap, t_form *f)
{
	int	i;
	int	len;
	int	rtn;
	char	*line;
	int	n_flag;
	// int	pre_flag;
	
	rtn = 0;
	line = NULL;
	n_flag = 0;
	// pre_flag = 0;
	line = va_arg(ap, char *);
	if (line == NULL)
	{
		line = ft_strdup("(null)");
		n_flag = 1;
	}
	len = ft_strlen(line);
	// if (f->pre)
	// 	pre_flag = 1;
	if (f->dot)
	{
		if (f->pre > len)
			f->pre = len;
	}
	else
		f->pre = len;
	i = -1;
	while (++i < f->wid - f->pre)
	{
		write(1, " ", 1);
		rtn++;
	}
	i = 0;
	rtn += f->pre;
	write(1, line, f->pre);
	if (n_flag)
		free(line);
	return (rtn);
}

int	ft_numlen_dec(int num)
{
	int	i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

int	ft_numlen_hex(unsigned int unum)
{
	int	i;

	i = 1;
	while (unum /= 16)
		i++;
	return (i);
}

void	ft_putnum_dec(int num)
{
	if (num == -2147483648)
	{
		ft_putnum_dec(num / 10);
		ft_putnum_dec(num % 10);
	}
	if (num < 0)
		num = num * -1;
	if (num < 10)
		write(1, &"0123456789"[num], 1);
	else
	{
		ft_putnum_dec(num / 10);
		ft_putnum_dec(num % 10);
	}
}

void	ft_putnum_hex(unsigned int unum)
{
	if (unum < 16)
		write(1, &"0123456789abcdef"[unum], 1);
	else
	{
		ft_putnum_hex(unum / 16);
		ft_putnum_hex(unum % 16);
	}
}

int	print_num(va_list ap, t_form *f, int hex)
{
	int	rtn;
	int	num;
	unsigned int	unum;
	int	len;
	int	i;

	num = 0;
	unum = 0;
	rtn = 0;
	len = 0;
	if (hex)
		unum = va_arg(ap, unsigned int);
	else
		num = va_arg(ap, int);
	if (hex)
		len = ft_numlen_hex(unum);
	else
		len = ft_numlen_dec(num);
	if (num == 0 && unum == 0 && f->dot && f->pre == 0)
	{
		while (rtn < f->wid)
		{
			write(1, " ", 1);
			rtn++;
		}
		return (rtn);
	}
	if (len > f->pre)
		f->pre = len;
	if (num < 0)
		f->pre++;
	i = -1;
	while (++i < f->wid - f->pre)
	{
		write(1, " ", 1);
		rtn++;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		f->pre--;
		rtn++;
	}
	i = -1;
	while (++i < f->pre - len)
		write(1, "0", 1);
	if (hex)
		ft_putnum_hex(unum);
	else
		ft_putnum_dec(num);
	rtn += f->pre;
	return (rtn);
}

int	run_proc(char *s, va_list ap)
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
			f.wid = 0;
			while (*s && (*s != 's' && *s != 'd' && *s != 'x'))
			{
				if (!f.dot && '0' <= *s && *s <= '9')
					f.wid = f.wid * 10 + (*s - '0');
				else if (*s == '.')
					f.dot = 1;
				else if (f.dot && '0' <= *s && *s <= '9')
					f.pre = f.pre * 10 + (*s - '0');
				s++;
			}
			if (*s == '\0')
				break ;
			if (*s == 's')
				rtn += print_str(ap, &f);
			if (*s == 'd')
				rtn += print_num(ap, &f, 0);
			if (*s == 'x')
				rtn += print_num(ap, &f, 1);
		}
		else
		{
			write(1, s, 1);
			rtn++;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (rtn);
}

int ft_printf(const char *s, ...)
{
	int	rtn;
	va_list	ap;

	if (!s)
		return (-1);
	rtn = 0;
	va_start(ap, s);
	rtn += run_proc((char *)s, ap);
	va_end(ap);
	return (rtn);
}