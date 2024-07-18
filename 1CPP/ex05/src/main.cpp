#include "Harl.hpp"

int main(int ac, char **av) {
	Harl harl;

	std::cout << "Harl when using the 'DEBUG' level" << std::endl;
	harl.complain("DEBUG");
	std::cout << "Harl when using the 'INFO' level" << std::endl;
	harl.complain("INFO");
	std::cout << "Harl when using the 'WARNING' level" << std::endl;
	harl.complain("WARNING");
	std::cout << "Harl when using the 'ERROR' level" << std::endl;
	harl.complain("ERROR");
	std::cout << "==================================" << std::endl;
	std::cout << "Wrong inputs:" << std::endl;
	std::cout << "Harl when using an empty level ''" << std::endl;
	harl.complain("");
	std::cout << "Harl when using a level with additional letters such as 'INFORMATION'" << std::endl;
	harl.complain("INFORMATION");
	if (ac == 2) {
		std::cout << "==================================" << std::endl;
		std::cout << "Harl when using a level entered as argument of this program" << std::endl;
		std::string str = "";
		str = str + av[1];
		harl.complain(str);
	}
	return (0);
}