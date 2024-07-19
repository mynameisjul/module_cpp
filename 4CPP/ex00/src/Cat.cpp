// 🐈 

#include "animal.h"

Cat::Cat() : Animal("Cat")
{
    std::cout << BGRN << "[Cat 🐈] Calling constructor" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other)
{
    std::cout << BGRN << "[Cat 🐈] Calling copy constructor" << std::endl;
}

Cat & Cat::operator=(Cat const &other)
{
    std::cout << GRN << "[Cat 🐈] Calling copy assignment operator" << RESET << std::endl;
    if (this != &other)
        Animal::operator=(other);
	return (*this);
}

Cat::~Cat()
{
    std::cout << BRED << "[Cat 🐈] Destroying cat..." << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat 🐈] Meow!" << std::endl;
}
