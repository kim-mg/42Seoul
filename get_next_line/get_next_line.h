/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 23:58:21 by myunkim           #+#    #+#             */
/*   Updated: 2022/04/01 22:35:42 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_info
{
	char	*sto[OPEN_MAX];
	char	*buf;
	ssize_t	r_size;
	ssize_t	nl_idx;
	ssize_t	sto_size;
	ssize_t	aloc_size;
	int		a_size;
}			t_info;

char	*ft_strndup(const char *s, int size);
char	*ft_strjoin_gnl(char const *s1, char const *s2, t_info *info);
size_t	ft_strlcat_gnl(char *dst, const char *src,
			size_t dstsize, t_info *info);

ssize_t	ft_findnl(char *s);
void	get_info(char **fd, t_info *info);
char	*get_line(char **sto, t_info *info);
char	*check_eof(char **sto, t_info *info);
char	*get_next_line(int fd);

#endif
