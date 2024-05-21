#pragma once

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string	m_first_name;
		std::string m_last_name;
		std::string	m_nickname;
		std::string	m_phone_number;
		std::string m_darkest_secret;
		void		display_param(std::string param, bool last);

	public:
		Contact();
		~Contact();
		void	update_Contact(std::string	first_name,
					std::string last_name,
					std::string	nickname,
					std::string	phone_number,
					std::string darkest_secret);
		void	display_one_line_Contact();
		void	display_full_Contact();
};

#endif