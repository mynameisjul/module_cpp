# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 22:16:08 by julieblaye        #+#    #+#              #
#    Updated: 2024/05/19 23:48:46 by jblaye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

# --------------------------------- FILES ------------------------------------ #

SRCS = Contact.cpp PhoneBook.cpp main.cpp
HEADERS = Contact.hpp PhoneBook.hpp

# ------------------------------ COMPILATION --------------------------------- #

C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(HEADERS)
OBJS = $(SRCS:.cpp=.o)

# --------------------------------- RULES ------------------------------------ #

all:		$(NAME)

%.o:		%.cpp
			$(C++) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(C++) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			clean $(NAME)

.PHONY:		all clean re
