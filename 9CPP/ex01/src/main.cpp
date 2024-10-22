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
		std::cerr << "Come on babe, we can do better!\n[Wrong number of arguments]" << std::endl;
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

	while (input[i] != 0) {
		if (input[i] == ' ' && input[i + 1] != 0)
			i++;
		if (isNumber(input[i]))
			pile.push(input[i] - '0');
		else if (isSign(input[i], signs)) {
			if (pile.size() < 2)
				return (printf("Error\n"), 1);
			try {
				int b = pile.top();
				pile.pop();
				int a = pile.top();
				pile.pop();
				int r = operation(a, b, input[i]);
				pile.push(r);
			}
			catch (std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
				return 1;
			}
		}
		else
			return (printf("Error\n"), 1);
		i++;
	}
	std::cout << pile.top() << std::endl;
	return 0;
}