#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "animal.h"

class AAnimal
{
protected: 
    std::string _type;

public:
    AAnimal();
    AAnimal(std::string type);
    AAnimal(AAnimal const &other);
    AAnimal &operator=(AAnimal const &other);
    virtual ~AAnimal();
    virtual void makeSound() const = 0;
	std::string getType() const;

	virtual std::string *getIdeas();
	virtual std::string getIdea(int index);
	virtual void setIdea(int index, std::string idea);
};

#endif