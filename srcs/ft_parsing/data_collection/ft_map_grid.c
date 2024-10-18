/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:50:20 by ahors             #+#    #+#             */
/*   Updated: 2024/10/18 18:13:57 by ahors            ###   ########.fr       */
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
	else if (c == 'W')
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
	else if (c == 'W') // Ouest
	{
		player->dirX = -1;
		player->dirY = 0;
	}
}

static int	ft_init_player(t_map *map, char *str, int y)
{
	int			i;

	i = 0;
	map->player = malloc(sizeof(t_player));
	if (!map->player)
	{
		printf("Error during malloc for player\n");
		return (1);
	}
	while (str[i])
	{
		ft_player_orientation(str[i], map->player);
		ft_player_plane(str[i], map->player);
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'W')
			map->player->x = i;
		i++;
	}
	map->player->y = y;
	return (0);
}

//Fonction d'affichage a supprimer plus tard
void	ft_display_line(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ')
			printf("_");
		else
			printf("%c", str[i]);
		i++;
	}
}

char *ft_copy_line_util(char *dest, char *src, int longest_string)
{
	int i; 

	i = 0;
	while(src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	while(i < longest_string)
	{
		dest[i] = ' ';
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

static int	ft_grid_copy_lines(t_map *map, int start)
{
	int	i;
	int	total_height;

	i = 0;
	total_height = start + map->real_height;
	while (start < total_height && map->dirty_grid[start])
	{
		map->grid[i] = malloc(sizeof(char) * (map->longest_str + 2));
		ft_copy_line_util(map->grid[i], map->dirty_grid[start], map->longest_str);
		// ft_display_line(map->grid[i]);
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

	ft_grid_copy_lines(map, map->begin);
	return (0);
}
