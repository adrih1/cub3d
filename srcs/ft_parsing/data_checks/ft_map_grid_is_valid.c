/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_is_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:43:15 by ahors             #+#    #+#             */
/*   Updated: 2024/09/24 11:52:54 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_unvalid_chars(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'O' || c == '0' || c == '1' || c == ' ' || c == '\n')
		return (0);	
	else
		printf("Use only valid chars\n");		
	return (1);
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

int	ft_check_ones_end_begin(char *str)
{
	int i;
	char	last_char;

	i = 0;
	while(str[i] == ' ')
		i++;
	if (str[i] != '1')
		return (1);
	while(str[i])
	{
		if (ft_isdigit(str[i]))
			last_char = str[i];
		i++;
	}
	if(last_char != '1')
	{
		printf("Missing a wall somewhere\n");
		return(1);
	}
	return (0);
}

int	ft_map_grid_is_valid(t_map *map, char **grid)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		// If current row is 0th row or the final row, only accept '1's and ' 's.
		if (i == 0 || i == map->real_height)
		{
			if (ft_check_has_only_walls_spaces(map->grid[i]))
			{
				printf("Something is wrong with the walls\n");
				return (1);
			}
		}
		// The first and final character should always be a '1'.
		if(ft_check_ones_end_begin(map->grid[i]))
			return (1);
		j = 0;
		while (grid[i][j])
		{
			if (ft_check_unvalid_chars(grid[i][j]))
				return (1);	
			if(i >= 1 && i < map->real_height - 1)
			{
				// If strlen(curr_row) > strlen(row_on_top) && current col > strlen(row_on_top), current character should be '1'
				if((ft_strlen(grid[i]) > ft_strlen(grid[i - 1])) && ((size_t)j > ft_strlen(grid[i - 1])))
					if(grid[i][j] != '1' && grid[i][j] != ' ' && grid[i][j] != '\n')
						return (1);
				// If strlen(curr_row) > strlen(row_on_bottom) && current col > strlen(row_on_bottom), current character should be '1'
				if((ft_strlen(grid[i]) > ft_strlen(grid[i + 1])) && ((size_t)j > ft_strlen(grid[i + 1])))
					if(grid[i][j] != '1' && grid[i][j] != ' ' && grid[i][j] != '\n')
						return (1);
			}	
			j++;
		}
		i++;
	}
	return (0);

	// In the case of any non leading whitespaces,
		// the only acceptable characters adjacent to the space are '1's or ' 's.
	
}