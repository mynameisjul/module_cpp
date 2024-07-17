#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "animal.h"

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(std::string type);
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);
    ~Animal();
    virtual void makeSound() const;
};

#endif