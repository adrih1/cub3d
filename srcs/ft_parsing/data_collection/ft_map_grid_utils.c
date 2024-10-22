/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:48:05 by ahors             #+#    #+#             */
/*   Updated: 2024/10/22 19:43:44 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	ft_find_player(t_map *map)
{
	int	i;
	int j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'E' || map->grid[i][j] == 'S' || map->grid[i][j] == 'W')
				if (ft_init_player(map, map->grid[i], i))
					return (1);
			j++;
		}
		
		i++;
	}
	return (0);
}

int	ft_check_is_grid_limit(char *str)
{
	int	i;
	int	count_one;

	i = 0;
	count_one = 0;
	while (str[i])
	{
		if (str[i] == '1')
		{
			count_one++;
			i++;
		}
		else if (str[i] == '\n' || str[i] == ' ' || str[i] == '0')
			i++;
		else
			return (0);
	}
	if (count_one >= 3)
		return (1);
	return (0);
}

int	ft_find_map_beginning(char **dirty_grid)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	temp = dirty_grid;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j] == ' ')
			j++;
		if (ft_check_is_grid_limit(temp[i]))
			return (i);
		i++;
	}
	return (0);
}

int	ft_find_map_end(t_map *map)
{
	int		i;
	int		j;
	char	**temp;

	temp = map->dirty_grid;
	i = map->m_height - 1;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j] == ' ')
			j++;
		if (ft_check_is_grid_limit(temp[i]))
			return (i);
		i--;
	}
	return (0);
}
