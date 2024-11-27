/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:26:04 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/27 15:13:40 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h> 
# include <stdio.h> // printf!!!!!

# define DIM 48
# define IMAGE_COUNTER 8
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_window
{
	int		x;
	int		y;
	void	*mlx_win;
}				t_window;

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_image
{
	void	*img;
	int		img_width;
	int		img_height;
}				t_image;

typedef struct s_player
{
	t_point	coordinates;
	int		collected;
	int		moves;
	char	dir;	
}			t_player;

typedef struct s_info
{
	void		*mlx;
	t_window	win;
	t_image		images[8];
	t_player	player;
	char		**map;
	int			exit;
	int			exit_condition;
	int			collectible;
	int			start;
	t_point		start_coordinates;
	int			width;
	int			height;
}			t_info;

// map_parsing.c
void	map_parsing(int file_fd, t_info *info);
void	map_checks(t_info *info);
void	letter_checks(t_info *info);
void	size_checks(t_info *info);
void	border_checks(t_info *info);

//map_chack_path.c
char	**map_copy(t_info *info);
void	player_pos(t_info *info, int flag);
void	check_path(t_info *info);
void	check_filled(t_info *info, char **area, int counter);

//map_build.c
void	put_background(t_info *info);
void	put_all_images(t_info *info);
void	put_image(t_info *info, int i, int j);
void	draw_image(t_info *info);
int		image_code(char cell);

// flood_fill.c
void	flood_fill_manager(char **area, t_point size, t_point start,
			int counter);
void	flood_fill(char **area, t_point size, t_point start, char to_fill);
void	flood_fill_exit(char **area, t_point size, t_point start, char to_fill);

//utils.c
void	free_array(char **array);
void	error(char *msg, t_info *info);
int		ft_strrncmp(char *str1, char *str2, int n);

//game.c
void	start_game(t_info *info);
void	update_game(t_info *info);
int		quit_game(t_info *info);
int		move_keys(int key, t_info *info);

//move.c
int		move_indicator(t_info *info, int i, int j);
void	move_up(t_info *info);
void	move_down(t_info *info);
void	move_left(t_info *info);
void	move_right(t_info *info);

//image.c
void	initialize_images(t_info *info);
void	load_images(t_info *info);
void	image_checker(t_info *info);
int		image_return(t_info *info);
void	destroy_images(t_info *info);

#endif