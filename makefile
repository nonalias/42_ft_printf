# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/18 17:01:47 by taehkim           #+#    #+#              #
#    Updated: 2020/04/27 18:46:46 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
HDR	=	-I ./includes
SRCS	=	./srcs/Libft/ft_isdigit.c \
		./srcs/Libft/ft_putchar_fd.c \
		./srcs/Libft/ft_putnbr_fd.c \
		./srcs/Libft/ft_putstr_fd.c \
		./srcs/Libft/ft_strlen.c \
		./srcs/Libft/ft_strncmp.c \
		./srcs/Libft/ft_substr.c \
		./srcs/check_flag.c \
		./srcs/display_c.c \
		./srcs/display_d.c \
		./srcs/display_large_x.c \
		./srcs/display_p.c \
		./srcs/display_percent.c \
		./srcs/display_s.c \
		./srcs/display_u.c \
		./srcs/display_x.c \
		./srcs/ft_printf.c \
		./srcs/initialize.c \
		./srcs/asterik_minus_process.c \
		./srcs/length.c \
		./srcs/parse.c \
		./srcs/put16base_fd.c \
		./srcs/putnbr_x_fd.c \
		./srcs/valid_check.c \
		./srcs/white_print.c \
		./srcs/zero_print.c \

OBJS	=	$(SRCS:%.c=%.o)

all	:	$(NAME)

$(NAME) :	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HDR)

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all
