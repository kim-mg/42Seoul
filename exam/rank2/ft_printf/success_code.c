#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

static int	ft_strlen(char *s)
{
	char	*t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

static char	*ft_strdup(char *s)
{
	char	*rtn;
	int	i;

	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (*s)
	{
		*(rtn + i) = *s;
		s++;
		i++;
	}
	*(rtn + i) = '\0';
	return (rtn);
}

static int	print_str(va_list ap)
{
	char	*line;
	int	rtn;
	int	len;

	rtn = 0;
	line = va_arg(ap, char *);
	if (!line)
		line = ft_strdup("(null)");
	len = ft_strlen(line);
	write(1, line, len);
	rtn += len;
	return (rtn);
}

static int	ft_numlen_dec(int num)
{
	int	i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

static int	ft_numlen_hex(unsigned int unum)
{
	int	i;

	i = 1;
	while (unum /= 16)
		i++;
	return (i);
}

static void	ft_putnbr_dec(int num)
{
	if (num == -2147483648)
	{
		ft_putnbr_dec(num / 10);
		ft_putnbr_dec(num % 10);
	}
	if (num < 0)
		num *= -1;
	if (num < 10)
		write(1, &"0123456789"[num], 1);
	else
	{
		ft_putnbr_dec(num / 10);
		ft_putnbr_dec(num % 10);
	}
}

static void	ft_putnbr_hex(unsigned int unum)
{
	if (unum < 16)
		write(1, &"0123456789abcdef"[unum], 1);
	else
	{
		ft_putnbr_hex(unum / 16);
		ft_putnbr_hex(unum % 16);
	}
}

static int	print_num(va_list ap, int hex)
{
	int	rtn;
	int	num;
	unsigned int	unum;
	int	len;

	rtn = 0;
	num = 0;
	unum = 0;
	len = 0;
	if (hex)
	{
		unum = va_arg(ap, unsigned int);
		len = ft_numlen_hex(unum);
	}
	else
	{
		num = va_arg(ap, int);
		len = ft_numlen_dec(num);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		rtn++;
	}
	if (hex)
		ft_putnbr_hex(unum);
	else
		ft_putnbr_dec(num);
	rtn += len;
	return (rtn);
}

static int	run_proc(char *s, va_list ap)
{
	int	rtn;

	rtn = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '\0')
				break ;
			if (*s == 's')
				rtn += print_str(ap);
			if (*s == 'd')
				rtn += print_num(ap, 0);
			if (*s == 'x')
				rtn += print_num(ap, 1);
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

int	ft_printf(const char *s, ...)
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