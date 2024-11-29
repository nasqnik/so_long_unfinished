/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:48 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/28 19:01:20 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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

void	put_moves_on_screen(t_info *info)
{
	char	*str;
	char	*moves;

	moves = ft_itoa(info->player.moves);
	str = ft_strjoin("moves: ", moves);
	mlx_string_put(info->mlx, info->win.mlx_win, 42, 22, 0xFFFFFF, str);
	free(str);
}

int	image_code(char cell, char dir)
{
	if (cell == 'P')
	{
		if (dir == 'f')
			return (0);
		else if (dir == 'l')
			return (2);
		else if (dir == 'r')
			return (1);
		else if (dir == 'b')
			return (3);
	}
	else if (cell == 'E')
		return (4);
	else if (cell == 'N')
		return (8);
	else if (cell == 'C')
		return (6);
	return (-1);
}
