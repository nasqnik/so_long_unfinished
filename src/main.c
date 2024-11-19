/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:16:10 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/14 17:49:42 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize(t_info *info)
{
	info->map = NULL;
	info->start = 0;
	info->start_coordinates = (t_point){0, 0};
	info->exit = 0;
	info->collectible = 0; 
	info->width = 0;
	info->height = 0;
}

int open_checks(int argc, char **argv)
{
	int file;

	if (argc != 2)
    {
        ft_printf("Correct usage: ./so_long map.ber\n");
        exit(EXIT_FAILURE); // check the exit code
    }
	if (ft_strrncmp(argv[1], ".ber", 4) != 0) // it works for .ber.ber
	{
		ft_printf("Invalid file type: .ber expected\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		ft_printf("Error accessing file\n");
		exit(EXIT_FAILURE);
	}
    file = open(argv[1], O_RDONLY);
    if (file == -1)
	{
		ft_printf("Error opening file\n");
		exit(EXIT_FAILURE);
	}
	return file;
}

int main(int argc, char **argv)
{
    int file;
	t_info info;

	file = open_checks(argc, argv);
	initialize(&info);
	map_parsing(file, &info);
	map_checks(&info);

	free_array(info.map);
	
}