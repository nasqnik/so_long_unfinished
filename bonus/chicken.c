/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chicken.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:04:46 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/28 18:49:18 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	chicken_animation(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'C')
				draw_chicken(info, i, j);
			j++;
		}
		i++;
	}
}

void	draw_chicken(t_info *info, int i, int j)
{
	static int	frame;

	mlx_put_image_to_window(info->mlx, info->win.mlx_win,
		info->images[7].img, j * DIM, i * DIM);
	if (frame < 15)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[10].img, j * DIM, i * DIM);
	if (frame < 30)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[11].img, j * DIM, i * DIM);
	else if (frame < 45)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[10].img, j * DIM, i * DIM);
	else if (frame < 60)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[12].img, j * DIM, i * DIM);
	frame++;
	if (frame >= 60)
		frame = 0;
}
