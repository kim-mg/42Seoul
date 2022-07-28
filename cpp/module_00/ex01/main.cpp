/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:35:43 by myunkim           #+#    #+#             */
/*   Updated: 2022/07/28 21:04:17 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::cur_ = 0;
int Contact::size_ = 0;

int	main() {
	std::string cmd;
	PhoneBook pb;

	while (true) {
		std::cout << std::endl << "Phonebook: ";
		std::getline(std::cin, cmd);
		std::cout << std::endl;
		if (!cmd.compare("EXIT"))
			exit(0);
		else if (!cmd.compare("ADD"))
			pb.add_proc();
		else if (!cmd.compare("SEARCH"))
			pb.search_proc();
		else
			std::cout << "usage : EXIT, ADD, SEARCH" << std::endl;
	}
	return 0;
}
