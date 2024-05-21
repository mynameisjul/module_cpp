#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string get_input() {
	std::string input = "";
	int			i = 0;

	while (input[0] == 0)
	{
		std::cout << "To start, enter a command [ADD, SEARCH, EXIT]" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("ADD") && input.compare("EXIT") && input.compare("SEARCH") && input.compare("HELP"))
			std::cout << "Invalid command. Please try again." << std::endl;
		else
			return (input);
		if (i > 2)
		{
			std::cout << " You seem to have troubles typing." << std::endl;
			std::cout << "To add a new contact, type 'ADD'." << std::endl;
			std::cout << "To search for a contact, type 'SEARCH'." << std::endl;
			std::cout << "To exit type 'EXIT'." << std::endl;
		}
		i++;
	}
	return (input);
}

void	add(PhoneBook &my_phonebook) {
	my_phonebook.update_PhoneBook();
}

void	search(PhoneBook &my_phonebook) {
	my_phonebook.search_PhoneBook();
}

int main(void) {
	std::string	cmd;
	PhoneBook	my_phonebook;

	std::cout << "Welcome to your ultra-modern phonebook" << std::endl;
	while (cmd.compare("EXIT"))
	{
		if (!cmd.compare("ADD"))
			add(my_phonebook);
		else if (!cmd.compare("SEARCH"))
			search(my_phonebook);
		cmd = get_input();
	}
	std::cout << "Phonebook will be exited and deleted . . ." << std::endl;
	return (0);
}