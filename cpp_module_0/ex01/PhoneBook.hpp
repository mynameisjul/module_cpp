#pragma once

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
		int		index_of_last_added;
		Contact	*contacts[8];
		std::string get_param(std::string message);
		void	display_one_line_Contact(int index, bool last);

	public:
		PhoneBook();
		~PhoneBook();
		void	update_PhoneBook();
		void	display_PhoneBook();
};

#endif