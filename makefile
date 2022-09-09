# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 17:40:51 by jmorneau          #+#    #+#              #
#    Updated: 2022/09/09 19:14:49 by jmorneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = @gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = @rm -f
INCLUDE = -I include/

SRC_DIR = src/
SRC_FILES =	ft_atoi.c philo_init.c philo.c thread_creation.c print_action.c time.c

OBJ_DIR = objs/
OBJS = ${addprefix ${OBJ_DIR}, $(SRC_FILES:.c=.o)}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@echo "$(_BLUE)$(_BOLD)Compilation Printf: $< $(_END)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#Couleurs!
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_WHITE=$'\x1b[37m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_IWHITE=$'\x1b[47m

all: $(NAME)

$(NAME): ${OBJ_DIR} $(OBJS)
	${CC} $(CFLAGS) ${OBJS} -o $@

${OBJ_DIR}:
	mkdir -p $@



clean:
	@$(RM) -r ${OBJ_DIR}

fclean: clean
	@$(RM) $(NAME)

re: fclean all