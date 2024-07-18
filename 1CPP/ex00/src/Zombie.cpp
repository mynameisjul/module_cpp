#include "Zombie.h"

Zombie::Zombie() : _name("Random Zombie") {
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie() {
	std::cout << BRED << _name << " has been destroyed*" << RESET << std::endl;
	std::cout << "." << std::endl;
	std::cout << "." << std::endl;
	std::cout << "." << std::endl;
	std::cout << "*this message was delivered to you by this way too talkative Zombie class" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}