/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:46:55 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/28 19:12:42 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error(char *msg, t_info *info)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	if (info->map != NULL)
		free_array(info->map);
	exit(EXIT_FAILURE);
}

int	ft_strrncmp(char *str1, char *str2, int n)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(str1) - 1;
	len2 = ft_strlen(str2) - 1;
	while (n > 0 && len1 >= 0 && len2 >= 0)
	{
		if (str1[len1] != str2[len2])
			return (str1[len1] - str1[len2]);
		len1--;
		len2--;
		n--;
	}
	return (0);
}

void	load_last_image(t_info *info)
{
	char	*address;

	address = "images/path.xpm";
	info->images[7].img = mlx_xpm_file_to_image(info->mlx, address,
			&info->images[7].img_width, &info->images[7].img_height);
}
