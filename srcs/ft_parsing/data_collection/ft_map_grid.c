/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:50:20 by ahors             #+#    #+#             */
/*   Updated: 2024/09/27 15:37:17 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_player_plane(char c, t_player *player)
{
	if (c == 'N')
	{
		player->planeX = 0.66;
		player->planeY = 0;
	}
	else if (c == 'E')
	{
		player->planeX = 0;
		player->planeY = 0.66;
	}
	else if (c == 'S')
	{
		player->planeX = -0.66;
		player->planeY = 0;
	}
	else if (c == 'O')
	{
		player->planeX = 0;
		player->planeY = -0.66;
	}
}

static void	ft_player_orientation(char c, t_player *player)
{
	if (c == 'N') // Nord
	{
		player->dirX = 0;
		player->dirY = -1;
	}
	else if (c == 'E') // Est
	{
		player->dirX = 1;
		player->dirY = 0;
	}
	else if (c == 'S') // Sud
	{
		player->dirX = 0;
		player->dirY = 1;
	}
	else if (c == 'O') // Ouest
	{
		player->dirX = -1;
		player->dirY = 0;
	}
}

static int	ft_init_player(t_map *map, char *str, int y)
{
	t_player	*player;
	int			i;

	i = 0;
	player = malloc(sizeof(t_player));
	map->player = player;
	if (!player)
	{
		printf("Error during malloc for player\n");
		return (1);
	}
	while (str[i])
	{
		ft_player_orientation(str[i], player);
		ft_player_plane(str[i], player);
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'O')
			player->x = i;
		i++;
	}
	player->y = y;
	return (0);
}

// static int	ft_copy_lines(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 9;
// 	while (i < map->real_height)
// 	{
// 		map->grid[i] = ft_strdup(map->dirty_grid[j]);
// 		if (ft_find_player(map->grid[i]))
// 			if (ft_init_player(map, map->grid[i], i))
// 				return (1);
// 		j++;
// 		i++;
// 	}
// 	map->grid[i] = NULL;
// 	return (0);
// }

static int	ft_grid_copy_lines(t_map *map, int start)
{
	int	i;
	int	total_height;

	i = 0;
	total_height = start + map->real_height;
	while (start < total_height )
	{
		map->grid[i] = ft_strdup(map->dirty_grid[start]);
		if (ft_find_player(map->grid[i]))
		{
			if (ft_init_player(map, map->grid[i], i))
				return (1);
		}
		start++;
		i++;
	}
	map->grid[i] = NULL;
	return (0);
}

int	ft_generate_map_grid_util(t_map *map)
{
	int map_beginning;

	map_beginning = ft_find_map_beginning(map->dirty_grid);
	ft_grid_copy_lines(map, map_beginning);
	return (0);
}
