/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienhors <adrienhors@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:10:01 by ahors             #+#    #+#             */
/*   Updated: 2024/09/19 17:19:41 by adrienhors       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clean_dirty_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->m_height)
	{
		map->dirty_grid[i] = ft_str_trim(map->dirty_grid[i], ' ');
		printf("I in clean dirty map: %d\n", i);
		i++;
	}
	map->dirty_grid[i] = NULL;
}

int	ft_generate_dirty_map_file(int fd, t_map *map, char *filename)
{
	map->m_height = ft_find_file_height(fd);
	map->dirty_grid = malloc(sizeof(char *) * (map->m_height + 1));
	if (!map->dirty_grid)
	{
		printf("Error during malloc for map->dirty_grid\n");
		return (1);
	}
	fd = ft_open_file(filename);
	if (fd < 0)
	{
		free(map);
		close(fd); 
		return (1);
	}
	ft_map_copy_lines(fd, map);
	if (ft_map_find_info(map))
		return (1);
	// ft_display_map_info(map);
	return (0);
}

int	ft_find_map_height(t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map->dirty_grid[i])
	{
		if (ft_strcmp("\0", map->dirty_grid[i]) == 0)
			i++;
		count++;
		i++;
	}
	return (count);
}

int	ft_generate_map_file(t_map *map)
{
	int	i;
	int	height;

	i = 0;
	height = ft_find_map_height(map);
	map->grid = malloc(sizeof(char *) * height);
	if (!map->grid)
	{
		printf("Error during malloc for map->grid");
		return (1);
	}
	while (i < map->m_height)
	{
		map->grid[i] = ft_strdup(map->dirty_grid[i]);
		i++;
	}
	return (0);
}

int	ft_parsing(t_map *map, char *filename)
{
	int	fd;

	fd = ft_open_file(filename);
	if (fd < 0)
	{
		close (fd); 
		return (1);
	}
	if (ft_generate_dirty_map_file(fd, map, filename))
		return (1);
	if (ft_map_info_is_valid(map))
		return (1);
	// if (ft_generate_map_file(map))
	// return (1);
	// ft_load_textures(map);
	// Check Valid
	return (0);
}
