/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:45:52 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/27 14:48:51 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

int	move_indicator(t_info *info, int i, int j)
{
	if (info->map[i][j] == 'C')
	{
		info->player.collected++;
		info->map[i][j] = '0';
		return (1);
	}
	else if (info->map[i][j] == '1')
		return (0);
	else if (info->map[i][j] == 'N')
		return (4);
	else if (info->map[i][j] == 'E' && (info->player.collected
			!= info->collectible))
		return (3);
	else if (info->map[i][j] == 'E' && (info->player.collected
			== info->collectible))
		return (2);
	return (1);
}

void	move_up(t_info *info)
{
	int	i;
	int	j;
	int	indicator;

	j = info->player.coordinates.x / DIM;
	i = info->player.coordinates.y / DIM - 1;
	info->player.dir = 'b';
	indicator = move_indicator(info, i, j);
	if (indicator == 1 || indicator == 4)
	{
		draw_image(info);
		info->map[i][j] = 'P';
		info->map[i + 1][j] = '0';
		update_game(info);
		if (indicator == 4)
			quit_game(info, 2);
	}
	else if (indicator == 2)
		quit_game(info, 1);
	else if (indicator == 3)
		ft_printf("You have to collect all chickens to exit\n");
}

void	move_down(t_info *info)
{
	int	i;
	int	j;
	int	indicator;

	j = info->player.coordinates.x / DIM;
	i = info->player.coordinates.y / DIM + 1;
	info->player.dir = 'f';
	indicator = move_indicator(info, i, j);
	if (indicator == 1 || indicator == 4)
	{
		draw_image(info);
		info->map[i][j] = 'P';
		info->map[i - 1][j] = '0';
		update_game(info);
		if (indicator == 4)
			quit_game(info, 2);
	}
	else if (indicator == 2)
		quit_game(info, 1);
	else if (indicator == 3)
		ft_printf("You have to collect all chickens to exit\n");
}

void	move_left(t_info *info)
{
	int	i;
	int	j;
	int	indicator;

	j = info->player.coordinates.x / DIM - 1;
	i = info->player.coordinates.y / DIM;
	info->player.dir = 'l';
	indicator = move_indicator(info, i, j);
	if (indicator == 1 || indicator == 4)
	{
		draw_image(info);
		info->map[i][j] = 'P';
		info->map[i][j + 1] = '0';
		update_game(info);
		if (indicator == 4)
			quit_game(info, 2);
	}
	else if (indicator == 2)
		quit_game(info, 1);
	else if (indicator == 3)
		ft_printf("You have to collect all chickens to exit\n");
}

void	move_right(t_info *info)
{
	int	i;
	int	j;
	int	indicator;

	j = info->player.coordinates.x / DIM + 1;
	i = info->player.coordinates.y / DIM;
	info->player.dir = 'r';
	indicator = move_indicator(info, i, j);
	if (indicator == 1 || indicator == 4)
	{
		draw_image(info);
		info->map[i][j] = 'P';
		info->map[i][j - 1] = '0';
		update_game(info);
		if (indicator == 4)
			quit_game(info, 2);
	}
	else if (indicator == 2)
		quit_game(info, 1);
	else if (indicator == 3)
		ft_printf("You have to collect all chickens to exit\n");
}
