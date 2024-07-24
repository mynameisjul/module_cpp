#ifndef WORLD_RESOURCES_HPP
#define WORLD_RESOURCES_HPP

#include "interface.h"

class WorldResources {
	// class to store the materia that s left by the character so as to 
	// delete it cleanly at the end
	private:
		AMateria			**store;
		unsigned int	n_materia;
	public:
		// Constructor and destructor
		WorldResources();
		WorldResources(WorldResources const &other);
		WorldResources &operator=(WorldResources const &other);
		~WorldResources();

		// Function to manage world inventory
		void	addMateria(AMateria *materia);
}

#endif /* WORLD_RESOURCES_HPP */
