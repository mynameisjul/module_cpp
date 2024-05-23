#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string _name;
		void	announce(void);

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

#endif