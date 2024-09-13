#include <stack>
#include <iostream>
#include <string.h>
#include <stdio.h>

class DividedByZero : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Cannot divide by 0";
		}
};

bool isNumber(char c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool isSign(char c, std::string signs) {
	if (signs.find(c) != std::string::npos)
		return true;
	return false;
}

int operation(int nb1, int nb2, char op) {
	if (nb2 == 0 && op == '/')
		throw (DividedByZero());
	switch (op) {
		case '+':
			return (nb1 + nb2);
		case '-':
			return (nb1 - nb2);
		case '*':
			return (nb1 * nb2);
		case '/':
			return (nb1 / nb2);
	}
	return (0);
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Come on babe, we can do better!" << std::endl;
		return 1;
	}
	
	for (size_t i = 0; i < strlen(av[1]); i++) {
		if (i % 2 == 1 && av[1][i] != ' ')
			return (printf("Error\n"), 1);
	}

	char *input = av[1];
	int i = 0;
	std::string signs = "+-*/";
	std::stack<int> pile;

	if (isNumber(input[i]) && isNumber(input[i + 2]) && isSign(input[i + 4], signs)) {
		pile.push(input[i] - '0');
		i = i + 2;
	}
	else 
		return (printf("Error\n"), 1);
	
	while (input[i] != 0) {
		if (isNumber(input[i]) && isSign(input[i + 2], signs)) {
			try {
				int r = operation(pile.top(), input[i] - '0', input[i + 2]);
				pile.push(r);
			}
			catch (std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
				return 1;
			}
		}
		else 
			return (printf("Error\n"), 1);
		if (input[i + 3])
			i = i + 4;
		else
			i = i + 3;
	}
	std::cout << pile.top() << std::endl;
	return 0;
}