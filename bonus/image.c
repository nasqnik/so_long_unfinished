/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:36:44 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/27 13:58:59 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	initialize_images(t_info *info)
{
	int	i;

	i = 0;
	while (i < IMAGE_COUNTER)
	{
		info->images[i].img = NULL;
		info->images[i].img_width = DIM;
		info->images[i].img_height = DIM;
		i++;
	}
}

void	load_images(t_info *info)
{
	int		i;
	char	*a;

	i = 0;
	while (i < 7)
	{
		if (i == 0)
			a = "images/char_front.xpm";
		else if (i == 1)
			a = "images/char_right.xpm";
		else if (i == 2)
			a = "images/char_left.xpm";
		else if (i == 3)
			a = "images/char_back.xpm";
		else if (i == 4)
			a = "images/door_closed.xpm";
		else if (i == 5)
			a = "images/grass.xpm";
		else if (i == 6)
			a = "images/collectible.xpm";
		info->images[i].img = mlx_xpm_file_to_image(info->mlx,
				a, &info->images[i].img_width, &info->images[i].img_height);
		i++;
	}
}

void	image_checker(t_info *info)
{
	if (image_return(info) == 1)
	{
		mlx_destroy_window(info->mlx, info->win.mlx_win);
		destroy_images(info);
		error("image_checker: one of the images is invalid", info);
	}
}

int	image_return(t_info *info)
{
	int	i;

	i = 0;
	while (i < IMAGE_COUNTER)
	{
		if (info->images[i].img == NULL)
			return (1);
		i++;
	}
	return (0);
}

void	destroy_images(t_info *info)
{
	int	i;

	i = 0;
	while (i < IMAGE_COUNTER)
	{
		if (info->images[i].img == NULL)
		{
			i++;
			continue ;
		}
		mlx_destroy_image(info->mlx, info->images[i].img);
		i++;
	}
}
