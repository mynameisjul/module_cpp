#include <string>
#include <iostream>
#include <sstream>
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
			param.clear();
		else if (param[0] == 0)
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
	index_of_last_added = (index_of_last_added + 1) % 8;
	this->number_of_contacts += 1;
}

void	PhoneBook::display_PhoneBook() {
	for (int i = 0; i < 8; i++)
	{
		if (i >= number_of_contacts)
			return ;
		std::cout.width(10); std::cout << std::right << i << "|";
		contacts[i].display_one_line_Contact();
		std::cout << std::endl;
	}
}

int	PhoneBook::get_index() {
	std::string	input;
	int			output = -2;

	while (output < -1 || output >= number_of_contacts)
	{
		std::cout << "Please enter a valid index from 0 to the index of the last contact" << std::endl;
		std::getline(std::cin, input);
		std::stringstream ss(input);
		ss >> output;
		if (ss.fail() || !ss.eof())
		{
			ss.clear();
			output = -2;
		}
		if (ss.eof())
			return (-2);
		if (output < -1)
			std::cout << "Invalid input." << std::endl;
		if (output >= number_of_contacts)
			std::cout << "This contact does not exist [index is too high]" << std::endl;
	}
	return (output);
}

void	PhoneBook::search_PhoneBook() {
	int	index = -2;

	if (number_of_contacts == 0)
	{	std::cout << "There are no contacts in this PhoneBook. Please add some" << std::endl;
		return ;
	}
	PhoneBook::display_PhoneBook();
	while (index == -2)
		index = get_index();
	if (index != -2)
		contacts[index].display_full_Contact();	
}