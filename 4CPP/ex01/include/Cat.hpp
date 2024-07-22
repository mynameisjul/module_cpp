#ifndef CAT_HPP
#define CAT_HPP

#include "animal.h"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat const &other);
	Cat &operator=(Cat const &other);
	virtual ~Cat();
	virtual void makeSound() const;
};

#endif