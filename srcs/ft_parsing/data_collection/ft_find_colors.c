/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:58:31 by adrienhors        #+#    #+#             */
/*   Updated: 2024/10/23 12:54:25 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_find_c_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_find_f_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'F')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_handle_f_color(t_map *map, char *line, int *count,
		int index_found)
{
	if (ft_find_f_color(line))
	{
		ft_clean_id_whitespace_color(line);
		map->f_color = ft_split(line, ',');
		if (!map->f_color)
		{
			printf("Error: Malloc for map->f_color\n");
			return (1);
		}
		(*count)++;
		ft_last_info_found(map, index_found);
		return (0);
	}
	return (1);
}

static int	ft_handle_c_color(t_map *map, char *line, int *count,
		int index_found)
{
	if (ft_find_c_color(line))
	{
		ft_clean_id_whitespace_color(line);
		map->c_color = ft_split(line, ',');
		if (!map->c_color)
		{
			printf("Error: Malloc for map->c_color\n");
			return (1);
		}
		(*count)++;
		ft_last_info_found(map, index_found);
		return (0);
	}
	return (1);
}

int	ft_find_colors(t_map *map)
{
	int	i;
	int	found_c;
	int	found_f;
	int	count;

	i = 0;
	found_c = 0;
	found_f = 0;
	count = 0;
	while (map->dirty_grid[i])
	{
		if (ft_handle_f_color(map, map->dirty_grid[i], &count, i) == 0)
			found_f = 1;
		if (ft_handle_c_color(map, map->dirty_grid[i], &count, i) == 0)
			found_c = 1;
		if (found_c && found_f && !(count > 2) && i == (map->m_height - 1))
			return (0);
		i++;
	}
	if (!found_c)
		printf("Error: Color C - Information not found \n");
	if (!found_f)
		printf("Error: Color F - Information not found \n");
	return (1);
}
