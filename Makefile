CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM 			= rm -rf

NAME 		= so_long
HEADER 		= so_long.h

SRC			= src/main.c src/map_parsing.c src/utils.c src/map_check_path.c \
			src/map_flood_fill.c  src/game.c src/image.c src/map_build.c \
			src/move.c
			
OBJ			= $(SRC:%.c=%.o)

LIBFT		=	lib/libft/libft.a
FT_PRINTF	=	lib/ft_printf/libftprintf.a
MLX			=	mlx/libmlx.a

all:		libft ft_printf $(NAME)

$(NAME):	$(OBJ) $(MLX) 
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

libft:
			@$(MAKE) -C lib/libft/

ft_printf:
			@$(MAKE) -C lib/ft_printf/

$(MLX):
			@$(MAKE) -C mlx/

clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C lib/libft/ clean
			@$(MAKE) -C lib/ft_printf/ clean

fclean:		clean
			@$(MAKE) -C lib/libft/ fclean
			@$(MAKE) -C lib/ft_printf/ fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean fclean re libft ft_printf


# BONUS		= 
# BONUS_H	= 
# BONUS_SRC	= 
# BONUS_OBJ = $(BONUS_SRC:.c=.o)

# bonus:	libft ft_printf $(BONUS_OBJ)
# 			$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF) -o $(BONUS)