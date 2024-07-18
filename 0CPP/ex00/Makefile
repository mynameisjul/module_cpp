# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julieblaye <julieblaye@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 22:16:08 by julieblaye        #+#    #+#              #
#    Updated: 2024/02/22 22:54:31 by julieblaye       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

# --------------------------------- FILES ------------------------------------ #

SRCS = megaphone.cpp

# ------------------------------ COMPILATION --------------------------------- #

C++ = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
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
