#include "animal.h"

// ========== BRAIN GETTERS AND SETTERS
std::string *Dog::getIdeas() {
    std::cout << "[Dog 🐕] Calling ideas getter" << std::endl;
    if (_brain)
        return (_brain->getIdeas());
    return (0);
}

std::string Dog::getIdea(int index) {
    std::cout << "[Dog 🐕] Calling brain getter for idea of index " << index << std::endl;
    if (_brain && index >= 0 && index < MAX_IDEAS)
        return (_brain->getIdea(index));
    return (0);
}

void Dog::setIdea(int index, std::string idea) {
    std::cout << "[Dog 🐕] Calling brain setter for idea of index " << index << std::endl;
    if (_brain && index >= 0 && index < MAX_IDEAS)
        _brain->setIdea(index, idea);
}

// ========== MEMBER FUNCTIONS

void Dog::makeSound() const {
    std::cout << "[Dog 🐕] Woof!" << std::endl;
}

// ========== CONSTRUCTORS AND DESTRUCTOR
Dog::Dog() : AAnimal("Dog"){
    std::cout << BGRN << "[Dog 🐕] Calling constructor" << RESET << std::endl;
    _brain = new Brain("I wanna be the goodest boy EVER!");
}

Dog::Dog(Dog const &other) : AAnimal(other){
    std::cout << BGRN << "[Dog 🐕] Calling copy constructor" << RESET << std::endl;
    *this = other;
}

Dog &Dog::operator=(Dog const &other){
    std::cout << GRN << "[Dog 🐕] Calling copy assignment operator" << RESET << std::endl;
    if (this != &other)
        AAnimal::operator=(other);
    *this->_brain = *other._brain;
    return (*this);
}

Dog::~Dog(){
    std::cout << BRED << "[Dog 🐕] Destroying dog..." << RESET << std::endl;
    delete _brain;
}
