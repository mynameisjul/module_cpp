#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include "animal.h"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat const &other);
	WrongCat &operator=(WrongCat const &other);
	virtual ~WrongCat();
	void makeSound() const;
};

#endif /* WRONG_CAT_H */