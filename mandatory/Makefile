# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 20:21:37 by anfreire          #+#    #+#              #
#    Updated: 2022/09/30 16:53:29 by dmendonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = $(wildcard *.c) $(wildcard ../ft_printf/*.c)

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
		@echo -e "\e[34m ______   __                      "
		@echo -e "/\  == \ /\ \                     "
		@echo -e "\ \  __/ \ \ \                    "
		@echo -e " \ \_\    \ \_\                   "
		@echo -e "  \/_/     \/_/                   "
		@echo -e "      __________                  "
		@echo -e "     /\____1____\                 "
		@echo -e "     \/_/\    \_/                 "
		@echo -e "        \_\    \__                "
		@echo -e "       /\_________\               "
		@echo -e "       \/____0____/               "
		@echo -e "                                  "
		@echo -e "    ______   ______     __  __    "
		@echo -e "   /\  == \ /\  ___\   /\_\_\_\   "
		@echo -e "   \ \  __/ \ \  __\   \/_/\_\/_  "
		@echo -e "    \ \_\    \ \_____\   /\_\/\_\ "
		@echo -e "     \/_/     \/_____/   \/_/\/_/ "
		@echo -e ""
		@echo -e "\e[32mWork made by:"
		@echo -e "Diogo MBM Calado, from 42 Lisbon."
		@echo -e "email : diogombcalado@gmail.com"
		@echo -e "\e[34mnow run ./pipex infile cmd1 cmd2 outfile and welcome!"
		@echo -e ""
		@echo -e "\e[0m"
		
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