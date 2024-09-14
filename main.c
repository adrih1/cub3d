/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:51 by ahors             #+#    #+#             */
/*   Updated: 2024/09/14 14:01:47 by edouard          ###   ########.fr       */
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
	(*map)->north_textxure = NULL;
	(*map)->east_textxure = NULL;
	(*map)->south_textxure = NULL;
	(*map)->west_textxure = NULL;
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
		return (1);
	if (ac != 2)
	{
		printf("Please give a .cub file for the map\n");
		if (ft_mock_data(map))
			return (1);
	}
	else
	{
		if (ft_parsing(map, av[1]))
		{
			// Clean - Exit
			return (1);
		}
	}
	ft_executor(map);
	// The Game
	// Ray Casting
	// Rendering the walls
	// Player Movement
	// Clean

	return (0);
}