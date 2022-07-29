/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:46:57 by myunkim           #+#    #+#             */
/*   Updated: 2022/07/29 22:41:13 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::set_data(int data_type, std::string* data) {
	if (data_type == 1)
		first_name_ = *data;
	if (data_type == 2)
		last_name_ = *data;
	if (data_type == 3)
		nickname_ = *data;
	if (data_type == 4)
		phone_number_ = *data;
	if (data_type == 5)
		darkest_secret_ = *data;
}

std::string Contact::get_data(int data_type) const {
	if (data_type == 1)
		return first_name_;
	if (data_type == 2)
		return last_name_;
	if (data_type == 3)
		return nickname_;
	if (data_type == 4)
		return phone_number_;
	if (data_type == 5)
		return darkest_secret_;
	return NULL;
}

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

std::string PhoneBook::truncate(std::string s) const {
	if (s.length() > 10) {
		s[9] = '.';
		s.erase(10);
	}
	return s;
}

void PhoneBook::get_cmd(void) {
	std::cout << std::endl << "Phonebook: ";
	std::getline(std::cin >> std::ws, cmd_);
	std::cout << std::endl;
}

void PhoneBook::add_proc(void) {
	std::string str;

	std::cout << "1. first name : ";
	std::getline(std::cin >> std::ws, str);
	cont_[cur_].set_data(1, &str);
	std::cout << "2. last name : ";
	std::getline(std::cin >> std::ws, str);
	cont_[cur_].set_data(2, &str);
	std::cout << "3. nickname : ";
	std::getline(std::cin >> std::ws, str);
	cont_[cur_].set_data(3, &str);
	std::cout << "4. phone number : ";
	std::getline(std::cin >> std::ws, str);
	cont_[cur_].set_data(4, &str);
	std::cout << "5. darkest secret : ";
	std::getline(std::cin >> std::ws, str);
	cont_[cur_].set_data(5, &str);
	cur_++;
	cur_ %= 8;
	if (size_ < 8)
		size_++;
}

void PhoneBook::find_proc(void) const {
	int idx;
	int size = size_;

	while (true) {
		std::cout << std::endl << "search from index (exit is '0') : ";
		std::cin >> idx;
		if (std::cin.fail() || idx < 0 || size < idx) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "wrong index" << std::endl;
			continue ;
		}
		break ;
	}
	if (!idx)
		return ;
	std::cout << std::endl
		<< "1. first name : " << cont_[idx - 1].get_data(1) << std::endl
		<< "2. last name : " << cont_[idx - 1].get_data(2) << std::endl
		<< "3. nickname : " << cont_[idx - 1].get_data(3) << std::endl
		<< "4. phone number : " << cont_[idx - 1].get_data(4) << std::endl
		<< "5. darkest secret : " << cont_[idx - 1].get_data(5) << std::endl;
}

void PhoneBook::search_proc(void) const {
	int size = size_;

	if (!size) {
		std::cout << "empty book" << std::endl;
		return ;
	}
	std::cout << std::endl << "|"
		<< std::setw(10) << std::setfill(' ') << "index" << "|"
		<< std::setw(10) << std::setfill(' ') << "first name" << "|"
		<< std::setw(10) << std::setfill(' ') << "last name" << "|"
		<< std::setw(10) << std::setfill(' ') << "nickname" << "|"
		<< std::endl;
	for (int i = 0; i < size ; i++) {
		std::cout << "|"
			<< std::setw(10) << std::setfill(' ') << i + 1 << "|"
			<< std::setw(10) << std::setfill(' ') << truncate(cont_[i].get_data(1)) << "|"
			<< std::setw(10) << std::setfill(' ') << truncate(cont_[i].get_data(2)) << "|"
			<< std::setw(10) << std::setfill(' ') << truncate(cont_[i].get_data(3)) << "|"
			<< std::endl;
	}
	find_proc();
}

PhoneBook::PhoneBook(void)
	: size_(0), cur_(0) {
}

PhoneBook::~PhoneBook(void) {
}
