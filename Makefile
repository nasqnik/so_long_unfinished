CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM 			= rm -rf

NAME 		= so_long
HEADER 		= so_long.h

SRC			= src/main.c src/map_parsing.c src/utils.c src/map_check_path.c \
			src/map_flood_fill.c  src/game.c src/image.c src/map_build.c \
			src/move.c
			
OBJ			= $(SRC:%.c=%.o)


BONUS		= so_long
BONUS_H		= bonus_so_long.h 

BONUS_SRC	= bonus/main.c bonus/utils.c bonus/image.c bonus/map_check_path.c \
			bonus/map_parsing.c bonus/enemies.c bonus/map_flood_fill.c bonus/game.c \
			bonus/map_build.c bonus/move.c bonus/chicken.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT		=	lib/libft/libft.a
FT_PRINTF	=	lib/ft_printf/libftprintf.a
MLX			=	mlx/libmlx.a

all:		libft ft_printf $(NAME)

bonus:		libft ft_printf $(BONUS_OBJ) $(MLX)
			$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

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
			@$(RM) $(OBJ) $(BONUS_OBJ)
			@$(MAKE) -C lib/libft/ clean
			@$(MAKE) -C lib/ft_printf/ clean
			@$(MAKE) -C mlx clean

fclean:		clean
			@$(MAKE) -C lib/libft/ fclean
			@$(MAKE) -C lib/ft_printf/ fclean
			@$(MAKE) -C mlx clean
			@$(RM) $(NAME) $(BONUS)

re:			fclean all

.PHONY:		all	clean fclean re bonus

