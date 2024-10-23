/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:50:20 by ahors             #+#    #+#             */
/*   Updated: 2024/10/23 12:54:41 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_player_plane(char c, t_player *player)
{
	if (c == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (c == 'E')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (c == 'S')
	{
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (c == 'W')
	{
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

static void	ft_player_orientation(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

int	ft_init_player(t_map *map, char *str, int y)
{
	int	i;

	i = 0;
	if (map->player)
		free(map->player);
	map->player = malloc(sizeof(t_player));
	if (!map->player)
	{
		printf("Error: Malloc for player\n");
		return (1);
	}
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'W')
		{
			ft_player_orientation(str[i], map->player);
			ft_player_plane(str[i], map->player);
			map->player->x = i + 0.01;
			map->player->y = y + 0.01;
			map->grid[y][i] = '0';
		}
		i++;
	}
	return (0);
}

static char	*ft_copy_line_util(char *dest, char *src, int longest_string)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n' && i < longest_string)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < longest_string)
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

int	ft_generate_map_grid_util(t_map *map)
{
	int	i;
	int	total_height;
	int	start;

	i = 0;
	start = map->begin;
	total_height = start + map->real_height;
	while (start < total_height && map->dirty_grid[start])
	{
		map->grid[i] = malloc(sizeof(char) * (map->longest_str + 2));
		ft_copy_line_util(map->grid[i], map->dirty_grid[start],
			map->longest_str);
		start++;
		i++;
	}
	map->grid[i] = NULL;
	if (ft_map_has_one_player_is_valid(map))
		return (1);
	if (ft_find_player(map))
		return (1);
	return (0);
}
