SRCS_LIST = philosofers_42.c fabric.c validator.c init_struct.c dinner.c routine.c

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

#BONUS = bonus
#BONUS_SRCS_LIST = checker.c check_pushes.c\
#			check_reverse_rotate.c check_rotate.c check_swaps.c\
#			get_next_line.c get_next_line_utils.c\
#			stack.c utils.c rounded_list_routine.c\
#			check_args.c free_memory.c validator.c
#BONUS_SRCS_DIR = checker_srcs/
#BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR), $(BONUS_SRCS_LIST))
#
#BONUS_INCLUDES = -Iincludes/push_swap.h -Iincludes/get_next_line.h -Iincludes/libft.h
#BONUS_HEADER = includes/push_swap.h includes/get_next_line.h includes/libft.h
#BONUS_OBJ_DIR = bonus_obj/
#BONUS_OBJ_LIST = $(patsubst %.c, %.o, $(BONUS_SRCS_LIST))
#BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_OBJ_LIST))
LIBFT = libft/libft.a

SOURCE = libft/ft_atoi.c \
		 libft/ft_bzero.c \
		 libft/ft_calloc.c \
		 libft/ft_isalnum.c \
		 libft/ft_isalpha.c \
		 libft/ft_isascii.c \
		 libft/ft_isdigit.c \
		 libft/ft_isprint.c \
		 libft/ft_itoa.c \
		 libft/ft_memccpy.c \
		 libft/ft_memchr.c \
		 libft/ft_memcmp.c \
		 libft/ft_memcpy.c \
		 libft/ft_memmove.c \
		 libft/ft_memset.c \
		 libft/ft_putchar_fd.c \
		 libft/ft_putendl_fd.c \
		 libft/ft_putnbr_fd.c \
		 libft/ft_putstr_fd.c \
		 libft/ft_split.c \
		 libft/ft_strchr.c \
		 libft/ft_strdup.c \
		 libft/ft_strjoin.c \
		 libft/ft_strlcat.c \
		 libft/ft_strlcpy.c \
		 libft/ft_strlen.c \
		 libft/ft_strmapi.c \
		 libft/ft_strncmp.c \
		 libft/ft_strnstr.c \
		 libft/ft_strrchr.c \
		 libft/ft_strtrim.c \
		 libft/ft_substr.c \
		 libft/ft_tolower.c \
		 libft/ft_toupper.c libft/libft.h
HEADER = includes/philo.h
HEADER_LIB = includes/libft.h

INCLUDES = -I$(HEADER) -I$(HEADER_LIB)

NAME = philo

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
		@gcc $(CFLAGS) $(LIBFT) $(INCLUDES) $(OBJ) -o $(NAME)
		@echo "\n$(NAME):$(GREEN).o files were created$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(LIBFT) : $(SOURCE)
		@make -C libft
		@echo "\nLibft:$(GREEN).a file was created$(RESET)"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
		@gcc $(CFLAGS) -c $(INCLUDES) $< -o $@
		@echo "$(GREEN)/$(RESET)\c"

#$(BONUS): $(BONUS_OBJ_DIR) $(BONUS_OBJ) $(LIBFT)
#		@gcc $(CFLAGS) $(LIBFT) $(BONUS_INCLUDES) $(BONUS_OBJ) -o checker
#		@echo "$(BONUS):$(GREEN).o files were created$(RESET)"
#		@echo "$(BONUS): $(GREEN)$(BONUS) was created$(RESET)"
#
#$(BONUS_OBJ_DIR):
#		@mkdir -p $(BONUS_OBJ_DIR)
#		@echo "$(NAME): $(GREEN)$(BONUS_OBJ_DIR) was created$(RESET)"
#
#$(BONUS_OBJ_DIR)%.o: $(BONUS_SRCS_DIR)%.c $(BONUS_HEADER)
#		@gcc $(CFLAGS) -c $(BONUS_INCLUDES) $< -o $@
#		@echo "$(GREEN)/$(RESET)\c"


clean:
		@make -C libft clean
		@echo "$(NAME):$(GREEN) libft is cleaned$(RESET)"
		@echo "$(NAME):$(GREEN) objects dirs are cleaned$(RESET)"
		@rm -rf objects

fclean: clean
		@$(RM) $(NAME)
		@make -C libft fclean

re : fclean all

.PHONY: all clean fclean re
