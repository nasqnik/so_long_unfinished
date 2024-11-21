/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:24:54 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/21 14:28:46 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_path(t_info *info)
{
    char **area_check;
    t_point size;
    t_point start;
    int counter;

    size = (t_point){info->width, info->height};
    start = info->start_coordinates;
    counter = 1;
    
    while (counter < 3)
    {
        area_check = map_copy(info);
        flood_fill_manager(area_check, size, start, counter);
        check_filled(info, area_check, counter);
        free_array(area_check);
        counter++;
    }
}

char **map_copy(t_info *info)
{
    char **copy;
    int i;

    copy = (char **)malloc(sizeof(char *) * (info->height + 1));
    if (!copy)
        error("map_copy: malloc failed", info);
    i = 0;
    while (i < info->height)
    {
        copy[i] = ft_strdup(info->map[i]);
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

void player_pos(t_info *info, int flag)
{
    int i;
    int j;

    i = 0;
    while (info->map[i])
	{
        j = 0;
        while (info->map[i][j])
        {
            if (info->map[i][j] == 'P')
            {
                if (flag)
                    info->start_coordinates = (t_point){j, i};
                info->player.coordinates = (t_point){j * DIM, i * DIM};
                // printf("x: %d, y: %d\n", info->start_coordinates.x, info->start_coordinates.y);
                // printf("x: %d, y: %d\n", info->player.coordinates.x, info->player.coordinates.y);
            }
            j++;
        }
		i++;
    }
}

void check_filled(t_info *info, char **area, int counter)
{
    int i;
    int j;

    i = 0;
	while (area[i])
	{
        j = 0;
        while (area[i][j])
        {
            if (counter == 1 && (area[i][j] == 'E' || area[i][j] == 'P' || area[i][j] == 'C'))
            {
                free_array(area);
                error("letter_checks: Map is not valid", info);
            }
            else if (counter == 2 && (area[i][j] == 'P' || area[i][j] == 'C'))
            {
                free_array(area);
                error("letter_checks: Map is not valid", info);
            }
            j++;
        }
		i++;
	}	
}