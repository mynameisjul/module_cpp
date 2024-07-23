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
    virtual ~Animal();
    virtual void makeSound() const = 0;
	std::string getType() const;

	virtual std::string *getIdeas();
	virtual std::string getIdea(int index);
	virtual void setIdea(int index, std::string idea);
};

#endif