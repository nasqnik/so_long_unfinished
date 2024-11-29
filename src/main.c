/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:16:10 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/29 13:12:12 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_info *info)
{
	info->mlx = NULL;
	info->win.x = 0;
	info->win.y = 0;
	info->win.mlx_win = NULL;
	info->player.coordinates = (t_point){0, 0};
	info->player.collected = 0;
	info->player.dir = 's';
	info->player.moves = 0;
	initialize_images(info);
	info->map = NULL;
	info->start = 0;
	info->start_coordinates = (t_point){0, 0};
	info->exit = 0;
	info->exit_condition = 0;
	info->collectible = 0;
	info->width = 0;
	info->height = 0;
}

int	open_checks(int argc, char **argv)
{
	int	file;

	if (argc != 2)
	{
		ft_printf("Error\nCorrect usage: ./so_long maps/map.ber\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strrncmp(argv[1], ".ber", 4) != 0)
	{
		ft_printf("Error\nInvalid file type: .ber expected\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		ft_printf("Error\nError accessing file\n");
		exit(EXIT_FAILURE);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_printf("Error\nError opening file\n");
		exit(EXIT_FAILURE);
	}
	return (file);
}

int	main(int argc, char **argv)
{
	int		file;
	t_info	info;

	file = open_checks(argc, argv);
	initialize(&info);
	map_parsing(file, &info);
	map_checks(&info);
	start_game(&info);
	mlx_hook(info.win.mlx_win, 17, 0L, quit_game, &info);
	mlx_key_hook(info.win.mlx_win, move_keys, &info);
	mlx_loop(info.mlx);
	free_array(info.map);
}
