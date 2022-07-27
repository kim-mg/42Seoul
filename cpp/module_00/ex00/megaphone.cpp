/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:23:03 by myunkim           #+#    #+#             */
/*   Updated: 2022/07/25 22:01:01 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

std::string	make_upper(char *str)
{
	char		*tmp;

	tmp = str;
	while (*tmp)
		*tmp++ = static_cast<char>(toupper(*tmp));
	return std::string(str);
}

std::string	join_str(char **str_arr)
{
	std::string rtn;

	while (*str_arr)
		rtn = rtn + make_upper(*str_arr++);
	return rtn;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << join_str(&argv[1]) << std::endl;
	return 0;
}