/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:46:59 by myunkim           #+#    #+#             */
/*   Updated: 2022/07/28 21:04:21 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>

class Contact {
private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;

public:
	static int size_;
	void set_data(int, std::string*);
	std::string get_data(int) const;

	Contact();
	~Contact();
};

class PhoneBook {
private:
	Contact cont_[8];

	std::string truncate(std::string);
	void find_proc(void);

public:
	static int cur_;
	void add_proc(void);
	void search_proc(void);
	
	PhoneBook();
	~PhoneBook();
};

#endif