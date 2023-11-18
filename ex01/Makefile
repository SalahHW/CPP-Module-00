# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 05:09:19 by sbouheni          #+#    #+#              #
#    Updated: 2023/11/18 07:34:04 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=			phonebook

CXX			=			g++
CXXFLAGS	=			-Wall -Wextra -Werror -std=c++98 -g

SRCS		=			source/main.cpp										\
						source/Contact.cpp									\
						source/PhoneBook.cpp								\
						source/utils.cpp									\

HDRS		=			include/Contact.hpp									\
						include/PhoneBook.hpp								\
						include/utils.hpp									\

OBJS		=			$(SRCS:.cpp=.o)

all			:			$(NAME)

$(NAME)		:			$(OBJS) $(HDRS)
						$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean		:
						rm -rf $(OBJS)

fclean		:			clean
						rm -rf $(NAME)

re			:			fclean all

.PHONY		:			all clean fclean re
