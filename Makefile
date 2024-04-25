CC           = gcc
LIBFT_DIR    = fractol_libft/
LIBFT        = $(LIBFT_DIR)libft.a
MINILIBX_DIR = minilibx-linux/
MINILIBX     = $(MINILIBX_DIR)libmlx.a
FRACTOL_DIR  = ./
CFLAGS       = -Wall -Wextra -Werror -O3 -g3
HEADERS      = -I $(FRACTOL_DIR) -I $(LIBFT_DIR)
NAME         = fractol
RM           = rm -rf

CFILES = $(wildcard $(FRACTOL_DIR)/*.c) \
         $(wildcard $(FRACTOL_DIR)/fractals/*.c)

OFILES = $(CFILES:.c=.o)

all: $(MINILIBX) $(LIBFT) $(NAME)

$(NAME): $(MINILIBX) $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lm -lX11 -lXext

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
