#include "animal.h"

WrongAnimal::WrongAnimal() : _type("default")
{
    std::cout << BGRN << "[WrongAnimal] Creating default WrongAnimal" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << BGRN << "[WrongAnimal] Creating WrongAnimal of type " << type << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
    std::cout << BGRN << "[WrongAnimal] Calling copy constructor with type " << _type << RESET << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
    std::cout << BGRN << "[WrongAnimal] Calling copy assignement operator" << RESET << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << BRED << "[WrongAnimal] Destroying WrongAnimal of type " << _type << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Generic WrongAnimals do not make sounds" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}