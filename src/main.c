/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:16:10 by anikitin          #+#    #+#             */
/*   Updated: 2024/11/04 17:14:39 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void initialize(t_info *info)
{
	info->map = NULL;
	info->start = 0;
	info->exit = 0;
	info->collectible = 0; 
	info->width = 0;
	info->height = 0;
}

int main(int argc, char **argv)
{
    // check argument count
    if (argc != 2)
    {
        ft_printf("Correct usage: ./so_long map.ber\n");
        exit(EXIT_FAILURE); // check the exit code
    }
    //___________________________
    
    
    // file opening and checks
    int file;

    if (access(argv[1], R_OK) == -1) // check for .ber and folder / stat function
        ft_printf("Error accessing file\n");
    file = open(argv[1], O_RDONLY);
    if (file == -1)
        ft_printf("Error opening file\n");
    else
        ft_printf("File opened successfully\n");
    //___________________________


	// map parsing
	t_info info;

	initialize(&info);
	map_parsing(file, &info);

	int i = 0;
	
	while (info.map[i])
	{
		ft_printf("%s\n", info.map[i]);
		i++;
	}
	//letter_checks(&info);
	size_checks(&info);
	free_array(info.map);
	
}