#pragma once

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
		int			index_of_last_added;
		int			number_of_contacts;
		Contact		contacts[8];
		std::string get_param(std::string message);
		int			get_index();

	public:
					PhoneBook();
					~PhoneBook();
		int			update_PhoneBook();
		void		display_PhoneBook();
		int			search_PhoneBook();
};

#endif