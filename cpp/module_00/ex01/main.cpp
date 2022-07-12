/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:35:43 by myunkim           #+#    #+#             */
/*   Updated: 2022/07/01 18:08:43 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

struct s_pbook
{
	char	first_name[30];
	char	last_name[30];
	char	nick_name[30];
	char	phone_num[30];
	char	darkest_secret[100];
}t_pbook;

int	main()
{
	std::string	cmd;
	// t_pbook	pb[8];

	while (std::cout << "Phonebook: ")
	{
		std::cin.ignore('\n') >> cmd;
		if (!strncmp("EXIT", cmd, strlen(cmd) + 1))
			exit(0);
	}
	return 0;
}