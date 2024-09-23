/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:50:20 by ahors             #+#    #+#             */
/*   Updated: 2024/09/23 14:38:28 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_find_player(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'O')
			return (str);
		i++;
	}
	return (NULL);
}

static void	ft_player_orientation(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dirX = 0;
		player->dirY = 1;
	}
	else if (c == 'E')
	{
		player->dirX = 1;
		player->dirY = 0;
	}
	else if (c == 'S')
	{
		player->dirX = 0;
		player->dirY = -1;
	}
	else if (c == 'O')
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
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'O')
			player->x = i;
		i++;
	}
	player->y = y;
	player->planeX = 0; // Plan de la caméra perpendiculaire à dirX et dirY
	player->planeY = 0.66;
    ft_display_player_info(player);
	return (0);
}

static int	ft_copy_lines(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 9;
	while (i < map->real_height)
	{
		map->grid[i] = ft_strdup(map->dirty_grid[j]);
		if (ft_find_player(map->grid[i]))
			if (ft_init_player(map, map->grid[i], i))
				return (1);
		j++;
		i++;
	}
	map->grid[i] = NULL;
	return (0);
}

void	ft_generate_map_file_util(t_map *map)
{
	ft_copy_lines(map);
}
