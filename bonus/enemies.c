/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:03:57 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/29 13:26:34 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	enemy_animation(t_info *info)
{
	int			i;
	int			j;
	static int	frame;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'N' && frame % 10 == 0)
				update_enemy_position(info, i, j);
			j++;
		}
		i++;
	}
	frame++;
	if (frame >= 2400)
		frame = 0;
}

void	load_enemies_and_chicken(t_info *info)
{
	int		i;
	char	*address;

	i = 7;
	while (i < IMAGE_COUNTER)
	{
		if (i == 7)
			address = "images/path.xpm";
		else if (i == 8)
			address = "images/enemy_right.xpm";
		else if (i == 9)
			address = "images/enemy_left.xpm";
		else if (i == 10)
			address = "images/chicken1.xpm";
		else if (i == 11)
			address = "images/chicken2.xpm";
		else if (i == 12)
			address = "images/chicken3.xpm";
		else if (i == 13)
			address = "images/door_open.xpm";
		info->images[i].img = mlx_xpm_file_to_image(info->mlx, address,
				&info->images[i].img_width, &info->images[i].img_height);
		i++;
	}
}

void	draw_enemy(t_info *info, int i, int j, int old_j)
{
	mlx_put_image_to_window(info->mlx, info->win.mlx_win,
		info->images[7].img, j * DIM, i * DIM);
	if (old_j <= j)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[8].img, j * DIM, i * DIM);
	if (old_j > j)
		mlx_put_image_to_window(info->mlx, info->win.mlx_win,
			info->images[9].img, j * DIM, i * DIM);
}

void	update_enemy_position(t_info *info, int i, int j)
{
	int	new_i;
	int	new_j;
	int	dir;

	new_i = i;
	new_j = j;
	dir = rand() % 4;
	if (dir == 0 && (info->map[i - 1][j] == '0' || info->map[i - 1][j] == 'P'))
		new_i = i - 1;
	if (dir == 1 && (info->map[i][j + 1] == '0' || info->map[i][j + 1] == 'P'))
		new_j = j + 1;
	if (dir == 2 && (info->map[i + 1][j] == '0' || info->map[i + 1][j] == 'P'))
		new_i = i + 1;
	if (dir == 3 && (info->map[i][j - 1] == '0' || info->map[i][j - 1] == 'P'))
		new_j = j - 1;
	if (new_i != i || new_j != j)
	{
		info->map[i][j] = '0';
		if (info->map[new_i][new_j] == 'P')
			quit_game(info, 2);
		info->map[new_i][new_j] = 'N';
	}
	mlx_put_image_to_window(info->mlx, info->win.mlx_win,
		info->images[7].img, j * DIM, i * DIM);
	draw_enemy(info, new_i, new_j, j);
}
