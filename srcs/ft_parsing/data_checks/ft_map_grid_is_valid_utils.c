/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_is_valid_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:18:38 by ahors             #+#    #+#             */
/*   Updated: 2024/10/17 14:35:05 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_unvalid_chars(char c)
{
	
	if (c == 'N' || c == 'E' || c == 'S' || c == 'O' || c == '0' || c == '1'
		|| c == ' ' || c == '\n')
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
	int		i;
	char	last_char;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != '1')
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			last_char = str[i];
		i++;
	}
	if (last_char != '1')
	{
		printf("Missing a wall somewhere\n");
		return (1);
	}
	return (0);
}