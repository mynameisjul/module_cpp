/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julieblaye <julieblaye@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:15:55 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/22 22:56:11 by julieblaye       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	std::string megaphone = "";
	size_t		i = 1;

	// Concatenate all strings from argv
	while ((int) i < ac)
	{
		megaphone+= av[i];
		i++;
	}

	// Change all lower case char to upper case
	i = 0;
	while (i < megaphone.length())
	{
		if (megaphone[i] >= 'a' && megaphone[i] <= 'z')
			megaphone[i] = megaphone[i] - 'a' + 'A';
		i++;
	}

	// Print the string and add new line
	std::cout << megaphone << std::endl;
	return (0);
}
