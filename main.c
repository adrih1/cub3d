/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:51 by ahors             #+#    #+#             */
/*   Updated: 2024/09/17 11:17:57 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_init_map(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (!(*map))
		return ft_message_error("Error during malloc for map\n");

	(*map)->m_width = 0;
	(*map)->m_height = 0;
	(*map)->dirty_grid = NULL;
	(*map)->grid = NULL;
	(*map)->player_x = 0;
	(*map)->player_y = 0;
	(*map)->f_color = NULL;
	(*map)->c_color = NULL;
	(*map)->data.mlx_ptr = NULL;
	(*map)->data.win_ptr = NULL;

	return (0);
}

int main(int ac, char **av)
{
	t_map *map;

	if (ft_init_map(&map))
	{
		printf("Probleme pour init\n");
		return (1);		
	}
	if (ac != 2)
		printf("Please give a .cub file for the map\n");
	else
		// MinilibX - Initialisation de la fenetre
		// Map Init - Parsing
		if (ft_parsing(map, av[1]))
		{
			// Clean - Exit
			ft_clean(map);
			return (1);
		}
	// ft_executor(map);
	// The Game
	// Casting the Rays
	// Rendering the walls
	// Playr Movement
	// Clean
	ft_clean(map);
	return (0);
}
