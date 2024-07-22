#include "animal.h"

int main()
{
	// {
	// 	const WrongAnimal *meta = new WrongAnimal();
	// 	const Animal *dog = new Dog();
	// 	const WrongAnimal *i = new WrongCat();
	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); // will not output the cat sound!
	// 	j->makeSound();
	// 	meta->makeSound();
	// 	delete (meta);
	// 	delete (i);
	// 	delete (j);
	// }

	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete (meta);
		delete (i);
		delete (j);
	}
	return (0);
}