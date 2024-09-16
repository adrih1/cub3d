NAME = cub3d
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
OBJ_DIR = obj
MLX_DIR = ./mlx_lib/

SRCS = 	main.c \
		$(SRC_DIR)/ft_clean.c \
		$(SRC_DIR)/ft_parsing/ft_display_adrien.c \
		$(SRC_DIR)/ft_parsing/ft_find_colors.c \
		$(SRC_DIR)/ft_parsing/ft_find_colors_utils.c \
		$(SRC_DIR)/ft_parsing/ft_find_textures.c \
		$(SRC_DIR)/ft_parsing/ft_map_info.c \
		$(SRC_DIR)/ft_execution/ft_executor.c \
		$(SRC_DIR)/ft_execution/outils/outils.c \
		$(SRC_DIR)/ft_parsing/ft_parsing_utils.c \
		$(SRC_DIR)/ft_parsing/ft_parsing.c \

OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
MAKE_MLX = make -C $(MLX_DIR)
INC = -Iincludes -Ilibft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin) 
   MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
   MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
endif

all: $(LIBFT) $(MLX_DIR)/libmlx.a $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@echo "Building mlx..."
	@$(MAKE_MLX)

$(NAME): $(OBJS) $(LIBFT)
	@echo "Building project $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS) 

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