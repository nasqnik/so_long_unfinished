/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:52:26 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/04 17:23:01 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_parsing(int file_fd, t_info *info)
{
	char *tmp_map;
    char *tmp;
	char *buffer;

	while (1)
	{
		buffer = get_next_line(file_fd);
		if (!buffer)
			break ;
        tmp = tmp_map;
		tmp_map = ft_strjoin(tmp_map, buffer); // leak
		free(buffer);
       // free(tmp);
	}
	info->map = ft_split(tmp_map, '\n'); 
    if (!info->map)
    {
        ft_printf("Map is not initialized");
        exit(EXIT_FAILURE);
    }
	close(file_fd);
}

void letter_checks(t_info *info)
{
	int i;
    int j;

    i = 0;
    
	while (info->map[i])
	{
        j = 0;
        while (info->map[i][j])
        {
            if (info->map[i][j] == 'E')
                info->exit++;
            else if (info->map[i][j] == 'S')
                info->start++;
            else if (info->map[i][j] == 'C')
                info->collectible++;
            j++; // proverit' na chto libo krome etih bukv
        }
		i++;
	}
	
	// ft_printf("exit: %i\n", info->exit);
	// ft_printf("start: %i\n", info->start);
	// ft_printf("collectible: %i\n", info->collectible);
	
	if (info->exit != 1 || info->start != 1 || info->collectible < 1)
		error("letter_checks: Map is not valid", info);
}

void size_checks(t_info *info)
{
	int current_row_length;
	
	info->width = ft_strlen(info->map[0]);
	while (info->map[info->height])
	{
		current_row_length = ft_strlen(info->map[info->height]);
		if (current_row_length != info->width || current_row_length == 0)
			error("size_checks: Map is not valid", info);
		info->height++;
	}

	// ft_printf("width: %d\n", info->width);
	// ft_printf("height: %d\n", info->height);
	
	if (info->height <= 2 || info->width <= 2 || info->height == info->width)
		error("size_checks: Map is not valid", info);
}

