#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include "animal.h"

class WrongAnimal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(std::string type);
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);
    virtual ~Animal();
    void makeSound() const;
};

#endif /* WRONG_ANIMAL_HPP */
