# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchim <lchim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 21:21:36 by lchim             #+#    #+#              #
#    Updated: 2016/11/21 11:49:52 by aridolfi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME	= a.out

# Compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Directories
SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= ./includes

# Sources && Objs
SRCS	= 					\
			main.c			\
			fill_tetris.c	\
			fill_error.c	\
			fill_fn.c		\
			print_fill.c


OBJS	= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

# **************************************************************************** #

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# Bonus

.PHONY			:	clean

# **************************************************************************** #

# Rules

all				:	$(OBJDIR) $(NAME)

$(NAME)			:	$(OBJS)
		  			@$(CC) $(CFLAGS) -o $@ $^ -I$(INCDIR)

$(OBJDIR)/%.o 	: 	$(SRCDIR)/%.c
					@echo "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
					@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ -I$(INCDIR)

$(OBJDIR)		:
					@mkdir -p $(OBJDIR)

clean			:
					@rm -f $(OBJS)
					@rm -rf $(OBJDIR)

fclean			:	clean
					@rm -f $(NAME)

re				:	fclean all
