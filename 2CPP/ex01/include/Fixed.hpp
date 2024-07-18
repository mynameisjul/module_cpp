#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <math.h>

class Fixed {
	private:
		int					_value;
		static int const	_bits = 8;
	
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const &other);
		Fixed & operator=(Fixed const &other);
		~Fixed();
		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
	};

std::ostream & operator<<(std::ostream & o, Fixed const & i );

//Bold high intensity text
# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"

//Regular text
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

//Regular bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

// ANSI Reset
# define RESET "\033[0m"

#endif