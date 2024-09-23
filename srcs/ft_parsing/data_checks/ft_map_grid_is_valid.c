/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_is_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:43:15 by ahors             #+#    #+#             */
/*   Updated: 2024/09/23 15:55:34 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_unvalid_chars(char c)
{
	if (c != 'N' && c != 'E' && c != 'S' && c != 'O' && c != '0' && c != '1'
		&& c != ' ' && c != '\n')
		return (1);
	return (0);
}

int	ft_check_has_only_walls_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == ' ' || str[i] == '\n')
            i++;
        else
            return (1);
	}
	return (0);
}

int	ft_map_grid_is_valid(t_map *map, char **grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		if (i == 0 || i == map->real_height)
		{
			if (ft_check_has_only_walls_spaces(map->grid[i]))
			{
				printf("Something is wrong with the walls\n");
				return (1);
			}
		}
		while (grid[i][j])
		{
			if (ft_check_unvalid_chars(grid[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
	// Ignore all leading whitespaces.

	// If current row is 0th row or the final row, only accept '1's and ' 's.
	// else, The first and final character should always be a '1'.

	// In the case of any non leading whitespaces,
		// the only acceptable characters adjacent to the space are '1's or ' 's.

	// If strlen(curr_row) > strlen(row_on_top)
		// && current col > strlen(row_on_top), current character should be '1'

	// If strlen(curr_row) > strlen(row_on_bottom)
		// && current col > strlen(row_on_bottom), current character should be '1'
}