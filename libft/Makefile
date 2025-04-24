# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrisse <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 06:37:27 by hrisse            #+#    #+#              #
#    Updated: 2024/12/05 09:13:27 by hrisse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source directories
SRC_DIR = src
CHAR_DIR = $(SRC_DIR)/char
MEM_DIR = $(SRC_DIR)/mem
STR_DIR = $(SRC_DIR)/str
LIST_DIR = $(SRC_DIR)/list
IO_DIR = $(SRC_DIR)/io
PRINTF_DIR = $(SRC_DIR)/printf
GNL_DIR = $(SRC_DIR)/gnl

# Source files
CHAR_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
           ft_toupper.c ft_tolower.c
MEM_SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
          ft_memcmp.c ft_calloc.c
STR_SRC = ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
          ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
          ft_strlcpy.c ft_strlcat.c ft_strmapi.c ft_striteri.c \
          ft_atoi.c ft_itoa.c
IO_SRC = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
PRINTF_SRC = ft_printf.c ft_printf_utils.c ft_printf_format.c
GNL_SRC = get_next_line.c get_next_line_utils.c
LIST_SRC = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
           ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
           ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

# Object files
CHAR_OBJ = $(addprefix $(CHAR_DIR)/, $(CHAR_SRC:.c=.o))
MEM_OBJ = $(addprefix $(MEM_DIR)/, $(MEM_SRC:.c=.o))
STR_OBJ = $(addprefix $(STR_DIR)/, $(STR_SRC:.c=.o))
IO_OBJ = $(addprefix $(IO_DIR)/, $(IO_SRC:.c=.o))
PRINTF_OBJ = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC:.c=.o))
GNL_OBJ = $(addprefix $(GNL_DIR)/, $(GNL_SRC:.c=.o))
LIST_OBJ = $(addprefix $(LIST_DIR)/, $(LIST_SRC:.c=.o))

# All objects
OBJ_ALL = $(CHAR_OBJ) $(MEM_OBJ) $(STR_OBJ) $(IO_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
OBJ_BONUS = $(LIST_OBJ)

# Compiler and flags
CC = gcc
FLAGS = -Wall -Wextra -Werror -I./includes -g3

# Library name
NAME = libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJ_ALL)
	ar -rcs $(NAME) $(OBJ_ALL)

bonus: $(OBJ_ALL) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_ALL) $(OBJ_BONUS)

$(CHAR_DIR)/%.o: $(CHAR_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(MEM_DIR)/%.o: $(MEM_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(STR_DIR)/%.o: $(STR_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(IO_DIR)/%.o: $(IO_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIST_DIR)/%.o: $(LIST_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_ALL) $(OBJ_BONUS)
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f *.a

re: fclean all

.PHONY: all clean fclean re bonus
