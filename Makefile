# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguerra- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 17:37:10 by sguerra-          #+#    #+#              #
#    Updated: 2021/10/28 15:26:05 by sguerra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	ft_printf.c			\
		ft_printf_utils.c	\
		ft_wchar.c			\
		ft_wstr.c			\
		ft_wptr.c			\
		ft_wint.c			\
		ft_wunsint.c		\
		ft_wlowerhex.c		\
		ft_wupperhex.c		\


OBJ			= $(SRC:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra
 
all:		$(NAME)

$(NAME):	$(OBJ) 
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)	
		
.PHONY:		all clean fclean re

clean:	
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			
re: 		fclean all
