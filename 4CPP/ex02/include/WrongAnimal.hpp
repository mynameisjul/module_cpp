#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include "animal.h"

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(WrongAnimal const &other);
    WrongAnimal &operator=(WrongAnimal const &other);
    virtual ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};

#endif /* WRONG_ANIMAL_HPP */
