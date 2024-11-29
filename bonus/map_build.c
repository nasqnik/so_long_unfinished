/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:46 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/28 19:01:54 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	put_background(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] != '1')
				mlx_put_image_to_window(info->mlx, info->win.mlx_win,
					info->images[7].img, j * DIM, i * DIM);
			else
				mlx_put_image_to_window(info->mlx, info->win.mlx_win,
					info->images[5].img, j * DIM, i * DIM);
			j++;
		}
		i++;
	}
}

void	update_background(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] != '1' && info->map[i][j] != 'N'
					&& info->map[i][j] != 'C')
				mlx_put_image_to_window(info->mlx, info->win.mlx_win,
					info->images[7].img, j * DIM, i * DIM);
			else if (info->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx, info->win.mlx_win,
					info->images[5].img, j * DIM, i * DIM);
			j++;
		}
		i++;
	}
}

void	put_all_images(t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		k = 0;
		while (info->map[i][j])
		{
			if (ft_strchr("CEPN", info->map[i][j]))
				k = image_code(info->map[i][j], 'f');
			else
			{
				j++;
				continue ;
			}
			mlx_put_image_to_window(info->mlx, info->win.mlx_win,
				info->images[k].img, j * DIM, i * DIM);
			j++;
		}
		i++;
	}
}

void	put_image(t_info *info, int i, int j)
{
	int		k;
	char	dir;

	k = 0;
	dir = info->player.dir;
	if (ft_strchr("CNP", info->map[i][j]))
		k = image_code(info->map[i][j], dir);
	else if (info->map[i][j] == '0')
		k = 7;
	else if (info->map[i][j] == 'E')
	{
		if (info->collectible != info->player.collected)
			k = 4;
		else
			k = 13;
	}
	mlx_put_image_to_window(info->mlx, info->win.mlx_win,
		info->images[k].img, j * DIM, i * DIM);
}

void	draw_image(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] != '1' && info->map[i][j] != 'N'
				&& info->map[i][j] != 'C')
				put_image(info, i, j);
			j++;
		}
		i++;
	}
}
