/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edouard <edouard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:56:47 by edouard           #+#    #+#             */
/*   Updated: 2024/09/14 14:27:04 by edouard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_mock_data(t_map *map)
{
	map->north_textxure = "./textures/1.xpm";
	map->south_textxure = "./textures/1.xpm";
	map->west_textxure = "./textures/1.xpm";
	map->east_textxure = "./textures/1.xpm";

	int floor_color[3] = {128, 128, 0};
	int ceiling_color[3] = {175, 238, 238};

	map->f_color = malloc(3 * sizeof(char *));
	map->c_color = malloc(3 * sizeof(char *));

	if (!map->f_color || !map->c_color)
		return ft_message_error("Error during malloc for colors\n");

	map->window.width = 800;
	map->window.height = 600;
	for (int i = 0; i < 3; i++)
	{
		map->f_color[i] = malloc(sizeof(char) * 4);
		map->c_color[i] = malloc(sizeof(char) * 4);
		if (!map->f_color[i] || !map->c_color[i])
			return ft_message_error("Error during malloc for color components\n");
		sprintf(map->f_color[i], "%d", floor_color[i]);
		sprintf(map->c_color[i], "%d", ceiling_color[i]);
	}

	map->grid = malloc(sizeof(char *) * 14);
	if (!map->grid)
		return ft_message_error("Error during malloc for grid\n");

	char *map_data[] = {
		 "1111111111111111111111111",
		 "1000000000110000000000001",
		 "1011000001110000000000001",
		 "1001000000000000000000001",
		 "111111111011000001110000000000001",
		 "100000000011000001110111111111111",
		 "11110111111111011100000010001",
		 "11110111111111011101010010001",
		 "11000000110101011100000010001",
		 "10000000000000001100000010001",
		 "10000000000000001101010010001",
		 "11000001110101011111011110N0111",
		 "11110111 1110101 101111010001",
		 "11111111 1111111 111111111111"};

	for (int i = 0; i < 14; i++)
	{
		map->grid[i] = ft_strdup(map_data[i]);
		if (!map->grid[i])
			return ft_message_error("Error during strdup for grid\n");
	}

	map->player_x = 12;
	map->player_y = 12;

	map->m_width = ft_strlen(map->grid[0]);
	map->m_height = 14;

	return 0;
}