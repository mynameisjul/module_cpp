#include "animal.h"

AAnimal::AAnimal() : _type("default") {
    std::cout << BGRN << "[AAnimal] Creating default Aanimal" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
    std::cout << BGRN << "[AAnimal] Creating Aanimal of type " << type << RESET << std::endl;
}

AAnimal::AAnimal(AAnimal const &other)
{
    std::cout << BGRN << "[AAnimal] Calling copy constructor with type " << _type << RESET << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(AAnimal const &other)
{
    std::cout << BGRN << "[AAnimal] Calling copy assignement operator" << RESET << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << BRED << "[AAnimal] Destroying Aanimal of type " << _type << RESET << std::endl;
}

// ========== MEMBER FUNCTIONS, GETTERS, SETTERS
void AAnimal::makeSound() const
{
    std::cout << "Generic Aanimals do not make sounds" << std::endl;
}

std::string AAnimal::getType() const
{
    return (_type);
}

std::string *AAnimal::getIdeas() {
    return (0);
}

std::string AAnimal::getIdea(int index) {
    (void) index;
    return (0);
}

void AAnimal::setIdea(int index, std::string idea) {
    (void) index;
    (void) idea;
}