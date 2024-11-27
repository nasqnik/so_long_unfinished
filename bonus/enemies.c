/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:03:57 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/27 14:35:23 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	load_enemies(t_info *info)
{
	int		i;
	char	*address;

	i = 8;
	while (i < IMAGE_COUNTER)
	{
		if (i == 8)
			address = "images/enemy1.xpm";
		else if (i == 9)
			address = "images/enemy2.xpm";
		else if (i == 10)
			address = "images/enemy3.xpm";
		else if (i == 11)
			address = "images/enemy4.xpm";
		info->images[i].img = mlx_xpm_file_to_image(info->mlx, address,
				&info->images[i].img_width, &info->images[i].img_height);
		i++;
	}
}

int	animation(t_info *info)
{
	find_enemy(info);
	return (0);
}

void	find_enemy(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'N')
				draw_enemy(info, i, j);
			j++;
		}
		i++;
	}
}

void	draw_enemy(t_info *info, int i, int j)
{
	static int	frame;

	mlx_put_image_to_window(info->mlx, info->win.mlx_win,
		info->images[7].img, j * DIM, i * DIM);
	draw_enemy_animation(info, i, j, frame);
	frame++;
	if (frame == 60)
		frame = 0;
}

void	draw_enemy_animation(t_info *info, int i, int j, int frame)
{
	if (frame < 15)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[8].img, j * DIM, i * DIM);
	else if (frame < 30)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[9].img, j * DIM, i * DIM);
	else if (frame < 45)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[10].img, j * DIM, i * DIM);
	else if (frame < 60)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[11].img, j * DIM, i * DIM);
}
