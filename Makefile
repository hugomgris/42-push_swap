# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 16:17:09 by hmunoz-g          #+#    #+#              #
#    Updated: 2024/10/16 18:08:38 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker_bonus
SRC_DIR = srcs/

SRC_1 = src/push_swap.c \

SRC_2 =	src/checker.c \
	src/builder.c \
	src/lister.c \
	src/lister2.c \
	src/swapper.c \
	src/pusher.c \
	src/rotator.c \
	src/rrotator.c \
	src/operator.c \
	src/ssorter.c \
	src/bsorter.c \
	src/reviewer.c \
	src/minimizer.c \
	src/maximizer.c \
	src/cost_calculator.c \
	src/cost_calculator2.c \
	src/order_manager.c \
	src/order_manager2.c \
	src/executer.c \
	src/returner.c
		
BONUS_SRC = checker/checker.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

%.o: %.c Makefile includes/push_swap.h libft/libft.a
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus
