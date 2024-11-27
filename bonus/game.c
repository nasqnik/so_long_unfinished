/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:02:48 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/27 14:21:02 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	start_game(t_info *info)
{
	info->win.x = info->width * DIM;
	info->win.y = info->height * DIM;
	info->mlx = mlx_init();
	if (!info->mlx)
		error("mlx_init failed in start_game", info);
	info->win.mlx_win = mlx_new_window(info->mlx,
			info->win.x, info->win.y, "so_long"); // should we check for the error?
	load_images(info);
	load_enemies(info);
	image_checker(info);
	put_background(info);
	put_all_images(info);
	put_moves_on_screen(info);
}

int	quit_game(t_info *info, int condition)
{
	if (condition == 1)
		ft_printf("Congratulations! You won the game :)\n");
	else if (condition == 2)
		ft_printf("You were caught by a dog\n");
	else
		ft_printf("You exited the game\n");
	destroy_images(info);
	mlx_destroy_window(info->mlx, info->win.mlx_win);
	if (info->map != NULL)
		free_array(info->map);
	exit(EXIT_SUCCESS);
}

void	update_game(t_info *info)
{
	info->player.moves++;
	player_pos(info, 0);
	put_background(info);
	draw_image(info);
	put_moves_on_screen(info);
}

int	move_keys(int key, t_info *info)
{
	if (key == W_KEY)
		move_up(info);
	else if (key == A_KEY)
		move_left(info);
	else if (key == S_KEY)
		move_down(info);
	else if (key == D_KEY)
		move_right(info);
	else if (key == ESC_KEY)
		quit_game(info, 0);
	return (0);
}
