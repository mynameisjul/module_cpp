#include "animal.h"

// ========== MEMBER FUNCTIONS
void Cat::makeSound() const {
    std::cout << "[Cat 🐈] Meow!" << std::endl;
}

// ========== BRAIN GETTERS AND SETTERS
std::string *Cat::getIdeas() {
    std::cout << "[Cat 🐈] Calling ideas getter" << std::endl;
    if (_brain)
        return (_brain->getIdeas());
    return (0);
}

std::string Cat::getIdea(int index) {
    if (_brain && index >= 0 && index < MAX_IDEAS) {
        std::cout << "[Cat 🐈] Calling brain getter for idea of index " << index << std::endl;
        return (_brain->getIdea(index));
    }
    return (0);
}

void Cat::setIdea(int index, std::string idea) {
    if (_brain && index >= 0 && index < MAX_IDEAS) {
        std::cout << "[Cat 🐈] Calling brain setter for idea of index " << index << std::endl;
        _brain->setIdea(index, idea);
        }
}

// ========== CONSTRUCTORS AND DESTRUCTOR
Cat::Cat() : Animal("Cat") {
    std::cout << BGRN << "[Cat 🐈] Calling constructor" << RESET << std::endl;
    _brain = new Brain("I hate hoomans");
}

Cat::Cat(Cat const &other) : Animal(other) {
    std::cout << BGRN << "[Cat 🐈] Calling copy constructor" << RESET << std::endl;
    *this = other;
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << GRN << "[Cat 🐈] Calling copy assignment operator" << RESET << std::endl;
    if (this != &other)
        Animal::operator=(other);
    *this->_brain = *other._brain;
    return (*this);
}

Cat::~Cat() {
    std::cout << BRED << "[Cat 🐈] Destroying cat..." << RESET << std::endl;
    delete _brain;
}
