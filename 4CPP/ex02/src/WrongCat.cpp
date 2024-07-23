// 🐈

#include "animal.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << BGRN << "[WrongCat 🐈] Calling constructor" << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
    std::cout << BGRN << "[WrongCat 🐈] Calling copy constructor" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
    std::cout << GRN << "[WrongCat 🐈] Calling copy assignment operator" << RESET << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << BRED << "[WrongCat 🐈] Destroying WrongCat..." << RESET << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat 🐈] Meow!" << std::endl;
}
