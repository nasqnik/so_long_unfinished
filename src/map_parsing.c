/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:52:26 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/21 14:27:19 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_parsing(int file_fd, t_info *info)
{
	char *tmp_map;
	char *buffer;
	char *tmp;

	tmp_map = NULL;
	while (1)
	{
		buffer = get_next_line(file_fd);
		if (!buffer)
			break ;
		tmp = tmp_map;
		if (tmp_map == NULL)
			tmp_map = ft_strdup(buffer);
		else
			tmp_map = ft_strjoin(tmp_map, buffer);
		free(tmp);
		free(buffer);
	}
	info->map = ft_split(tmp_map, '\n'); 
	free(tmp_map);
    if (!info->map)
		error("Map is not initialized", info);
	close(file_fd);
}

void map_checks(t_info *info)
{
	letter_checks(info);
	size_checks(info);
	border_checks(info);
	player_pos(info, 1);
	check_path(info);
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
            else if (info->map[i][j] == 'P')
				info->start++;
            else if (info->map[i][j] == 'C')
                info->collectible++;
			if (!ft_strchr("01CEP\n", info->map[i][j]))
				error("letter_checks: Map is not valid", info);
            j++;
        }
		i++;
	}	
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
	
	if (info->height <= 2 || info->width <= 2)
		error("size_checks: Map is not valid", info);
}

void border_checks(t_info *info)
{
	int i = 0;
	int j;

	while (i < info->width)
	{
		if (info->map[0][i] != '1' || info->map[info->height - 1][i] != '1')
			error("border_checks: Map must be surrounded by walls\n", info);
		i++;
	}
	j = 1;
	while (j < info->height - 1)
	{
		if (info->map[j][0] != '1' || info->map[j][info->width - 1] != '1')
			error("border_checks: Map must be surrounded by walls\n", info);
		j++;
	}
}

