/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:10:01 by ahors             #+#    #+#             */
/*   Updated: 2024/09/27 15:40:15 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	ft_generate_map_grid(t_map *map)
{

	map->real_height = ft_find_map_height(map);
	map->grid = malloc(sizeof(char *) * (map->real_height + 1));
	if (!map->grid)
	{
		printf("Error during malloc for map->grid");
		return (1);
	}
	ft_generate_map_grid_util(map);
	if(ft_map_grid_is_valid(map, map->grid))
	{
		printf("This map is not valid\n");
		return (1);
	}
	return (0);
}

int	ft_parsing(t_map *map, char *filename)
{
	int	fd;

	fd = ft_open_file(filename);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	if (ft_generate_dirty_map_file(fd, map, filename))
		return (1);
	if (ft_map_info_is_valid(map))
		return (1);
	if (ft_generate_map_grid(map))
		return (1);
	
	return (0);
}
