/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_is_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:43:15 by ahors             #+#    #+#             */
/*   Updated: 2024/10/23 12:53:04 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_height_is_valid(t_map *map)
{
	if (map->real_height < 3)
	{
		printf("Error: Map is too smal\n");
		return (1);
	}
	return (0);
}

int	ft_map_walls_is_valid(t_map *map)
{
	if (ft_check_has_only_walls_spaces(map->grid[0])
		|| ft_check_has_only_walls_spaces(map->grid[map->real_height - 1]))
	{
		printf("Error: Your map must be enclosed by walls\n");
		return (1);
	}
	if (ft_check_player_can_exit_map(map))
	{
		printf("Error: Player should not be able to exit map\n");
		return (1);
	}
	return (0);
}

int	ft_map_has_special_chars_is_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (ft_check_unvalid_chars(map->grid[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_map_has_one_player_is_valid(t_map *map)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'E'
				|| map->grid[i][j] == 'W' || map->grid[i][j] == 'S')
				count_player++;
			j++;
		}
		i++;
	}
	if (count_player != 1)
	{
		printf("Error: Your map should have one player\n");
		return (1);
	}
	return (0);
}

int	ft_map_grid_is_valid(t_map *map)
{
	if (map->last_info_found > map->begin)
	{
		printf("Eroor: Your map should be at the end of the file\n");
		return (1);
	}
	if (ft_map_height_is_valid(map))
		return (1);
	if (ft_map_walls_is_valid(map))
		return (1);
	if (ft_map_has_special_chars_is_valid(map))
		return (1);
	return (0);
}
