#ifndef DOG_HPP
#define DOG_HPP

#include "animal.h"

class Dog : public Animal
{
public:
    Dog();
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);
    ~Dog();
}

#endif