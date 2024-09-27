/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_grid_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahors <ahors@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:48:05 by ahors             #+#    #+#             */
/*   Updated: 2024/09/27 15:39:27 by ahors            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_find_player(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'O')
			return (str);
		i++;
	}
	return (NULL);
}

int	ft_find_map_beginning(char **dirty_grid)
{
	int i;
	int j;
	char **temp;

	i = 0;
	temp = dirty_grid;
	while (temp[i])
	{
		j = 0;
		while(temp[i][j] == ' ')
			j++;
		if (temp[i][j] == '1')
			return (i);
		i++;
	}
	free(temp);
	return (0);
}