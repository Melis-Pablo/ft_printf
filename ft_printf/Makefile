# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 20:21:26 by pmelis            #+#    #+#              #
#    Updated: 2023/04/18 12:28:16 by pmelis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# List of source files for the library
MY_SOURCES =	ft_printf.c \
				ft_tools.c \

# Name of the output library
NAME = libftprintf.a

# Flags for the C compiler
CFLAGS = -Wall -Wextra -Werror

# Object files for the main library
MY_OBJECTS = $(MY_SOURCES:.c=.o)

# Default target - builds the main library
all: $(NAME)

# Target to build the main library
$(NAME): $(MY_OBJECTS)
	@ar rc $(NAME) $(MY_OBJECTS)    # create the library archive
	@echo "$(NAME) created"
	@ranlib $(NAME)                 # index the library for faster linking
	@echo "$(NAME) indexed"

# Rule for compiling individual source files
%.o: %.c
	@cc $(CFLAGS) -c $< -o $@      # compile the source file into an object file
	
# Target to clean up object files
clean:
	@rm -f $(MY_OBJECTS)            # delete object files
	@echo "OBJ deleted"

# Target to clean up object files and the library
fclean: clean
	@rm -f $(NAME)               # delete the library archive
	@echo "$(NAME) deleted"

# Target to rebuild the library
re: fclean all

# Declare these targets as phony, to ensure they always run
.PHONY: all, clean, fclean, re
