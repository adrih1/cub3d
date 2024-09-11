/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:10:01 by ahors             #+#    #+#             */
/*   Updated: 2024/09/11 17:55:31 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_generate_dirty_map_file(int fd, t_map *map, char *filename)
{
	map->m_height = ft_find_map_height(fd);
	map->dirty_grid = malloc(sizeof(char *) * map->m_height);
	if (!map->dirty_grid)
	{
		printf("Error during malloc for map->dirty_grid\n");
		return(1);
	}
	fd = ft_open_file(filename);
	if (fd < 0)
	{
		free(map);
		return (1);
	}
	ft_map_copy_lines(fd, map);
	return (0);
}

int ft_generate_map_file(t_map *map)
{
	int i;

	i = 0;
	map->grid = malloc(sizeof(char *) * map->m_height);
	if(!map->grid)
	{
		printf("Error during malloc for map->grid");
		return (1);
	}
	while(i < map->m_height)
	{
		map->grid[i] = ft_strdup(map->dirty_grid[i]);
		map->grid[i] = ft_str_trim(map->grid[i], ' ');
		printf("%s", map->grid[i]);
		i++;
	}
	return (0);
}

int	ft_parsing(char *filename)
{
	int fd;
	t_map *map;

	map = malloc(sizeof(t_map));
	fd = ft_open_file(filename);
	if (fd < 0)
		return (1);
	if(ft_generate_dirty_map_file(fd, map, filename))
		return (1);
	if(ft_generate_map_file(map))
		return (1);
	// ft_load_textures(map);
	// Find Colors (Floor and Ceiling)
	// Check Valid
	return (0);
}