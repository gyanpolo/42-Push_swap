# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 11:11:44 by gpolo             #+#    #+#              #
#    Updated: 2024/10/29 12:57:26 by gpolo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= push_swap
 
LIBS			:= push_swap.h

SRC_DIR			:= src/

OBJ_DIR			:= obj/

LIBS_DIRS		:= ./libs/libft ./libs/ft_printf 
LIBS_A          := ./libs/libft/libft.a ./libs/ft_printf/ft_printf.a 
LIBS_INC		:= $(addprefix -I , $(LIBS_DIRS))

SRCS_FILES		:= $(shell find $(SRC_DIR) -type f -iname "*.c" | sed 's#[.][^.]*$$##')
SRCS			:= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS			:= $(shell find $(SRC_DIR) -type d)
OBJSDIRS		:= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP		:= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS			:= $(addsuffix .o, $(OBJSTEMP))

CC				:= gcc

CFLAGS			:= -Wall -Wextra -Werror -g  $(LIBS_INC)

AR				:= ar rcs
RANLIB			:= ranlib
RM				:= rm -rf
MKDIR			:= mkdir -p

all:			$(NAME)

$(NAME):	    $(OBJSDIRS) $(OBJS) $(LIBS_A) $(LIBS) Makefile
				$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(LIBS_A) -o $(NAME)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c Makefile 
				$(CC) -I . $(CFLAGS) -c $< -o $@

$(OBJSDIRS):
				$(MKDIR) $(OBJSDIRS)

$(LIBS_A):
				for dir in $(LIBS_DIRS); do \
					$(MAKE) -C $$dir; \
				done

clean:
				$(RM) $(OBJS)
				for dir in $(LIBS_DIRS); do \
					$(MAKE) clean -C $$dir; \
				done

fclean:			clean
				$(RM) $(OBJSDIRS)
				$(RM) $(NAME)
				for dir in $(LIBS_DIRS); do \
					$(MAKE) fclean -C $$dir; \
				done

re:				fclean $(NAME)

normi:
				@norminette $(SRCS) $(LIBS)
info:
				$(info $(SRCS_FILES))

.PHONY:			all clean fclean re info normi
