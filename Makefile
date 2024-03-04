# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:48:51 by nnourine          #+#    #+#              #
#    Updated: 2024/03/01 17:37:18 by nnourine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color
COLOR = \033[0;34m
RESET_COLOR = \033[0m

# Executable name
NAME = so_long

# Compiler and flags
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
GENERAL_LIB_FLAGS = -L$(LIBFT) -L$(LIBPRINT) -lft -lftprintf
LMX_FLAGS = -L$(LIBMLX)/build -L$(BREW_LIB) -lmlx42 -ldl -pthread -lm -lglfw

# Directories
SRCDIR = src/c_files
INCDIR = include
LIBMLX = lib/MLX42
LMXINC = $(LIBMLX)/include
LIBFT = lib/libft
LIBPRINT = lib/ft_printf
BREW_LIB = /Users/$(USER)/.brew/Cellar/glfw/3.4/lib

# Files
SRCS = $(SRCDIR)/calculate_character_size.c  \
		$(SRCDIR)/check_exit.c  \
		$(SRCDIR)/check_near_wall.c  \
		$(SRCDIR)/check_reach_to_collectible.c  \
		$(SRCDIR)/check_with_wall_instance.c  \
		$(SRCDIR)/create_backgroub.c  \
		$(SRCDIR)/create_elements.c  \
		$(SRCDIR)/create_window_elements.c  \
		$(SRCDIR)/escape_key.c  \
		$(SRCDIR)/exit.c  \
		$(SRCDIR)/map_to_instance.c  \
		$(SRCDIR)/press_key.c  \
		$(SRCDIR)/point_data_start.c  \
		$(SRCDIR)/resize.c  \
		$(SRCDIR)/so_long.c
OBJS = $(SRCS:.c=.o)

# Phony targets
.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	cmake $(LIBMLX) -B $(LIBMLX)/build
	@$(MAKE) -C $(LIBMLX)/build -j4
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBPRINT)
	@$(CC) $(CFLAGS) $(GENERAL_LIB_FLAGS) $(LMX_FLAGS) $(OBJS) -o $@
	@echo "$(COLOR)Compiling and linking: done$(RESET_COLOR)"

# Compiling
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LMXINC) -c $< -o $@

# Clean-up
clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBPRINT) clean
	@$(RM) -r $(LIBMLX)/build
	@echo "$(COLOR)Clean-up: done$(RESET_COLOR)"

# Full clean
fclean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBPRINT) clean
	@$(RM) -r $(LIBMLX)/build
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBPRINT) fclean
	@echo "$(COLOR)Full clean: done$(RESET_COLOR)"

# Recompile
re: fclean all