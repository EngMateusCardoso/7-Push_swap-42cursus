# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 02:09:58 by matcardo          #+#    #+#              #
#    Updated: 2022/10/24 22:59:36 by matcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRCS			= $(wildcard src/*.c)
SRCS_BONUS		= $(wildcard src_bonus/*.c)
OBJS			= ${SRCS:src/%.c=objs/%.o}
OBJS_BONUS		= ${SRCS_BONUS:src_bonus/%.c=objs_bonus/%.o}
HEADER			= src/push_swap.h
HEADER_BONUS	= src_bonus/push_swap_bonus.h
OBJS_DIR		= objs/
OBJS_DIR_BONUS	= objs_bonus/

RM				= rm -fr
CC				= gcc
FLAGS			= -Wall -Wextra -Werror

LIBFT			= ./libraries/libft/libft.a

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT)
			@printf "\n$(CY)Generating push_swap executable...$(RC)\n"
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
			@printf "$(GR)Done!$(RC)\n\n"

$(OBJS_DIR):
			mkdir $(OBJS_DIR)

objs/%.o: src/%.c
			@printf "\n$(CY)Generating object...$(RC)\n"
			${CC} ${FLAGS} -c $< -o ${<:src/%.c=objs/%.o}
			@printf "$(GR)Object ready!$(RC)"

$(LIBFT):
			@printf "\n$(CY)Generating libft...$(RC)\n"
			make -C ./libraries/libft
			@printf "$(GR)libft ready!$(RC)"

bonus: $(OBJS_DIR_BONUS) $(OBJS_BONUS) $(LIBFT)
			$(RM) $(NAME)
			@printf "\n$(CY)Generating push_swap executable bonus...$(RC)\n"
			$(CC) $(FLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBFT)

$(OBJS_DIR_BONUS):
			mkdir $(OBJS_DIR_BONUS)

objs_bonus/%.o: src_bonus/%.c
			@printf "\n$(CY)Generating object...$(RC)\n"
			${CC} ${FLAGS} -c $< -o ${<:src_bonus/%.c=objs_bonus/%.o}
			@printf "$(GR)Object ready!$(RC)"

norm:
			norminette ${SRCS} ${HEADER} ${SRCS_BONUS} ${HEADER_BONUS} 

clean:
			make -C ./libraries/libft clean
			$(RM) $(OBJS_DIR)
			$(RM) $(OBJS_DIR_BONUS)
			@printf "$(RE)push_swap objects removed!$(RC)\n\n"

fclean:		clean
			make -C ./libraries/libft fclean
			$(RM) $(NAME)
			@printf "$(RE)push_swap executables removed!$(RC)\n\n"

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
