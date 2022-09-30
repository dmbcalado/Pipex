# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 20:21:37 by anfreire          #+#    #+#              #
#    Updated: 2022/09/30 18:21:39 by dmendonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = $(wildcard *.c) $(wildcard ../gnl/*.c) $(wildcard ../ft_printf/*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS	= -g -Wall -Wextra -Werror #-fsanitize=address

all	:	$(NAME)


$(NAME)	:	$(OBJS)
		@gcc -o $(NAME) $(OBJS) $(CFLAGS)
		@echo	""
		@echo	"$$ ./minishell && Object Files Generated"
		@echo	""
		@echo	""
		@echo	""
		@echo -e "\033[34m  ______     ______     __   __     __  __     ______"
		@echo -e " /\  == \   /\  __ \   /\  -.\ \   /\ \/\ \   /\  ___\	 	"
		@echo -e " \ \  __<   \ \ \/\ \  \ \ \-.  \  \ \ \_\ \  \ \___  \	"
		@echo -e "  \ \_____\  \ \_____\  \ \_\\ \_ \  \ \_____\  \/\_____\	"
		@echo -e "   \/_____/   \/_____/   \/_/ \/_/   \/_____/   \/_____/	"
		@echo -e "                                                       	"
		@echo -e "         ______   __     ______   ______     __  __        "
		@echo -e "        /\  == \ /\ \   /\  == \ /\  ___\   /\_\_\_\       "
		@echo -e "        \ \  _-/ \ \ \  \ \  _-/ \ \  __\   \/_/\_\/_      "
		@echo -e "         \ \_\    \ \_\  \ \_\    \ \_____\   /\_\/\_\     "
		@echo -e "          \/_/     \/_/   \/_/     \/_____/   \/_/\/_/	    "
		@echo -e ""
		@echo -e ""
		@echo -e ""
		@echo -e "\033[32m	Work made by: Diogo MBM Calado."
		@echo -e ""
		@echo -e "	email : diogombcalado@gmail.com"
		@echo -e ""
		@echo -e "\033[0m"
		
%.o	:	%.c
	@gcc $(CFLAGS) -c $^ -I./ -o $@
	

clean	:
	@rm -f $(OBJS)
	@echo	""
	@echo	"$$ Object Files Deleted"
	@echo	""
		
fclean	:	clean
	@rm -f $(NAME)
	@echo	""
	@echo	"$$ ./minishell Deleted"
	@echo	""

re			:	fclean all

.PHONY		:	all clean fclean re bonus