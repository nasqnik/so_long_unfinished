/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:26:04 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/04 17:22:39 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../lib/libft/libft.h"
#include "../lib/ft_printf/ft_printf.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 


typedef struct s_info
{
	char	**map;
	int		exit;
	int		collectible;
	int		start;
	int		width;
	int		height;
} t_info;

// map.c
void	map_parsing(int file_fd, t_info *info);
void	letter_checks(t_info *info);
void	size_checks(t_info *info);

//utils.c
void	free_array(char **array);
void    error(char *msg, t_info *info);

#endif