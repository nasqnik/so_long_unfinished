/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:26:04 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/14 15:24:12 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/libft/libft.h"
#include "../lib/ft_printf/ft_printf.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
#include <stdio.h> // printf!!!!!

typedef struct s_point
{
	int x;
	int y;
}	t_point;

typedef struct s_info
{
	char	**map;
	int		exit;
	int		collectible;
	int		start;
	t_point	start_coordinates;
	int		width;
	int		height;
} t_info;

// map.c
void	map_parsing(int file_fd, t_info *info);
void	map_checks(t_info *info);
void	letter_checks(t_info *info);
void	size_checks(t_info *info);
void	border_checks(t_info *info);

//map_chack_path.c
char **map_copy(t_info *info);
void player_pos(t_info *info);
void check_path(t_info *info);
void check_filled(t_info *info, char **area, int counter);

// flood_fill.c
void flood_fill_manager(char **area, t_point size, t_point start, int counter);
void flood_fill(char **area, t_point size, t_point start, char to_fill);
void flood_fill_exit(char **area, t_point size, t_point start, char to_fill);


//utils.c
void	free_array(char **array);
void    error(char *msg, t_info *info);
int		ft_strrncmp(char *str1, char *str2, int n);

#endif