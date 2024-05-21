#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index_of_last_added(-1) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::get_param(std::string message) {
	std::string param;

	while (param[0] = 0)
	{
		std::cout << message << std::endl;
		std::getline(std::cin, param);
		if (param[0] = 0)
			std::cout << "Field shouldn't be empty. Please try again" << std::endl;
	}
	return (param);
}

void	PhoneBook::update_PhoneBook() {
	std::string	fname;
	std::string lname;
	std::string nickname;
	std::string	number;
	std::string darkest_secret;

	fname = PhoneBook::get_param("Please enter the contact's first name");
	lname = PhoneBook::get_param("Please enter the contact's last name");
	nickname = PhoneBook::get_param("Please enter the contact's nickname");
	number = PhoneBook::get_param("Please enter the contact's number");
	darkest_secret = PhoneBook::get_param("Please enter the contact's darkest secret");

	int i = (index_of_last_added + 1) % 8;
	contacts[i].update_Contact(fname, lname, nickname, number, darkest_secret);
	std::cout << "Contact has been added!" << std::endl;
}

void	PhoneBook::display_PhoneBook() {
	for (int i, i < 8, i++)
	{
		std::cout.width(10); std::cout << std::right << i << "|";
		PhoneBook::display_param(this.contacts[i].)
		std::cout << std::endl;
	}
}
