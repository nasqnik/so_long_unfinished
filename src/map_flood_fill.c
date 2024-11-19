/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:45:36 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/14 15:24:24 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill_manager(char **area, t_point size, t_point start, int counter)
{
    if (counter == 1)
        flood_fill(area, size, start, 'V');
    else if (counter == 2)
        flood_fill_exit(area, size, start, 'V');
    // else if (counter == 2)
}

void flood_fill(char **area, t_point size, t_point start, char to_fill)
{
    if (start.y < 0 || start.x < 0 || start.y >= size.y || start.x >= size.x 
        || area[start.y][start.x] == '1' || area[start.y][start.x] == to_fill)
        return ;
    area[start.y][start.x] = to_fill;
    flood_fill(area, size, (t_point){start.x - 1, start.y}, to_fill);
    flood_fill(area, size, (t_point){start.x + 1, start.y}, to_fill);
    flood_fill(area, size, (t_point){start.x, start.y - 1}, to_fill);
    flood_fill(area, size, (t_point){start.x, start.y + 1}, to_fill);
}

void flood_fill_exit(char **area, t_point size, t_point start, char to_fill)
{
    if (start.y < 0 || start.x < 0 || start.y >= size.y || start.x >= size.x 
        || area[start.y][start.x] == '1' || area[start.y][start.x] == 'E' 
        || area[start.y][start.x] == to_fill)
        return ;
    area[start.y][start.x] = to_fill;
    flood_fill_exit(area, size, (t_point){start.x - 1, start.y}, to_fill);
    flood_fill_exit(area, size, (t_point){start.x + 1, start.y}, to_fill);
    flood_fill_exit(area, size, (t_point){start.x, start.y - 1}, to_fill);
    flood_fill_exit(area, size, (t_point){start.x, start.y + 1}, to_fill);
}