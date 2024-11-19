CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM 			= rm -rf

NAME 		= so_long
HEADER 		= so_long.h

SRC			= src/main.c src/map.c src/utils.c src/map_check_path.c src/map_flood_fill.c
OBJ			= $(SRC:%.c=%.o)

LIBFT		=	lib/libft/libft.a
FT_PRINTF	=	lib/ft_printf/libftprintf.a

all:		libft ft_printf $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS)  -c $< -o $@

libft:
			@$(MAKE) -C lib/libft/

ft_printf:
			@$(MAKE) -C lib/ft_printf/

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