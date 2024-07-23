#ifndef DOG_HPP
#define DOG_HPP

#include "animal.h"

class Dog : public Animal
{
    private:
        Brain   *_brain;
    public:
        Dog();
        Dog(Dog const &other);
        Dog &operator=(Dog const &other);
        virtual ~Dog();

        virtual void makeSound() const;

		std::string *getIdeas();
		std::string getIdea(int index);
		void setIdea(int index, std::string idea);
};

#endif