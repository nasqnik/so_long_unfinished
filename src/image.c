/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:29:45 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/29 12:50:12 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	char	*address;

	i = 0;
	while (i < IMAGE_COUNTER - 1)
	{
		if (i == 0)
			address = "images/char_front.xpm";
		else if (i == 1)
			address = "images/char_right.xpm";
		else if (i == 2)
			address = "images/char_left.xpm";
		else if (i == 3)
			address = "images/char_back.xpm";
		else if (i == 4)
			address = "images/door_open.xpm";
		else if (i == 5)
			address = "images/grass.xpm";
		else if (i == 6)
			address = "images/collectible.xpm";
		info->images[i].img = mlx_xpm_file_to_image(info->mlx, address,
				&info->images[i].img_width, &info->images[i].img_height);
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
