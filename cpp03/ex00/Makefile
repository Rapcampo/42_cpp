# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 13:52:55 by rapcampo          #+#    #+#              #
#    Updated: 2025/03/06 15:32:13 by rapcampo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Files ======================================

NAME	= ClapTrap
SOURCE	= src/main.cpp src/ClapTrap.cpp  #src/HumanA.cpp src/HumanB.cpp
OBJS	= objs/main.o objs/ClapTrap.o #objs/HumanA.o objs/HumanB.o

# ============================ Folder Structures ===============================

HEADERS		= includes
SOURCE_DIR	= src
OBJS_DIR	= objs

# ============================ Commands & Flags ===============================

CC			= c++
RM			= rm -rf
#AR			= ar -rcs
FLAGS		= -Wall -Wextra -Werror -std=c++98# -g #-O3  #-fsanitize=address 
MAKE_FLAG	= --no-print-directory

# =========================== Ansi Escape Codes ================================

ULINE	= \e[4m
BLINK	= \e[5m
BLACK 	= \e[1;30m
RED 	= \e[1;31m
GREEN 	= \e[1;32m
YELLOW 	= \e[1;33m
BLUE	= \e[1;34m
PURPLE 	= \e[1;35m
CYAN 	= \e[1;36m
WHITE 	= \e[1;37m
RESET	= \e[0m

# ================================ Rules =======================================

all: $(NAME)

$(NAME): $(OBJS)
	echo "[$(CYAN)$(BLINK)Linking...$(RESET)]"
	$(CC) $(FLAGS) -o $@ $^
	echo "\n*************************$(GREEN)$(BLINK)    "\
		"[Compilation Sucessfull!]    $(RESET)*************************\n"

$(OBJS): 
	echo "[$(PURPLE)$(BLINK)Compiling...$(RESET)] $(YELLOW)sources$(RESET)"
	mkdir -p objs
	$(CC) $(FLAGS) -c $(SOURCE) -I $(HEADERS)
	mv *.o $(OBJS_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_DIR)
	echo "\n\n++++++++++++++    $(ULINE)$(GREEN)Fixed's Objects have been" \
		"removed sucessfully$(RESET)    +++++++++++++++\n\n"

fclean: clean
	$(RM) $(NAME)
	echo "\n\n++++++++++++++    $(ULINE)$(GREEN)Fixed's Static library and "\
		"programs removed successfully$(RESET)    +++++++++++++++\n\n"

re: fclean all

leak: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) DEBUG
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) INFO 
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) WARNING
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ERROR

.SILENT:

.PHONY: all clean fclean re
