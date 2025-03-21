# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ly-sha <ly-sha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 08:14:03 by lthan             #+#    #+#              #
#    Updated: 2025/03/16 19:11:16 by ly-sha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = fdf
RM = rm -rf

HEADERS = includes/fdf.h

SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/main.c \
	$(SRCS_DIR)/fdf.c \
	$(SRCS_DIR)/fdf_utils.c \
	$(SRCS_DIR)/clear_functions.c \
	$(SRCS_DIR)/draw_grid.c \
	$(SRCS_DIR)/find_hz.c \
	$(SRCS_DIR)/find_scale.c \
	$(SRCS_DIR)/ft_split_set.c \
	$(SRCS_DIR)/hook.c \
	$(SRCS_DIR)/parse_line.c \
	$(SRCS_DIR)/set_iso.c

OBJS_DIR = objects
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
#OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

MINILIBX_PATH = ./mlx_linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FUNCTIONS = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
ft_printf.c \
print_char.c \
print_hexa.c \
print_nbr.c \
print_ptr.c \
print_str.c \
print_unsigned_nbr.c \
get_next_line.c \
get_next_line_utils.c

LIBFT_FILES = $(addprefix $(LIBFT_PATH)/, $(LIBFT_FUNCTIONS)) $(LIBFT_PATH)/libft.h $(LIBFT_PATH)/Makefile
MLX_FILES = $(MINILIBX_PATH)/mlx.h $(MINILIBX_PATH)/mlx_int.h $(MINILIBX_PATH)/Makefile $(MINILIBX_PATH)/Makefile.mk

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -I$(MINILIBX_PATH) -I$(LIBFT_PATH) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT_FILES) $(MLX_FILES)
	make -C $(MINILIBX_PATH)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(MINILIBX_PATH) -lmlx -lmlx_Linux -I$(MINILIBX_PATH) -lXext -lX11 -lm -lz $(LIBFT) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MINILIBX_PATH) clean
	$(RM) $(OBJS) $(OBJS_DIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
