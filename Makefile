# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:18:25 by mmisumi           #+#    #+#              #
#    Updated: 2025/05/07 15:25:00 by mmisumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

HEADER := header

SRCDIR := src
OBJDIR := obj

SRCS:= $(SRCDIR)/events.c

OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

LIBFT := libft/libft.a
LIBFT_DIR := libft
LIBFT_SUBMODULE := libft/.git
MLX_SUBMODULE := mlx_linux/.git

$(SUBMODULE):
	git submodule update --init -- recursive

CC := cc
CFLAGS := -Wall -Werror -Wextra -g -I$(HEADER) -Ilibft

RM := rm -f 

all: $(OBJDIR) $(LIBFT) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT_DIR):
	@if [ ! -d "$(LIBFT_SUBMODULE)" ];
	git submodule update --init --recursive

$(LIBFT): $(LIBFT_DIR)
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)
	make -C libft clean

fclean: clean 
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re