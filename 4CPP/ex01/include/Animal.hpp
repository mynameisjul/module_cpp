#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "animal.h"

class Animal
{
protected:
    std::string _type;
    Brain       *_brain;

public:
    Animal();
    Animal(std::string type);
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const;
    std::string *getIdeas();
    std::string getIdea(int index);
    void setIdea(int index, std::string idea);
};

#endif