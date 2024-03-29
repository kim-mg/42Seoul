/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:35:43 by myunkim           #+#    #+#             */
/*   Updated: 2022/08/01 14:25:20 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook pb;

	while (true) {
		pb.get_cmd();
		if (!pb.cmd_.compare("EXIT"))
			exit(0);
		else if (!pb.cmd_.compare("ADD"))
			pb.add_proc();
		else if (!pb.cmd_.compare("SEARCH"))
			pb.search_proc();
		else
			std::cout << "usage : EXIT, ADD, SEARCH" << std::endl;
	}
	return 0;
}
