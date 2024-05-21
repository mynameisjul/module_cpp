/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:15:55 by julieblaye        #+#    #+#             */
/*   Updated: 2024/05/17 18:52:11 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string megaphone = "";
	size_t		i = 1;

	// Manage case with no arguments
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	// Concatenate all strings from argv with string method
	while ((int) i < ac) {
		megaphone+= av[i];
		i++;
	}

	// Change all lower case char to upper case
	i = 0;
	while (i < megaphone.length()) {
		if (megaphone[i] >= 'a' && megaphone[i] <= 'z')
			megaphone[i] = megaphone[i] - 'a' + 'A';
		i++;
	}

	// Print the string and add new line
	std::cout << megaphone << std::endl;
	return (0);
}
