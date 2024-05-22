#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index_of_last_added(-1), number_of_contacts(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::get_param(std::string message) {
	std::string param;

	while (param[0] == 0)
	{
		std::cout << message << std::endl;
		std::getline(std::cin, param);
		if (std::cin.eof())
			return ("");
		else if (param[0] == 0)
			std::cout << "Field shouldn't be empty. Please try again" << std::endl;
		else {
			for (size_t i = 0; i < param.size(); i++) {
				if (isalnum(param[i]) == 0) {
					param.clear();
					std::cout << "Please enter only alphanumeric caracters" << std::endl;
				}
			}
		}
	}
	return (param);
}

int	PhoneBook::update_PhoneBook() {
	std::string	fname;
	std::string lname;
	std::string nickname;
	std::string	number;
	std::string darkest_secret;

	fname = PhoneBook::get_param("Please enter the contact's first name");
	if (fname.empty())
		return (EXIT_FAILURE);
	lname = PhoneBook::get_param("Please enter the contact's last name");
	if (lname.empty())
		return (EXIT_FAILURE);
	nickname = PhoneBook::get_param("Please enter the contact's nickname");
	if (nickname.empty())
		return (EXIT_FAILURE);
	number = PhoneBook::get_param("Please enter the contact's number");
	if (number.empty())
		return (EXIT_FAILURE);
	darkest_secret = PhoneBook::get_param("Please enter the contact's darkest secret");
	if (darkest_secret.empty())
		return (EXIT_FAILURE);

	int i = (index_of_last_added + 1) % 8;
	contacts[i].update_Contact(fname, lname, nickname, number, darkest_secret);
	std::cout << "Contact has been added!" << std::endl;
	index_of_last_added = (index_of_last_added + 1) % 8;
	this->number_of_contacts += 1;
	return (EXIT_SUCCESS);
}

void	PhoneBook::display_PhoneBook() {
	for (int i = 0; i < 8; i++)
	{
		if (i >= number_of_contacts)
			return ;
		std::cout.width(10); std::cout << std::right << i + 1 << "|";
		contacts[i].display_one_line_Contact();
		std::cout << std::endl;
	}
}

int	PhoneBook::get_index() {
	std::string	input;
	int			output = -2;

	std::cout << "Please enter a valid index from 1 to the index of the last contact" << std::endl;
	if (!std::getline(std::cin, input) || std::cin.eof())
		return (-1);
	const char *charinput = input.c_str();
	output = atoi(charinput);
	if (output < 1 || output > number_of_contacts || output > 8)
		std::cout << "Index is out of range." << std::endl;
	return (output);
}

int	PhoneBook::search_PhoneBook() {
	int	index = -2;
	int i = 0;

	if (number_of_contacts == 0)
	{
		std::cout << "There are no contacts in this PhoneBook. Please add some" << std::endl;
		return (EXIT_SUCCESS);
	}
	PhoneBook::display_PhoneBook();
	while ((index < 1 || index > number_of_contacts || index > 8) && i < 3)
	{
		index = get_index();
		if (index == -1)
			return (EXIT_FAILURE);
		i++;
	}
	if (index > 0 && index <= number_of_contacts && index < 9)
		contacts[index - 1].display_full_Contact();
	return (EXIT_SUCCESS);
}