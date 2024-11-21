/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:46 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/21 16:33:22 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_background(t_info *info)
{
    int i;
    int j;

    i = 0;
    while (info->map[i])
    {
        j = 0;
        while (info->map[i][j])
        {
            if (info->map[i][j] != '1')
                mlx_put_image_to_window(info->mlx, info->win.mlx_win, 
                info->images[7].img, j * DIM, i * DIM);
            j++;
        }
        i++;
    }
}

void put_all_images(t_info *info)
{
    int i;
    int j;
    int k;

    i = 0;
    while (info->map[i])
    {
        j = 0;
        k = 0;
        while (info->map[i][j])
        {
            if (ft_strchr("1CEP", info->map[i][j]))
                k = image_code(info->map[i][j]);
            else
            {
                j++;
                continue;
            }
            mlx_put_image_to_window(info->mlx, info->win.mlx_win, 
                info->images[k].img, j * DIM, i * DIM);
            j++;
        }
        i++;
    }
}

void put_image(t_info *info, int i, int j)
{
    int k;
    char dir;
    
    k = 0;
    dir = info->player.dir;
    if (ft_strchr("1CE", info->map[i][j]))
        k = image_code(info->map[i][j]);
    else if (info->map[i][j] == '0')
        k = 7;
    else if (info->map[i][j] == 'P')
    {
        if (dir == 'f')
            k = 0;
        else if (dir == 'l')
            k = 2;
        else if (dir == 'r')
            k = 1;
        else if (dir == 'b')
            k = 3;
    }
    mlx_put_image_to_window(info->mlx, info->win.mlx_win, 
        info->images[k].img, j * DIM, i * DIM);
}

void draw_image(t_info *info)
{
    int i;
    int j;

    i = 0;
    while (info->map[i])
    {
        j = 0;
        while (info->map[i][j])
        {
            put_image(info, i, j);
            j++;
        }
        i++;
    }
}

int image_code(char cell)
{
    if (cell == 'P')
        return 0;
    else if (cell == 'E')
        return 4;
    else if (cell == '1')
        return 5;
    else if (cell == 'C')
        return 6;
    return -1;
}

