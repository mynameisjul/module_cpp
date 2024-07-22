#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "animal.h"

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(std::string idea);
		Brain(Brain const &other);
		Brain &operator=(Brain const &other);
		~Brain();
		std::string *getIdeas();
		std::string getIdea(int index);
		void setIdea(int index, std::string idea);
};

#endif /* BRAIN_HPP */