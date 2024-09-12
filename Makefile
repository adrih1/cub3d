NAME = cub3d
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = obj

SRCS = 	main.c \
		$(SRC_DIR)/ft_parsing/ft_find_colors.c \
		$(SRC_DIR)/ft_parsing/ft_map_info.c \
		$(SRC_DIR)/ft_parsing/ft_parsing_utils.c \
		$(SRC_DIR)/ft_parsing/ft_parsing.c \

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
INC = -Iincludes -Ilibft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Building project $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files cleaned."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "Full cleanup done."

re: fclean all

.PHONY: all clean fclean re