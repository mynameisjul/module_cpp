#include <string>
#include <iostream>
#include "Contact.hpp"

Contact::Contact() {
	m_first_name = "";
	m_last_name = "";
	m_nickname = "";
	m_phone_number = "";
	m_darkest_secret = "";
}

void Contact::update_Contact(std::string	first_name,
							std::string last_name,
							std::string	nickname,
							std::string	phone_number,
							std::string darkest_secret) {
	m_first_name = first_name;
	m_last_name = last_name;
	m_nickname = nickname;
	m_phone_number = phone_number;
	m_darkest_secret = darkest_secret;
}

Contact::~Contact() {}

std::string	Contact::formatted_param(std::string p) {
	
}

void	Contact::display_one_line_Contact() {
	std::string	displayed;

	if (param.size() > 10)
		displayed = param.substr(0, 9) + ".";
	else
		displayed = param;
	std::cout.width(10); std::cout << std::right << displayed;
	if (last == true)
		std::cout << std::endl;
	else
		std::cout << "|";
}

void	Contact::display_full_Contact() {
	std::cout << "First name = " << m_first_name << std::endl;
	std::cout << "Last name = " << m_last_name << std::endl;
	std::cout << "Nickname = " << m_nickname << std::endl;
	std::cout << "Phone numer = " << m_phone_number << std::endl;
	std::cout << "Darkest secret = " << m_darkest_secret << std::endl;
}
