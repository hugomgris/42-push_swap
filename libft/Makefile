# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 15:45:04 by hmunoz-g          #+#    #+#              #
#    Updated: 2024/09/20 10:44:26 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_itoa.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strmapi.c \
	  ft_strnstr.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_substr.c \
	  ft_split.c \
	  ft_atoi.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_isspace.c \
	  ft_isvalidsign.c \
	  ft_memcmp.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_strncmp.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_memchr.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_striteri.c \
	  ft_strtrim.c \
	  ft_free.c \
	  get_next_line.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstsize_bonus.c \

BONUS_OBJ = $(BONUS:.c=.o)

CC = gcc -Wall -Werror -Wextra

%.o: %.c libft.h Makefile
	$(CC) -I. -c $< -o $(<:.c=.o)


all: $(NAME)

bonus: $(NAME) $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
