# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 15:39:41 by aalliot           #+#    #+#              #
#    Updated: 2016/12/14 15:59:25 by aalliot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 21sh
NAME_DEBUG	= 21sh_debug
 
SRC			=	main.c		\
				ft_term.c	\
				get_key_hook.c	\
				init_cmd.c		\
				init_hook.c		\
				init_term.c		\
				printable_key_hook.c \
				tputc.c		\
				ft_tputs.c		\
				move_cursor_left.c		\
				move_cursor_right.c		\
				arrow_left_hook.c		\
				arrow_right_hook.c		\
				init_signals.c			\
				ft_error.c				\
				winsize.c

HEAD_DIR	= includes
SRC_DIR		= src
DEBUG_DIR	= debug
STATIC_DIR	= static
DEP_DIR		= dep

LIB_STATIC	= libft/libft.a
LIB_DEBUG	= libft/libft_debug.a
LIB_HEAD	= libft/includes

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	INCLUDES	=
	LIBS		=
	FLAGS		= # -Wall -Wextra -Werror
endif

ifeq ($(UNAME_S),Darwin)
	INCLUDES	=
	LIBS		=
	FLAGS		= -Wall -Wextra # -Werror
endif

OBJ			= $(patsubst %.c,$(STATIC_DIR)/%.o,$(SRC))
OBJ_DEBUG	= $(patsubst %.c,$(DEBUG_DIR)/%.o,$(SRC))
DEPS		= $(patsubst %.c,$(DEP_DIR)/%.d,$(SRC))

CC			= gcc
OPTI		= -O3
DEPENDS 	= -MT $@ -MD -MP -MF $(subst .o,.d,$@)

EXTERN_LIBS = -ltermcap

$(shell mkdir -p $(STATIC_DIR) $(DEBUG_DIR) $(DEP_DIR))

.PHONY: clean fclean re debug

all: $(NAME)

$(NAME): $(OBJ) $(LIB_STATIC)
	$(CC) $(FLAGS) $(OPTI) $(EXTERN_LIBS) -I $(HEAD_DIR) -I $(LIB_HEAD) -o $@ $(OBJ) $(LIB_STATIC)
	@echo "Compilation complete. (realease)"

debug: $(OBJ_DEBUG) $(LIB_DEBUG)
	$(CC) $(FLAGS) $(OPTI) $(EXTERN_LIBS) -I $(HEAD_DIR) -I $(LIB_HEAD) -o $(NAME_DEBUG) $(OBJ_DEBUG) $(LIB_DEBUG) -g
	@echo "Compilation complete. (debug)"

-include $(OBJ:.o=.d)

$(STATIC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(OPTI) $(DEPENDS) -I $(HEAD_DIR) -I $(LIB_HEAD) -o $@ -c $<

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(OPTI) $(DEPENDS) -I $(HEAD_DIR) -I $(LIB_HEAD) -o $@ -c $< -g

$(LIB_STATIC):
	make -C libft/ libft.a

$(LIB_DEBUG):
	make -C libft/ libft_debug.a

clean:
	make -C libft clean
	rm -f $(OBJ) $(OBJ_DEBUG) $(DEPS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(NAME_DEBUG)

re: fclean
	make
