/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:46:23 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 17:48:32 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_find_file_height(int fd)
{
	int		height;
	char	*line;
	char	*temp;

	height = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		temp = line;
		line = get_next_line(fd);
		free(temp);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	ft_map_copy_lines(int fd, t_map *map)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\0')
	{
		temp = line;
		map->dirty_grid[i] = ft_strdup(line);
		line = get_next_line(fd);
		free(temp);
		i++;
	}
	map->dirty_grid[i] = NULL;
	free(line);
	close(fd);
	return (0);
}

size_t	ft_my_str_len(char *str)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

int	ft_find_map_longest_str(t_map *map)
{
	int		i;
	size_t	max_string;

	i = map->begin;
	max_string = 0;
	while (map->dirty_grid[i])
	{
		if (ft_my_str_len(map->dirty_grid[i]) > max_string)
			max_string = ft_my_str_len(map->dirty_grid[i]);
		i++;
	}
	return (max_string);
}

void	ft_last_info_found(t_map *map, int new_index_last_info)
{
	if (new_index_last_info > map->last_info_found)
		map->last_info_found = new_index_last_info;
}
