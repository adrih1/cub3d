/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:58:31 by adrienhors        #+#    #+#             */
/*   Updated: 2024/09/16 17:29:57 by ahors            ###   ########.fr       */
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

char	*ft_clean_id_whitespace(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ' && !ft_isalpha(str[i]))
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

static int	ft_handle_f_color(t_map *map, char *line)
{
	if (ft_find_f_color(line))
	{
		ft_clean_id_whitespace(line);
		map->f_color = ft_split(line, ',');
		if (!map->f_color)
		{
			printf("There was an issue during malloc for map->f_color\n");
			return (1);
		}
		return (0);
	}
	return (1);
}

static int	ft_handle_c_color(t_map *map, char *line)
{
	if (ft_find_c_color(line))
	{
		ft_clean_id_whitespace(line);
		map->c_color = ft_split(line, ',');
		if (!map->c_color)
		{
			printf("There was an issue during malloc for map->c_color\n");
			return (1);
		}
		return (0);
	}
	return (1);
}

int	ft_find_colors(t_map *map)
{
	int	i;
	int	found_c;
	int	found_f;

	i = 0;
	found_c = 0;
	found_f = 0;
	while (map->dirty_grid[i] && i < map->m_height)
	{
		if (ft_handle_f_color(map, map->dirty_grid[i]) == 0)
			found_f = 1;
		if (ft_handle_c_color(map, map->dirty_grid[i]) == 0)
			found_c = 1;
		if (found_c && found_f)
			return (0);
		i++;
	}
	return (1);
}
