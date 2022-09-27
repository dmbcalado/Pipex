# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 20:21:37 by anfreire          #+#    #+#              #
#    Updated: 2022/09/27 19:41:14 by ratinhosujo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = $(wildcard *.c) $(wildcard ../gnl/*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS	= -g -Wall -Wextra -Werror -fsanitize=address

all	:	$(NAME)


$(NAME)	:	$(OBJS)
		@gcc -o $(NAME) $(OBJS) $(CFLAGS)
		@echo	""
		@echo	"$$ ./minishell && Object Files Generated"
		@echo	""
		@echo	""
		@echo	""
		@echo 	"\e[34m  ______     ______     __   __     __  __     ______"
		@echo	" /\  == \   /\  __ \   /\  -.\ \   /\ \/\ \   /\  ___\	 	"
		@echo	" \ \  __<   \ \ \/\ \  \ \ \-.  \  \ \ \_\ \  \ \___  \	"
		@echo	"  \ \_____\  \ \_____\  \ \_\\ \_ \  \ \_____\  \/\_____\	"
		@echo	"   \/_____/   \/_____/   \/_/ \/_/   \/_____/   \/_____/	"
		@echo	"                                                       	"
		@echo	"         ______   __     ______   ______     __  __        "
		@echo	"        /\  == \ /\ \   /\  == \ /\  ___\   /\_\_\_\       "
		@echo	"        \ \  _-/ \ \ \  \ \  _-/ \ \  __\   \/_/\_\/_      "
		@echo	"         \ \_\    \ \_\  \ \_\    \ \_____\   /\_\/\_\     "
		@echo	"          \/_/     \/_/   \/_/     \/_____/   \/_/\/_/	    "
		@echo	""
		@echo	""
		@echo	""
		@echo	"\e[32m	Work made by: Diogo MBM Calado."
		@echo	""
		@echo	"	email : diogombcalado@gmail.com"
		@echo	""
		@echo	"\e[0m"
		
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