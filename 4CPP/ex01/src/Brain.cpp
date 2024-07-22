#include "animal.h"

// ========== CONSTRUCTORS AND DESTRUCTOR
Brain::Brain() {
	std::cout << BGRN << "[🧠 Brain] Calling default constructor" << RESET << std::endl;
}

Brain::Brain(std::string idea) {
	std::cout << BGRN << "[🧠 Brain] Calling overload constructor" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

Brain::Brain(Brain const &other) {
	std::cout << BGRN << "[🧠 Brain] Calling copy constructor" << RESET << std::endl;
	*this = other;
}

Brain & Brain::operator=(Brain const &other) {
	std::cout << BCYN << "[🧠 Brain] Calling copy assignment operator" << RESET << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << BRED << "[🧠 Brain] Calling destructor" << RESET << std::endl;
}

// ========== GETTERS AND SETTERS
std::string *Brain::getIdeas() {
	return(_ideas);
}

std::string getIdea(int index) {
	return (_ideas[index]);
}

void setIdea(int index, std::string idea) {
	_ideas[index] = idea;
}