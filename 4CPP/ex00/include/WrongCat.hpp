#ifndef DDB6EE0B_F6DF_4D4A_BC9F_B853B5E22B5A
#define DDB6EE0B_F6DF_4D4A_BC9F_B853B5E22B5A

class Cat : public WrongAnimal {
	public:
		Cat();
		Cat(Cat const &other);
		Cat &operator=(Cat const &other);
		virtual ~Cat();
		virtual void makeSound() const;
}

#endif /* DDB6EE0B_F6DF_4D4A_BC9F_B853B5E22B5A */
