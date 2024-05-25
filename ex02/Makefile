# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 10:52:31 by okraus            #+#    #+#              #
#    Updated: 2024/05/25 13:47:00 by okraus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	IdentifyRealType
SRCS		=	main.cpp Base.cpp colours.cpp
HEADERS		=	Base.hpp colours.hpp
OBJS		=	$(SRCS:.cpp=.o)
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g
CPP			=	c++

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp $(HEADERS)
			$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
