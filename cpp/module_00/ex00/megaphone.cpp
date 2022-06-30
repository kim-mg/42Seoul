/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:23:03 by myunkim           #+#    #+#             */
/*   Updated: 2022/06/29 17:10:50 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

static void	print_upper(char *str)
{
	while (*str)
		putchar(toupper(*str++));
}

static char	*join_str(char **str_arr)
{
	string rtn;

	while (*str_arr)
		rtn = rtn + *str_arr++;
	return rtn;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		std::cout << print_upper(join_str(&argv[1]));
	std::cout << "\n";
	return 0;
}