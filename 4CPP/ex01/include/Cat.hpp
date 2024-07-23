#ifndef CAT_HPP
#define CAT_HPP

#include "animal.h"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(Cat const &other);
		Cat &operator=(Cat const &other);
		virtual ~Cat();
		
		virtual void makeSound() const;

		std::string *getIdeas();
		std::string getIdea(int index);
		void setIdea(int index, std::string idea);
};

#endif