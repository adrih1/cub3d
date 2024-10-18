/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:10:01 by ahors             #+#    #+#             */
/*   Updated: 2024/10/18 16:05:31 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_generate_dirty_map_file(int fd, t_map *map, char *filename)
{
	map->m_height = ft_find_file_height(fd);
	map->dirty_grid = malloc(sizeof(char *) * (map->m_height + 1));
	if (!map->dirty_grid)
		return (ft_message_error("Error during malloc for map->dirty_grid"));
	fd = ft_open_file(filename);
	if (fd < 0)
	{
		free(map);
		close(fd);
		return (1);
	}
	ft_map_copy_lines(fd, map);
	return (0);
}

int	ft_generate_map_grid(t_map *map)
{
	map->begin = ft_find_map_beginning(map->dirty_grid);
	map->end = ft_find_map_end(map);
	map->longest_str = ft_find_map_longest_str(map);
	map->real_height = ft_find_map_height(map);
	map->grid = malloc(sizeof(char *) * (map->real_height + 1));
	if (!map->grid)
		return (ft_message_error("Error during malloc for map->grid"));
	ft_generate_map_grid_util(map);
	if(ft_map_grid_is_valid(map))
		return (ft_message_error("This map is not valid"));
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
	if (ft_map_find_info(map))
		return (1);		
	// ft_display_map_info(map);
	if (ft_map_info_is_valid(map))
		return (1);
	if (ft_generate_map_grid(map))
		return (1);
	return (0);
}
